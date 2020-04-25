//
// Created by lollipop on 22.03.20.
//

#include "Bill.h"
#include "clients/User.h"
#include "exceptions/TooLowMoneyException.h"

Bill::Bill(long number, long cash, User * user) : number(number), cash(cash), user(user) {}

Bill::Bill(long number, User * user) : number(number), cash(0), user(user) {}

long Bill::getNumber() const {
    return number;
}

long Bill::getCash() const {
    return cash;
}

void Bill::setCash(long cash) {
    Bill::cash = cash;
}

void Bill::addCash(long cash) {
    if (Bill::cash + cash < 0) {
        throw TooLowMoneyException();
    }
    else {
        Bill::cash += cash;
        std::cout << "Operation was successful" << std::endl;
    }
}

void Bill::sendCash(long cash, Bill *bill) {
    this->addCash(-cash);
    bill->addCash(cash);
}

void Bill::toString() {
    String * str = new String("Username: ");
    char number[22];
    sprintf(number, "%ld", this->number);
    char cash [22];
    sprintf(cash, "%ld", this->cash);
    std::cout << *str << *user->getUsername() << "\n\tBill number: "
    << number << "\n\tCash: " << cash << std::endl;
}
