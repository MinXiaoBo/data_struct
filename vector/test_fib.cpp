#include <iostream>
#include <cstdlib>
#include "fib.h"

using namespace std;

int main(void){
	Fib fib(10);
	cout << fib.prev() << endl;
	cout << fib.get() << endl;
	cout << fib.next() << endl;
	cout << fib.next() << endl;
	cout << fib.prev() << endl;
	return 0;
}