#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#pragma once
#include"LinkedList.h"
template<class T>
class CircularLinkedList:public LinkedList<T>
{
public:
    CircularLinkedList();
    ~CircularLinkedList();
    void registrar(T* dato);
    string toJson(string (*ptr)(T*));
    bool eliminarDato(T&dato);

};
template<class T>
CircularLinkedList<T>::CircularLinkedList():LinkedList<T>()
{
    
}

template<class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    
}

template<class T>
void CircularLinkedList<T>::registrar(T* dato)
{
    if(LinkedList<T>::cabeza==NULL){
       LinkedList<T>::cabeza=new Nodo<T>(dato);
       LinkedList<T>::cabeza->setSig(LinkedList<T>::cabeza);
       LinkedList<T>::cola=LinkedList<T>::cabeza;
    }
    else{
        Nodo<T>* nuevo= new Nodo<T>(dato);
        LinkedList<T>::cola->setSig(nuevo);
        nuevo->setSig(LinkedList<T>::cabeza);
        LinkedList<T>::cola=nuevo;
    }
    LinkedList<T>::ind++;
}

template<class T>
string CircularLinkedList<T>::toJson(string (*ptr)(T*))
{
    
    stringstream ss;
    ss<<"[";
    int i=1;
    /*while(it!=NULL){
        ss<<(*ptr)(it->getDato());
        if(i<LinkedList<T>::ind-1)ss<<",";
        i++;
        it=it->getSig();
    }
    */
   if(LinkedList<T>::cabeza!=NULL){
     ss<<(*ptr)(LinkedList<T>::cabeza->getDato())<<",";
   for(Nodo<T>* it=LinkedList<T>::cabeza->getSig();it!=LinkedList<T>::cabeza;it=it->getSig()){
        ss<<(*ptr)(it->getDato());
        if(i<LinkedList<T>::ind-1)ss<<",";
        i++;
   }
   }
    ss<<"]";
    return ss.str();    
}

template<class T>
bool CircularLinkedList<T>::eliminarDato(T&dato)
{
    
}


#endif