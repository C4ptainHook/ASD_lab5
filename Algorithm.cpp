#include "Algorithm.h"

void find_median(const char* name)
{
    string filename = name;
    MaxHeap low;
    MinHeap high;
    int curr_number;
    int range;
    string line;
    std::ifstream infile;
    infile.open(filename, ios::in);
    if(!infile.is_open()){throw std::invalid_argument("File wasnt opened!!");}
    std::ofstream outfile("Median_output"+filename, ios::out);
    getline(infile, line);
    range = stoi(line);
    for (int i = 0; i < range; ++i)
    {
        getline(infile,line);
        curr_number=std::stoi(line);
        if(low.Is_empty()) {high.Insert(curr_number);}
        else {
            if(curr_number<low.Peek()){low.Insert(curr_number);}
            else{high.Insert(curr_number);}
        }
        if(low.GetSize()-high.GetSize()==2) {
            high.Insert(low.Delete());
       }
        else if((low.GetSize()-high.GetSize()==-2)) {
            low.Insert(high.Delete());
        }
        if((low.GetSize()==high.GetSize()))
        {outfile<<low.Peek()<<" "<<high.Peek()<<std::endl;}
        else if(low.GetSize()>high.GetSize()){outfile<<low.Peek()<<std::endl;}
        else{outfile<<high.Peek()<<std::endl;}
    }
    infile.close();
    outfile.close();
}