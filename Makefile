EXEC=strrev
OBJS=strrev.o

default: ${EXEC}

clean:
	rm -f ${OBJS} ${EXEC}

${EXEC}: ${OBJS}
	gcc -ggdb -o $@ $^

%.o: %.c
	gcc -ggdb -c $<
