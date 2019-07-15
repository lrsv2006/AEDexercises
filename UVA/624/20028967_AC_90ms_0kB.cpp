#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> maxComb; //combination
int maxLength;
int amountSongs;
int maxSumLength;


void findMax (vector<int> comb, int songs[], int sumLength, int song) {
    comb.push_back(songs[song]);
    sumLength += songs[song];

    if (sumLength > maxSumLength || sumLength == maxSumLength && comb.size() > maxComb.size()) {
        //if 2 options have the same length, it priorizes the option w more songs
        maxSumLength = sumLength;
        maxComb = comb;
    }

    for (int i = song+1; i < amountSongs; i++) {
        if (sumLength+songs[i] <= maxLength) {
            findMax(comb, songs, sumLength, i);
        }
    }
}


int main(int argc, char *argv[]) {

    while (cin >> maxLength) {
        maxSumLength = 0;
        cin >> amountSongs;
        int songs[amountSongs];
        for (int i = 0; i < amountSongs; i++) {
            int song;
            cin >> song;
            songs[i] = song;
        }

        for (int i = 0; i < amountSongs; i++) {
            vector<int> comb;
            findMax(comb, songs, 0, i);
        }

        for (int i = 0; i < maxComb.size(); i++) {
            cout << maxComb[i] << " ";
        }
        cout << "sum:" << maxSumLength << endl;
    }
}