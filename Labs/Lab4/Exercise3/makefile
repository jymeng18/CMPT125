RectTest:  testDriver.o InRectangle.o
	gcc -Wall -o RectTest testDriver.o InRectangle.o -lm

InRectangle.o: InRectangle.c InRectangle.h
	gcc -Wall -c InRectangle.c -lm

testDriver.o: testDriver.c InRectangle.h
	gcc -Wall -c testDriver.c -lm

clean:
	rm -f RectTest *.o