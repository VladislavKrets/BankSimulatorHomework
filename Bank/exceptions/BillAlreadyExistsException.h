//
// Created by lollipop on 10.04.20.
//

#ifndef BANKSIMULATOR_BILLALREADYEXISTSEXCEPTION_H
#define BANKSIMULATOR_BILLALREADYEXISTSEXCEPTION_H

#include <exception>

class BillAlreadyExistsException: public std::exception {
    long billNumber;

public:
    BillAlreadyExistsException(long billNumber);

    long getBillNumber() const;
};


#endif //BANKSIMULATOR_BILLALREADYEXISTSEXCEPTION_H
