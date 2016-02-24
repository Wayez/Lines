OBJECTS= main.o draw.o display.o
CFLAGS= -Wall
CC= gcc

all: $(OBJECTS)
	$(CC) -o main $(OBJECTS) -lm

main.o: main.c display.h draw.h ml6.h
	$(CC) -c main.c -lm

draw.o: draw.c draw.h display.h ml6.h
	$(CC) $(CFLAGS) -c draw.c -lm

dsiplay.o: display.c display.h ml6.h
	$(CC) $(CFLAGS) -c display.c -lm

clean:
	rm *.o *~