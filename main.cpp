#include<iostream>
using namespace std;
#include "Node.h"
#include "List.h"
#include "NodeTraits.h"
#include "ListHelper.h"


int main (int, char *[]){

    typedef DoubleListNode<int> forward_node_t;
    typedef List<forward_node_t> list_t;
    typedef list_t::Iterator iterator_t;
    
    /*
    typedef DoubleListNode<float> double_node_t;
    typedef List<double_node_t> dlist_t;
    */


    list_t list;
    list.push_back(5);
    list.push_back(10);    
    list.push_back(20); 
    list.push_back(24);
    list.push_back(50);
    list.push_back(25);
    list.pop_back();
    cout << list << endl;
    list.push_front(1);
    cout<< list.getSize()<<endl;
    cout << list.back()<< endl;
    cout << list.front()<< endl;
    list.pop_front();
    cout << list.front()<< endl;
    cout << list.getSize() << endl;
    list.clear();
    cout << list.getSize() << endl;
    list.push_front(4);
    list.push_front(2);
    list.push_front(1);
    list.erase(1);
    list.pop_front();
    cout<<list.front() << endl;
    cout << list << endl;


  
    list.push_front(10);
    iterator_t it = list.begin();
    cout << *(it);
    
    return 0;
}
