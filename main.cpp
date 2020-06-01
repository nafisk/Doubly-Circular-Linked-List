#include <iostream>
#include "cdlinkedlist.cpp"
#include <stdlib.h>
using namespace std;

//This Program is coded to create a Circular Doubled Linked List and to manupulate its values. The direction of the list is from the head towards the right which then comes back to the head. All the functions work properly and is created to keep the list circular while executing all the functions. Program By Nafis Khan


//Menu Function for Calling repeatedly
int menu();

int main(){

    cout << "\t\t~Welcome to The Linked List Program~\n" <<
            "\t\t\t~By Nafis Khan\n" << endl;


    int option = menu();

    cdlinkedlist<int> list;
    cdlinkedlist<int> newlist;
    cdlinkedlist<int> newlist2;


    //Switch to call Class Functions
    while( option != 0 ){
    int a;
    switch(option){
        case 1: //Prints the List
          list.printList(); cout << endl;
          break; 
        case 2: //Inserts data to the front of the list
          cout << "\nWhat Value Would You Like To Add?\n";cin >> a;
          list.insertFront(a);  cout << endl;
          break;
        case 3: //Inserts data to the back of the list
          cout << "\nWhat Value Would You Like To Add?\n";cin >> a;
          list.insertBack(a); cout << endl;
          break;
        case 4: //Deletes the number placed throughout the entire list
          cout << "\n1Which Value Would You Like to Delete?" << endl;
          int y;
          cin >> y; 
          list.deleteNode(y); cout << endl;
          break;
        case 5: //Calling the copy contructor to copy the list
          newlist2.copyList(list);
          cout << "\nData Has Been Copied\n" << endl;
          break;
        case 6: //Checking to see if the list is empty or not
          list.checkList();
          break;
        case 7: //Clears the entire list
          list.emptyList();
          break;  
        case 8: //Shows the length of the list created by the user
          list.lengthList();
          break;  
        case 9: //Uses operator overloading to copy data to a new list
          newlist = list;
          newlist.printList();
          cout << "\nData Has Been Copied\n" << endl;
          break;
        case 10: //Searching if the entered value exists within the list
          cout << "\nWhat Would You Like To Seach For?\n";
          int x; cin >> x;
          list.searchList(x);
          break;
        case 11: //Interetes through the list from front to back
          list.interateFrontToBack();
          break;
        case 12: //Interetes through the list from back to front
          list.interateBackToFront();
      }

      //Looping Menu Function
      option = menu();
    }

    //Exit Code to End Program
    cout << "\n~Exiting Program~\n" << endl;
    exit(0);


    return 0;
}

//Menu Option
int menu(){
    

    int x;  //Variable for Selecting Menu
    cout << "\t\t\tPlease Enter On Of the Following Operations To Be Done:\n";
    cout << "1. Print The Linked List" << endl;
    cout << "2. Insert A Value to The Front" << endl;
    cout << "3. Insert A Value to The Back" << endl;
    cout << "4. Delete A Value from the List" << endl;
    cout << "5. Copy Data Using Copy Constructor" << endl;
    cout << "6. Check List to see if Empty" << endl;
    cout << "7. Clear the Entire List" << endl;
    cout << "8. Length of List" << endl;
    cout << "9. Copy using Overloaded Operator" << endl;
    cout << "10. Search Item in List" << endl;
    cout << "11. Iterate from Front to Back" << endl;
    cout << "12. Iterate from Back to Front" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Option: "; 
    cin >> x;
    
    //Error Handling for Out of Range Options
    if (x < 0 || x > 12){
      cout << "\n~Menu Option " << x << " Is Not Valid\n" << "Please Enter a Valid Option~\n\n";
    }

    return x;
}