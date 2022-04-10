/*
    Author : Kaiser Sakhi  
    Date : 4-09-22
    Environmen : Wsl Ubuntu

*/

// program to implement fractional knapsack

#include<iostream>

struct Item{
    int count;
    float profit;
    float weight;
    float profitByWeight(){
        return profit/weight;
    }
    Item(float c,float p,float w){
        count = c;
        profit = p;
        weight = w;
    }
    Item(Item &item){
        count = item.count;
        profit = item.profit;
        weight = item.weight;
    }
};

void printItems(Item *items, int);
void sortItems(Item*, int);

int main(){
    Item items[4] = {{1,280,40},{1,100,10},{1,120,20},{1,120,24}};
    // items[0] = {5,5,1};
    int len = 4;
    float *knapsackProfit = new float[len];
    int kanpsackWeight = 60;
    sortItems(items, len);
    printItems(items, len);

    // main logic
    std::cout<<"\n\nProfit\t|Weight\t|RemainingWeight\n";
    for (int i = 0; i < len; ++i){
        // if there is more enough room to fill the item as a whole 
        if (items[i].weight <= kanpsackWeight){
            kanpsackWeight -= items[i].weight;
            knapsackProfit[i] = items[i].profit;
            std::cout<<items[i].profit<<"\t|"<<items[i].weight<<"\t|"<<kanpsackWeight<<"\n";
        }else if (kanpsackWeight > 0){ // if there is little room where item has to be broken down

            // (profit * remainingWeight)/weght of the item
            knapsackProfit[i] = (items[i].profit * kanpsackWeight)/items[i].weight;
            kanpsackWeight = 0;// knapsackProfit[i] / kanpsackWeight;
            float weightIncurred = items[i].weight / (items[i].profit / knapsackProfit[i]);
            std::cout<<knapsackProfit[i]<<"\t|"<<weightIncurred<<"\t|"<<kanpsackWeight<<"\n";
        }
    }

    std::cout<<"\n\nTotal Profit : ";
    for (int i = 1; i < len; ++i){
        knapsackProfit[0] += knapsackProfit[i];
    }
    std::cout<<knapsackProfit[0]<<"\n";


    return 0;
}

void sortItems(Item* items, int len){
    for (int i = 0; i < len; ++i){
        for (int j = 0; j <= i; ++j){
            if (items[j].profitByWeight() < items[j+1].profitByWeight()){
                //swap
                Item temp = items[j];
                items[j] =  items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

void printItems(Item *items, int len){
    std::cout<<"ID\t|Profit\t|Weight\t|Ratio\n";
    for (int i =0 ; i < len; ++i){
        std::cout<<i<<"\t|"<<items[i].profit<<"\t|"<<items[i].weight<<"\t|"<<items[i].profitByWeight()<<"\n";
    }
}