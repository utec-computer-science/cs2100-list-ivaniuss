//
// Created by ivaniuss on 4/19/20.
//

#pragma once
#include <iostream>
#include "Node.h"
using std::cout;
using std::endl;
template <typename T>
class doubleList{
    typedef NodeD<T> doubleNodeH;
    doubleNodeH * head;
    doubleNodeH * rHead;
    int sizee = 0;
public:
    typedef container::iterator2<T> iteratorr;
    doubleList();
    ~doubleList();
    T getFront()const;
    T getBack()const;
    void push_front(const T& new_value);
    void push_back(const T& new_value);
    void pop_front();
    void pop_back();
    T max();
    T min();
    T &operator[](const int & index);
    void printForward();
    void printReverse();
    bool empty();
    unsigned int size();
    void clear();
    iteratorr begin(){return iteratorr(head->nextNode);}
    iteratorr end() {return iteratorr(rHead);}
//    iteratorr rbegin(){return iteratorr(rHead->prevNode);}
//    iteratorr rend() {return iteratorr(head);}

};

template <typename T>
doubleList<T>::doubleList() {
    head= new doubleNodeH;
    rHead = new doubleNodeH;
    head->nextNode = rHead;
    rHead->prevNode = head;
    head->prevNode = nullptr;
    rHead->nextNode = nullptr;
}
template <typename T>
doubleList<T>::~doubleList(){
    while (head->nextNode != rHead)
        pop_front();
    delete head;
    delete rHead;
}
template <typename T>
T doubleList<T>::getFront() const{
    return head->nextNode->value;
}
template <typename T>
T doubleList<T>::getBack()const {
    return rHead->prevNode->value;
}

template <typename T>
void doubleList<T>::push_front(const T& new_value){
    auto * newNode = new doubleNodeH;
    newNode->value = new_value;
    newNode->prevNode = head;
    newNode->nextNode = head->nextNode;
    head->nextNode->prevNode = newNode;
    head->nextNode = newNode;
    sizee++;
}

template <typename T>
void doubleList<T>::push_back(const T& new_value){

    auto * newNode = new doubleNodeH;
    newNode->value = new_value;
    newNode->prevNode = rHead->prevNode;
    newNode->nextNode = rHead;
    rHead->prevNode->nextNode = newNode;
    rHead->prevNode = newNode;
    sizee++;
}

template <typename T>
void doubleList<T>::pop_front(){
    doubleNodeH * pointer = head->nextNode->nextNode;

    delete head->nextNode;
    head->nextNode = pointer;
    pointer->prevNode = head;
    sizee--;
}

template <typename T>
void doubleList<T>::pop_back(){
    doubleNodeH * pointer = rHead->prevNode->prevNode;
    delete rHead->prevNode;
    rHead->prevNode = pointer;
    pointer->nextNode = rHead;
    sizee--;
}


template <typename T>
T doubleList<T>::max(){
    doubleNodeH * pointer = head->nextNode;
    T temp = 0;
    while(pointer != rHead){
        if(pointer->value > temp)
            temp = pointer->value;
        pointer = pointer->nextNode;
    }
    return temp;
}


template <typename T>
T doubleList<T>::min(){
    doubleNodeH * pointer = head->nextNode;
    T temp = pointer->value;
    while(pointer != rHead){
        if(pointer->value < temp)
            temp = pointer->value;
        pointer = pointer->nextNode;
    }
    return temp;
}

template<typename T>
T &doubleList<T>::operator[](const int &index) {

    doubleNodeH *pointer = head->nextNode;
    for (int i = 0; i < index; ++i) {
        pointer = pointer->nextNode;
    }

    return pointer->value;
};

template <typename T>
void doubleList<T>::printForward(){
    doubleNodeH * pointer = head->nextNode;
    while (pointer != rHead){
        cout << pointer->value<< " ";
        pointer = pointer->nextNode;
    }

};

template <typename T>
void doubleList<T>::printReverse(){
    doubleNodeH * pointer = rHead->prevNode;
    while (pointer != head){
        cout << pointer->value<< " ";
        pointer = pointer->prevNode;
    }

}

template<typename T>
bool doubleList<T>::empty() {
    return head->nextNode == nullptr;
}

template<typename T>
void doubleList<T>::clear() {
    while(head->nextNode != rHead)
        pop_front();
}

template<typename T>
unsigned int doubleList<T>::size() {
    return sizee;
}


