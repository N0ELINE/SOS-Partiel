/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on October 21, 2020, 8:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackUsingPointers.h" //linked stack ou linked list
#include "binarySearchTree.h"
#include "binaryHeap.h"
#include "avlTree.h"


#define N 800

#define MaxSize (1000)

void stackUsingPointersTEST(){
    
    struct node* head = NULL;
    int size, element;
    int counter = 0;
 
    printf("Enter the number of stack elements:");
    scanf("%d",&size);
 
    printf("--- Push elements into the linked stack ---\n");
 
    init(head);
 
    while(counter < size)
    {
 
        printf("Enter a number to push into the stack:");
        scanf("%d",&element);
        head = push(head,element);
        display(head);
        counter++;
    }
 
    printf("--- Pop elements from the linked stack --- \n");
    while(empty(head) == 0)
    {
        head = pop(head,&element);
        printf("Pop %d from stack\n",element);
        display(head);
    }
 
    return 0;
}






void linkedList(){
    int command = 0;
    int data;
 
    node* head = NULL;
    node* tmp = NULL;
    callback disp = display;
 
    menu();
    while(1)
    {
        printf("\nEnter a command(0-10,-1 to quit):");
        scanf("%d",&command);
 
        if(command == -1)
            break;
        switch(command)
        {
        case 0:
            menu();
            break;
        case 1:
            printf("Please enter a number to prepend:");
            scanf("%d",&data);
            head = prepend(head,data);
            traverse(head,disp);
            break;
        case 2:
            printf("Please enter a number to append:");
            scanf("%d",&data);
            head = append(head,data);
            traverse(head,disp);
            break;
        case 3:
            printf("Please enter a number to search:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL)
            {
                printf("Element with value %d found.",data);
            }
            else
            {
                printf("Element with value %d not found.",data);
            }
            break;
        case 4:
            printf("Enter the element value where you want to insert after:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL)
            {
                printf("Enter the element value to insert after:");
                scanf("%d",&data);
                head = insert_after(head,data,tmp);
                if(head != NULL)
                    traverse(head,disp);
            }
            else
            {
                printf("Element with value %d not found.",data);
            }
            break;
        case 5:
            printf("Enter the element value where you want to insert before:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL)
            {
                printf("Enter the element value to insert before:");
                scanf("%d",&data);
                head = insert_before(head,data,tmp);
 
                if(head != NULL)
                    traverse(head,disp);
            }
            else
            {
                printf("Element with value %d not found.",data);
            }
            break;
        case 6:
            head = remove_front(head);
            if(head != NULL)
                traverse(head,disp);
            break;
        case 7:
            head = remove_back(head);
            if(head != NULL)
                traverse(head,disp);
            break;
        case 8:
            printf("Enter the element value to remove:");
            scanf("%d",&data);
            tmp = search(head,data);
            if(tmp != NULL)
            {
                remove_any(head,tmp);
                if(head != NULL)
                    traverse(head,disp);
            }
            else
            {
                printf("Element with value %d not found.",data);
            }
            break;
        case 9:
            head = insertion_sort(head);
            if(head != NULL)
                traverse(head,disp);
            break;
        case 10:
            head = reverse(head);
            if(head != NULL)
                traverse(head,disp);
            break;
        }
 
    }
    dispose(head);
    return 0;
}





void binarySearchTree(){
    node* root = NULL;
    comparer int_comp = compare;
    callback f = display;
 
    /* insert data into the tree */
    int a[SIZE] = {8,3,10,1,6,14,4,7,13};
    int i;
    printf("--- C Binary Search Tree ---- \n\n");
    printf("Insert: ");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ",a[i]);
        root = insert_node(root,int_comp,a[i]);
    }
    printf(" into the tree.\n\n");
 
    /* display the tree */
    display_tree(root);
 
    /* remove element */
    int r;
    do
    {
        printf("Enter data to remove, (-1 to exit):");
        scanf("%d",&r);
        if(r == -1)
            break;
        root = delete_node(root,r,int_comp);
        /* display the tree */
        if(root != NULL)
            display_tree(root);
        else
            break;
    }
    while(root != NULL);
 
    /* search for a node */
    int key = 0;
    node *s;
    while(key != -1)
    {
        printf("Enter data to search (-1 to exit):");
        scanf("%d",&key);
 
        s = search(root,key,int_comp);
        if(s != NULL)
        {
            printf("Found it %d",s->data);
            if(s->left != NULL)
                printf("(L: %d)",s->left->data);
            if(s->right != NULL)
                printf("(R: %d)",s->right->data);
            printf("\n");
        }
        else
        {
            printf("node %d not found\n",key);
        }
    }
 
    /* remove the whole tree */
    dispose(root);
    return 0;
}




void binaryHeap(){
    PriorityQueue H;
    int i, j;
 
    H = Initialize(MaxSize);
    for (i = 0, j = MaxSize / 2; i < MaxSize; i++, j = (j + 71) % MaxSize)
        Insert(j, H);
 
    j = 0;
    while (!IsEmpty(H))
        if (DeleteMin(H) != j++)
            printf("Error in DeleteMin, %d\n", j);
    printf("Done...\n");
    return 0;
}


void avlTree(){
    node *t , *p;
    int i;
    int j = 0;
    const int max = 10;
 
    printf("--- C AVL Tree Demo  ---\n");
 
    t = NULL;
 
    printf("Insert: ");
    for( i = 0; i < max; i++, j = ( j + 7 ) % max )
    {
 
        t = insert( j, t );
        printf("%d ",j);
 
    }
    printf(" into the tree\n\n");
 
    display_avl(t);
 
    dispose(t);
 
    return 0;
}



void redBlack(){
    RedBlackTree T;
    Position P;
    int i;
    int j = 0;
 
    T = Initialize();
    T = MakeEmpty(T);
 
    for (i = 0; i < N; i++, j = (j + 7) % N)
        T = Insert(j, T);
    printf("Inserts are complete\n");
 
    for (i = 0; i < N; i++)
        if ((P = Find(i, T)) == NULL || Retrieve(P) != i)
            printf("Error at %d\n", i);
 
    printf("Min is %d, Max is %d\n", Retrieve(FindMin(T)),
            Retrieve(FindMax(T)));
 
    return 0;
}




/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

