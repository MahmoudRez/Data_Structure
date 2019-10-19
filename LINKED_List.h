/*
 * LINKED_List.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Mahmoud Rezk Mahmoud
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "STD_TYPES.h"

typedef struct node
{
	uint32 data;
	struct node * next;
}ST_Node;

typedef struct list
{
	 ST_Node * Head;
}ST_list;

/*creating ID History for user*/
enum options
{
	CREAT,
	INSERT,
	DELET,
	SEARCH,
	SORT,
	REVERSE,
	PRINT,
	SIZE,
	EXIT
};


void createList( ST_list **Head);
void insertToList(ST_Node **listHead, uint8 position, uint32 data);
void DeleteNode(ST_Node ** listHead,uint8 position);
void SearchNode(ST_Node** listHead, uint32 data);
void ListSize(ST_Node** listhead);
void SortList(ST_Node **listHead);
void ReverseList(ST_Node** listHead);
void PrintList(ST_Node ** listHead);



#endif /* LINKED_LIST_H_ */
