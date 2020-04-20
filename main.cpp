#include <iostream>

// main.cpp
#include <iostream>
#include "SimpleList.h"
using std::cout;
using std::endl;
int main (int, char*[]){

    SimpleList<int> list;

    list.push_back(3);
    list.push_back(7);
    list.push_back(5);
    list.push_back(2);
    list.push_front(4);
    list.push_front(9);

    cout<<list<<endl;

    list.pop_front();
    cout << list << endl;
    list.pop_back();
    cout << list << endl;
    cout << list.operator[](2) << endl;
    cout << list.empty() << endl;
    cout << list.size() << endl;
    list.clear();
    cout << list.size() << endl;

    return 0;
}

