#include <iostream>
using namespace std;

struct words {
    string key;
    string *name[101] { NULL };

}words;

int Hash(string key);
int h(string key);
void insert(string key);
bool insertaftercollision(string key, int freepos);
int find(string key);
int findaftercollision(string key, int newpos);
void deletekey (string key);
bool deletekeyaftercollision (string key, int newpos);


int Hash(string key) {
    return ((h(key)) % 101);
}

int h(string key) {
    int sum;

    for (int i = 1, j = 0; i <= key.length(); i++, j++) {
        sum = sum + (key[j]*i);
    }
    sum = sum*19;
    return sum;
}

int collisions(string key, int j) {
    int freepos = (Hash(key) + (j*j) + (23*j))%101;
    return freepos;
}

void insert(string key) {
    int pos = Hash(key);
    if (words.name[pos] == NULL) {
        words.name[pos] = &key;
    } else {
        bool inserted = false;
        for (int i = 1; i <= 20; i++) {
            int freepos = collisions(key, i);
            inserted = insertaftercollision(key, freepos);
            if (inserted == true) {
                break;
            }
        }
    }
}

bool insertaftercollision(string key, int freepos) {
    if (words.name[freepos] == NULL) {
        words.name[freepos]= &key;
        return true;
    } else {
        return false;
    }

}


int find(string key) {
    int index = Hash(key);
    if (words.name[index] == &key) {
        return index;
    } else {
        int found = 0;
        for (int i = 1; i <= 101; i++) {
            int newpos = collisions(key, i);
            found = findaftercollision(key, newpos);
            if (found != -1) {
                return newpos;
            }
        }
    }
}

int findaftercollision(string key, int newpos) {
    if (words.name[newpos] == &key) {
        return newpos;
    } else {
        return -1;
    }
}

void deletekey (string key) {
    int pos = find(key);
    if (words.name[pos] == &key) {
        words.name[pos] == NULL;
        delete words.name[pos];
    } else {
        bool deleted = false;
        for (int i = 1; i <= 101; i++) {
            int newpos = collisions(key, i);
            deleted = deletekeyaftercollision(key, newpos);
            if (deleted == true) {
                break;
            }
        }
    }

}

bool deletekeyaftercollision (string key, int newpos) {
    if (words.name[newpos] == &key) {
        words.name[newpos] = NULL;
        delete words.name[newpos];
        return true;
    } else {
        return false;
    }
}







int main() {
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++) {
        struct words Word;
        int operations;
        cin >> operations;
        for (int j = 0; j < operations; j++) {
            string operation;
            cin >> operation;
            if (operation.at(0) == 'A') {
                int size = operation.length();
                size = size-4;
                string word = operation.substr(4,size);
                insert(word);
            } else {
                int size = operation.length();
                size = size-4;
                string word = operation.substr(4,size);
                deletekey(word);
            }
        }

        for (int j = 0; j < 101; j++) {
            cout << Word.name[j] << endl;
        }
    }


    return 0;
}