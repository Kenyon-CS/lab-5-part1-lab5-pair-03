#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType.
//***********************************************************

#include "linkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <class Type>
//class unorderedLinkedList: public linkedListType<Type>
class unorderedLinkedList: public linkedListType<int>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list,
      //    otherwise the value false is returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the beginning of the list, last points to
      //    the last node, and count is incremented by 1.
      //

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the end of the list, last points to the
      //    last node, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing deleteItem
      //    is deleted from the list. first points to the first
      //    node, last points to the last node of the updated
      //    list, and count is decremented by 1.

    void delSmallest();
      //Function to delete the node with the smallest info in the list.
      //Postcondition: If the list is not empty, the first occurrence
      //    of the node with the smallest info is deleted from the list.
      //    first points to the first node, last points to the last node
      //    of the updated list, and count is decremented by 1.

    void delAllOccurrences(const Type& deleteItem);
      //Function to delete all occurrences of deleteItem from the list.
      //Postcondition: If found, all nodes containing deleteItem are
      //    deleted from the list. first points to the first node,
      //    last points to the last node of the updated list, and
      //    count is decremented by the number of nodes deleted.

};


template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;

    current = first; //set current to point to the first
                     //node in the list

    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == NULL)   //if the list was empty, newNode is also
                        //the last node in the list
        last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->link = NULL;     //set the link field of newNode
                              //to NULL

    if (first == NULL)  //if the list is empty, newNode is
                        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2: the node to be deleted is the first node
        {
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to
                                   //the second node

            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted
                                       //was the last node
                    last = trailCurrent; //update the value
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

template <class Type>
void unorderedLinkedList<Type>::delSmallest()
{
    if (first == NULL)
    {
        cout << "Cannot delete from an empty list." << endl;
        return;
    }

    nodeType<Type> *current;          //pointer to traverse the list
    nodeType<Type> *trailCurrent;     //pointer just before current
    nodeType<Type> *smallestNode;     //pointer to the node with smallest info
    nodeType<Type> *trailSmallest;    //pointer just before smallestNode

    //Initialize: assume first node has the smallest value
    smallestNode = first;
    trailSmallest = NULL;

    //Traverse the list only once to find the smallest
    trailCurrent = first;
    current = first->link;

    while (current != NULL)
    {
        if (current->info < smallestNode->info)
        {
            smallestNode = current;
            trailSmallest = trailCurrent;
        }
        trailCurrent = current;
        current = current->link;
    }

    //Delete the node with smallest info
    if (smallestNode == first)  //smallest is the first node
    {
        first = first->link;
        if (first == NULL) { //the list had only one node
            last = NULL;
        }
        delete smallestNode;
    }
    else  //smallest is not the first node
    {
        trailSmallest->link = smallestNode->link;

        if (smallestNode == last) {  //smallest is the last node
            last = trailSmallest;
            last->link = NULL;
        }
        delete smallestNode;
    }

    count--;
}//end delSmallest

template <class Type>
void unorderedLinkedList<Type>::delAllOccurrences(const Type& deleteItem)
{
    if (first == NULL)
    {
        cout << "Cannot delete from an empty list." << endl;
        return;
    }

    nodeType<Type> *current;          //pointer to traverse the list
    nodeType<Type> *trailCurrent;     //pointer just before current
    nodeType<Type> *temp;             //pointer to delete nodes

    //Delete all occurrences from the beginning of the list
    while (first != NULL && first->info == deleteItem)
    {
        temp = first;
        first = first->link;
        delete temp;
        count--;
    }

    //If the list becomes empty after deleting from the beginning
    if (first == NULL)
    {
        last = NULL;
        return;
    }

    //Delete all occurrences from the rest of the list (single traversal)
    trailCurrent = first;
    current = first->link;

    while (current != NULL)
    {
        if (current->info == deleteItem)
        {
            trailCurrent->link = current->link;

            if (current == last) {  //node to be deleted is the last node
                last = trailCurrent;
                last->link = NULL;
            }
            temp = current;
            current = current->link;
            delete temp;
            count--;
        }
        else
        {
            trailCurrent = current;
            current = current->link;
        }
    }
}//end delAllOccurrences


#endif
