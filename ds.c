#include <stdio.h>

#include "clist.h"
#include "linked_list.h"


int main()
{
    /* start with empty list */
    struct list_node* head = NULL;
	insert_at(&head, 1, 20000);
	insert_at(&head, 0, 10000);
	
    append(&head, 1);
    append(&head, 2);
    append(&head, 568);
    insert(&head, 3);
    insert(&head, 24);
    insert(&head, 13);
    insert(&head, 9);
    insert(&head, 9);
	insert_at(&head, 1000, 500);

    int i = search(head, 999999);
    printf("%d\n", i);

    print(head);

    delete_at(&head, 0);
    delete_at(&head, 999999);
    delete_at(&head, 4);

    print(head);
    delete_data(&head, 24);

    print(head);
    delete_data(&head, 9);
    print(head);
    delete_data(&head, 568);
    delete_data(&head, 99999999);

    print(head);

	free_list(head);


    return 0;
}
