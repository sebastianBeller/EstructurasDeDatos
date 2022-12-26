#ifndef STACK_H
#define STACK_H

#pragma once
#include"Nodo.h"
template<class T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(T* dato);
    void pop();
    T* getTop();
    bool empty();
    void clear();
    

private:
    Nodo<T>* top;
    
};
template<class T>
Stack<T>::Stack()
{
    top=NULL;
}

template<class T>
Stack<T>::~Stack()
{
    
}

template<class T>
void Stack<T>::push(T* dato)
{
    Nodo<T>* nuevo=new Nodo<T>(dato);
    if(!empty())nuevo->setSig(top);
    top=nuevo;
}

template<class T>
void Stack<T>::pop()
{
    if(!empty()){
    Nodo<T>* borrar=top;
    top=top->getSig();
    delete borrar->getDato();
    delete borrar;
    }
}

template<class T>
T* Stack<T>::getTop()
{
    return top->getDato();
}

template<class T>
bool Stack<T>::empty()
{
    return top==NULL;
}

template<class T>
void Stack<T>::clear()
{
    while(!empty())pop();
}


#endif