EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

run: 
	clear
	./$(PROJECT_NAME) -e /home/vfsilva/estudo/repositories/project/input -f casa-campo.geo -o /home/vfsilva/estudo/repositories/project/output -q 001-dels.qry

clear: 
	rm *.o;
	rm $(PROJECT_NAME);
	cd ..;cd output; rm *.svg; rm *.txt

$(PROJECT_NAME): main.o system.o files.o geo.o list.o svg.o circle.o rectangle.o line.o text.o queue.o qry.o
	$(EXEC) $(CFLAGS) main.o system.o files.o geo.o list.o svg.o circle.o rectangle.o line.o text.o queue.o qry.o -o $(PROJECT_NAME)

svg.o: svg.c svg.h
	$(EXEC) $(CFLAGS) -c svg.c

list.o: list.c list.h
	$(EXEC) $(CFLAGS) -c list.c

queue.o: queue.c queue.h list.h
	$(EXEC) $(CFLAGS) -c queue.c

qry.o: qry.c qry.h queue.h circle.h rectangle.h line.h text.h svg.h
	$(EXEC) $(CFLAGS) -c qry.c

circle.o: circle.c circle.h
	$(EXEC) $(CFLAGS) -c circle.c

rectangle.o: rectangle.c rectangle.h
	$(EXEC) $(CFLAGS) -c rectangle.c

line.o: line.c line.h
	$(EXEC) $(CFLAGS) -c line.c

text.o: text.c text.h
	$(EXEC) $(CFLAGS) -c text.c

geo.o: geo.c geo.h list.h svg.h circle.h rectangle.h line.h text.h
	$(EXEC) $(CFLAGS) -c geo.c

files.o: files.c files.h
	$(EXEC) $(CFLAGS) -c files.c

system.o: system.c system.h
	$(EXEC) $(CFLAGS) -c system.c

main.o: main.c system.h files.h geo.h
	$(EXEC) $(CFLAGS) -c main.c