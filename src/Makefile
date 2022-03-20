EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

clear: 
	rm *.o
	rm $(PROJECT_NAME)

$(PROJECT_NAME): main.o system.o files.o geo.o
	$(EXEC) $(CFLAGS) main.o system.o files.o geo.o -o $(PROJECT_NAME)

geo.o: geo.c geo.h
	$(EXEC) $(CFLAGS) -c geo.c

files.o: files.c files.h
	$(EXEC) $(CFLAGS) -c files.c

system.o: system.c system.h
	$(EXEC) $(CFLAGS) -c system.c

main.o: main.c system.h files.h geo.h
	$(EXEC) $(CFLAGS) -c main.c