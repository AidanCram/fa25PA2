//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        if (size == 64) {
            cout<<"Heap is Full"<<endl;
            return;
        }
        data[size] = idx;
        size++;
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size == 0) {
            cout<<"Heap is Empty"<<endl;
            return -1;
        }
        int val = data[0];
        // Replace root with last element, then call downheap()
        data[0] = data[size - 1];
        size--;
        downheap(0, weightArr);
        return val;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (weightArr[data[pos]] < weightArr[data[(pos - 1) / 2]]) { //While the weight at the index held by data[pos] is less than that of the parent
            swap(data[pos], data[(pos - 1) / 2]);
            pos = (pos - 1) / 2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int smallVal = pos;
        while (true) { //Goes on forever until it reaches return statement
            int leftChild = 2*pos + 1; //Left child is reassigned every loop
            int rightChild = 2*pos + 2; //Right child is reassigned every loop

            if (leftChild < size && weightArr[data[smallVal]] > weightArr[data[leftChild]]) {
                smallVal = leftChild;
            }
            else if (rightChild < size && weightArr[data[smallVal]] > weightArr[data[rightChild]]) {
                smallVal = rightChild;
            }
            else { //smallVal still equals pos
                return;
            }
            swap(data[pos], data[smallVal]);
            pos = smallVal;
        }
    }
};

#endif