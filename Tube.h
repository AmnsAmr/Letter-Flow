#ifndef TUBE_H
#define TUBE_H

#include <cstddef>
#include <vector>

class Tube {
    std::vector<char> data;
    bool Done = false;

public:
    Tube();
    void setDone();
    size_t size() const;
    void input(int a);
    std::vector<char>& getdata();
    bool push(char value);
    char pop();
    bool allSame();
};

#endif