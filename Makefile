EXEC=strrev
OBJS=strrev.o

default: ${EXEC}

clean:
	rm -f ${OBJS} ${EXEC}

${EXEC}: ${OBJS}
	gcc -Wall -ggdb -o $@ $^

%.o: %.c
	gcc -Wall -ggdb -c $<
