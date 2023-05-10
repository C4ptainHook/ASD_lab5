#ifndef LAB_ASD_HEAP_5_MINHEAP_H
#define LAB_ASD_HEAP_5_MINHEAP_H
#include "Heap.h"

class MinHeap: public Heap{
    int size;
    std::vector<int> minH;
    void min_heapify(int);
public:
    MinHeap(){ size=0;}
    void Insert(int) override;
    int Delete() override;
    int Peek() override;
    int GetSize() override;
    bool Is_empty() override;
};


#endif //LAB_ASD_HEAP_5_MINHEAP_H
