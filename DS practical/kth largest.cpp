/*kth smallest element*/
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
 /*void inOrderTraversal(struct node* root , int k , int *cnt ){
 	if(root!=NULL){
 		if(*cnt == k ){
 			(*cnt)++;
 			printf("%d" , root->data);
		 }
 		inOrderTraversal(root->right , k , cnt);
 		inOrderTraversal(root->left , k , cnt );
	 }
 }*/
 void reverseInOrderTraversal(struct node* root , int k , int *cnt ){
  if(root!=NULL){
    reverseInOrderTraversal(root->right , k , cnt);
    if(*cnt == k ){
      (*cnt)++;
      printf("%d" , root->data);
     }
    reverseInOrderTraversal(root->left , k , cnt );
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
    printf("enter the value of k ");
    int k ,cnt = 0 ; 
    scanf("%d"  ,&k);
    
     reverseInOrderTraversal(root , k , &cnt);

}

