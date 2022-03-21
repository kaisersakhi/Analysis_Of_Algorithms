#include<iostream>

int binarySearch(int *arr, int length, int key);
int recursiveBinarySearch(int *, int low, int high, int key);

int main(){
    int len = 7;
    int arr[len] = {1,2,3,4,5,6,7};
    std::cout<<"Element 3 found at : "<< recursiveBinarySearch(arr, 0, len -1, 30)<<"\n";
    return 0;
}

int binarySearch(int *arr, int length, int key){
    int low = 0;
    int high = length -1;
    int mid = 0;

    while (low <= high){
        mid = (low + high) / 2;

        if (arr[mid] == key){ // element found return the index
            return mid;
        }else if (key > arr[mid]){ // element might be on the right havle
            low = mid + 1;
        }else if (key < arr[mid]){ // element might be on the left havle
            high = mid - 1;
        }
    }
    return -1; // element not found
}

int recursiveBinarySearch(int *arr, int low, int high, int key){

    if (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] == key){
            return mid;
        }else if (key < arr[mid]){
            return recursiveBinarySearch(arr, low, mid -1, key);
        }else if (key > arr[mid]){
            return recursiveBinarySearch(arr, mid + 1, high, key);
        }
    }

    return -1; 
    
}