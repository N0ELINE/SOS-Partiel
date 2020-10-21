/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   binarySearchTree.h
 * Author: student
 *
 * Created on October 21, 2020, 8:29 PM
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#ifdef __cplusplus
extern "C" {
#endif


typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

#ifdef __cplusplus
}
#endif

#endif /* BINARYSEARCHTREE_H */


node* create_node(int data);
node* insert_node(node *root, comparer compare, int data);
node* delete_node(node* root, int data,comparer compare);
node* search(node *root,const int data,comparer compare);
void traverse(node *root,callback cb);
void dispose(node* root);
int compare(int left,int right);
void display(node* nd);
void display_tree(node* nd);