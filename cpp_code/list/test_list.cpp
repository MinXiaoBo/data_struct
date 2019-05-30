#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;

int main(){
    List<int> mylist;
    for(int i = 1; i <= 10; i++){
        mylist.insertAsLast(i);
    }
    mylist.PrintList();
    cout << "秩为０的元素是" << mylist[0] << endl;
    cout << "列表的规模为" << mylist.size() << endl;
    if(mylist.empty()){
        cout << "列表为空" << endl;
    }else{
        cout << "列表不为空" << endl;
    }
    mylist.insertA(mylist.last(), 11);
    mylist.PrintList();
    mylist.remove(mylist.last());
    mylist.PrintList();
}
