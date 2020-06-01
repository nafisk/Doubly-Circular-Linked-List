#ifndef NODEMANUP_H
#define NODEMANUP_H
#include <iostream>
#include "node.h"
using namespace std;

//Manupulates Info in the Linked List
template<class T>
class cdlinkedlist{
    private:
        int count;                                  //Number of Nodes
        node<T> *head;                              //Starting Point
        node<T> *currentIterator;                   //Helps to Iterate Throught the List

    public:
    cdlinkedlist();                                 //Constructor
    ~cdlinkedlist();                                //Deconstructor
    cdlinkedlist(const cdlinkedlist<T>& otherlist); //Copy Constructor
    void operator=(const cdlinkedlist<T>& otherlist);//Overloaded Operator
    void copyList(const cdlinkedlist<T>& otherlist);//Used for Copying to newList
    void insertFront(T info);                       //Inserts Info Infront of head
    void insertBack(T info);                        //Inserts Info Back of head
    void deleteNode(T info);                        //Deletes Nodes of Info
    void printList();                               //Prints the Entire List
    void checkList();                               //Checks list to See If Empty 
    void emptyList();                               //Empties the Entire List
    void lengthList();                              //Returns The Number of Nodes/Infos
    void searchList(T info);                        //Searches Through the List
    void interateFrontToBack();                     //Iterates from From to Back
    void interateBackToFront();                     //Iterates from Back to Front
    

};


#endif