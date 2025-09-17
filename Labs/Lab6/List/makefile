testList: testDriver.o dataStructure.o
	gcc -Wall testDriver.o dataStructure.o -o testList

dataStructure.o: dataStructure.c dataStructure.h
	gcc -Wall -c dataStructure.c

testDriver.o: testDriver.c dataStructure.h
	gcc -Wall -c testDriver.c

clean:
	rm -f testList *.o
