//Class pulled from Assignment 2

#pragma once
#include <iostream>
#include <string>
using namespace std;

// Node struct used to define nodes in the linked list
template<class T>
struct LNode {
    T data;
    LNode *nextPtr;
    explicit LNode(T d, LNode* nextP = nullptr); //Node constructor
};

template<class T>
LNode<T>::LNode(T d, LNode *nextP) : data(d), nextPtr(nextP) {} //Node constructor

// Linked class declaration
template<class T>
class Linked {
protected:
    LNode<T> *headPtr;
    LNode<T> *tailPtr;
    int num_items{};
public:
    Linked(){ //default constructor
        headPtr = nullptr;
        tailPtr = nullptr;
    };
    ~Linked(){ //destructor
        LNode<T>* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            LNode<T>* next = tempPtr->nextPtr;
            delete tempPtr;
            tempPtr = next;
        }
        headPtr = nullptr;
    };

    //function declarations & definitions

    //POST: New node created at front of linked list
    void push_front(T d){
        auto* newN = new LNode<T>(d, headPtr);
        headPtr = newN;
        num_items++;
    };

    //POST: New node created at back of linked list
    void push_back(T d){
        auto* newN = new LNode<T>(d);
        if (tailPtr == nullptr && headPtr == nullptr){
            headPtr = newN;
        }
        else{
            tailPtr->nextPtr = newN;
        }
        tailPtr = newN;
        num_items++;
    };

    //POST: Remove front node
    void pop_front(){
        if (headPtr == nullptr){ //empty list
            return;
        }
        else if (headPtr->nextPtr == nullptr){ //only 1 node
            delete headPtr;
            headPtr = nullptr;
            tailPtr = nullptr;
            num_items--;
        }
        else{
            LNode<T>* delN = headPtr;
            headPtr = headPtr->nextPtr;
            delete delN;
            num_items--;
        }
    };

    //POST: Remove back node
    void pop_back(){
        if (headPtr == nullptr && tailPtr == nullptr){ //empty list
            return;
        }
        else if (headPtr->nextPtr == nullptr){ //only 1 node
            delete headPtr;
            headPtr = nullptr;
            tailPtr = nullptr;
            num_items--;
        }
        else{
            LNode<T>* currentP = headPtr;
            while (currentP->nextPtr->nextPtr != nullptr){ //continue until 1 before tailPtr
                currentP = currentP->nextPtr;
            }
            LNode<T>* delN = tailPtr;
            tailPtr = currentP;
            tailPtr->nextPtr = nullptr;
            delete delN;
            num_items--;
        }
    };

    //POST: Return front pointer
    LNode<T>* front(){
        return headPtr;
    };

    //POST: Return tail pointer
    LNode<T>* back(){
        return tailPtr;
    };

    //POST: Return true/false based on if linked list is empty
    bool empty(){
        if (headPtr == nullptr && tailPtr == nullptr){
            return true;
        }
        else{
            return false;
        }
    };

    //POST: Insert new node at index
    void insert(size_t index, T d){
        if (empty()){ //empty list
            auto* newN = new LNode<T>(d);
            headPtr = newN;
            tailPtr = newN;
            num_items++;
        }
        else if (index >= num_items){  //at end of list
            push_back(d);
        }
        else{ //inserting in middle
            int count = 0;
            LNode<T>* current = headPtr;
            while (count != index - 1){ //move through list to find node before insert position
                current = current->nextPtr;
                count++;
            }
            //update pointers
            auto* newN = new LNode<T>(d, current->nextPtr);
            current->nextPtr = newN;
            num_items++;
        }
    };

    //POST: returns true if node at index successfully removed, false if unsuccessful
    bool remove(size_t index){
        if (index >= num_items){ //index out of bounds or empty list
            return false;
        }
        else if (headPtr->nextPtr == nullptr){ //only 1 node
            delete headPtr;
            headPtr = nullptr;
            tailPtr = nullptr;
            num_items--;
            return true;
        }
        else{ //more than 1 node
            int count = 0;
            LNode<T>* current = headPtr;
            while (count != index - 1){ //move through list to find node before delete position
                current = current->nextPtr;
                count++;
            }
            //update pointers
            LNode<T>* delN = current->nextPtr;
            current->nextPtr = current->nextPtr->nextPtr;
            delete delN;
            num_items--;
            return true;
        }
    };

    //POST: returns index of value d in linked list
    size_t find(T d){
        if (empty()){
            return 0;
        }
        else{
            int count = 0;
            LNode<T>* current = headPtr;
            while (current != nullptr){
                if (current->data == d){
                    return count;
                }
                current = current->nextPtr;
                count++;
            }
            return num_items;
        }
    };

    //POST: displays linked list
    void print(){
        int count = 0;
        LNode<T>* tempN = front();
        cout << "Place\t Data\n";
        while (tempN != nullptr){
            cout << count << "\t\t\t" << tempN->data << endl;
            count++;
            tempN = tempN->nextPtr;
        }
    };

    void insertion_sort(){
        if (headPtr == nullptr || headPtr->nextPtr == nullptr) { //IF empty or 1 node, already sorted
            return;
        }
        LNode<T>* sortedEnd = headPtr;
        while (sortedEnd->nextPtr != nullptr) {
            LNode<T>* current = sortedEnd->nextPtr;
            if (current->data >= sortedEnd->data) { // IF current is already in place
                sortedEnd = current;
            }
            else {
                // REMOVE current from unsorted portion
                sortedEnd->nextPtr = current->nextPtr;
                // FIND position in sorted portion
                if (current->data < headPtr->data) { // IF smallest data, make current head
                    current->nextPtr = headPtr;
                    headPtr = current;
                }
                else {
                    LNode<T>* search = headPtr;
                    while (search->nextPtr != nullptr && search->nextPtr->data < current->data) { // TRAVERSE
                        search = search->nextPtr;
                    }
                    // Insert current after search
                    current->nextPtr = search->nextPtr;
                    search->nextPtr = current;
                }
            }
        }
    };
};