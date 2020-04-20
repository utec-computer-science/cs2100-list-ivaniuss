//
// Created by ivaniuss on 4/17/20.
//
#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class SimpleList{
private:
    typedef Node<T> node;
        node * head;
        node * tail;
        unsigned int sizee = 0;
public:
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

    // Inserta un elemento al final
    void push_back(const T& element);

    // Inserta un elemento al inicio
    void push_front(const T& element);
//
//    virtual // Quita el ultimo elemento y retorna una referencia
    T& pop_back(void);
//
//    virtual // Quita el primer elemento y retorna una referencia
    T& pop_front(void);
//
//    virtual // Acceso aleatorio
    T& operator[] (const int&);
//
//    virtual // la lista esta vacia?
    bool empty(void);
//
//    virtual // retorna el tamaño de la lista
    unsigned int size(void);
//
//    virtual // Elimina toda la lista
    void clear(void);
//


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