/* leaf nodes*/
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
 struct node*insert(struct node**root , int data ){
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
 
 int  inOrderTraversal(struct node*root){
 	if( root == NULL){
 		return 0 ; 
	 }
	 if(root->left == NULL && root->right == NULL ){
	 	return 1 ; 
	 }
	 return  inOrderTraversal(root->left)+inOrderTraversal(root->right);
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
     int no = inOrderTraversal(&root);
     printf("%d" , no );
}
