#include<stdio.h>
#include<stdlib.h>
 struct node{
 	int data ; 
 	struct node*next ; 
 	
 };
 void insertAtEnd(struct node**head , int data){
 	 struct node* newNode = (struct node*)malloc(sizeof(struct node));
 	 newNode->data = data ; 
 	 newNode->next = NULL ; 
 	 if(*head == NULL ){
 	 	*head = newNode ; 
	  }
	  else{
	  	struct node*current = *head ; 
	  	while(current->next != NULL){
	  		current = current->next ; 
		  }
		  current->next = newNode ; 
	  }
 }
 void print(struct node*head ){
 	while(head){
 		printf("%d",head->data);
 		head = head->next ; 
	 }
 }
int main(){
 struct node*head = NULL ;
 int n , value ; 
 printf("enter the no of elements");
 scanf("%d",&n);
 for(int i = 0 ; i< n ; i++){
 	printf("enter the data");
 	scanf("%d",&value);
 	insertAtEnd(&head , value);
 }
 print(head );	
	return 0 ; 
}
