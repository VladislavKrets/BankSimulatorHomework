//
// Created by lollipop on 10.04.20.
//

#include "NoSuchBillException.h"

NoSuchBillException::NoSuchBillException(long billNumber) {
    this->billNumber = billNumber;
}

long NoSuchBillException::getBillNumber() const{
    return this->billNumber;
}
