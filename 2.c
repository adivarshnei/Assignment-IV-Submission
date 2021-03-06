/* 

Assignemnt IV
Name: Adersh Varshnei
2. Write a C Program to print all even or odd numbers in given range using recursion

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

enum boolType {
	ODD = 1,
	EVEN
}; //enum boolType

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

int seriesPrint(int, int, enum boolType);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int lowLim, upLim, tempNum;
		enum boolType seriesType;

		printf("Enter the range of the numbers (Limits will be switched if entered in wrong order and converted to positive if negative): \n");

		printf("Enter the lower limit: ");
		scanf("%d", & lowLim);

		printf("Enter the upper limit: ");
		scanf("%d", & upLim);

		do {
			printf("Enter the series type: (ODD = 1, EVEN = 2): ");
			scanf("%d", & seriesType);

			if (seriesType != ODD && seriesType != EVEN) {
				printf("Invalid Entry\n");
			} //if (seriesType != ODD && seriesType != EVEN)
		} while (seriesType != ODD && seriesType != EVEN);

		lowLim = abs(lowLim);
		upLim = abs(upLim);

		if (upLim < lowLim) {
			tempNum = upLim;
			upLim = lowLim;
			lowLim = tempNum;
		}

		if (seriesType == ODD) {
			printf("Odd numbers between %d and %d are:\n", lowLim, upLim);
		} else if (seriesType == EVEN) {
			printf("Even numbers between %d and %d are:\n", lowLim, upLim);
		} //End of extended if clause

		seriesPrint(lowLim, upLim, seriesType);

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);
		scanf("%c", & temp);

		count++;

		if (count >= 15) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		} //if (count >= 15) 
	} //while (rep == 1) 

	printf("Normal END\n");

	getch();
	return 0;
} //int main(void)

//************************************************************************************************

int seriesPrint(int lowLim, int upLim, enum boolType seriesType) {
	if ((lowLim % 2 == 0 && seriesType == ODD) || (lowLim % 2 == 1 && seriesType == EVEN)) {
		lowLim += 1;
	} //if ((lowLim % 2 == 0 && seriesType == ODD) || (lowLim % 2 == 1 && seriesType == EVEN))

	if (lowLim <= upLim) {
		printf("%d\t", lowLim);

		return seriesPrint(lowLim + 2, upLim, seriesType);
	} else {
		return 1;
	} //End of extended if clause
} //int seriesPrint(int lowLim, int upLim, enum boolType seriesType)