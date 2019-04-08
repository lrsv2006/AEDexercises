#include <iostream>
using namespace std;

struct word {
    string key;
    string name[101];

};

int h(string key);

int printASCII (char c) {
    int i = c;
    return i;
}

int Hash(string key) {
    return h(key) % 101;
}

int h(string key) {
    int sum;

    for (int i = 1; i <= key.length(); i++) {
       int j = 0;
        sum = sum + (printASCII(key.at(j)) * i);
    }

    sum = sum*19;
    return sum;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}