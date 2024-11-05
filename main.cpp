#include <iostream>
#include "Queue.h"
#include "functions.h"

int main() {
    Queue<int> myQueue;
    for (int i=0; i<10; i++){
        myQueue.push(i);
    }
    myQueue.display();

    vector<int> myVector = {10,0,1,2,3,4,0,1,2,3,4};
    int pos = int(myVector.size()) - 1;
    cout << "\n\nmyVector: {10,0,1,2,3,4,0,1,2,3,4}\n\n";
    cout << "Last Occurrence of 2: " << mod_linear_search(myVector, 2, pos);
    cout << "\nLast Occurrence of 10: " << mod_linear_search(myVector, 10, pos);
    cout << "\nLast Occurrence of 15: " << mod_linear_search(myVector, 15, pos);

}
