//
// Created by lollipop on 10.04.20.
//

#include "BillAlreadyExistsException.h"

BillAlreadyExistsException::BillAlreadyExistsException(long billNumber) {
    this->billNumber = billNumber;
}

long BillAlreadyExistsException::getBillNumber() const{
    return this->billNumber;
}
