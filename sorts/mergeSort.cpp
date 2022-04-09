/*
    Author : Kaiser Sakhi  
    Date : 23-Mar-2022
    Environment : Wsl Ubuntu
*/

#include<iostream>

void sort(int *list, int len);
void merge(int* left, int leftLen, int* right , int rightLen, int *list);

int main(){
  
    int *list = new int [6]{2,54,0,-1,6,-1};
    int len = 6;
    sort(list, len);

    for (int i = 0; i < len; ++i){
        std::cout<<" "<<list[i];
    }
    return 0;
}

void sort(int *list, int len){
    if (len > 1){
        int end = len -1;
        int mid = (0 + end)/2;

        int *left = new int[mid + 1]; //mid is the middle index, +1 will make it the length of the left array
        int *right = new int[end - mid];
        int k = 0;

        //std::cout<<"\nLeft : ";
        for (int i = 0; i <= mid ; ++i){
            left[i] = list[k++];
            //std::cout<<" "<<left[i];
        }
        //std::cout<<"\nRight : ";
        for (int j = 0; j < (end - mid); ++j){
            right[j] = list[k++];
            //std::cout<<" "<<right[j];
        }
        // return;
        // std::cout<<"\nList :"; 
        // for (int l = 0; l < len; ++l){
        //     std::cout<<" "<<list[l];
        // }

        sort(left, mid+1);
        sort(right, end - mid);

        merge(left, mid +1, right, end - mid, list);
     
        std::cout<<"\n";
        delete[] left;
        delete[] right;
    }
}


void merge(int* left, int leftLen, int* right , int rightLen, int *list){

    int i = 0;
    int j = 0;
    int k = 0;

    // std::cout<<"\nLeft : ";
    // for (int i = 0; i < leftLen ; ++i){
    //     //left[i] = list[k++];
    //     std::cout<<" "<<left[i];
    // }
    // std::cout<<"\nRight : ";
    // for (int j = 0; j < rightLen; ++j){
    //     // right[j] = list[k++];
    //     std::cout<<" "<<right[j];
    // }    
    

    while((i < leftLen) && (j < rightLen)){
        if (left[i] <= right[j]){
            list[k++] = left[i++];
        }else{
            list[k++] = right[j++];
        }
    }
    while(i < leftLen){
        list[k++] = left[i++];
    }
    while (j < rightLen){
        list[k++] = right[j++];
    }
}