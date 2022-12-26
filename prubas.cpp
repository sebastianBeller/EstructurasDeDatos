#include"LinkedList.h"
#include"SortedLinkedList.h"
#include"DoubleLinkedList.h"
#include"CircularLinkedList.h"
#include"Stack.h"
string toJson(int * num){
   stringstream ss;
   ss<<"{\"numero\":"<<*num<<"}";
   return ss.str();
}
bool cmp(int *i1,int *i2){
  return (*i2)>(*i1);
}
int main(){
  LinkedList<int> lista;
  for(int i=0;i<10;i++){
    lista.registrar(new int(i));
  }

  cout<<lista.toJson(toJson)<<endl;
  int bus=9;
  int * encontrado=lista.buscar(bus);
  cout<<toJson(encontrado)<<endl;
  if(lista.eliminarDato(bus)){
  lista.registrar(new int(10));
  cout<<lista.toJson(toJson)<<endl;
  cout<<toJson(lista[9])<<endl;
  }
  SortedLinkedList<int>lista2(cmp);
  /*for(int i=0;i<10;i++){
    lista2.registrar(new int(i));
  }*/
  lista2.registrar(new int(1));
  lista2.registrar(new int(2));
  lista2.registrar(new int(0));
  lista2.registrar(new int(8));
  lista2.registrar(new int(5));
  lista2.registrar(new int(9));
  lista2.registrar(new int(4));
  lista2.registrar(new int(7));
  lista2.registrar(new int(3));
  lista2.registrar(new int(6));
  lista2.eliminarDato(bus);
  cout<<lista2.toJson(toJson)<<endl;
  
  /////
  DoubleLinkedList<int> lista3;
  lista3.registrar(new int(1));
  lista3.registrar(new int(2));
  lista3.registrar(new int(3));
  lista3.registrar(new int(4));
  cout<<lista3.toJson(toJson)<<endl;
  cout<<*lista3.buscar(*new int(1))<<endl;
  if(lista3.eliminarDato(*new int(1))) cout<<lista3.toJson(toJson)<<endl;
  else cout<<"NO"<<endl;
  CircularLinkedList<int> lista4;
  lista4.registrar(new int(1));
  lista4.registrar(new int(2));
  lista4.registrar(new int(3));
  lista4.registrar(new int(4));
  cout<<lista4.toJson(toJson)<<endl;
  ///// stack
  Stack<int> pila;
  pila.push(new int(1));
  pila.push(new int(2));
  pila.push(new int(3));
  pila.push(new int(4));
  pila.clear();
  while(!pila.empty()){
    cout<<toJson(pila.getTop());
    pila.pop();
    if(!pila.empty())cout<<",";
  }
  cout<<pila.empty()<<endl;
  
  
}