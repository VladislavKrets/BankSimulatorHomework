//
// Created by lollipop on 22.03.20.
//

#include "User.h"
#include "../Bill.h"
#include "../Bank.h"
#include "../exceptions/WrongCommandException.h"
#include "../exceptions/NoSuchBillException.h"
#include "../exceptions/BillAlreadyExistsException.h"

namespace UserParams{
    const char * SEND_MONEY = "send_money";
    const char * OPEN_BILL = "open_bill";
    const char * ADD_MONEY = "add_money";
    const char * GET_MONEY = "get_money";
    const char * BILLS_LIST = "bills_list";
};

User::User(String *username, String *password, Bank *bank)
        : Client(username, password, bank) {
    this->bills = new List<Bill *>();
}

List<Bill *> *User::getBills() const {
    return bills;
}

Bill *User::addBill(long number) {
    Bill *bill = addBill(number, 0);
    return bill;
}

Bill *User::addBill(long number, long cash) {
    List<Bill *> *bills = this->getBank()->getBills();
    Bill *bill;
    try {
        bill = getBillByNumber(bills, number);
        throw BillAlreadyExistsException(number);
    }
    catch (const NoSuchBillException & e){
        bill = new Bill(number, cash, this);
        this->getBills()->add(bill);
        getBank()->getBills()->add(bill);
        return bill;
    }
}

Bill *User::getBillByNumber(List<Bill *> *bills, long number) {
    Bill *bill = nullptr;
    for (int i = 0; i < bills->getSize(); i++) {
        if (bills->get(i)->getNumber() == number) {
            bill = bills->get(i);
            return bill;
        }
    }
    throw NoSuchBillException(number);
}

void User::sendMoney(long billNumber, long currentBillNumber, long cash) {
    List<Bill *> *bills = this->getBank()->getBills();
    Bill *bill = getBillByNumber(bills, billNumber);
    Bill *currentBill = getBillByNumber(getBills(), currentBillNumber);
    currentBill->sendCash(cash, bill);
    std::cout << "Operation completed successfully" << std::endl;
}

void User::execute(String * comm) {
    Bill *bill = nullptr;
    long thisBillNumber = 0;
    long thatBillNumber = 0;
    long cash = 0;
    String temp;
    String command = *comm;
    if (command == UserParams::SEND_MONEY) {
        std::cout << "Enter your billNumber you want to send money from: " << std::endl;
        std::cin >> thisBillNumber;
        std::cout << "Enter your billNumber you want to send money to: " << std::endl;
        std::cin >> thatBillNumber;
        std::cout << "Enter amount of money you want to send: " << std::endl;
        std::cin >> cash;
        sendMoney(thatBillNumber, thisBillNumber, cash);
    } else if (command == UserParams::OPEN_BILL) {
        while (bill == nullptr) {
            std::cout << "Enter bill number: " << std::endl;
            std::cin >> temp;
            thisBillNumber = temp.parseLong();
            bill = addBill(thisBillNumber);
            std::cout << "Ok" << std::endl;
        }
    } else if (command == UserParams::ADD_MONEY) {
        std::cout << "Enter bill number: " << std::endl;
        std::cin >> temp;
        thisBillNumber = temp.parseLong();
        bill = getBillByNumber(this->bills, thisBillNumber);
        if (bill == nullptr) {
            std::cout << "No such bill found" << std::endl;
        } else {
            std::cout << "Enter money amount to add: " << std::endl;
            std::cin >> temp;
            cash = temp.parseLong();
            bill->addCash(cash);
        }
    } else if (command == UserParams::GET_MONEY) {
        std::cout << "Enter bill number: " << std::endl;
        std::cin >> temp;
        thisBillNumber = temp.parseLong();
        bill = getBillByNumber(this->bills, thisBillNumber);
        if (bill == nullptr) {
            std::cout << "No such bill found" << std::endl;
        } else {
            std::cout << "Enter money amount to get: " << std::endl;
            std::cin >> temp;
            cash = temp.parseLong();
            bill->addCash(-cash);
        }

    } else if (command == UserParams::BILLS_LIST) {
        for (int i = 0; i < this->bills->getSize(); i++) {
            this->bills->get(i)->toString();
        }
    } else {
        throw WrongCommandException();
    }
}

void User::printCommands() {
    std::cout << "This is your command panel. You can enter some of this commands" << std::endl;
    std::cout << "(send_money, open_bill, add_money, get_money, bills_list, exit)" << std::endl;
}




