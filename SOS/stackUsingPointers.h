/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackUsingPointers.h
 * Author: student
 *
 * Created on October 21, 2020, 8:10 PM
 */

#ifndef STACKUSINGPOINTERS_H
#define STACKUSINGPOINTERS_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* STACKUSINGPOINTERS_H */

int empty(struct node *s);
struct node* push(struct node *s,int data);
struct node* pop(struct node *s,int *data);
void init(struct node* s);
void display(struct node* head);
