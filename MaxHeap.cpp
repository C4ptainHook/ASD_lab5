#include "MaxHeap.h"

void MaxHeap::Insert(int node) {
    size++;
    maxH.push_back(node);
    size_t index = size - 1;
    size_t parent_index;
    (!index % 2) ? parent_index = static_cast<int>(index / 2) - 1 : parent_index = static_cast<int>(index / 2);
    while (index >= 1 && index<size && node > maxH[parent_index]) {
        std::swap(maxH[index], maxH[parent_index]);
        index = parent_index;
        (!index % 2) ? parent_index = static_cast<int>(index / 2) - 1 : parent_index = static_cast<int>(index / 2);
    }
}
int MaxHeap::Delete()
{
    if(size==0)
    {
        throw std::range_error("Deleting from empty heap");
    }
    else {
            int root = maxH[0];
            std::swap(maxH[0], maxH[size-1]);
            maxH.pop_back();
            size--;
        switch(size){
            case 1: return root;
            case 2: if(maxH[0]<maxH[1]){std::swap(maxH[0],maxH[1]);} return root;
            default: max_heapify( 0); return root;
        }
    }
}
    void MaxHeap::max_heapify(int n) {
        int l = 2*n + 1;
        int r = 2*n + 2;
        int Largest = n;

        if(l<size&& ((maxH[l]>maxH[n])&&maxH[l]>maxH[r])) {Largest = l;}
        if(r<size && ((maxH[r]>maxH[n])&&maxH[r]>maxH[l])) {Largest = r;}

        if(Largest!=n)
        {
            std::swap(maxH[n], maxH[Largest]);
            max_heapify( Largest);
        }
    }
    int MaxHeap::Peek() {
    if(size!=0) {return maxH[0];}
    else{throw std::invalid_argument("Peek to empty heap");}
    }
    int MaxHeap::GetSize() {
        return size;
}
bool MaxHeap::Is_empty() {
    if(size==0) {return true;}
    else{return false;}
}
