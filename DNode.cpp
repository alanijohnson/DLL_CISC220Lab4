#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

/*DNode(int) - 1 arg constructor
 *             initializes next and prev as null
 *             assigns data to input int
 * 
 *  int - data 
 */
DNode::DNode(int k) {
    data = k;
    next = NULL;
    prev = NULL;
}

/*~DNode() - destructor
 *  
 */
DNode::~DNode() {
    if (next != NULL || prev != NULL) {
        cout << "deleting this DNode may cause a memory leak" << endl;
    }
}