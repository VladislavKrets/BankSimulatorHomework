//
// Created by lollipop on 10.04.20.
//

#ifndef BANKSIMULATOR_NOSUCHUSEREXCEPTION_H
#define BANKSIMULATOR_NOSUCHUSEREXCEPTION_H


#include <exception>
#include "../utils/String.h"
class NoSuchUserException: public std::exception {
    String * username;
public:

    NoSuchUserException();

    NoSuchUserException(String * username);

    String * getUsername() const;
};


#endif //BANKSIMULATOR_NOSUCHUSEREXCEPTION_H
