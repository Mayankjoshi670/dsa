/*Write a C program to create a single linked list then input a value V, partition it such that all nodes less 
 than V come before nodes greater than or equal to V.*/
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
 		printf("%d\t",head->data);
 		
 		head = head->next ; 
	 }
 }
void partation(struct node **head , int v){
  	struct node*temp1 = (struct node *) malloc(sizeof(struct node)) ; 
	struct node* temp2 = (struct node *) malloc(sizeof(struct node))  ;
	struct node*h1 = temp1 ; 
	struct node*travel1 = temp1 ; 
		struct node*travel2 = temp2 ;
	struct node * h2 = temp2 ; 
	temp1->data = 0 ; 
	temp1->next = NULL ; 
	temp2->data = 0 ; 
	temp2->next = NULL;
	struct node * demo  = *head ; 
	while(demo){
		struct node*newNode = (struct node*) malloc(sizeof(struct node));
		if(demo->data < v ){
			newNode->data = demo->data ;
			newNode->next = NULL ;
			 travel1->next = newNode;
			 travel1 = newNode ; 
		}
		else {
			 newNode->data = demo->data ;
			 newNode->next = NULL ; 
			 travel2->next = newNode ;
			  travel2 = newNode ;   
			 
		}
		demo = demo->next ; 
	} 
	  
	   travel1->next = temp2->next  ; 
	   	 struct node* realhead = temp1->next ; 
	   	  print(realhead) ; 
  }
int main(){
 struct node*head = NULL ;
 int n , value , v ; 
 printf("enter the no of elements");
 scanf("%d",&n);
 for(int i = 0 ; i< n ; i++){
 	printf("enter the data");
 	scanf("%d",&value);
 	insertAtEnd(&head , value);
 }
 printf("enter the value of v");
 scanf("%d" , &v );
  partation(&head , v) ; 
	return 0 ; 
}
