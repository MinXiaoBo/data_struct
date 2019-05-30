#include <iostream>
#include <cstdlib>
#include "queue.h"

using namespace std;

int main(){
    Queue<int> Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    cout << Q.empty() << endl;
    for( int i = 1; i < 6; i++){
        cout << Q.dequeue() << endl;
    }
}
