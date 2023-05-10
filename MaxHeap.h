#ifndef LAB_ASD_HEAP_5_MAXHEAP_H
#define LAB_ASD_HEAP_5_MAXHEAP_H
#include "Heap.h"

class MaxHeap:public Heap {
    int size;
    std::vector<int> maxH;
    void max_heapify(int);
public:
    MaxHeap(){size=0;}
    void Insert(int) override;
    int Delete() override;
    int Peek() override;
    int GetSize() override;
    bool Is_empty() override;
};


#endif //LAB_ASD_HEAP_5_MAXHEAP_H
