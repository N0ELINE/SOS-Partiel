/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   binaryHeap.h
 * Author: student
 *
 * Created on October 21, 2020, 8:36 PM
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#ifdef __cplusplus
extern "C" {
#endif


struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
 
PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#ifdef __cplusplus
}
#endif

#endif /* BINARYHEAP_H */

