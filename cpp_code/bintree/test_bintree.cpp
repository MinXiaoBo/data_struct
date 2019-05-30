#include <iostream>
#include <cstdlib>
#include "bintree.h"

using namespace std;

void visit( int e){
    cout << e << ",";
}

int main(){
    BinTree<int> bt;
    BinNodePosi(int) root = bt.insertAsRoot(1);
    bt.insertAsLC(root, 2);
    BinNodePosi(int) res = bt.insertAsRC(root, 3);
    bt.insertAsLC(res, 4);
    bt.insertAsRC(res, 5);
    bt.travPre(visit);
    return 0;
}

