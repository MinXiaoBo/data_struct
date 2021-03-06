#include <iostream>
#include <cstdlib>
#include "myvector.h"

#define random(x) (rand() % x)

using namespace std;

int main(){
    Vector<int> MyVector;
    int e = 0;
    for(int i = 0; i < 100; i++){
        e = (int) random(100);
        MyVector.insert(i, e);
    }
    MyVector.printVector();
    cout << "\n" << endl;
    cout << MyVector.find(99) << endl;
    cout << "\n" << endl;
    MyVector.sort();
    MyVector.printVector();
    cout << "\n" << endl;
    cout << MyVector.search(7) << endl;
    cout << "\n" << endl;
    MyVector.remove(20,100);
    MyVector.printVector();
    cout << "\n" << endl;
    cout << MyVector.size() << endl;
    return 0;
}
