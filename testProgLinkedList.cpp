//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999

#include <iostream>      
#include <string>                           //Line 1
#include "unorderedLinkedList.h"                    //Line 2

using namespace std;                                //Line 3

int main()                                          //Line 4
{
     int num;
     string ans;
     cout << "Do you want to test insert, delete, and oLLiterator?(y/n) ";
     cin >> ans;
     if (ans == "y") {
          unorderedLinkedList<int> list1, list2;                                      //Line 7

          cout << "Enter integers ending "
               << "with -999" << endl;                    //Line 8
          cin >> num;                                     //Line 9

          while (num != -999) {
               list1.insertLast(num);                      //Line 12
               cin >> num;                                 //Line 13
          }                                               //Line 14

          cout << endl;                                   //Line 15

          cout << "list1: ";                     //Line 16
          list1.print();                                  //Line 17
          cout << endl;                                   //Line 18
          cout << "Length of list1: " << list1.length() << endl;                 //Line 19

          list2 = list1;	   //test the assignment operator Line 20

          cout << "list2: ";                     //Line 21
          list2.print();                                  //Line 22
          cout << endl;                                   //Line 23
          cout << "Length of list2: " << list2.length() << endl;                 //Line 24

          cout << "Enter the number to be deleted: ";                            //Line 25
          cin >> num;                                     //Line 26
          cout << endl;                                   //Line 27

          list2.deleteNode(num);                          //Line 28

          cout << "After deleting " << num << " list2: " << endl;                     //Line 29
          list2.print();                                  //Line 30
          cout << endl;                                   //Line 31

          cout << "Length of list2: " << list2.length() << endl;                 //Line 32

          cout << endl << "Output list1 " << "using an iterator" << endl;            //Line 33

          linkedListIterator<int> it;                     //Line 34

          for (it = list1.begin(); it != list1.end(); ++it) {
          cout << *it << " ";                         //Line 36
          cout << endl; 
          }
          cout << "\n";
     }
     cout << "Do you want to test find Kth Element?(y/n) ";
     cin >> ans;
     if (ans == "y") {
          unorderedLinkedList<int> listA;
          cout << "Build listA. Enter integers ending with -999" << endl;
          cin >> num;
          while (num != -999) {
               listA.insertLast(num);
               cin >> num;
          }
          cout << endl;
          listA.print();
          cout << "\n";
     
          int k;
          cout << "Enter index to be found" << endl;
          cin >> k;
          //testing with throwing an error
          int x = listA.findKthEleA(k);
          cout << "Found element at index "<< k <<": " << x << endl;

          //testing with giving a message
          cout << "Enter index to be found" << endl;
          cin >> k;
          x = listA.findKthEleB(k);
          cout << "Found element at index "<< k <<": " << x << endl;
     }
     cout << "Do you want to test rotate?(y/n) ";
     cin >> ans;
     if (ans == "y") {
          unorderedLinkedList<int> listB;
          cout << "Build listB. Enter integers ending with -999" << endl;
          cin >> num;
          while (num != -999) {
               listB.insertLast(num);
               cin >> num;
          }
          cout << endl;
          listB.print();
          cout << "Rotating..." << endl;
          listB.rotate();
          listB.print();
     }
     cout << "Do you want to test delSmallest and delAllOccurrences?(y/n) ";
     cin >> ans;
     if (ans == "y") {
          unorderedLinkedList<int> list3, list4;
          cout << "Build list3. Enter integers ending with -999" << endl;
          cin >> num;
          while (num != -999) {
               list3.insertLast(num);
               cin >> num;
          }
          cout << endl;
          cout << "list3: ";
          list3.print();
          cout << endl;
          cout << "Length of list3: " << list3.length() << endl;

          list3.delSmallest();

          cout << "After delSmallest, list3: ";
          list3.print();
          cout << endl;
          cout << "Length of list3: " << list3.length() << endl;

          cout << endl << "Build list4. Enter integers ending with -999" << endl;
          cin >> num;
          while (num != -999) {
               list4.insertLast(num);
               cin >> num;
          }
          cout << endl;
          cout << "list4: ";
          list4.print();
          cout << endl;
          cout << "Length of list4: " << list4.length() << endl;

          cout << "Enter the number to delete all occurrences: ";
          cin >> num;
          cout << endl;

          list4.delAllOccurrences(num);

          cout << "After deleting all " << num << ", list4: ";
          list4.print();
          cout << endl;
          cout << "Length of list4: " << list4.length() << endl;
     }
    //system("pause");
    return 0;
}

