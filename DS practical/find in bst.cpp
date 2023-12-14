/*srarch a particual key in bst*/
/*bst*/
#include<stdio.h>
#include<stdlib.h>
 struct node{
 	int data ; 
 	struct node* left ; 
 	struct node*right ; 
 };
 struct node*createNode(int data){
 	struct node * newNode = (struct node*)malloc(sizeof(struct node));
 	newNode->data = data ; 
 	newNode->left = NULL ; 
 	newNode->right = NULL ; 
 	return newNode  ; 
 }
 struct node*insert(struct node*root , int data ){
 	if(root== NULL ){
 		return createNode(data);
	 }
	 if(data<root->data){
	 	root->left = insert(root->left , data);
	 }
	 else {
	 	root->right = insert(root->right  ,data);
	 }
	 return root ; 
 }
 void inOrderTraversal(struct node* root , int val , int*flag){
 	if(root!=NULL){
 		if(root->data == val){
 			*flag = 1 ; 
 			return ; 
		 }
 		inOrderTraversal(root->left , val , flag);
 	//	printf("%d" , root->data);
 		inOrderTraversal(root->right ,val , flag);
	 }
 }
int main(){
	struct node*root = NULL ; 
	root = insert(root , 50);
	insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int n  , flag = 0 ; 
    printf("enter the key to find");
    scanf("%d",&n);
    inOrderTraversal(root,n , &flag);
     if (flag ==1 ){
     	printf("element find ");
	 }
	 else{
	 	printf("not found ");
	 }
}
