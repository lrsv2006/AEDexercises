#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int sol;
bool possible (int collumn, int queens[]) {
    for (int i = 0; i < collumn; i++) {
        if ((queens[i] == queens[collumn]) || (abs(queens[i] - queens[collumn]) == collumn - i)) {
            return false;
        }
    }
    return true;
}

void eightQueens (int collumn, int queens[], int firstL, int firstC) {
    if (collumn == 8) {
        if (queens[firstC] == firstL) {
            if (sol < 10) {
                cout << " " << sol << "      ";
            }
            else {
                cout << sol << "      ";
            }
            for (int i = 0; i < 7; i++) {
                cout << queens[i]+1 << " ";
            }
            cout << queens[7]+1 << endl;
            sol++;
        }
    } else {
        for (int i = 0; i < 8; i++) {
            queens[collumn] = i;
            if (possible(collumn, queens)) {
                eightQueens(collumn + 1, queens, firstL, firstC);
            }
        }
    }
}

int main(int argc, char *argv[]) {

    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++) {
        sol = 1;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        int firstL;
        int firstC;
        cin >> firstL;
        cin >> firstC;
        int queens[8] = {};
        eightQueens(0, queens, firstL-1, firstC-1);
        if (i < numCases-1) {
            cout << endl;
        }
    }
    return 0;
}
