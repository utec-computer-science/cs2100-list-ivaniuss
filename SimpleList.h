//
// Created by ivaniuss on 4/17/20.
//
#pragma once
#include <iostream>
#include "Node.h"
#include "iterator.h"

template <typename T>
class SimpleList{
private:
    typedef Node<T> node;
        node * head;
        node * tail;
        unsigned int sizee = 0;
public:
   typedef container::iterator<T> iteratorr;
   SimpleList(const SimpleList<T> & list){

    }

    SimpleList(){
       head = nullptr;
       tail = nullptr;
   }

    ~SimpleList(void){
       while(head != nullptr)
           pop_front();
    }

    void push_back(const T& element);
    void push_front(const T& element);
    T& pop_back(void);
    T& pop_front(void);
    T& operator[] (const int&);
    bool empty(void);
    unsigned int size(void);
    void clear(void);
    iteratorr begin(){return iteratorr(head);}
    iteratorr end() {return iteratorr(tail->next);}
    inline friend std::ostream& operator<<(std::ostream& os , const SimpleList<T>& list){
        Node<T> * pointer = list.head;
        while (pointer != nullptr){
            os << pointer->value << " ";
            pointer = pointer->next;
        }
        return os;
    };
};


template <typename T>
void SimpleList<T>::push_back(const T& element){
    node * newNode = new node();
    newNode->value = element;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
    sizee++;

}

template <typename T>
void SimpleList<T>::push_front(const T& element){
    node * newNode = new node();
    newNode->value = element;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else{
        newNode->next = head;
        head = newNode;
    }
    sizee++;
}

template <typename T>
T& SimpleList<T>::pop_front(void){

    if (head != nullptr) {

        node * holder = head;
        head = holder->next;
        holder->next = nullptr;
        delete holder;
    }
    sizee--;
}

template <typename T>
T& SimpleList<T>::pop_back(void){

    if (head != nullptr) {
        node * holder = head;
        while(holder->next != tail){
            holder = holder->next;
        }
        holder->next = nullptr;

        delete tail;
        tail = holder;
    }
    sizee--;
}
template <typename T>
T& SimpleList<T>::operator[] (const int& val){
    node * pointer = head;
    if(pointer != nullptr){
        for (int i = 0; i < val ; ++i) {
            pointer = pointer->next;
        }
        return pointer->value;
    }

}

template <typename T>
bool SimpleList<T>::empty(void){
    return head == nullptr;
}
template <typename T>
unsigned int SimpleList<T>::size(void){
    return sizee;
}

template <typename T>
void SimpleList<T>::clear(void){
    while(head != nullptr)
        pop_front();
}

