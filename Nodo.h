#ifndef NODO_H
#define NODO_H

#pragma once
#include<iostream>
#include<sstream>
using namespace std;
template<class T>
class Nodo
{
public:
    Nodo(T*dato);
    ~Nodo();
    T* getDato();
    Nodo<T>* getSig();
    void setDato(T* dato);
    void setSig(Nodo<T>* sig);
protected:
    T *dato;
    Nodo<T> * sig;
};
template<class T>
Nodo<T>::Nodo(T*dato)
{
    this->dato=dato;
    sig=NULL;
}

template<class T>
Nodo<T>::~Nodo()
{
    
}

template<class T>
T* Nodo<T>::getDato()
{
    return dato;
}

template<class T>
Nodo<T>* Nodo<T>::getSig()
{
    return sig;
}

template<class T>
void Nodo<T>::setDato(T* dato)
{
    this->dato=dato;
}

template<class T>
void Nodo<T>::setSig(Nodo<T>* sig)
{
    this->sig=sig;
}



#endif