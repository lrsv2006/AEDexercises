#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <numeric>


int main() {
    std:: string word1;
    std:: string word2;
    std::cin >> word1;
    std::cin >> word2;


    int i = 1;
    int word1length = word1.length();
    int word2length = word2.length();
    int counter = 0;
    int movements = 0;
    int minimumlength = 0;

    if (word1length > word2length) {
        minimumlength = word2length;
    } else if (word1length < word2length) {
        minimumlength = word1length;
    } else if (word1length == word2length) {
        minimumlength = word1length;
    }

    while (i<= minimumlength) {

        if (word1.at(word1.length()-i) == word2.at(word2.length()-i)) {
            counter++;
            i++;
        } else {

            break;
        }
    }

    movements = ((word1.length() - counter) + (word2.length() - counter));
    std:: cout << movements;
}