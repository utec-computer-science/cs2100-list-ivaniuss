//
// Created by ivaniuss on 4/17/20.
//

#pragma once
template <typename T>
class Node {
public:
    T value;
    Node<T> * next;
    Node(void){next = nullptr;}
//    Node(const T & v, const Node<T>* &n) : value(v), next(n){};
    ~Node(void){ next = nullptr;}
};
