#include <iostream>

// main.cpp
#include <iostream>
#include "SimpleList.h"
#include "doubleList.h"
#include "circularList.h"

using std::cout;
using std::endl;
int main (int, char*[]){

    //simple linked list
//    SimpleList<int> list;
//    SimpleList<int>::iteratorr it;
//
//    list.push_back(3);
//    list.push_back(7);
//    list.push_back(5);
//    list.push_back(2);
//    list.push_front(4);
//    list.push_front(9);
//
//
//    for (auto it = list.begin(); it != list.end() ; ++it) {
//        cout << *it << " ";
//    }

//    cout << endl;
//    cout<<list<<endl;
//
//    list.pop_front();
//    cout << list << endl;
//    list.pop_back();
//    cout << list << endl;
//    cout << list.operator[](2) << endl;
//    cout << list.empty() << endl;
//    cout << list.size() << endl;
//    list.clear();
//    cout << list.size() << endl;
//



    //double linked list
//    doubleList<int> list;
//    doubleList<int>::iteratorr it;
//
//    list.push_back(3);
//    list.push_back(7);
//    list.push_back(5);
//    list.push_back(2);
//    list.push_front(4);
//    list.push_front(9);
//
//    for (auto it = list.begin(); it != list.end() ; ++it) {
//        cout << *it << " ";
//    }
//
//    cout << endl;
//    list.printForward();
//    cout << endl;
//    list.printReverse();
//    cout << endl;
//    list.pop_front();
//    list.printForward();
//    cout << endl;
//    list.pop_back();
//    list.printForward();
//    cout << endl;
//    cout << list[2] << endl;
//    cout << list.empty() << endl;
//    cout << list.size() << endl;
//    list.clear();
//    cout << list.size() << endl;

    //circular linked list
//    CircularSimpleList<int> list;
//    CircularSimpleList<int>::iteratorr it;
//
//    list.push_back(3);
//    list.push_back(7);
//    list.push_back(5);
//    list.push_back(2);
//    list.push_front(4);
//    list.push_front(9);
//
//
//    for (auto it = list.begin(); it != list.end() ; ++it) {
//        cout << *it << " ";
//    }
//        cout << *(list.end());
//
//    cout << endl;
//    cout<<list<<endl;
//    list.pop_front();
//    cout << list << endl;
//    list.pop_back();
//    cout << list << endl;
//    cout << list[2] << endl;
//    cout << list.empty() << endl;
//    cout << list.size() << endl;
//    list.clear();
//    cout << list.size() << endl;



    //double circular linked list
    doubleCircularList<int> list;
    doubleCircularList<int>::iteratorr it;

    list.push_back(3);
    list.push_back(7);
    list.push_back(5);
    list.push_back(2);
    list.push_front(4);
    list.push_front(9);

    for (auto it = list.begin(); it != list.end() ; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    list.printForward();
    cout << endl;
    list.printReverse();
    cout << endl;
    list.pop_front();
    list.printForward();
    cout << endl;
    list.pop_back();
    list.printForward();
    cout << endl;
    cout << list[2] << endl;
    cout << list.empty() << endl;
    cout << list.size() << endl;
    list.clear();
    cout << list.size() << endl;

    return 0;
}


