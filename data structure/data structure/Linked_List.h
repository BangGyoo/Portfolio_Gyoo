#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef short boolean; 

typedef int element;

typedef struct _ListNode{
	element data;
	struct _ListNode *next;
}ListNode;

void InitNode(ListNode *list){
	list->data = 0;
	list->next = NULL;
	return ;
}

void CreateNode(ListNode **list,element item){
	ListNode *node;
	node = (ListNode*)malloc(sizeof(ListNode));
	InitNode(node);
	node->data = item;
	*list = node;
	return ;
}

void InsertNode(ListNode **pnode,element item){
	ListNode *node = *pnode;
	ListNode *inputNode;	
	if(node == NULL){
		CreateNode(&node,item);		
		node->data = item;
		*pnode = node;
	}
	else if(node->next == node){
		CreateNode(&inputNode,item);
		node->next   = inputNode;
	}
	else{
		CreateNode(&inputNode,item);
		while(node->next != NULL) node = node->next;
		node->next = inputNode;

	}
}

int Display(ListNode *list){						// list의 length를 반환 차후에 deleteNode를 삭제위해 쓰임 
	ListNode *nextNode = list;
	int ListLength = 0;
	if(list != NULL){
		do{
			ListLength++;
			printf("%d->",nextNode->data);
			nextNode = nextNode->next;
		}while(nextNode != NULL);
	}
	else{
		fprintf(stdout,"출력값이 존재하지 않습니다.");
	}
	printf("\n");
	return ListLength;
}

void DeleteNode(ListNode **pnode,int place_Address){ // place_address는 장소 번호를 뜻한다. 1번부터 start
	
	if(*pnode == NULL){
		fprintf(stderr,"pnode is NULL\n");
		return ;
	}
	else if( place_Address < 1){
		fprintf(stderr,"error : Address Number\n");
		return ;
	}
	else{
		ListNode *p_deletionNode = *pnode;
		
		if(p_deletionNode->next == NULL && place_Address == 1){
			free(p_deletionNode);
			return ;
		}
		else if(place_Address == 1){
			*pnode = (*pnode)->next;
			return ;
		}
		while(p_deletionNode->next != NULL && place_Address != 2){
			p_deletionNode = p_deletionNode->next;
			place_Address--;
		}
		if( p_deletionNode->next == NULL ){
			fprintf(stderr,"error : Address Number\n");
			return ;
		}
		else if(place_Address == 2){
			ListNode *deletionNode = p_deletionNode->next;
			p_deletionNode->next = deletionNode->next;
			free(deletionNode);
			return ;
		}	
	}
}

boolean Delete_Node_Of_All(ListNode *node){
	ListNode *ptr;
	if(node == NULL) return FALSE;
	do{
		ptr = node;
		node = node->next;
		free(ptr);
	}while( node != NULL);
	return TRUE;
}





