all: main.c function.o
        cc -o cej112016 main.c function.o

function.o: function.c chess.h
        cc -c function.c

clean:
        rm *.o a.out *.*~