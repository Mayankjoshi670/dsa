#include<stdio.h>
#include<stdlib.h>
struct node{
	int data ; 
	struct node*next ; 
};
void insertAtEnd(struct node**head , int data ){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = data ; 
	newNode->next = NULL ; 
	 if (*head == NULL){
	 	  *head = newNode  ; 
	 }
	 else{
	 	struct node * current = *head ; 
	 	while(current->next!= NULL){
	 		current = current->next ; 
		 }
		 current->next = newNode ; 
	 }
}
 void MergedLL( struct node**head ,struct node**Head , struct node** mergedLL){
	 struct node *temp1 = *head ; 
	 struct node *temp2 = *Head ; 
	while(temp1!= NULL && temp2!=NULL){
		insertAtEnd(mergedLL , temp1->data );
		temp1= temp1->next ; 
		insertAtEnd(mergedLL , temp2->data);
		temp2 = temp2->next ; 
	}
	 if ( temp1 == NULL ){
	 	while(temp2){
	 		insertAtEnd(mergedLL  , temp2->data);
	 		temp2= temp2->next ; 
		 }
		 
	 }
	 else{
	 	while(temp1){
	 		insertAtEnd(mergedLL , temp1->data);
	 		temp1= temp1->next ; 
		 }
	 }
}
void print(struct node*head ){
 	while(head){
 		printf("%d",head->data);
 		head = head->next ; 
	 }
 }
int main(){
	struct node* head = NULL  ;
	struct node*Head = NULL ; 
	struct node*merged = NULL ;
	int n  , data ; 
	int N , Data ; 
	printf("enter no of elements ");
	scanf("%d",&n);
	for(int i = 0 ; i< n ; i++){
		printf("enter the data");
		scanf("%d",&data);
		insertAtEnd(&head , data);
	}
	printf("enter no of element of second ll ");
	scanf("%d" , &N) ; 
	for(int i = 0 ; i< N ; i++){
		printf("enter values ");
		scanf("%d" , &Data);
		insertAtEnd(&Head , Data);
	}
	MergedLL(&head , &Head , &merged);
	print(merged);
	return 0 ;
}


