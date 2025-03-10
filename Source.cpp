#include "Tube.h"
#include "relation.h"
#include<iostream>
using namespace std;
int main() {
    relation rel(3);
    rel.Create();
    rel.print_all();

    char continueMoving;
    bool a = true;
    while (a) {
        
        rel.moveLetter();
        if (rel.checkWin()) {
            cout << "you win\n";
            a = false;
        }
    }
    return 0;
}