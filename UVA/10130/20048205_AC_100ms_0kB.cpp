#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int amountObj;
int visiteds[1001][31];


int queimaDeEstoque(int maxWeight, int weight[], int price[]) {

    for (int obj = 0; obj <= amountObj; obj++) {
        for (int capacity = 0; capacity <= maxWeight; capacity++) { //actual capacity, not maximum capacity
            if (obj == 0 || capacity == 0) {
                visiteds[obj][capacity] = 0;
            } else if (weight[obj-1] <= capacity) {
                visiteds[obj][capacity] = max(visiteds[obj-1][capacity], price[obj-1]+visiteds[obj-1][capacity-weight[obj-1]]);
            } else {
                visiteds[obj][capacity] = visiteds[obj-1][capacity];
            }
        }
    }
    return visiteds[amountObj][maxWeight]; // maxWeight = maxCapacity
}

//eu tinha implementado dessa forma, achei mais simples de entender, mas tem um caso que ele retorna o valor 31 maior doq o que deveria, e não entendi o problema
//então implementei como no slide

/*int SALDAOELETROSHOPPING(int price[], int weight[], int obj, int freeSpace) {

    if (visiteds[obj][freeSpace] > -1) {
        return visiteds[obj][freeSpace];
    }
    if (obj == amountObj || freeSpace == 0) {
        return visiteds[obj][freeSpace] = 0;
    }
    int nAddTryNext = SALDAOELETROSHOPPING(price, weight, obj+1, freeSpace);
    if (weight[obj] <= freeSpace) {
        int add = price[obj]+SALDAOELETROSHOPPING(price, weight, obj+1, freeSpace-weight[obj]);
        return visiteds[obj][freeSpace] = max(add, nAddTryNext);
    }
    return visiteds[obj][freeSpace] = nAddTryNext;
}*/

int main() {
    int amountCases;
    cin >> amountCases;

    for (int i = 0; i < amountCases; i++) {
        cin >> amountObj;
        int price[amountObj];
        int weight[amountObj];

        for (int j = 0; j < amountObj; j++) {
            cin >> price[j];
            cin >> weight[j];
        }
        int numPeople = 0;
        cin >> numPeople;
        int totalVal = 0;
        int freeSpace = 0;
        for (int k = 0; k < numPeople; k++) {
            //int maxVal = 0;
            cin >> freeSpace;
            memset(visiteds, -1, 1000 * 30 * sizeof(int));
            int temp;
            /*for (int i = 0; i < amountObj; i++) {
                temp = SALDAOELETROSHOPPING(price, weight, i, freeSpace);
                if (temp > maxVal){
                    maxVal = temp;
                }
            }
            totalVal+= maxVal;*/
            totalVal += queimaDeEstoque(freeSpace, weight, price);
        }

        cout << totalVal << endl;
    }

        return 0;
}