//
// Created by ivaniuss on 4/20/20.
//

#pragma once
#include "Node.h"
namespace container{

    template <typename T>
    class iterator{
    private:
        typedef Node<T> node;
        node * pointer;

    public:
        iterator(){ pointer = nullptr; }
        explicit iterator(node * ptr) { this->pointer = ptr; }

        void operator ++(){
            this->pointer = this->pointer->nextNode;
        }

        T operator * (){
            return this->pointer->value;
        }

        bool operator == (const iterator & it){
            return this->pointer == it.pointer;
        }

        bool operator != (const iterator & it){
            return this->pointer != it.pointer;
        }
    };



    template <typename T>
    class iterator2{
    private:
        typedef NodeD<T> node;
        node * pointer;
    public:
        iterator2(){ pointer = nullptr; }
        explicit iterator2(node * ptr) { this->pointer = ptr; }

        void operator ++(){
            this->pointer = this->pointer->nextNode;
        }

        T operator * (){
            return this->pointer->value;
        }

        bool operator == (const iterator2 & it){
            return this->pointer == it.pointer;
        }

        bool operator != (const iterator2 & it){
            return this->pointer != it.pointer;
        }
    };

}
