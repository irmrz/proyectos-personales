tracker: main.o functions.o 
	gcc  -Wall -Wextra -std=c99 -g main.o functions.o -o test

main.o: main.c
	gcc -c  -Wall -Wextra -std=c99 main.c 

functions.o: functions.c functions.h
	gcc -c -Wall -Wextra -std=c99 functions.c 

clean:
	rm *.o test 