#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

int main(){
    Stack<int> S;
    S.push(1);
    S.push(3);
    S.push(2);
    cout << S.size() << endl;
    cout << S.pop() << endl;
    cout << S.top() << endl;
}
