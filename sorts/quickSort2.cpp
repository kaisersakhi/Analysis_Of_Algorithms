/*
    Author : Kaiser Sakhi  
    Date : 4-09-22
    Environmen : Wsl Ubuntu

*/

// program to implement quick sort


#include<iostream>

int partition(int *list, int start, int end);
void sort(int *list, int start, int end);
void swap(int&, int&);
void printList(int* arr, int n);
int main(){
    int list[] = {4, 9, 6, 5, 2, 3};
    std::cout<<"Before Sorting the list: "<<std::endl;
    printList(list, 6);
    sort(list, 0 , 5);
    std::cout<<"After Sorting the List : "<<std::endl;
    printList(list, 6);   
    return 0;
    return 0;
}

void sort(int *list, int start, int end){
    if (start < end){
        int k = partition(list,start,end);
        sort(list,start,k-1);
        sort(list,k+1, end);
    }
}

int partition(int *list, int start, int end){
    int k =0; // k is paritioning position
    int pivot = end;
    for (int i = 0; i < end ; ++i){
        if (list[i] < list[pivot]){
            swap(list[k++], list[i]);
        }
    }
    swap(list[k], list[pivot]);
    return k;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
void printList(int* arr, int n){
    for (int i = 0; i < n; i++){
        std::cout<<arr[i]<<", ";
    }
    std::cout<<std::endl;
}
