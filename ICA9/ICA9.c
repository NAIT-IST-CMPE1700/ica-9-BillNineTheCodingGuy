#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include "ICA9.h"

node* createNode(int ID, float mark, char* name) 
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->ID = ID;
	newNode->name = name;
	newNode->mark = mark;
	newNode->next = NULL;
	return newNode;
}

node* creatList(int Size, char** names) 
{
	
	srand(time(NULL));
	node* start = createNode(1000+0, rand() % 101, names[0]);
	node* current = start;
	for (int i = 1; i < Size; i++)
	{
		current->next = createNode(1000+i, (float)(rand() % 101)+(float)((rand() % 100)/100.0), names[i]);
		current = current->next;
	}
	return start;
}
void orderNodesID(node* head) 
{
	node* current = head;
	node* temp;
	while (current != NULL)
	{
		
		temp = current->next != NULL? current->next : NULL;
		while (temp != NULL)
		{
			if (current->ID > temp->ID)
			{
				node tempData = { current->ID,current->mark,current->name };
				current->ID = temp->ID; current->mark = temp->mark; current->name = temp->name;
				temp->ID = tempData.ID; temp->mark = tempData.mark; temp->name = tempData.name;
			}
			temp = temp->next;
		}
		current = current->next;
	}
}
void orderNodesMARK(node* head)
{
	node* current = head;
	node* temp;
	while (current != NULL)
	{

		temp = current->next != NULL ? current->next : NULL;
		while (temp != NULL)
		{
			if (current->mark > temp->mark)
			{
				node tempData = { current->ID,current->mark,current->name };
				current->ID = temp->ID; current->mark = temp->mark; current->name = temp->name;
				temp->ID = tempData.ID; temp->mark = tempData.mark; temp->name = tempData.name;
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

void displayNode(node* display , int searchID, float seachMark) 
{
	node* current = display;
	while (current != NULL)
	{
		if (current->ID != searchID && searchID != NULL)
		{
			current = current->next;
			continue;
		}
		if (current->mark < seachMark && seachMark >= 0)
		{
			current = current->next;
			continue;
		}
		if (searchID == NULL || seachMark < 0)
		{
			printf("\nID: %i", current->ID);
		}
		printf("\nName: "); printf(current->name);
		printf("\nMark: %.2f", current->mark);
		current = current->next;
	}
}
//appending to a list v
//essentailly all linked lists get ittrated with the same mentalitly 
//while(node* ->next != null), use a current to shuffle around data so that you can manipulate it 

