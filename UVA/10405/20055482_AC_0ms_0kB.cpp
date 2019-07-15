#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;
int vis[1000][1000];

int LCS(int a, int b, string sequence1[], string sequence2[]) {

    if (vis[a][b] >= 0) {
        return vis[a][b];
    }
    if (a == 0 || b == 0) {
        return vis[a][b] = 0;
    }
    if (sequence1[a].compare(sequence2[b]) == 0) { // if they are equals
        return 1+LCS(a-1, b-1, sequence1, sequence2);
    }
    return vis[a][b] = max(LCS(a-1, b, sequence1, sequence2), LCS(a, b-1, sequence1, sequence2));

}

int main() {
    string sequence1;
    while (getline(cin, sequence1)) {
        string sequence2;
        getline(cin, sequence2);


        string aSeq1[sequence1.length()+1];
        string aSeq2[sequence2.length()+1];
        for (int i = 1, j = 0; i <= sequence1.length(); i++, j++) {
            aSeq1[i] = sequence1.at(j);
        }

        for (int i = 1, j = 0; i <= sequence2.length(); i++, j++) {
            aSeq2[i] = sequence2.at(j);
        }
        memset(vis, -1, 1000 * 1000 * sizeof(int));

       cout << LCS(sequence1.length(), sequence2.length(), aSeq1, aSeq2);
       cout << endl;

    }

    return 0;
}