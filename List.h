#ifndef LISTAS_LIST_H
#define LISTAS_LIST_H

#include<iostream>
#include "NodeTraits.h"
#include "Node.h"
using namespace std;

template <typename Node>
class List {

protected:

    using node_t = Node;
    typedef typename node_t::value_t value_t;

    node_t* head;
    node_t* tail;
    int size = 0;

public:
    friend class Iterator;
    class Iterator{
    protected:
        node_t * pointer;

    public:
        using node_t = Node ;
        typedef typename node_t::value_t value_t;

    public:
        Iterator (node_t* pointer = nullptr){
        }

        ~Iterator(void){
        }

        Iterator& operator++ (void){
            pointer = pointer->next;
            return *this;
        }

        Iterator operator=(Iterator other) {
            return (*this);
        }

        bool operator!= (Iterator it){
            return pointer != it.pointer;
        }

        value_t& operator* (void) {
            return **pointer;
        }

    };

public:
    List(const List&):head(nullptr){
    }

    List(value_t*):head(nullptr){
    }

    List(node_t*):head(nullptr){
    }

    List(int):head(nullptr){
    }

    List(void):head(nullptr){
    }

    ~List(void){
    }


    value_t front(){
        return head->value;
    }

    value_t back(){
        return tail->value;
    }


    value_t& operator[] (const int& _position){
        if(_position >= size)
            throw out_of_range("INDEX OUT OF RANGE");
        node_t * tmp = head;
        for (int i = 0; i < _position; i++, tmp = tmp->next);
        return tmp->value;
    }

    bool empty(void){
        return head == nullptr;
    }

    int getSize(){
        return this->size;
    }


    template<int nodeType>
    void __push_back__(Node**,Node**,value_t,int&);

    void push_back(const value_t& element){
        __push_back__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element,size);
    }
     
    template<int nodeType>
    void __push_front__(Node**,Node**,value_t,int&);

    void push_front(const value_t& element){
        __push_front__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element,size);
    }


    template<int nodeType>
    void __pop_back__(Node**,Node**,int& size);

    void pop_back(){
        __pop_back__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,size);
    }


    template<typename _T>
    inline friend ostream& operator<< (ostream& out, const List<_T>& list){
        return out;
    }


    //ITERATORS


    //virtual Iterator begin() = 0;
    //virtual Iterator end() = 0;


    //SOBRECARGA << Y >>
    /*
    List& operator<< (const value_t& _value){
        this->push_back(_value);
        return *this;
    }

    List& operator>> (const value_t& _value){
        this->push_front(_value);
        return *this;
    }
     */

};


#endif //LISTAS_LIST_H

