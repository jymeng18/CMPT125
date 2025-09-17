dS: dataStructure.o Demo_File_IO.o
	gcc -Wall -o dS dataStructure.o Demo_File_IO.o

dataStructure.o: dataStructure.c dataStructure.h
	gcc -Wall -c dataStructure.c 

Demo_File_IO.o: Demo_File_IO.c dataStructure.h
	gcc -Wall -c Demo_File_IO.c 

clean:
	rm -f dS *.o