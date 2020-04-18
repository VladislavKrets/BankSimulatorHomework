//
// Created by lollipop on 10.04.20.
//

#ifndef BANKSIMULATOR_NOSUCHBILLEXCEPTION_H
#define BANKSIMULATOR_NOSUCHBILLEXCEPTION_H


#include <exception>

class NoSuchBillException: public std::exception {

long billNumber;

public:
    NoSuchBillException(long billNumber);

    long getBillNumber() const;
};


#endif //BANKSIMULATOR_NOSUCHBILLEXCEPTION_H
