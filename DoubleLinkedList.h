#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#pragma once
#include"NodoDoble.h"
template<class T>
class DoubleLinkedList
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void registrar(T* dato);
    T* buscar(T& dato);
    string toJson(string (*ptr)(T*));
    bool eliminarDato(T&dato);


private:
    NodoDoble<T>* cabeza;
    NodoDoble<T>* cola; 
    int ind;
};
template<class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    ind=0;
    cabeza=NULL;
    cola=NULL;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    
}

template<class T>
void DoubleLinkedList<T>::registrar(T* dato)
{
    if(cabeza==NULL){
        cabeza=new NodoDoble<T>(dato);
        cola=cabeza;
    }
    else{
        NodoDoble<T>* nuevo=new NodoDoble<T>(dato);
        cola->setSig(nuevo);
        nuevo->setAnterior(cola);
        cola=nuevo;
        /*for(NodoDoble<T>* it=cabeza;it->getSig()!=NULL;it=it->getSig()){
        }*/
    }
    ind++;
}

template<class T>
string DoubleLinkedList<T>::toJson(string (*ptr)(T*))
{
    stringstream ss;
    int i=0;
    ss<<"[";
    for(NodoDoble<T>* it=cola;it!=NULL;it=it->getAnterior()){
            ss<<(*ptr)(it->getDato());
            if(i<ind-1)ss<<",";
            i++;
    }
    ss<<"]";
    return ss.str();
}

template<class T>
T* DoubleLinkedList<T>::buscar(T& dato)
{
    for(NodoDoble<T>* it=cola;it!=NULL;it=it->getAnterior()){
            if(*it->getDato()==dato) return it->getDato();
    }
    return NULL;
}

template<class T>
bool DoubleLinkedList<T>::eliminarDato(T& dato)
{
    NodoDoble<T>* borrar=NULL;
    if(*cabeza->getDato()==dato){
            borrar=cabeza;
            cabeza=cabeza->getSig();
            cabeza->setAnterior(NULL);
    }
    else{
        for(NodoDoble<T>* it=cabeza;it!=NULL;it=it->getSig()){
            if(*it->getDato()==dato){
                borrar=it;
                NodoDoble<T>* anterior =it->getAnterior();
                anterior->setSig(it->getSig());
                if(it->getSig()!=NULL)it->getSig()->setAnterior(anterior);
                else cola=anterior;
            }
        }
    }
    if(borrar!= NULL){
         ind--;
         delete borrar;
         return true;
    }
    return false;
}
#endif