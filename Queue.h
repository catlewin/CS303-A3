#pragma once
using namespace std;

// Node struct used to define nodes in the linked list
template<class T>
struct Node {
    T data;
    Node *nextPtr;
    explicit Node(T d, Node* nextP = nullptr); //Node constructor
};

template<class T>
Node<T>::Node(T d, Node *nextP) : data(d), nextPtr(nextP) {} //Node constructor

// Queue class declaration
template<class T>
class Queue {
protected:
    Node<T> *headPtr;
    Node<T> *tailPtr;
    int num_items{};
public:
    Queue(){ //default constructor
        headPtr = nullptr;
        tailPtr = nullptr;
        num_items = 0;
    };
    ~Queue(){ //destructor
        Node<T>* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            Node<T>* next = tempPtr->nextPtr;
            delete tempPtr;
            tempPtr = next;
        }
        headPtr = nullptr;
    };

    //function declarations & definitions

    //POST: New node created at back of queue
    void push(T d){
        auto* newN = new Node<T>(d);
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
    void pop(){
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
            Node<T>* delN = headPtr;
            headPtr = headPtr->nextPtr;
            delete delN;
            num_items--;
        }
    };

    //POST: Return front node
    Node<T>* front(){
        return headPtr;
    };

    //POST: Return true/false based on if queue is empty
    bool empty(){
        if (headPtr == nullptr && tailPtr == nullptr){
            return true;
        }
        else{
            return false;
        }
    };

    int size(){
        return num_items;
    };

    void display(){
        int Qsize = size();
        cout << "Data\n";
        for (int i = 0; i < Qsize; i++){
            cout << "\t\t\t" << front()->data << endl;
            push(front()->data);
            pop();
        }
    };

    void move_to_rear(){
        push(front()->data);
        pop();
    };
};