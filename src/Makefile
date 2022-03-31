EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

clear: 
	rm *.o
	rm $(PROJECT_NAME)
	cd ..;cd output; rm teste.svg

$(PROJECT_NAME): main.o system.o files.o geo.o list.o svg.o
	$(EXEC) $(CFLAGS) main.o system.o files.o geo.o list.o svg.o -o $(PROJECT_NAME)

svg.o: svg.c svg.h
	$(EXEC) $(CFLAGS) -c svg.c

list.o: list.c list.h
	$(EXEC) $(CFLAGS) -c list.c

geo.o: geo.c geo.h list.h svg.h
	$(EXEC) $(CFLAGS) -c geo.c

files.o: files.c files.h
	$(EXEC) $(CFLAGS) -c files.c

system.o: system.c system.h
	$(EXEC) $(CFLAGS) -c system.c

main.o: main.c system.h files.h geo.h
	$(EXEC) $(CFLAGS) -c main.c