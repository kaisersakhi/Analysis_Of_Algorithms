#include<iostream>

void findMinMax(int, int, int&, int&, int*);
void findMinMaxRecursive(int, int , int& , int& , int*);
int main(){

    int list[] = {2, 4, -9, 6, 90, -1};
    int min, max;
    min = max = list[0];
    findMinMaxRecursive(0,  5, min, max, list);
    // findMinMax(0,  5, min, max, list);
    std::cout<<"Min : "<<min<<" | Max : "<<max<<"\n";
    
    return 0;
}


void findMinMaxRecursive(int start, int end, int& min, int& max, int *list){

    // there is 1 base case+*.+

        //1. if there is only one item in the list
        if (start == end){
            if (list[start] > max) max = list[start];
            else if (list[start] < min) min = list[start];  
            return;
        }
        int mid = (start + end) / 2;
        findMinMaxRecursive(start, mid, min, max, list);
        findMinMaxRecursive(mid+1, end, min, max, list);

}

void findMinMax(int start, int end, int& min, int&max, int* list){
    
    for (int i = 0; i <= end ; ++i){
        if (list[i] > max) max = list[i];
        else if (list[i] < min) min = list[i];
    }
}