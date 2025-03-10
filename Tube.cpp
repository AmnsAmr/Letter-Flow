#include "Tube.h"
#include <iostream>

using namespace std;

Tube::Tube() : data() {}

size_t Tube::size()  {
    return data.size();
}

void Tube::input(int a) {
    cout << "enter content\n";
    for (int i = 0; i < a; i++) {
        char A;
        cin >> A;
        data.push_back(A);
    }
}

vector<char>& Tube::getdata() { return data; }

bool Tube::push(char value) {
    if (data.empty() || data.back() == value) {
        data.push_back(value);
        return true;
    }
    else {
        return false;
    }
}

char Tube::pop() {
    char value = data.back();
    data.pop_back();
    return value;
}

void Tube::setDone() { Done = true; }

bool Tube::allSame(size_t capacity) {
    if (data.empty()) {
        return true;
    }
    if (data.size() < capacity) {
        return false;
    }
    char a = data[0];
    for (int i = 1;i < data.size();i++) {
        if (a!=data[i]) {
            return false;
        } 
    }
    return true;
}