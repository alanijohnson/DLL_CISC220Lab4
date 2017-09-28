/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alani
 *
 * Created on April 3, 2017, 9:53 PM
 */
#include "DLL.hpp"
#include "DNode.hpp"
#include <time.h>
#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {


    srand(time(NULL)); //set the seed as the time at runtime
    int size = (rand() % 11) + 10; //generate a random size
    DLL* lst = new DLL(size); //build DLL of random size containing random int 0-100
    //     // test addFirst, addAtFront, push, insertInOrder and print
    //        DLL* d1 = new DLL();
    //        d1->printDLL();
    //        d1->addFirst(2);
    //        d1->addAtFront(0);
    //        d1->push(3);
    //        d1->printDLL();
    //        d1->printReverse();
    //        d1->insertInOrder(-1);
    //        d1->insertInOrder(4);
    //        d1->insertInOrder(1);
    //        d1->printDLL();
    //        d1->printReverse();
    return 0;
}

