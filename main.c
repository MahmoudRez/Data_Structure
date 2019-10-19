/*
 * main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Mahmoud Rezk Mahmoud
 */
#include <stdio.h>
#include <stdlib.h>
#include "LINKED_List.h"
/*char createList(ST_list **head)
{
	head=NULL;
}*/


/*void insert_NodeAtFirst(short data){
// create link
	struct node* link = (struct node*) malloc(sizeof(node)) ;

	link->data=data;
	link->next=head;
	head=&link;
}*/
void main (void)
{

	ST_list LIST1;
	ST_list * LIST=&LIST1;
	static uint32 LOC_ID;
	static uint32 LOC_Position;
	static uint32 LOC_Data;
	static uint8 LOC_ExitFlag=0;
	printf("Creat list ID is: %d \n",CREAT);
	printf("insert Node : %d \n",INSERT);
	printf("delete Node ID is: %d \n",DELET);
	printf("search Node ID is: %d \n",SEARCH);
	printf("Sort list is: %d \n",SORT);
	printf("Reverse list: %d \n",REVERSE);
	printf("Print list : %d \n",PRINT);
	printf("List Size : %d \n",SIZE);
	printf("Exit from the program: %d \n",EXIT);
	while(LOC_ExitFlag==0)
	{
		printf("Please Enter Your Operation ID: ");
		scanf("%d",&LOC_ID);
		switch (LOC_ID)
		{
		case CREAT:
			createList(&LIST);
			ST_Node * NODE_Head= LIST->Head;

			break;
		case INSERT:
			printf("Please Enter the Data which you want to insert");
			scanf("%d",&LOC_Data);
			printf("Please Enter the position which you want to insert in to");
			scanf("%d",&LOC_Position);
			insertToList(&NODE_Head,LOC_Position,LOC_Data);
			break;
		case DELET:
			printf("Please Enter the Index of Node which want to Delete");
			scanf("%d",&LOC_Position);
			DeleteNode(&NODE_Head,LOC_Position);
			break;
		case SEARCH:
			printf("Please Enter the Data which you want to search");
			scanf("%d",&LOC_Data);
			SearchNode(&NODE_Head,LOC_Data);
			break;
		case REVERSE:
			ReverseList(&NODE_Head);
			break;
		case SORT:
			SortList(&NODE_Head);
			break;
		case EXIT:
			printf("Thank you,Goodbye \n");
			LOC_ExitFlag=1;
			break;
		case PRINT:
			PrintList(&NODE_Head);
			break;
		case SIZE:
			ListSize(&NODE_Head);
			break;
		default:
			printf("incorrect Entery please try again \n");
			break;
		}
	}














}


