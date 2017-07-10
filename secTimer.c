#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>

#include "oneDigitCC.h"

#define BUZZER 22
#define SWITCH 21

int A= 0;
int B= 1;
int C= 2;
int D= 3;
int E= 4;
int F= 5;
int G= 6;

int main(void)
{
	wiringPiSetup();
	int maxTime, i;
	int wait= 1000;
	printf("Enter the maximum time in seconds(max. limit is 99 sec):- ");
	scanf("%d", &maxTime);
	for(i=maxTime; i>=0; i--)
	{
		oneDigitCC(i, wait);
		printf("\t%ds\n", i);
		while(i==0)
		{
			pinMode(BUZZER, OUTPUT);
			digitalWrite(BUZZER, HIGH);
			while(SWITCH==1)
			{
				pinMode(BUZZER, OUTPUT);
				digitalWrite(BUZZER, LOW);
			}
		}
	}
	return EXIT_SUCCESS;
}
