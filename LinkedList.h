#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include"Nodo.h"
template<class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    virtual void registrar(T* dato);
    virtual string toJson(string (*ptr)(T*));
    T* buscar(T&dato);
    virtual bool eliminarDato(T&dato);
    T* operator[](int indice);
protected:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    int ind;
};
template<class T>
LinkedList<T>::LinkedList()
{
    cabeza=NULL;
    cola=NULL;
    ind=0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    
}

template<class T>
void LinkedList<T>::registrar(T* dato)
{
    if(cabeza==NULL){
        cabeza=new Nodo<T>(dato);
        cola=cabeza;
    }
    else{
        cola->setSig(new Nodo<T>(dato));
        cola=cola->getSig();
    }
    ind++;

}

template<class T>
T* LinkedList<T>::operator[](int indice)
{ 
    if(indice==0){
        return cabeza->getDato();
    }
    else if(indice==ind-1){
        return cola->getDato();
    }
    else{
        Nodo<T>* it=cabeza->getSig();
        for(int i=1;i<ind-1;i++){
            if(i==indice) return it->getDato();
            it=it->getSig();
        }
    }
    return NULL;

}

template<class T>
bool LinkedList<T>::eliminarDato(T& dato)
{ 
    Nodo<T>* borrar;
    if(*cabeza->getDato()==dato){
        borrar=cabeza;
        cabeza=cabeza->getSig();

    }
    else{
        Nodo<T>* anterior;
        anterior=cabeza;
        for(Nodo<T>* it=anterior->getSig();it!=NULL;it=it->getSig()){
            if(*it->getDato()==dato){
                borrar=it;
                if(it->getSig()==NULL) cola=anterior;
                anterior->setSig(it->getSig());
            }

            anterior=anterior->getSig();
        }
    }
    ind--;
    if(borrar!=NULL){
     delete borrar;
     return true;
    }
    else return false;


}
template<class T>
string LinkedList<T>::toJson(string (*ptr)(T*))
{
    stringstream ss;
    ss<<"[";
    Nodo<T>* it=cabeza;
    int i=0;
    /*while(it!=NULL){
        ss<<(*ptr)(it->getDato());
        if(i<ind-1)ss<<",";
        i++;
        it=it->getSig();
    }
    */
   for(Nodo<T>* it=cabeza;it!=NULL;it=it->getSig()){
        ss<<(*ptr)(it->getDato());
        if(i<ind-1)ss<<",";
        i++;
   }
    ss<<"]";
    return ss.str();
}

template<class T>
T* LinkedList<T>::buscar(T&dato)
{
    for(Nodo<T>*it=cabeza;it!=NULL;it=it->getSig()){
      if((*it->getDato())==dato){
            return it->getDato();
      }
    }
    return NULL;
}


#endif