/**
 * linked_list.c
 *
 * Implements an unsorted linked list with ops insert, append, print, delete.
 * To keep track of list, you'll pass in its head and then update it (if
 * necessary) using double pointers.
 *
 * Compile:  gcc -g -Wall -o linked_list linked_list.c
 * Run:      ./linked_list
 */

#include <stdio.h>
#include <stdlib.h>

struct list_node {
   int data;
   struct list_node *next;
};

/** Insert at the beginning (head) of the list. */
int insert(struct list_node **head, int data);

/** Prints the list contents */
void print(struct list_node *head);

int insert(struct list_node **head, int data)
{
    struct list_node *new_node = malloc(sizeof(struct list_node));
    //struct list_node *new_node = NULL;

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    return 0;
}

int car(struct list_node *head)
{
	if (head == NULL) {
		return -1;
	}
	return head->data;
}

struct list_node *cdr(struct list_node *head)
{
	if (head == NULL || head->next == NULL) {
		return NULL;
	} else {
		return head->next;
	}
}

int foldl(int ( *f ) ( void ), struct list_node *head) 
{
    return 0;
}

int add(int a, int b)
{
	return a + b;
}

void print(struct list_node *head)
{
    struct list_node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int insert_at(struct list_node **head, int index, int data)
{
	struct list_node *new_node = malloc(sizeof(struct list_node));
	if(new_node == NULL){
		return -1;
	}
	new_node->data = data;

	if(head == NULL){
		*head = new_node;
		return 0;
	}
	int counter = 0;
	struct list_node *temp = *head;
	if(index == 0) {
		new_node->next = *head;
		*head = new_node;
		return 0;
	}
	while(temp->next != NULL && counter < index - 1){
		temp = temp->next;
		counter++;
	}

	
	if(counter == index - 1) {
		new_node->next = temp->next;
		temp->next = new_node;
		return 0;
	} 
	else {
		printf("Index larger than length of list\n");
		return -1;
	}
	
}

int append(struct list_node **head, int data){
	struct list_node *new_node = malloc(sizeof(struct list_node));
	if(new_node == NULL){
		return -1;
	}

	new_node->data = data;
	new_node->next = NULL;

	if(*head == NULL){
		*head = new_node;
		return 0;
	}
	
	struct list_node* current_node = *head;

	while(current_node->next != NULL){
		current_node = current_node->next;
	}
	
	current_node->next = new_node;
	return 0;
}

int search(struct list_node *head , int data) {
    struct list_node *current = head;
    int index = 0;

    while (current != NULL)
    {
        if (current->data == data) {
            return index;
        }
        index++;
        current = current->next;
    }
    // not found
    return -1;
}

int delete_at(struct list_node **head, int index){
	struct list_node *current = *head;
	if (head == NULL || *head == NULL) {
		return -1;
	}

	if (current->next == NULL) {
		*head = NULL;
	}

	/*Delete head*/
	if (index == 0) {
		*head = current->next;
		free(current);
		return 0;
	}
	
	int count_index = 0;
	while(current != NULL && count_index < index - 1) {
		current = current->next;
		count_index++;
	}

	if (current == NULL || current->next == NULL){
		return -1;
	}


	struct list_node *next = current->next->next;
	free(current->next); 
	
	current->next = next;
	return 0;
}

int delete(struct list_node **head, int data) {
    struct list_node *current = *head;
    
    if (current == NULL) {
        return -1;
    }   

    if (current->data == data) {
        *head = current->next;
        return 0;
    }

    while (current != NULL && current->next != NULL) {
        if (current->next->data == data) {
            current->next = current->next->next;
            return 0;
        }
        current = current->next;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    /* start with empty list */
    struct list_node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 568);
    insert(&head, 3);
    insert(&head, 24);
    insert(&head, 13);
    insert(&head, 9);
    insert(&head, 9);

    int i = search(head, 999999);
    printf("%d\n", i);

    print(head);

    delete_at(&head, 0);
    delete_at(&head, 999999);
    delete_at(&head, 4);

    print(head);
    delete(&head, 24);

    print(head);
    delete(&head, 9);
    print(head);
    delete(&head, 568);
    delete(&head, 99999999);

    print(head);

    return 0;
}


