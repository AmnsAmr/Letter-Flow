#ifndef RELATION_H
#define RELATION_H

#include <cstddef>
#include <vector>

class Tube;

class relation {
private:
    std::vector<Tube> tubes;
    size_t tubeCapacity;
    size_t Totaltubes;

public:
    relation();
    relation(size_t initialCapacity);
    relation(const relation& other);
    relation& operator=(const relation& other);
    Tube& getTube(size_t index);
    const Tube& getTube(size_t index) const;
    size_t size() const;
    void print_all() const;
    void Create();
    void moveLetter();
    bool checkWin();
};

#endif // RELATION_H