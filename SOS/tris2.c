/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tris2.c
 * Author: student
 *
 * Created on October 21, 2020, 9:14 PM
 */

#include <stdio.h>
#include <stdlib.h>

void shellsort(int a[], const int size)
{
  int i, j, inc, tmp;
 
  inc = 3;
  while (inc > 0)
  {
    for (i=0; i < size; i++)
    {
      j = i;
      tmp = a[i];
      while ((j >= inc) && (a[j-inc] > tmp))
      {
        a[j] = a[j - inc];
        j = j - inc;
      }
      a[j] = tmp;
    }
    if (inc/2 != 0)
      inc = inc/2;
    else if (inc == 1)
      inc = 0;
    else
      inc = 1;
  }
}

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int choose_pivot(int i,int j )
{
    return((i+j) /2);
}
 
void quicksort(int list[],int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swap(&list[i],&list[j]);
        }
        /* swap two elements */
        swap(&list[m],&list[j]);
 
        /* recursively sort the lesser list */
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}

void merge_sort(int a[], int tmp[], const int size)
{
    msort(a, tmp, 0, size - 1);
}
 
void msort(int a[], int tmp[], int left, int right)
{
    int mid;
    if (right > left)
    {
        mid = (right + left) / 2;
        msort(a, tmp, left, mid);
        msort(a, tmp, mid + 1, right);
        merge(a, tmp, left, mid + 1, right);
    }
}
 
void merge(int a[], int tmp[], int left, int mid, int right)
{
    int i, left_end, count, tmp_pos;
    left_end = mid - 1;
    tmp_pos = left;
    count = right - left + 1;
 
    while ((left <= left_end) && (mid <= right))
    {
        if (a[left] <= a[mid])
        {
            tmp[tmp_pos] = a[left];
            tmp_pos = tmp_pos + 1;
            left = left +1;
        }
        else
        {
            tmp[tmp_pos] = a[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }
    }
 
    while (left <= left_end)
    {
        tmp[tmp_pos] = a[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (mid <= right)
    {
        tmp[tmp_pos] = a[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }
 
    for (i = 0; i <= count; i++)
    {
        a[right] = tmp[right];
        right = right - 1;
    }
}

int binary_search(int sorted_list[], int low, int high, int element)
{
    int middle;
    while (low <= high)
    {
        middle = low + (high - low)/2;
        if (element > sorted_list[middle])
            low = middle + 1;
        else if (element < sorted_list[middle])
            high = middle - 1;
        else
            return middle;
    }
    return -1;
}