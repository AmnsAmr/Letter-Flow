#include "relation.h"
#include "Tube.h"
#include <iostream>

using namespace std;

relation::relation() : tubes(), tubeCapacity(0), Totaltubes(0) {}

relation::relation(size_t initialCapacity) : tubes(), tubeCapacity(0), Totaltubes(0) {
    tubes.reserve(initialCapacity);
}

relation::relation(const relation& other) : tubes(other.tubes), tubeCapacity(other.tubeCapacity), Totaltubes(other.Totaltubes) {}

relation& relation::operator=(const relation& other) {
    if (this != &other) {
        tubes = other.tubes;
        tubeCapacity = other.tubeCapacity;
        Totaltubes = other.Totaltubes;
    }
    return *this;
}

Tube& relation::getTube(size_t index) {
    return tubes[index];
}

const Tube& relation::getTube(size_t index) const {
    return tubes[index];
}

size_t relation::size() const {
    return tubes.size();
}

void relation::print_all() const {
    if (tubes.empty()) return;

    size_t maxHeight = tubeCapacity;

    for (size_t level = 0; level < maxHeight; ++level) {
        for (size_t i = 0; i < tubes.size(); ++i) {
            Tube tube = tubes[i];
            size_t idx = maxHeight - 1 - level;
            if (idx < tube.size()) {
                cout << "| " << tube.getdata()[idx] << " | ";
            }
            else {
                cout << "|   | ";
            }
        }
        cout << "\n";
    }
    for (size_t i = 0; i < tubes.size(); ++i) {
        cout << "|___| ";
    }
    cout << "\n";
}

void relation::Create() {
    int Tubenum, content, empty;
    cout << "how many Full tubes in the game?\n";
    while (!(cin >> Tubenum) || Tubenum <= 0) {
        cout << "Please enter a positive integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "how many empty tubes in the game?\n";
    while (!(cin >> empty) || empty < 0) {
        cout << "Please enter a non-negative integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    Totaltubes = empty + Tubenum;
    cout << "how many places in each tube?\n";
    while (!(cin >> content) || content <= 0) {
        cout << "Please enter a positive integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    tubeCapacity = content;
    tubes.clear();

    for (int i = 0; i < Tubenum; i++) {
        Tube a;
        a.input(content);
        tubes.push_back(a);
    }

    for (int i = 0; i < empty; i++) {
        Tube a;
        tubes.push_back(a);
    }
}

void relation::moveLetter() {
    int source;
    cout << "Enter the source tube number (0 to " << tubes.size() - 1 << "): ";
    while (!(cin >> source) || source < 0 || source >= static_cast<int>(tubes.size())) {
        cout << "Please enter a valid tube number (0 to " << tubes.size() - 1 << "): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (tubes[source].size() == 0) {
        cout << "Source tube " << source << " is empty!\n";
        return;
    }

    int dest;
    cout << "Enter the destination tube number (0 to " << tubes.size() - 1 << "): ";
    while (!(cin >> dest) || dest < 0 || dest >= static_cast<int>(tubes.size()) || dest == source) {
        cout << "Please enter a valid different tube number (0 to " << tubes.size() - 1 << "): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    char letter = tubes[source].pop();
    if (tubes[dest].push(letter)) {
        cout << "Moved '" << letter << "' from tube " << source << " to tube " << dest << ".\n";
    }
    else {
        tubes[source].getdata().push_back(letter);
        cout << "Cannot move '" << letter << "' to tube " << dest << " because the top letter doesn't match.\n";
    }

    cout << "New state:\n";
    print_all();
}

bool relation::checkWin() {
    for (int i = 0;i < tubes.size();i++) {
        if (!(tubes[i].allSame())) {
            return false;
        }
    }
    return true;
}