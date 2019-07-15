#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;


void swapint (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapstring (string* a, string* b) {
    string temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int sizeofFloors[], string coloursofFloors[], int first, int last) {

    int pivot = sizeofFloors[first];
    int splitposition = first;
    for (int i = first; i <= last; i++) {
        if (sizeofFloors[i] < pivot) {
            splitposition++;
            swapint(&sizeofFloors[splitposition], &sizeofFloors[i]);
            swapstring(&coloursofFloors[splitposition], &coloursofFloors[i]);

        }
    }
    swapint(&sizeofFloors[first], &sizeofFloors[splitposition]);
    swapstring(&coloursofFloors[first], &coloursofFloors[splitposition]);

    return (splitposition);

}

void quicksort (int sizeofFloors[], string coloursofFloors[], int first, int last) {

    if (first < last) {
        int splitposition = partition(sizeofFloors, coloursofFloors, first, last);

        quicksort(sizeofFloors, coloursofFloors, first, splitposition - 1);
        quicksort(sizeofFloors, coloursofFloors, splitposition + 1, last);
    }
}

int main() {

    int amountofcases;
    cin >> amountofcases;
    int i = 0;


    while (i < amountofcases) {

        //Inserting elements

        int amountofFloors;
        int sizeofFloor;
        cin >> amountofFloors;

        if (amountofFloors == 1) {
            cout << 1 << endl;
            cin >> sizeofFloor;
            i++;
            continue;
        } else {

            int sizeofFloors[amountofFloors];
            string coloursofFloors[amountofFloors];
            i++;
            for (int i = 0; i < amountofFloors; i++) {
                cin >> sizeofFloor;
                if (sizeofFloor > 0) {
                    sizeofFloors[i] = sizeofFloor;
                    coloursofFloors[i] = "blue";
                } else {
                    sizeofFloors[i] = sizeofFloor * (-1);
                    coloursofFloors[i] = "red";
                }
            }

            quicksort(sizeofFloors, coloursofFloors, 0, amountofFloors - 1);

            //Finding the biggest number of floors w the specified conditions

            int maxsize = 0;

            for (int i = amountofFloors - 1; i > 0; i--) {

                if (coloursofFloors[i] != coloursofFloors[i - 1]) {
                    if ((i == amountofFloors-1) || (maxsize == 0)) {
                        maxsize++;
                        maxsize++;
                    } else {
                        maxsize++;
                    }

                } else {
                        int j = i - 2;
                        bool samecolours = true;
                        while ((samecolours == true) && (j >= 0)) {
                            if (coloursofFloors[i] != coloursofFloors[j]) {
                                if (maxsize == 0) {
                                    maxsize++;
                                    maxsize++;
                                } else {
                                    maxsize++;
                                }
                                i = j + 1;
                                samecolours = false;
                            } else {
                                j--;
                            }
                        }
                }
            }

            cout << maxsize << endl;

        }
    }
}