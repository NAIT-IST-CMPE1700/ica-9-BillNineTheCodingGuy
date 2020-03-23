#pragma once

typedef struct 
{
	int ID;
	float mark;
	char* name;
	struct node* next;		
}node;				//this defines node as a type

node* createNode(int ID, float mark, char* name);
node* creatList(int Size, char**);
//node the head reffers to the first member of the list
void orderNodesID(node* head);
void orderNodesMARK(node* head);
void displayNode(node* head, int searchID, float search);
