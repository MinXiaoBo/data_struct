#include <iostream>
#include <cstdlib>
#include "bst.h"

using namespace std;

void visit(int e){
    cout << e << ",";
}

int main(){
    BST<int> bst;
    for(int i = 0; i < 100; i++){
        bst.insert(i);
    }
    bst.travLevel(visit);
    cout << endl;
    BinNodePosi(int) x = bst.search(50);
    cout << x->data << endl;
    bst.remove(x->data);
    bst.travLevel(visit);
    while(!bst.empty()){
        cout << "删除" << bst.root()->data << "," ;
        bst.remove(bst.root()->data);
    }
    return 0;
}
