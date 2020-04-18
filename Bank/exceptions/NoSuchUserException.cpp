//
// Created by lollipop on 10.04.20.
//
#include "NoSuchUserException.h"

NoSuchUserException::NoSuchUserException(String *username){
    this->username = new String(username->getLine());
}

NoSuchUserException::NoSuchUserException(){
    this->username = new String("");
}

String* NoSuchUserException::getUsername() const{
    return this->username;
}
