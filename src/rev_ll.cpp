//
//  rev_ll.cpp
//  wm
//
//  Created by Surya Sahukar on 12/18/19.
//  Copyright © 2019 Surya Sahukar. All rights reserved.
//

#include "rev_ll.hpp"

#define MAX_LIST_SIZE 10

/*Helper functions*/
struct node *create_head(int value)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = value;
    newnode-> next = NULL;
    return newnode;
}


struct node *insert_node(struct node *head, int val)
{
    struct node *curr = NULL;
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    
    newnode -> data = val;
    newnode -> next = NULL;
    
    curr = head;
    if (curr == NULL) {
        curr = newnode;
        return (newnode);
    }
    else {
        while(curr -> next!=NULL) {
            curr = curr -> next;
        }  
    }
    curr -> next = newnode;

    return (newnode);
}


struct node *create_list(void)
{
    srand((unsigned int) time(NULL));
    uint16_t len =  rand() % MAX_LIST_SIZE;
    int data = rand() % 10;
    
    struct node *head = create_head(data);
    
    for (int i = 0; i < len; i++)
    {
        data = rand() % 10;
        insert_node(head, data);
    }
    
    return head;
 
}

void print_list(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head -> next;
    }
    printf("NULL\n");
}

struct node *rev_list(struct node *head)
{
    if (!head) return NULL;
    
    struct node *next, *prev, *current;
    prev = NULL; next = NULL;
    current = head;
    
    while(current != NULL)
    {
        next = current -> next;
        current -> next=prev;
        prev = current;
        current = next;
    }
    return prev;
}


void test_driver_rev_list()
{
    struct node *head = create_list();
    printf("Orig List\n");
    print_list(head);
    printf("Rev List\n");
    head = rev_list(head);
    print_list(head);
    
}
