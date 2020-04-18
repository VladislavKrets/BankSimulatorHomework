//
// Created by lollipop on 22.03.20.
//

#ifndef BANKSIMULATOR_BILL_H
#define BANKSIMULATOR_BILL_H

#include "clients/User.h"
#include "iostream"

class Bill {
    long number;
    long cash;
    User * user;

public:
    Bill(long number, long cash, User * user);

    Bill(long number, User * user);

    long getNumber() const;

    long getCash() const;

    void setCash(long cash);

    void addCash(long cash);

    void sendCash(long cash, Bill * bill);

    void toString();
};


#endif //BANKSIMULATOR_BILL_H
