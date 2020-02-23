#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_TREE 40

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef int element;
typedef int* Tree;
 

Tree CreateTree(Tree header){
	
	int* tree = (int*)malloc(sizeof(int) * MAX_SIZE_TREE + 1);
	
	return tree;
}

void InitTree(Tree header){
	int i;
	for(i = 0; i<=MAX_SIZE_TREE;i++){
		header[i] = -1;
	}
}

element InsertTree(Tree header , int inputNum, element data){
	if(inputNum == 1){
		header[inputNum] = data;
		printf("data %d를 %d칸에 집어넣었습니다.\n",data,inputNum);
		return data;

	}
	else if(MAX_SIZE_TREE < inputNum || 0>= inputNum || header[inputNum/2] == -1){
		fprintf(stdout,"에러 발생\n");
		return -1;
	}
	else{
		header[inputNum] = data;
		printf("data %d를 %d칸에 집어넣었습니다.\n",data,inputNum);
		return data;
	}
}

int GotoLeft(Tree tree,int num){
	if( tree[2*num] != -1 ){
		return 2*num;
	}
	else{	
		return -1;
	}
}
int GotoRight(Tree tree,int num){
	if( tree[2*num+1] != -1 ){
		return 2*num+1;
	}
	else{
		return -1;
	}
}
int GotoRoot(Tree tree,int num){
	if( num/2 != 0 ){
		return num/2;
	}
	else{
		return -1;
	}
}



int Preorder(Tree tree,int num){
	printf("%d->",num);	
	if(tree[num*2] != -1){
		Preorder(tree,num*2);
	}
	if(tree[num*2+1] != -1){
		Preorder(tree,num*2 + 1);
	}
	else return -1;
}
int Inorder(Tree tree,int num){
	if(tree[num*2] != -1){
		Inorder(tree,num*2);
	}
	printf("%d->",num);		
	if(tree[num*2+1] != -1){
		Inorder(tree,num*2 + 1);
	}
	return -1;
}

int Postorder(Tree tree,int num){	
	if(tree[num*2] != -1){
		Postorder(tree,num*2);
	}
	if(tree[num*2+1] != -1){
		Postorder(tree,num*2 + 1);
	}
	printf("%d->",num);	
	return -1;
}

int main(int argc, char *argv[]) {
	
	Tree tree1 = CreateTree(tree1);
	InitTree(tree1);

	InsertTree(tree1,1,1);
	InsertTree(tree1,2,2);
	InsertTree(tree1,3,3);	
	InsertTree(tree1,5,3);
	InsertTree(tree1,4,4);
	InsertTree(tree1,10,10);
	
	printf("선위순회\n");	
	Preorder(tree1,1);
	printf("\n");
	printf("중위순회\n"); 
	Inorder(tree1,1);
	printf("\n");
	printf("후위순회\n"); 
	Postorder(tree1,1);
	
	system("pause");
	return 0;
}
