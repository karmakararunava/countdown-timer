%.o: %.c
	gcc -Wall -c *.c -I./
secTimer: *.o
	gcc -Wall -o secTimer *.o -lwiringPi
clean
	rm -f *.o secTimer
