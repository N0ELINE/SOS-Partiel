/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arbreRougeNoir.h
 * Author: student
 *
 * Created on October 21, 2020, 8:55 PM
 */

#ifndef ARBREROUGENOIR_H
#define ARBREROUGENOIR_H

#ifdef __cplusplus
extern "C" {
#endif

struct RedBlackNode;
typedef struct RedBlackNode *Position;
typedef struct RedBlackNode *RedBlackTree;
 
RedBlackTree MakeEmpty(RedBlackTree T);
Position Find(ElementType X, RedBlackTree T);
Position FindMin(RedBlackTree T);
Position FindMax(RedBlackTree T);
RedBlackTree Initialize(void);
RedBlackTree Insert(ElementType X, RedBlackTree T);
RedBlackTree Remove(ElementType X, RedBlackTree T);
ElementType Retrieve(Position P);
void PrintTree(RedBlackTree T);



#ifdef __cplusplus
}
#endif

#endif /* ARBREROUGENOIR_H */

