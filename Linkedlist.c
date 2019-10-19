/*
 * LINKED_List.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Mahmoud Rezk Mahmoud
 */
#include "LINKED_List.h"
#include <stdio.h>
#include <stdlib.h>


static void Insert_First(ST_Node **listHead,uint32 data);

void createList( ST_list **LIST)
{
	(*LIST)->Head=NULL;
}

void insertToList(ST_Node **listHead, uint8 position, uint32 data)
{

	ST_Node* LOC_NewNode=(ST_Node *)malloc(sizeof(ST_Node));
	if((*listHead)==NULL)
	{
		(*listHead)=LOC_NewNode;
		(*listHead)->data=data;
		(*listHead)->next=NULL;
		return;
	}
	else
	{
		if(position==0)
		{
			LOC_NewNode->next=(*listHead);
			LOC_NewNode->data=data;
			(*listHead)=LOC_NewNode;
			return;
		}
		else
		{
			uint8 LOC_Itteration=0;

			ST_Node* LOC_current=(*listHead);

			for(LOC_Itteration=0;LOC_Itteration<position-1;LOC_Itteration++)
			{
				if(LOC_current->next==NULL)
				{
					LOC_NewNode->next=NULL;
					LOC_current->next=LOC_NewNode;
					LOC_NewNode->data=data;

					return;
				}
				LOC_current=LOC_current->next;
			}

			LOC_NewNode->data=data;

			LOC_NewNode->next=LOC_current->next;
			LOC_current->next=LOC_NewNode;

		}
	}


}
void PrintList(ST_Node **listHead)
{
	ST_Node *ptr = (*listHead);
	printf("[LIST_Head] =>");

	/*start looping from the head until the last node*/
	while(ptr != NULL)
	{
		printf(" %d =>",ptr->data);
		ptr = ptr->next;
	}

	printf(" [NULL]\n");
}
void DeleteNode(ST_Node ** listHead,uint8 position)
{
	ST_Node* current = *listHead;
	ST_Node* DeleteNode = NULL;
	int i,flag = 1;

	if(position == 0)
	{
		(*listHead )= current->next;
		free(current);
		return;
	}
	/* Searching for index node */
	for(i=0;i<position-1;i++){
		if(current->next == NULL)
		{
			flag = -1;
			return;
		}
		else
		{
			current = current->next;
		}
	}

	if(flag == 1)
	{
		/* saving pointer to free it */
		DeleteNode = current->next;

		/* Pre-deleted node point to the post_deleted node */
		current->next = current->next->next;

		/* free deleted node */
		free(DeleteNode);
	}
}




void SearchNode(ST_Node** listHead, uint32 data)
{
	uint8 pos = 0;
	ST_Node *current = NULL;
	if((*listHead)==NULL)
	{
		printf("Linked List is empty");
		return;
	}

	// start checking from the first node
	current = (*listHead);
	while(current != NULL)
	{
		if(current->data == data)
		{
			printf("%d found at position %d\n", data, pos);
			return;
		}
		current = current->next;
		pos++;
	}
	// item not found in the list
	printf("%d does not exist in the list\n", data);
}

void ListSize(ST_Node** listhead)
{
	uint8 size = 0;
	ST_Node *current = NULL;
	// check if the linked list is empty
	if((*listhead)==NULL)
	{
		printf("List size : %d\n", size);
		return;
	}
	// list is not empty contains one node at least
	current = (*listhead);
	size = 1;
	while(current->next != NULL)
	{
		current = current->next;
		size++;
	}
	printf("List size : %d\n", size);
}

/*******************************************************************************
 * Function Name:	ReverseList
 *
 * Description: 	Reverse the Linked List
 *
 * Inputs:			*pointer to pointer to struct "Head of Linked List"
 *
 * Return:		    void
 *******************************************************************************/
void ReverseList(ST_Node** listHead)
{
	ST_Node * current = (*listHead);
	ST_Node * prev = NULL;
	ST_Node * Next = NULL;

	if((*listHead)==NULL)
	{
		printf("Linked List is empty");
		return;
	}
	else
	{
		while(current != NULL)
		{
			Next=current->next;
			current->next=prev;
			prev=current;
			current=Next;
		}
		(*listHead)=prev;
	}


}
/*******************************************************************************
 * Function Name:	SortList
 *
 * Description: 	sort the element of the Linked List
 *
 * Inputs:			*pointer to pointer to struct "Head of Linked List"
 *
 * Return:		    void
 *******************************************************************************/

void SortList(ST_Node **listHead){
	uint8 temp=0;
	ST_Node * node=(*listHead);
	ST_Node * sec_node=(*listHead);
	sec_node = node->next;
	while(node->next!=NULL){
		/*prev_Data=node->data;*/
		while(sec_node!=NULL)
		{

			if((node->data) > (sec_node->data))
			{
				temp=sec_node->data;
				sec_node->data=node->data;
				node->data=temp;
			}
			sec_node = sec_node->next;
		}
		node=node->next;
		sec_node = node->next;
	}

}

void Insert_First(ST_Node **listHead,uint32 data)
{

	ST_Node * LOC_NewNode;
	if(listHead==NULL)
	{
		(*listHead)=LOC_NewNode;
		(*listHead)->data=data;
		(*listHead)->next=NULL;
	}
	else
	{
		LOC_NewNode->next=(*listHead);
		LOC_NewNode->data=data;
		(*listHead)=LOC_NewNode;
	}

}
