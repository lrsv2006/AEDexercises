#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main() {

    int childrenAmount;
    cin >> childrenAmount;
    int everySize[childrenAmount];
    int childrenSize;

    int i = 0;
    while(cin >> childrenSize){
        everySize[i] = childrenSize;
        i++;

        if (i == childrenAmount) {
            break;
        }
    }

    for (int i = 1; i < childrenAmount; i++) {
        int value = everySize[i];
        int pastvalue = i-1;
        while (pastvalue >= 0 && everySize[pastvalue] > value) {
            everySize[pastvalue+1] = everySize[pastvalue];
            pastvalue--;
        }
        everySize[pastvalue+1] = value;
    }

    if (childrenAmount < 4) {
        for (int i = 0; i < childrenAmount; i++) {
            cout << everySize[i] << " ";
        }
        exit(0);
    }

    int everySize2[(sizeof(everySize))/4];



    if (childrenAmount > 3) {}
    if (childrenAmount % 2 != 0) {
        everySize2[childrenAmount / 2] = everySize[childrenAmount - 1];

        for (int i = 0, j = i + 1, ii = 0, jj = 1;
             j < childrenAmount - 1; i++, j++, ii++, jj++) {

            everySize2[childrenAmount - jj] = everySize[i];
            everySize2[ii] = everySize[j];
            i++;
            j++;

        }
    } else {
        everySize2[(childrenAmount/2)-1] = everySize[childrenAmount - 1];
        for (int i = 0, j = i + 1, ii = 0, jj = 1;
             j < childrenAmount; i++, j++, ii++, jj++) {

            if(ii != childrenAmount/2) {

                everySize2[childrenAmount - jj] = everySize[i];
                everySize2[ii] = everySize[j];
                i++;
                j++;
            } else {
                ii++;
                everySize2[ii] = everySize[j];
            }
        }
    }

    for (int i = 0; i < childrenAmount; i++) {
        cout << everySize2[i] << " ";
    }








}