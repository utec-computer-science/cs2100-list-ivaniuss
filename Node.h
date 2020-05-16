#ifndef LISTAS_NODE_H
#define LISTAS_NODE_H

#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    typedef T value_t;
    typedef unsigned int size_t;

public:
    value_t value;

public:
    Node(const value_t& _value):value(_value){
    }

    size_t size(){
        return 0;
    }

    ~Node(void){
    }

    value_t& operator*(void){
        return value;
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
        _out << "Nodo: " <<  _node.value;
        return _out;
    }
};

#endif //LISTAS_NODE_H

