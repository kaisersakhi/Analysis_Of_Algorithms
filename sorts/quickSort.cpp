#include<iostream>
#include<climits>

void quickSort(int, int, int*);
int partition(int, int, int*);
void swap(int&, int&);
void printList(int*, int);

int main(){
    int arr[] = {4, 9, 6, 5, 2, 3, INT_MAX};
    std::cout<<"Before Sorting the list: "<<std::endl;
    printList(arr, 7);
    quickSort(0, 6, arr);
    std::cout<<"After Sorting the List : "<<std::endl;
    printList(arr, 7);   
    return 0;
}

void quickSort(int start, int end, int* arr){

    if (start < end){
        int i = partition(start, end, arr);
        printList(arr, 7);
        quickSort(start, i, arr);
        quickSort(i+1, end, arr);
    }
     
}

int partition(int start, int end, int *arr){
    int i = start;
    int j = end -1;
    int pivot = (start + end) / 2;

    while (i < j){
        while(arr[pivot] > arr[i] && i < j) {
            ++i;
        }
        while(arr[pivot] < arr[j] && i < j) {
            --j;
        }
        swap(arr[i], arr[j]);    
    }
    if (arr[pivot] < arr[i])
        swap(arr[pivot], arr[i]);
    return i;
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

