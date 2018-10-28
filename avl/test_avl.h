#include <iostream>
#include <cstdlib>
#include "./avl.h"

using namespace std;

void visit(int e){
    cout << e << ",";
}

int main(){
    AVL<int> avl;
    for(int i = 0; i < 100; i++){
        avl.insert(i);
    }
    avl.travLevel(visit);
    return 0;
}
