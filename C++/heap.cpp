//
//  main.cpp
//  heap_debug
//
//  Created by Joel on 01/08/15.
//  Copyright (c) 2015 Itchi. All rights reserved.
//

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;
vector<int> heap;

void bubble(int index)
{
    int parent = floor((index - 1) / 2);

    if (heap[index] > heap[parent])
    {
        int temp = heap[index];
        heap[index] = heap[parent];
        heap[parent] = temp;

        bubble(parent);
    }
}

// Sätt in ett element i heapen
void insert(int element)
{
    heap.push_back(element);
    bubble(int(heap.size()-1));
}

// Returnera det största elementet i heapen
int getMax()
{
    if (heap.size() != 0)
        return heap.front();
    return -1;
}

void maxHeapify(int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int largest = index;

    if (left <= (int)heap.size() && heap[left] > heap[largest])
        largest = left;
    if (right <= (int)heap.size() && heap[right] > heap[largest])
        largest = right;

    if (largest != index)
    {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        maxHeapify(largest);
    }
}

// Returnera antalet element i heapen
int getSize()
{
    //if (heap.size() != 0)
    return int(heap.size());
    //return -1;
}

// Ta bort det största värdet i heapen
void removeMax()
{
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    maxHeapify(0);
}