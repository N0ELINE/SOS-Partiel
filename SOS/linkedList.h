/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkedList.h
 * Author: student
 *
 * Created on October 21, 2020, 8:21 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* LINKEDLIST_H */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node* next;
} node;
 
typedef void (*callback)(node* data);

node* create(int data,node* next);
node* prepend(node* head,int data);
node* append(node* head, int data);
node* insert_after(node *head, int data, node* prev);
node* insert_before(node *head, int data, node* nxt);
void traverse(node* head,callback f);
node* remove_front(node* head);
node* remove_back(node* head);
node* remove_any(node* head,node* nd);
void display(node* n);
node* search(node* head,int data);
void dispose(node *head);
int count(node *head);
node* insertion_sort(node* head);
node* reverse(node* head);
void menu();