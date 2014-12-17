#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const size_t MAXSTR=512;


void string_reverse1(char * string) {

    // in place reverse of string.

    if ((string == NULL) || (strlen(string) >= MAXSTR)) {
        // should return error code.
        return;
    }
    char *head=string;
    char *tail = string + strlen(string) - 1;

    while (head < tail) {

        char tmp = *head;
        *head = *tail;
        *tail = tmp;
        tail--;
        head++;

    }
    
}


char * string_reverse2a(const char * string) {
    
    // reentrant version, uses heap.
    // note: need to call free() on returned string.
    
    if ((string == NULL) || (strlen(string) >= MAXSTR)) {
        return NULL;
    }

    // leave 1 byte for NULL.
    char *dup = strndup(string, MAXSTR-1);
    
    string_reverse1(dup);
    return dup;

}


char * string_reverse2b(const char * string) {

    // note: not reentrant, returns ptr to static.
    
    static char str[MAXSTR];

    if ((string == NULL) || (strlen(string) >= MAXSTR)) {
        return NULL;
    }

    strlcpy (str, string, MAXSTR);
    string_reverse1(str);
    return str;

}



int main (int argc, char *argv[]){

    if (argc == 1) {

        printf ("%s: string reverser\n", argv[0]);
        printf ("%s <string(s) to reverse> ...\n", argv[0]);
        exit (1);
        
    }

    for (int i=1; i < argc; i++){
        
        char *revstr = string_reverse2a(argv[i]);
        printf ("strrev2a: %s -> %s\n", argv[i], revstr);
        printf ("strrev2b: %s -> %s\n", revstr, string_reverse2b(revstr));
        free(revstr);
        // string_reverse1() is implicitly tested by the above.

    }

    exit (0);

}
