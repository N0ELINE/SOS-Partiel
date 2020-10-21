/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   avlTree.h
 * Author: student
 *
 * Created on October 21, 2020, 8:45 PM
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#ifdef __cplusplus
extern "C" {
#endif

 
typedef struct node
{
    int data;
    struct node*  left;
    struct node*  right;
    int      height;
} node;
 
 
void dispose(node* t);
node* find( int e, node *t );
node* find_min( node *t );
node* find_max( node *t );
node* insert( int data, node *t );
node* delete( int data, node *t );
void display_avl(node* t);
int get( node* n );


#ifdef __cplusplus
}
#endif

#endif /* AVLTREE_H */

