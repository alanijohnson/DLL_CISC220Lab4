#ifndef DLL_HPP_
#define DLL_HPP_
#include "DNode.hpp"

class DLL {
    DNode *first;
    DNode *last;
    int size;
public:
    DLL();
    DLL(int x);
    //(8 pts) This is the constructor that takes as input x, which is the size of the
//    list you’ll be creating. The constructor then generates x random numbers between 0
//    and 100, and uses the DLL’s methods to insert each random number into the list in
//    order. It then prints out the list both forwards and backwards. Your main should
//    call this constructor with a random number between 10 and 20, and that will pretty
//    much test most of the methods. For testing purposes, you can print out the list
//    forwards and backwards after inserting each new number to make sure everything is
//    working.
    ~DLL();
    void printDLL();
    // (2 pts)prints the list
    void printReverse();
    //(4 pts) prints the list in reverse
    void addFirst(int x);
    //(4 pts)adds the very first node to the list (when size is 0)
    void addAtFront(int x);
    // (5 pts)adds a node to beginning of the list (when size>0)
    void push(int x);
    //(4 pts)adds node to the end of the list
    void insertInOrder(int x);
    // (8 pts)creates a new node and inserts it in order into
    // the existing list
};
#endif /* DLL_HPP_ */