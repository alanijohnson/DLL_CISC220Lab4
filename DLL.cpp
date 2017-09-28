#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*DLL() - no arg constructor
 *        initializes first and last as NULL and sets size to 0
 *  
 */
DLL::DLL() {
    first = NULL;
    last = NULL;
    size = 0;
}

/*DLL(int) - 1 arg constructor
 *           generates list of length x specified by argument
 *           items in list are random numbers 0-100 placed in order
 *           then prints the list forward and backwards
 */
DLL::DLL(int x) {
    //    //(8 pts) This is the constructor that takes as input x, which is the size of the
    //    list you’ll be creating. The constructor then generates x random numbers between 0
    //    and 100, and uses the DLL’s methods to insert each random number into the list in
    //    order. It then prints out the list both forwards and backwards. Your main should
    //    call this constructor with a random number between 10 and 20, and that will pretty
    //    much test most of the methods. For testing purposes, you can print out the list
    //    forwards and backwards after inserting each new number to make sure everything is
    //    working.

    srand(time(NULL)); //sets the seed to use the time at runtime

    //initialize data
    first = NULL; //initialize first
    last = NULL; //initialize last
    size = 0; //initialize size

    int dataVal = rand() % 101; //generate a random number 0-100 for data

    //fill the DLL
    while (size < x) {
        insertInOrder(dataVal); //insert item in order
        dataVal = rand() % 101; //generate new random number
    }

    //print DLL
    printDLL(); //print forward
    printReverse(); //print backwards
}

//destructor

DLL::~DLL() {
    cout << "inside destructor. List size: " << size << endl;
    DNode* node = first;
    DNode* tmp;
    int count = 0;
    while (node != NULL) {
        tmp = node->next;
        //cout << "node " << node->data << " destroyed" << endl;
        node->next = NULL;
        node->prev = NULL;
        delete node;
        count++;
        node = tmp;
    }
    first = NULL;
    last = NULL;
    cout << "completed. " << count << " nodes deleted" << endl;
}

/* printDLL() - prints the doubly linked list in order
 *             
 * arguments: none
 * return: void
 */
void DLL::printDLL() {
    // (2 pts)prints the list


    if (size != 0) { //make sure the list isn't empty
        DNode *tmp = first; //create a temp variable set at the first node
        while (tmp != NULL) { //iterate till tmp equals NULL (no more nodes) or if nodes are used in multiple lists will stop at desired last
            cout << tmp->data << ", "; //print node and separate node data with comma
            tmp = tmp->next; //iterate to next node
        }
    }
    cout << endl; //flush buffer
}

/*printReverse() - prints the DLL in reverse
 *
 * input: none
 * output: void  
 */
void DLL::printReverse() {
    //(4 pts) prints the list in reverse

    DNode *tmp = last; //create a temp variable set at the first node
    while (tmp != NULL) { //iterate till tmp equals NULL (no more nodes) or if nodes are used in multiple lists will stop at desired last
        cout << tmp->data << ", "; //print node and separate node data with comma
        tmp = tmp->prev; //iterate to next node
    }
    cout << endl; //flush buffer
}

/*addFirst(int) - adds the first element to the list
 *
 * input: int - the integer data value
 * output: void  
 */
void DLL::addFirst(int x) {
    //(4 pts)adds the very first node to the list (when size is 0)

    if (size == 0) { //makes sure the list empty
        DNode* n = new DNode(x); //create new node
        first = n; //set first to new DNode
        last = n; //set last to new DNode
        size++; //increment the size by 1 - size should = 1;
    }
}

/*addAtFront(int) - adds node to the front of an existing list
 *
 * input: int - data for node
 * output: void  
 */
void DLL::addAtFront(int x) {
    // (5 pts)adds a node to beginning of the list (when size>0)
    if (size > 0) { // checks to make sure the list has elements
        DNode* n = new DNode(x); // create a new node using the argument as data type
        first->prev = n; //sets the prev of the first node to the new node
        n->next = first; //sets the next node of the new node as the first node
        first = n; //updates the first node to the new node
        size++; //increments the size by 1

    }
}

/*push(int) - adds the node to the end of the list
 *
 * input: int - data for the new node
 * output: void  
 */
void DLL::push(int x) {
    //(4 pts)adds node to the end of the list

    if (size == 0) { //if the size is zero, add node as the first node
        addFirst(x);
    } else { //list has elements
        DNode* n = new DNode(x); //create new node using argument
        last->next = n; //point last node to the new node
        n->prev = last; //point new nodes previous to last
        last = n; //update the last node to the new node that was create
        size++; //increment size by 1
    }
}

/*insertInOrder(int) - add new node in the proper order
 *                     this method uses push(), addAtFront(), addFirst()
 *                     as helper function
 * input: int - data for the new node
 * output: void  
 */
void DLL::insertInOrder(int x) {
    // (8 pts)creates a new node and inserts it in order into


    if (size == 0) { //the list has no elements, the item needs to be added as first
        addFirst(x);
    } else { //elements exist in the list
        if (x <= first->data) { //if the item is less than or equal to the first, add it to the front
            addAtFront(x);
        } else if (x >= last->data) { //if the item is greater than or equal to the last, add it to the end of the list
            push(x);
        } else { //the item needs to go somewhere in the middle of the list
            DNode* n = new DNode(x); //create the new node
            DNode* tmp = first; //initialize tmp as the first node
            while (tmp->data < x) { //iterate to the last DNode with Data less than the int
                tmp = tmp->next;
            }

            //insert the node
            n->prev = tmp->prev;
            n->next = tmp;
            tmp->prev = n;
            n->prev->next = n;
            size++; //increment the size
        }
    }
}
