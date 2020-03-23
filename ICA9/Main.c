#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ICA9.h";

//#pragma warning(disable:4996)
int main()
{
	char* names[10] = { '\0' };
	names[0] = "bob"; names[1] = "ted"; names[2] = "berry"; names[3] = "careen"; names[4] = "poppy";
	names[5] = "joe"; names[6] = "kile"; names[7] = "al"; names[8] = "kevin"; names[9] = "jackie";
	char cInput = 'a';
	int nInput = 0;
	float fInput = 0;
	node* start = creatList(10, names);

	while (cInput != '5')
	{
		cInput = '0';
		printf("\n\n");
		printf("1. Display list order of Id's\n");
		printf("2. Display list marks in decending order\n");
		printf("3. Display marks Given ID\n");			//only names and makrs
		printf("4. Display Marks Above threashold\n");	//only names and marks
		printf("5. Exit\n");
		scanf_s("%c", &cInput, sizeof(char));
		printf("\n");
		switch (cInput)
		{
		case '1':
			orderNodesID(start);
			displayNode(start, NULL, -1);
			break;
		case '2':
			orderNodesMARK(start);
			displayNode(start, NULL, -1);
			break;
		case '3':
			printf("Enter ID:");
			scanf_s("%i", &nInput, sizeof(int));
			displayNode(start, nInput, 0);
			break;
		case '4':
			printf("Enter Mark Threashold:");
			scanf_s("%f", &fInput, sizeof(float));
			displayNode(start, 0, fInput);
			break;
		case '5':
			break;
		default:
			printf("you have entered a invalid input");
			break;
		}
		getchar();
	}
	exit(EXIT_SUCCESS);
}

	//displayNode(start);
	//and it begeins
	

	// creates 3 arrays/store data of Names,ID numbers, marks
	//builds a link list of structs where each struct contains all 3 (names,ID and makrs)

	//Continusly display a menu that has the following options
			/* 1 display list in order of id */ 
			//display list in decending order of marks
			//display the name and mark with INPUTED ID
			//display the names and marks of a all persons above a threashold INPUTED MARK
			//exit
