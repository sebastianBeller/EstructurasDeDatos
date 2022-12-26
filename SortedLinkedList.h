#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include"LinkedList.h"
#pragma once
template<class T>
class SortedLinkedList: public LinkedList<T>
{
public:
    SortedLinkedList(bool(* ptrCmp)(T*,T*));
    void registrar(T* dato);
private:
    bool (*ptrCmp)(T*,T*);
};

template<class T>
void SortedLinkedList<T>::registrar(T* dato)
{
     Nodo<T>* nodoInser;
    if(LinkedList<T>::cabeza==NULL){
        LinkedList<T>::cabeza=new Nodo<T>(dato);
        LinkedList<T>::cola=LinkedList<T>::cabeza;
    }/*
    else if((*ptrCmp)(LinkedList<T>::cola->getDato(),dato)){//dato>LinkedList<T>::cola->Dato
        LinkedList<T>::cola->setSig(new Nodo<T>(dato));
        LinkedList<T>::cola=LinkedList<T>::cola->getSig();
    }*/
    else if(!(*ptrCmp)(LinkedList<T>::cabeza->getDato(),dato)){
         nodoInser=new Nodo(dato);
         nodoInser->setSig(LinkedList<T>::cabeza);
         LinkedList<T>::cabeza=nodoInser;
    }
    else{
       Nodo<T>* anterior=LinkedList<T>::cabeza;
       Nodo<T>* it=LinkedList<T>::cabeza->getSig();
       for(it;it!=NULL;it=it->getSig()){
            if(!(*ptrCmp)(it->getDato(),dato)){//dato<LinkedList<T>::LinkedList<T>::cola->getDato
                break;
            }
            anterior=anterior->getSig();
        }
        nodoInser=new Nodo(dato);
        nodoInser->setSig(it);
        anterior->setSig(nodoInser);
    }
    LinkedList<T>::ind++;
}

template<class T>
 SortedLinkedList<T>::SortedLinkedList(bool(* ptrCmp)(T*,T*)):LinkedList<T>()
 {
   this->ptrCmp=ptrCmp;
}

#endif