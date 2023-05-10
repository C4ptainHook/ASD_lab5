#include "MinHeap.h"

void MinHeap::Insert(int node) {
    size++;
    minH.push_back(node);
    int index = size - 1;
    int parent_index;
    (index % 2==0) ? parent_index = static_cast<int>(index / 2) - 1 : parent_index = static_cast<int>(index / 2);
    while (index >= 1 && index<size && node < minH[parent_index]) {
        std::swap(minH[index], minH[parent_index]);
        index = parent_index;
        (!index % 2) ? parent_index = static_cast<int>(index / 2) - 1 : parent_index = static_cast<int>(index / 2);
    }
}
    int MinHeap::Delete()
    {
        if(size==0)
        {
            throw std::range_error("Deleting from empty heap");
        }
        else {
            int root = minH[0];
            std::swap(minH[0], minH[size-1]);
            minH.pop_back();
            size--;
        switch(size){
            case 1: return root;
            case 2: if(minH[0]>minH[1]){std::swap(minH[0],minH[1]);} return root;
            default: min_heapify( 0); return root;
        }
        }
    }
    void MinHeap::min_heapify(int n) {
        int l = 2*n + 1;
        int r = 2*n + 2;
        int Smallest=n;

        if(l<size && ((minH[l]<minH[n])&&minH[l]<minH[r])) {Smallest = l;}
        else if(r<size && ((minH[r]<minH[n])&&minH[r]<minH[l])) {Smallest = r;}

        if(Smallest!=n)
        {
            std::swap(minH[n], minH[Smallest]);
            min_heapify( Smallest);
        }
}
    int MinHeap::Peek() {
       if(size!=0) {return minH[0];}
       else{throw std::invalid_argument("Peek to empty heap");}
    }
    int MinHeap::GetSize()
    {
        return size;
    }
    bool MinHeap::Is_empty() {
        if(size==0) {return true;}
        else{return false;}
    }
