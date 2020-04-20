//
// Created by ivaniuss on 4/19/20.
//

#pragma once
#include <iostream>
#include "Node.h"
#include "iterator.h"
template <typename T>
class CircularSimpleList{
private:
    typedef Node<T> node;
    node * head;
    node * tail;
    unsigned int sizee = 0;
public:
    typedef container::iterator<T> iteratorr;
    CircularSimpleList(const CircularSimpleList<T> & list){

    }

    CircularSimpleList(){
        head = nullptr;
        tail = nullptr;
    }

    ~CircularSimpleList(){
        while(head != tail)
            pop_front();
    }

    void push_back(const T& element);
    void push_front(const T& element);
    T& pop_back();
    T& pop_front();
    T& operator[] (const int&);
    bool empty();
    unsigned int size();
    void clear();
    iteratorr begin(){return iteratorr(head);}
    iteratorr end() {return iteratorr(tail);}
    inline friend std::ostream& operator<<(std::ostream& os , const CircularSimpleList<T>& list){
        Node<T> * pointer = list.head;
        Node<T> *temp = list.head;
        while (pointer ->next != temp){
            os << pointer->value << " ";
            pointer = pointer->next;
        }
        os << pointer->value;
        return os;
    };

};


template <typename T>
void CircularSimpleList<T>::push_back(const T& element){
    node * newNode = new node();
    newNode->value = element;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;

    } else {
        node *pointer = head;
        while (head->next != pointer)
            head = head->next;
        head->next = newNode;
        tail = newNode;
        head = pointer;
        newNode->next = head;

    }
    sizee++;

}

template <typename T>
void CircularSimpleList<T>::push_front(const T& element){
    node * newNode = new node();
    newNode->value = element;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    } else{
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    sizee++;
}

template <typename T>
T& CircularSimpleList<T>::pop_front(){

    if (head != nullptr) {
        node * holder = head;
        head = holder->next;
        holder->next = nullptr;
        tail->next = head;
        delete holder;
    }
    sizee--;
}

template <typename T>
T& CircularSimpleList<T>::pop_back(){

    if (head != nullptr) {
        node * holder = head;
        while(holder->next != tail){
            holder = holder->next;
        }
        holder->next = nullptr;

        delete tail;
        tail = holder;
        tail->next = head;
    }
    sizee--;
}
template <typename T>
T& CircularSimpleList<T>::operator[] (const int& val){
    node * pointer = head;
    if(pointer != nullptr){
        for (int i = 0; i < val ; ++i) {
            pointer = pointer->next;
        }
        return pointer->value;
    }

}

template <typename T>
bool CircularSimpleList<T>::empty(){
    return head == nullptr;
}
template <typename T>
unsigned int CircularSimpleList<T>::size(){
    return sizee;
}

template <typename T>
void CircularSimpleList<T>::clear(){
    while(head != tail){
        pop_front();
        head = head->next;
    }
    pop_front();
    pop_front();
}




template<typename T>
class doubleCircularList {
    typedef NodeD<T> doubleNode;
    doubleNode *head;
    doubleNode *rHead;
    int sizee = 0;
public:
    typedef container::iterator2<T> iteratorr;
    doubleCircularList();
    ~doubleCircularList();
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
doubleCircularList<T>::doubleCircularList() {
    head= new doubleNode;
    rHead = new doubleNode;
    head->nextNode = rHead;
    rHead->prevNode = head;
    head->prevNode = rHead;
    rHead->nextNode = head;
}
template <typename T>
doubleCircularList<T>::~doubleCircularList(){
    while (head->nextNode != rHead)
        pop_front();
    delete head;
    delete rHead;
}
template <typename T>
T doubleCircularList<T>::getFront() const{
    return head->nextNode->value;
}
template <typename T>
T doubleCircularList<T>::getBack()const {
    return rHead->prevNode->value;
}

template <typename T>
void doubleCircularList<T>::push_front(const T& new_value){
    auto * newNode = new doubleNode;
    newNode->value = new_value;
    newNode->prevNode = head;
    newNode->nextNode = head->nextNode;
    head->nextNode->prevNode = newNode;
    head->nextNode = newNode;
    sizee++;
}

template <typename T>
void doubleCircularList<T>::push_back(const T& new_value){

    auto * newNode = new doubleNode;
    newNode->value = new_value;
    newNode->prevNode = rHead->prevNode;
    newNode->nextNode = rHead;
    rHead->prevNode->nextNode = newNode;
    rHead->prevNode = newNode;
    sizee++;
}

template <typename T>
void doubleCircularList<T>::pop_front(){
    doubleNode * pointer = head->nextNode->nextNode;

    delete head->nextNode;
    head->nextNode = pointer;
    pointer->prevNode = head;
    sizee--;
}

template <typename T>
void doubleCircularList<T>::pop_back(){
    doubleNode * pointer = rHead->prevNode->prevNode;
    delete rHead->prevNode;
    rHead->prevNode = pointer;
    pointer->nextNode = rHead;
    sizee--;
}


template <typename T>
T doubleCircularList<T>::max(){
    doubleNode * pointer = head->nextNode;
    T temp = 0;
    while(pointer != rHead){
        if(pointer->value > temp)
            temp = pointer->value;
        pointer = pointer->nextNode;
    }
    return temp;
}


template <typename T>
T doubleCircularList<T>::min(){
    doubleNode * pointer = head->nextNode;
    T temp = pointer->value;
    while(pointer != rHead){
        if(pointer->value < temp)
            temp = pointer->value;
        pointer = pointer->nextNode;
    }
    return temp;
}

template<typename T>
T &doubleCircularList<T>::operator[](const int &index) {

    doubleNode * pointer = head->nextNode;
    for (int i = 0; i < index; ++i) {
        pointer = pointer->nextNode;
    }

    return pointer->value;
};

template <typename T>
void doubleCircularList<T>::printForward(){
    doubleNode * pointer = head->nextNode;
    while (pointer != rHead){
        cout << pointer->value<< " ";
        pointer = pointer->nextNode;
    }

};

template <typename T>
void doubleCircularList<T>::printReverse(){
    doubleNode *pointer = rHead->prevNode;
    while (pointer != head) {
        cout << pointer->value << " ";
        pointer = pointer->prevNode;
    }

}

template<typename T>
bool doubleCircularList<T>::empty() {
    return head->nextNode == nullptr;
}

template<typename T>
void doubleCircularList<T>::clear() {
    while(head->nextNode != rHead)
        pop_front();
}

template<typename T>
unsigned int doubleCircularList<T>::size() {
    return sizee;
}


