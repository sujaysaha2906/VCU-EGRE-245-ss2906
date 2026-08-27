#include <stdio.h>

#define Reading_Assignment 5
#define Homework 5
#define Lab_Assignment 15
#define Programming_Assignment 25
#define TopHat 5
#define Quiz 10
#define Midterm 15
#define Final 20

int main()
{
	double want, raAvg, hwAvg, laAvg, paAvg, mtAvg, thAvg, quAvg, final;
	printf("What average do you want to earn: ");
	scanf("%lf", &want);
	printf("\n\nInput your Reading Assignment average: ");
	scanf("%lf", &raAvg);
	printf("\n\nInput your Homework average: ");
	scanf("%lf", &hwAvg);
	printf("\n\nInput your Lab Assignment average: ");
	scanf("%lf", &laAvg);
	printf("\n\nInput your Programming Assignment average: ");
	scanf("%lf", &paAvg);
	printf("\n\nInput your Quiz average: ");
	scanf("%lf", &quAvg);
	printf("\n\nInput your TopHat average: ");
	scanf("%lf", &thAvg);
	printf("\n\nInput your Midterm score: ");
	scanf("%lf", &mtAvg);

	printf("\n\nYou need a %lf on the final exam to earn a %lf in the course", (want - ((raAvg*Reading_Assignment + hwAvg*Homework + laAvg*Lab_Assignment + paAvg*Programming_Assignment + quAvg*Quiz + thAvg*TopHat + mtAvg*Midterm)/100))/0.2, want);

	return 0;
}