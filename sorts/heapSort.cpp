/*

*    Author : Kaiser Sakhi
*    Date : 27-Jan-2022 : 9:20 PM
*    Environment : Ubuntu-18.04

*/

// program to implement heap sort , thanks to Sir Abdul Bari

#include <iostream>
#include "../ArrayList/arrayList.h"

class MaxHeap{
private:
    ArrayList<int> list;
    // int length ;
public:
    MaxHeap(){
        // this->length = 0;
    }

    void addElement(int item){
        list.add(item);
        this->maintainOrder();
        // ++length;
    }

    void printItems(){
        for (int i = 0 ; i < list.length() ; ++i){
            std::cout<<list.get(i) << ", ";
        }
        std::cout<<"\n";
    }

    int pop(){
        if (list.length() > 2){
            list.swap(0, list.length() - 1);
            int popedItem = list.pop();

            int i = 0 ;

            while (i < list.length() - 1){

                if (list.get(2*i+1) > list.get(2*i+2)){
                    list.swap(i, 2*i+1);
                    i = i * 2 + 1;
                    continue;
                }else if(list.get(2*i+1) < list.get(2*i+2)){
                    list.swap(i, 2*i+2);
                    i = 2*i+2;
                    continue;
                }
                i++;
            }
            return popedItem;
        }
    }


    //implement heap sort
    void sort(){
        if (list.length() > 2){
            
            int lastIndex = list.length() -1; 
            int i = 0 ;
            int left_child = 0;
            int right_child = 0;

            // this loop will run for n times
            for (int k = 0 ; k < list.length() ; ++k){
                list.swap(0, lastIndex);
                --lastIndex;
                i = 0;
                //this loop will run for log(n) times
                while (lastIndex >= 1 && i < lastIndex){
                    left_child = 2*i+1;
                    right_child = 2*i+2;

                    //the left_child should only swap with unsorted items like wise for right child
                    if (list.get(left_child) > list.get(right_child) && left_child < lastIndex){ 
                        list.swap(i, left_child);
                        i = i * 2 + 1;
                        continue;
                    }else if(list.get(2*i+1) < list.get(2*i+2) && right_child < lastIndex){
                        list.swap(i, 2*i+2);
                        i = 2*i+2;
                        continue;
                    }
                    i++;

                } 
            }   
        }
    }
private:
    void maintainOrder(){ // like hepify
        int i = list.length() - 1;

        while ( i > 0){
            if (list.get((int) i / 2) < list.get(i)){
                list.swap((int)i/2, i);
            }
            i = (int) i / 2;
        }
    }
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
};

int main(){
    int len = 7;
    int list[len] = {6, 9, 2, 4, 13, 5, 0};

    MaxHeap heap;

    for (const int& i : list){

        heap.addElement(i);
    }
    heap.printItems();
    // std::cout<<"pop "<<heap.pop()<<", "<<heap.pop()<<"\n";
    std::cout<<"After Sort ";
    heap.sort();
    heap.printItems();
    return 0;
}



