#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct _TreeNode{
	element data;
	int thread;
	struct _TreeNode *left, *right;
}TreeNode;

void InitTree(TreeNode *tree){
	tree->data = 0;
	tree->thread= FALSE;
	tree->left = NULL;
	tree->right= NULL;
}

TreeNode *CreateNode(TreeNode *tree,element input){
	tree = (TreeNode*)malloc(sizeof(TreeNode));
	InitTree(tree);
	tree->data = input;
	tree->thread= TRUE;
	return tree;
}

TreeNode *InsertTree(TreeNode *tree,TreeNode *next,int choice){			// 선택은 1번 왼쪽, 2번 오른쪽 
	if(choice == 1){
		tree->left = next;
		tree->thread= FALSE;
		return tree;
	}
	else if(choice == 2){
		tree->right= next;
		tree->thread= FALSE;
		return tree;
	}
	else{
		fprintf(stdout,"3번째 인자는 1or2입니다.");
		return NULL; 
	}
}

TreeNode *GotoThread(TreeNode *root,TreeNode *node){

	if( root == node ) return root;
	
	if(node->thread == TRUE){
		TreeNode *leftAngle = root->left;
		while(leftAngle->thread == FALSE){
			leftAngle = leftAngle->right;
		}
		TreeNode *rightAngle= root->right;
		while(rightAngle->thread == FALSE){
			rightAngle = rightAngle->left;
		}
		if(leftAngle == node ){
			printf("%d left 스레드는 %d이다.\n",node->data,root->data);
			node->right = root;
		}
		else if(rightAngle == node ){
			printf("%d right 스레드는 %d이다.\n",node->data,root->data);			
			node->left =  root;
		}
//		else{
//			printf("해당 노드는 root의 하위단에 존재하지 않는다.\n");
//		}
		return root;
		
		
	}
	else{
		printf("하위 노드가 존재합니다.");
		return NULL;
	}

}

void Match_Thread(TreeNode *root, TreeNode *tree){
	if(root->thread == FALSE && tree->thread == TRUE) GotoThread(root,tree);
	if(tree->thread == FALSE){
		Match_Thread(root,tree->left);
		Match_Thread(root,tree->right);
	}
	else if(root->thread == FALSE){
	 	Match_Thread(root->left,tree);
	    Match_Thread(root->right,tree);
	}
}

void Inorder(TreeNode *root){
	while(root->right != NULL){
		if(root->thread == FALSE)root = root->left;
		if(root->thread == TRUE){
			printf("%d->",root->data);
			root = root->right;
			printf("%d->",root->data);
			root = root->right;
		}
	}
	printf("%d->",root->data);
}
/*
void Preorder(TreeNode *root){
	if(root){
		printf("%d->",root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Postorder(TreeNode *root){
	if(root){
		Postorder(root->left);
		Postorder(root->right);
		printf("%d->",root->data);
	}
}
*/

int main(int argc, char *argv[]) {
	
	TreeNode *tree[22];
	int i;
	for(i=1;i<22;i++){
		tree[i] = CreateNode(tree[i],i*10);
	}
	for(i=1;i<11;i++){
		InsertTree(tree[i],tree[i*2],1);
		InsertTree(tree[i],tree[i*2+1],2);
	}
	TreeNode *tree1,*tree2,*tree3,*tree4,*tree5,*tree6,*tree7,*tree8,*tree9,*tree10,*tree11;
	tree1 = CreateNode(tree1,10);
	tree2 = CreateNode(tree2,20);
	tree3 = CreateNode(tree3,30);
	tree4 = CreateNode(tree4,40);
	tree5 = CreateNode(tree5,50);
	tree6 = CreateNode(tree6,60);
	tree7 = CreateNode(tree7,70);
	tree8 = CreateNode(tree8,80);
	tree9 = CreateNode(tree9,90);
	tree10 = CreateNode(tree10,100);	
	tree11 = CreateNode(tree11,110);	
	
	InsertTree(tree1,tree2,1);
	InsertTree(tree1,tree3,2);
	InsertTree(tree2,tree4,1);
	InsertTree(tree2,tree5,2);
	InsertTree(tree3,tree6,1);
	InsertTree(tree3,tree7,2);
	InsertTree(tree4,tree8,1);
	InsertTree(tree4,tree9,2);
	InsertTree(tree5,tree10,1);
	InsertTree(tree5,tree11,2);
	Match_Thread(tree1, tree1);

//	printf("tree11의 스레드의 데이터는 %d입니다.\n",tree11->right->data);
	
//	printf("tree6는 %d입니다.\n",tree1->right->left->data);
	
	Inorder(tree1);
	printf("\n");
	Match_Thread(tree[1], tree[1]);	
	Inorder(tree[1]);
	printf("\n");
	
//	Postorder(tree1);
//	printf("\n");
//	Preorder(tree1);
//	printf("\n");
//	
	system("pause");
	return 0;
}
