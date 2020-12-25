// Samet BELLUR
// Doubly Linked List and Functions

#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int data;//data
	struct node *next;// next node pointer
	struct node *prev;//previous node pointer
};

struct node * start = NULL;//we must be know the first node

struct node* makenode (int idata){ //this fuction creat a node, ("idata" mean incoming data)
	
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data= idata;
	newnode->next= NULL;
	newnode->prev= NULL;
	
	return(newnode);
}

void addToFirst (int idata){//This function adds a node to first node ("idata" mean incoming data)
    struct node * willBeAdded = makenode (idata);//formed a node and assigned it
    
    if (start == NULL){//we have to check that this is the first node
		start= willBeAdded;
		printf("---ADDED---\n");
	}
	else {
		start->prev= willBeAdded;
		willBeAdded->next= start;
		start= willBeAdded;
		}
	system ("pause");
	system ("cls");
}

void addToLast (int idata){//This function adds a node to last node ("idata" mean incoming data)
	struct node * willBeAdded = makenode (idata);//formed a node and assigned it
	
	if (start == NULL){//we have to check that this is the first node
		start= willBeAdded;
		printf("---ADDED---\n");
	}
	else {//if this node is not the first, we must find the last node
		
		struct node * temp = start;//temp pointer for traverse
		
		while (temp->next !=NULL){//Loop result gives us the last node
			temp= temp->next;
		}
		
		willBeAdded->prev = temp;//we assign it to the previous pointer of the new node
		temp->next= willBeAdded;//we assign the new node to the next pointer of the last node
		printf("---ADDED---\n");
		
	}
	system ("pause");
	system ("cls");
}

struct node* searchNode (int sdata){//This function looks for a node ("sdata" mean search data)
    if (start==NULL){//we must check the list
		system ("cls");
		printf("List Empty\n");
		system ("pause");
		system ("cls");
		return;
	}
	struct node * temp = start;//temp pointer for traverse
	while (temp->next != NULL){
		if (temp->data == sdata){//this loop check to the last node, but  last node not include
			system("cls");
			printf("---Node Finded: %d---\n",temp->data);
			system("pause");
			system ("cls");
			return (temp);
		}
		temp= temp->next;
	}
	if (temp->data== sdata){//we checking the last node
		    system("cls");
			printf("---Node Finded: %d---\n",temp->data);
			system("pause");
			system ("cls");
			return (temp);
	}
	printf("\nThis data is not listed!!\n");
	system("pause");
	system ("cls");
}

void insertion (int sdata,int idata){//insert function (sdata mean search data)

    struct node * temp = start;//temp pointer for search
    struct node * willBeAdded= makenode (idata);//formed a node and assigned it
    struct node * previousNode= NULL;//null pointer for insertion
    
	temp= searchNode (sdata);
    previousNode= temp->prev;
	
	if (previousNode==NULL){//We have to check the user wants to add before the first node
		addToFirst(idata);
	}
	else{// if that's not the first node we can continue
    temp->prev= willBeAdded;
    willBeAdded->next = temp;
    willBeAdded->prev= previousNode;
    previousNode->next = willBeAdded;
	}
	printf("---inserted: %d before %d---\n",idata,temp->data);
	system ("pause");
	system ("cls");
}

void deleteNode (int sdata){//This function deletes a node
	if (start==NULL){//we must check the list
		system ("cls");
		printf("List Empty\n");
		system ("pause");
		system ("cls");
	}
	else {
	struct node * temp = NULL;//temp pointer for search
	temp = searchNode(sdata);
	if (temp==NULL){}//probability that the sought data cannot be found
	else{
	struct node * nextNode = temp->next;//pointer for delete prosses
	struct node * previousNode = temp->prev;//pointer for delete prosses
	   if (previousNode==NULL && nextNode==NULL){//We must check the possibility that there is only 1 data in the list
		free(start);
	   	start= NULL;	
	   }
	   else if (previousNode==NULL){//We have to check the user wants to delete the first node
	    struct node * secondNode = temp->next;//Second node on the list
		free(temp);
		secondNode->prev= NULL;
		start= secondNode;	
	   }
	   else if (nextNode==NULL){//We have to check the user wants to delete the last node
	    free(temp);
	    previousNode->next= NULL;
	   }
	   else{
	    free(temp);
	    previousNode->next = nextNode;
     	nextNode->prev = previousNode;
     }
	printf("---Deleted!!!---\n"),
    system ("pause");
    system ("cls");
    }
  }
}

void printNode (void){//this function prints the list to the screen
	
	struct node * temp = start;//temp pointer for traverse
	system("cls");
	printf ("List:\n\n");
	while (temp !=NULL){//Print loop
		printf ("%d\n",temp->data);
		temp= temp->next;
	}
	printf("\n");
	system ("pause");
	system ("cls");
}

int main(void){
	
	int i,choice,data,sdata;
	//selection screen
	while (1){
		printf("[1] Add To First\n[2] Add To Last\n[3] insertion\n[4] Delete Data\n[5] Print List\n[6] Search Data\n");
		printf("\nPlease do your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				system ("cls");
				printf("Enter your data: ");
				scanf("%d",&data);
				addToFirst(data);
				break;
			case 2:
				system ("cls");
				printf("Enter your data: ");
				scanf("%d",&data);
				addToLast(data);
				break;
			case 3:
				system ("cls");
				printf("Enter the value you want to insert before: ");
				scanf("%d",&sdata);
				printf("\n");
				printf("Enter your data: ");
				scanf("%d",&data);
				insertion(sdata,data);
				break;
			case 4:
				system ("cls");
				printf ("Please Enter Data To Be Deleted: ");
				scanf("%d",&sdata);
				deleteNode(sdata);
				break;
			case 5:
				printNode();
				break;
			case 6:
				system ("cls");
				printf("Please Enter Search Data: ");
				scanf("%d",&sdata);
				searchNode(sdata);
				break;
		}
	}
}
