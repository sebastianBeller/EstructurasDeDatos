#ifndef NODODOBLE_H
#define NODODOBLE_H

#pragma once
template<class T>
class NodoDoble
{
public:
    NodoDoble(T* dato);
    ~NodoDoble();
    NodoDoble<T>* getAnterior();
    void setAnterior(NodoDoble<T>* nuevo);
    NodoDoble<T>* getSig();
    void setSig(NodoDoble<T>* nuevo);
    T* getDato();
   
private:
    T* dato;
    NodoDoble<T>* anterior;
    NodoDoble<T>* sig;
};
template<class T>
NodoDoble<T>::NodoDoble(T* dato)
{
    this->dato=dato;
    anterior=NULL;
    sig=NULL;
}

template<class T>
NodoDoble<T>::~NodoDoble()
{
    
}
template<class T>
NodoDoble<T>* NodoDoble<T>::getAnterior()
{
    return anterior;
}

template<class T>
void NodoDoble<T>::setAnterior(NodoDoble<T>* nuevo)
{
    anterior=nuevo;
}

template<class T>
NodoDoble<T>* NodoDoble<T>::getSig()
{
    return sig;
}

template<class T>
void NodoDoble<T>::setSig(NodoDoble<T>* nuevo)
{
    sig=nuevo;
}

template<class T>
T* NodoDoble<T>::getDato()
{
    return dato;
}

#endif