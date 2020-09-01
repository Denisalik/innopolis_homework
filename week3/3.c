#include <stdio.h>
#include <stdlib.h>
struct node
{	
	int value;
	struct node* next;
};
void print_list(struct node* current){
	if(current->value == NULL){printf("no elements in an array");return;}
	printf("%d ",current->value);
	if(current->next == NULL)return;
	print_list(current->next);
}
struct node* insert_first_node(value){
	struct node* newnode = malloc(sizeof(struct node));
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}
void insert_node(int value, int previous, struct node* current){
	if(current->value == previous){
		struct node* newnode = malloc(sizeof(struct node));
		newnode->value = value;
		newnode->next = current->next;
		current->next = newnode;
	}
	else {
		if(current->next == NULL)printf("you don't have this element\n");
		else insert_node(value, previous, current->next);
}}
void delete_node(int value, struct node* current){
	if(current->next == NULL){
		if(current->value == value){
			current->value = NULL;
		}
		return;
	}
	if(current->value == value){
		struct node* next = current->next->next;
		current->value = current->next->value;//udalit 1 elem, perezapisat 0
		free(current->next);
		current->next = next;
		return;
	}
	if(current->next != NULL) {
		if(current->next->value == value){
			if(current->next->next == NULL){current->next = NULL;
			free(current->next);
			}
			else {
				struct node* next = current->next->next;
				free(current->next);
				current->next = next;
			}
			return;
		}
		else {
			delete_node(value,current->next);
		}
	}
}
int main(){
	struct node* first_node = insert_first_node(0);//create an linked array with first elementwhich is equel to 0
	insert_node(2,0,first_node);//insert element 2 after element 0
	insert_node(3,2,first_node);//insert element 3 after element 2
	insert_node(1,0,first_node);//list is 0 1 2 3
	delete_node(0,first_node);//1 2 3
	delete_node(3,first_node);//1 2
	delete_node(2,first_node);//1 
	delete_node(1,first_node);//no elements in an array
	print_list(first_node);
}
