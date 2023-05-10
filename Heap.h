#ifndef LAB_ASD_HEAP_5_HEAP_H
#define LAB_ASD_HEAP_5_HEAP_H
#include<iostream>
#include<vector>
#include<stdexcept>
class Heap {
    virtual void Insert (int)=0;
    virtual int Delete()=0;
    virtual int Peek()=0;
    virtual int GetSize()=0;
    virtual bool Is_empty()=0;
};


#endif //LAB_ASD_HEAP_5_HEAP_H
