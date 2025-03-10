#ifndef Relation_H
#define Relation_H

#include <cstddef>
#include <vector>

class Tube;

class Relation {
private:
    std::vector<Tube> tubes;
    size_t tubeCapacity;
    size_t Totaltubes;

public:
    size_t getTubecapacity();
    Relation();
    Relation(size_t initialCapacity);
    Relation( Relation& other);
    Relation& operator=( Relation& other);
    Tube& getTube(size_t index);
    size_t size() ;
    void print_all() ;
    void Create();
    void moveLetter();
    bool checkWin();
};

#endif // Relation_H