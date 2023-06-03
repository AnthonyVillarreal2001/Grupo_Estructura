#include "Cnodo.h"
#include <iostream>

Cnodo::Cnodo(int ent, Cnodo *sig=NULL){
    this->entrada=ent;
    this->siguiente=sig;
}
Cnodo::~Cnodo(){
    delete siguiente;
}
int Cnodo::getEntrada(){
    return entrada;
}

Cnodo* Cnodo::getSiguiente(){
    return siguiente;
}
void Cnodo::setEntrada(int entr){
    this->entrada=entr;
}
void Cnodo::setSiguiente(Cnodo *sig){
    this->siguiente=sig;
}