#include <iostream>
#include "Queue.h"
#include "functions.h"
#include "LinkedList.h"

int main() {
    //PART 1
    Queue<int> myQueue;
    for (int i=0; i<10; i++){
        myQueue.push(i);
    }
    myQueue.display();

    //PART 2
    vector<int> myVector = {10,0,1,2,3,4,0,1,2,3,4};
    int pos = int(myVector.size()) - 1;
    cout << "\n\nmyVector: {10,0,1,2,3,4,0,1,2,3,4}\n\n";
    cout << "Last Occurrence of 2: " << mod_linear_search(myVector, 2, pos);
    cout << "\nLast Occurrence of 10: " << mod_linear_search(myVector, 10, pos);
    cout << "\nLast Occurrence of 15: " << mod_linear_search(myVector, 15, pos);


    //PART 3
    Linked<int> myList;
    myList.push_back(15);
    myList.push_back(2);
    myList.push_back(7);
    myList.push_back(0);
    myList.push_back(100);
    myList.push_back(-1);
    myList.push_back(2);
    cout << endl << endl << "Before sort:\n";
    myList.print();
    myList.insertion_sort();
    cout << endl << endl << "\nAfter sort:\n";
    myList.print();

}
