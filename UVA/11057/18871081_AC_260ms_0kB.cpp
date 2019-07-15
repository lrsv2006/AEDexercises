#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main() {

    int availablebooks;


    while (cin >> availablebooks) {
        int booksprices[availablebooks];
        int i = 0;

        while (i < availablebooks) {
            cin >> booksprices[i];
            i++;

        }

        for (int i = 0; i < availablebooks; i++) {
            int bookprice = booksprices[i];
            int previousbookprice = i - 1;
            while (previousbookprice >= 0 && booksprices[previousbookprice] > bookprice) {
                booksprices[previousbookprice + 1] = booksprices[previousbookprice];
                previousbookprice--;
            }
            booksprices[previousbookprice + 1] = bookprice;
        }

        int amountofmoney;
        cin >> amountofmoney;


        if (availablebooks == 2) {
            cout << "Peter should buy books whose prices are " << booksprices[0] << " and " << booksprices[1] << "."
                 << endl;
            cout << "\n";
        } else {
            int book1;
            int book2;
            int differenceofprices = 1000002;
            for (int i = 0; i < availablebooks - 1; i++) {
                for (int j = i+1; j < availablebooks; j++) {
                    if (booksprices[i] + booksprices[j] == amountofmoney) {
                        if ((booksprices[j] - booksprices[i]) < differenceofprices) {
                            book1 = booksprices[i];
                            book2 = booksprices[j];
                            differenceofprices = book2 - book1;
                            if (differenceofprices < 0) {
                                differenceofprices = differenceofprices * (-1);
                                int temp = book1;
                                book1 = book2;
                                book2 = temp;
                            }

                        }
                    }
                }
            }
            cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << "." << endl;
            cout << "\n";
        }
    }

}