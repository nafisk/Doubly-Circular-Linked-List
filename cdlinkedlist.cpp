#ifndef CDLINKEDLIST_H
#define CDLINKEDLIST_H
#include <iostream>
#include "cdlinkedlist.h"
using namespace std;

//Default Constructor: Setting everything to NULL
template<class T>
cdlinkedlist<T>::cdlinkedlist(){ 
    count = 0;
    head = NULL;
    currentIterator = NULL;
}



//Deconstrcutor: Destroys all the data one by one
template<class T>
cdlinkedlist<T>::~cdlinkedlist(){
    while(head != NULL){
      node<T>* temp = new node<T>();
        temp = head;
        head = head->next;
        delete temp;
        count -= 1;
    }
    delete head;
    head = NULL;
}



//Inserts New Node at the front of the List
template<class T>
void cdlinkedlist<T>::insertFront(T info){
    node<T>* frontNode = new node<T>();
    frontNode->info = info;

    //if head is Null then the new node is the head itself
    if(head == NULL){
        head = frontNode;
        head->next = head;
        head->prev = head;

    }
    else {//placing the new node infront of head [newNode] before [head] then it as the head itself
      if(count == 1){
        
        head->next = frontNode;
        frontNode->next = head;
        head->prev = frontNode;
        frontNode->prev = head;
        head = frontNode;        
      }
      else if (count >= 2){
        //Connecting the last node to the newnode that takes heads places and sends head to the second place
        frontNode->prev = head->prev;
        head->prev->next = frontNode;

        frontNode->next = head;
        head->prev = frontNode;

        head = frontNode;
      }

    }
   count += 1; //Incrementing count as more nodes are added to the list
     
}



//Inserts New Node at the back of the head
template<class T>
void cdlinkedlist<T>::insertBack(T info){
    node<T>* backNode = new node<T>();
    backNode->info = info;
    
    //Accouting for a head that does not have have any data. If head is Null then the new node is the head itself
    if(head == NULL){
        head = backNode;
        head->next = head;
        head->prev = head;
    }
    else { 
        //accounting for a list of two nodes to make it circular
        if(count == 1){
          head->next = backNode;
          backNode->next = head;
          head->prev = backNode;
          backNode->prev = head;
        }
        else if(count >= 2) { //accounting for all the other cases to add to the back
          backNode->prev = head->prev;
          head->prev->next = backNode;
          backNode->next = head;
          head->prev = backNode;

        }
   
     }

   count += 1;  //Incrementing count as more nodes are added to the list

}





//Deleting Node 
template<class T>
void cdlinkedlist<T>::deleteNode(T info){
    //uses current & currentTemp to iterate and delete nodes throughout the list
    node<T>* current;
    node<T>* currentTemp; 
    current = head;
    current = current->next;

    //this function uses count to account for deleting Nodes in different cases

    if(head == NULL){ //Returns msg if list is empty
        cout << "\nList is Empty. Create a list first\n";
    }
    else if(count == 1){ //deleting when there is only a head
      head = NULL;
      delete head;
    }
    else if(count == 2){ //deleting when there are two nodes and make the head itself circular
      if(head->info == info){
        currentTemp = head;
        head = head->next;
        delete currentTemp;
        head->next = NULL;
        head->prev = NULL;
      }
      else if (head->next->info == info){
        currentTemp = head->next;
        delete currentTemp;
        head->next = NULL;
        head->prev = NULL;
      }
    }
    else{ //acccounts for all other cases of nodes in the list
        while(&(*current) != &(*head)){ //Address if the info
            if(current->info == info){
                currentTemp = current->next;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                current = currentTemp;
            }
            else{
                current = current->next;
            }

        }
        if(head->info == info){
            current = head;
            head->prev = head->next;
            head->next = head->prev;
            head = head->next;
            delete current;
            current = NULL;
            
      }
    }

  count -= 1; //decrements count as nodes are being deleted 
}



//Prints the List
template<class T>
void cdlinkedlist<T>::printList(){
    cout << endl;
    if(head == NULL){
        cout << "\nList is Empty\n";
    }
    else{
        node<T>* current;
        current = head;
        cout << current->info << " ";
        current = current->next;


        if (current != NULL) {
          while(current->info != head->info){
            cout << current->info << " ";
            current = current->next;
          }
        }
        cout << endl;
        
        
    }
}



//Overloading the = Operator
template<class T>
void cdlinkedlist<T>::operator=(const cdlinkedlist<T>& otherlist) {
  copyList(otherlist);
}



//Making a copy Constructor that calls the copy function
template<class T>
cdlinkedlist<T>::cdlinkedlist(const cdlinkedlist<T>& otherlist) {
  copyList(otherlist);
}



//Creating a Copy Constructor
template<class T>
void cdlinkedlist<T>::copyList(const cdlinkedlist<T>& otherlist){
  count = 0;
  head = NULL;

  if (otherlist.head == NULL) {
    return;
  }

  //oldCurrent is the pointer to the otherlist/original list
  count = otherlist.count;
  head = new node<T>();
  node<T> *oldCurrent = otherlist.head;
  head->info = oldCurrent->info;
  head->next = head;
  head->prev = head;

  //Uses a for loop to copy all the data into the new list
  for (int i = 0; i < count - 1; i++) {
    oldCurrent = oldCurrent->next;

    node<T>* newNode = new node<T>();
    newNode->info = oldCurrent->info;

    head->prev->next = newNode;
    newNode->prev = head->prev->next;
    head->prev = newNode;
    newNode->next = head;

  }
    
}



//Checking to see if List is Empty
template<class T>
void cdlinkedlist<T>::checkList(){
  if (head == NULL) {
    cout << "\nList is Empty\n\n";
  }
  else 
    cout << "\nList is not Empty\n\n";
}



//Emptying the list
template<class T>
void cdlinkedlist<T>::emptyList(){
    while(head != NULL){
      node<T>* temp = new node<T>();
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        count -= 1;
    }
    cout << endl;

}



//Uses count to check the length of the Linked list
template<class T>
void cdlinkedlist<T>:: lengthList(){
  cout << "\nThe Length is: " << count << endl <<endl;
}



//Uses a pointer to go through the entire list to seach for the info
template<class T>
void cdlinkedlist<T>::searchList(T info){
  node<T>* temp;
  temp = head;
  if (head == NULL){
    cout << "List is Empty";
  }
  else {
    for (int i = 0; i < count; i++) {
      if (temp->info == info){
        cout << "\nThe Item Is In The List\n" << endl;
        break;
      }
      else 
        temp = temp->next;
    }
  }
}



//Iterates from Front to Back
template<class T>
void cdlinkedlist<T>::interateFrontToBack(){

  if (currentIterator == NULL) {
    currentIterator = head;
    cout << "You are currently at Head\n" ;
  } else {
    currentIterator = currentIterator->next;
  }

  cout << "\nAccessed Next Node with Data: " << currentIterator->info << endl << endl;
}



//Iterates from Back to Front
template<class T>
void cdlinkedlist<T>::interateBackToFront(){

  if (currentIterator == NULL) {
    currentIterator = head;
    cout << "You are currently at Head\n" ;
  } else {
    currentIterator = currentIterator->prev;
  }
  
  cout << "\nAccessed Previous Node With Data: " << currentIterator->info << endl << endl;
  
}



#endif