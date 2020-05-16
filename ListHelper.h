//
// Created by Maor Roizman Gheiler on 5/11/20.
//

#ifndef TEST_LISTAS_FINAL_LISTHELPER_H
#define TEST_LISTAS_FINAL_LISTHELPER_H

#include <iostream>
#include "List.h"
#include "Node.h"
#include "forwardNode.h"
#include "doubleNode.h"
#include "circularNode.h"
using namespace std;

template <typename Node, typename ValueNode, int nodeType>
class ListHelper{
public:
    static void push_back(Node** head, Node** tail, ValueNode element, int& size);
    static void push_front(Node** head, Node** tail, ValueNode element, int& size);
    static void pop_back(Node** head, Node** tail, int& size);
    static void print(Node** head, Node** tail, ValueNode element);
    
};



template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,FOWARD_NODE>{
public:
    static void push_back(Node** head, Node** tail, ValueNode element, int& size){

        auto * new_node = new ForwardListNode<ValueNode>(element);
        new_node->value = element;
        new_node->next = nullptr;

        if(*head == nullptr){
            *head = new_node;
            *tail = new_node;
    
        }else{
            auto temp = (*head);
            (*tail)-> next = new_node;
            (*tail) = new_node;
        
        }
        size++;
    }

static void push_front(Node** head, Node** tail, ValueNode element, int& size){
    
        auto * new_node = new ForwardListNode<ValueNode>(element);
        new_node->value = element;
        new_node->next = nullptr;

        if(*head == nullptr){
            *head = new_node;
            *tail = new_node;
    
        }else{
            new_node->next = *head;
            *head = new_node;
            
        }
        size++;
    }
       
        
    static void pop_back(Node** head, Node** tail, int& size){

            if(size > 0){
            auto * temp = (*head);

            for(int i = 0; i < size -2; ++i){
                temp = temp->next;
            }
        
            temp->next = (*head);
            delete (*tail);
            (*tail) = temp;
            
            size--;
        }
    }

    static void print(Node** head, Node** tail, ValueNode element){


    }

};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,DOUBLE_NODE>{
public:
    static void push_back(Node** head, Node** tail, ValueNode element, int& size){

        auto new_node = new DoubleListNode<ValueNode>(element);
        new_node->value = element;

        if (!(*head)) {
            (*head) = new_node;
        } else {
            new_node->prev = (*tail);
            new_node->next = nullptr;
            (*tail)->next = new_node;
        }
        *tail = new_node;
        size++;
    }

    static void pop_back(Node** head, Node** tail, int& size){

        if(size > 0){
            DoubleListNode<ValueNode>* temp = *tail;
            *tail = (*tail)->prev;
            (*tail)->next = nullptr;
            delete temp;
            size--;
        }

    }
};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,CIRCULAR_NODE>{
public:
    static void push_back(Node** head, Node** tail, ValueNode element, int& size){
        
        auto * new_node = new CircularListNode<ValueNode>(element);
        new_node->value = element;
        new_node->next = (*head);
        
        if(*head == nullptr){
            *head = new_node;
            *tail = new_node;
        }else{
            (*tail)->next = new_node;
            (*tail) = new_node;
        }
        size++;
    }

    static void pop_back(Node** head, Node** tail, int& size){
    
          if(size > 0){
            auto * temp = (*head);

            for(int i = 0; i < size -2; ++i){
                temp = temp->next;
            }
        
            temp->next = (*head);
            delete (*tail);
            (*tail) = temp;
            
            size--;
        }
    }

      



  };


template< typename Node>  template <int nodeType>
void List<Node>::__push_back__(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail,
        typename List<Node>::value_t element,
        int& size){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_back(head,tail,element, size);
}

template< typename Node>  template <int nodeType>
void List<Node>::__pop_back__(typename List<Node>::node_t ** head,
                                typename List<Node>::node_t ** tail,
                                int& size){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::pop_back(head,tail,size);
}
template< typename Node>  template <int nodeType>
void List<Node>::__push_front__(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail,
        typename List<Node>::value_t element,
        int& size){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_front(head,tail,element, size);
}

#endif //TEST_LISTAS_FINAL_LISTHELPER_H
