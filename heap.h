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
        int val = weightArr[data[0]];
        // Replace root with last element, then call downheap()
        data[0] = data[size - 1];
        size--;
        downheap(data[0], weightArr);
        return val; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (weightArr[data[pos]] < weightArr[data[(pos - 1) / 2]]) {
            int temp = data[pos];
            data[pos] = data[(pos - 1) / 2];
            data[(pos - 1) / 2] = temp;
            pos = (pos - 1) / 2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (weightArr[data[pos]] > weightArr[data[2*pos + 1]] || weightArr[data[pos] + 1] > weightArr[data[2*pos + 2]]) {
            if (weightArr[data[pos]] > weightArr[data[2*pos + 1]] && weightArr[data[pos] + 1] <= weightArr[data[2*pos + 2]]) {
                int temp = data[pos];
                data[pos] = data[2*pos + 1];
                data[2*pos + 1] = temp;
                pos = 2*pos + 1;
            }
            else if (weightArr[data[pos]] > weightArr[data[2*pos + 2]] && weightArr[data[pos] + 1] > weightArr[data[2*pos + 2]]) {
                int temp = data[pos];
                data[pos] = data[2*pos + 2];
                data[2*pos + 2] = temp;
                pos = 2*pos + 2;

            }
        }
    }
};

#endif