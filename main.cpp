#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int everySize[100];
    int childrenAmount;
    cin >> childrenAmount;
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

    for (int i = 0; i < childrenAmount; i++) {
        cout << everySize[i] << endl;
    }


    return 0;
}