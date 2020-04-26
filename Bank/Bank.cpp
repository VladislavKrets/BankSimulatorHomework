#include "Bank.h"

#include "utils/List.h"
#include "clients/Client.h"
#include "Bill.h"
#include "iostream"
#include "clients/Admin.h"
#include "exceptions/NoSuchUserException.h"
#include "exceptions/BillAlreadyExistsException.h"
#include "exceptions/NoSuchBillException.h"
#include "exceptions/WrongCommandException.h"
#include "exceptions/TooLowMoneyException.h"

long Bank::getCash() const {
    return cash;
}

void Bank::setCash(long cash) {
    Bank::cash = cash;
}

List<Client *> *Bank::getClients() const {
    return clients;
}

void Bank::setClients(List<Client *> *clients) {
    Bank::clients = clients;
}

Bank::Bank(long cash) : cash(cash) {
    this->clients = new List<Client *>();
    this->bills = new List<Bill *>();
}

List<Bill *> *Bank::getBills() const {
    return bills;
}



void Bank::execute() {
    String * username = new String();
    String * password = new String();
    String * command = new String();
    Client * currentClient = nullptr;
    if (clients->getSize() == 0){
        std::cout << "First initialization. You need to register admin" << std::endl;
        std::cout << "Enter admin username" << std::endl;
        std::cin >> *username;
        std::cout << "Enter admin password" << std::endl;
        std::cin >> *password;
        getClients()->add(new Admin(new String(username->getLine()),
                new String(password->getLine()), this));
    }

    while (true) {
        delete username;
        delete password;
        delete command;
        username = new String();
        password = new String();
        command = new String();
        std::cout << "You need to authorize to use system or to register in it" << std::endl;
        std::cout << "(login, register, exit)" << std::endl;
        std::cin >> *command;

        if (*command == "register") {
            while (true) {
                delete username;
                delete password;
                delete command;
                username = new String();
                password = new String();
                command = new String();
                try {
                    std::cout << "Enter username or print exit:" << std::endl;
                    std::cin >> *username;
                    if (*username == "exit") break;
                    getClientByUsername(username);
                    std::cout << "Such username already exists" << std::endl;
                }
                catch (const NoSuchUserException &e) {
                    std::cout << "Enter password or print exit:" << std::endl;
                    std::cin >> *password;
                    if (*password == "exit") break;
                    getClients()->add(new User(new String(username->getLine()),
                                               new String(password->getLine()), this));
                    break;
                }
            }
        } else if (*command == "login") {
            while (true) {
                delete username;
                delete password;
                delete command;
                username = new String();
                password = new String();
                command = new String();
                try {
                    std::cout << "Enter username or print exit:" << std::endl;
                    std::cin >> *username;
                    if (*username == "exit") break;
                    std::cout << "Enter password or print exit:" << std::endl;
                    std::cin >> *password;
                    if (*password == "exit") break;
                    currentClient = getClientByUsername(username);
                    if (!isLinesEquals(currentClient->getPassword()->getLine(),
                            password->getLine())) {
                        std::cout << "Wrong password" << std::endl;
                        continue;
                    }
                    break;
                }
                catch (const NoSuchUserException &e) {
                    std::cout << "No such user found" << std::endl;
                }
            }
            if (currentClient == nullptr) continue;
            while (true){
                delete username;
                delete password;
                delete command;
                username = new String();
                password = new String();
                command = new String();
                currentClient->printCommands();
                std::cin >> *command;
                if (*command == "exit") break;
                try {
                    currentClient->execute(new String(command->getLine()));
                }
                catch (const NoSuchUserException &e){
                    std::cout << "No such user found " << *e.getUsername() << std::endl;
                }
                catch (const BillAlreadyExistsException &e){
                    std::cout << "Such bill already exists " << e.getBillNumber() << std::endl;
                }
                catch (const NoSuchBillException &e){
                    std::cout << "No such bill found " << e.getBillNumber() << std::endl;
                }
                catch (const TooLowMoneyException &e){
                    std::cout << "Error, too low money" << std::endl;
                }
                catch (const WrongCommandException &e){
                    std::cout << "Wrong command"<< std::endl;
                }
            }
            currentClient = nullptr;
        }
        else if (*command == "exit"){
            break;
        }
        else {
            std::cout << "Wrong command"<< std::endl;
        }
    }
}

Client *Bank::getClientByUsername(String *username) {
    for (int i = 0; i < this->getClients()->getSize(); i++) {
        if (isLinesEquals(getClients()->get(i)->getUsername()->getLine(), username->getLine())){
            return this->getClients()->get(i);
        }
    }
    throw NoSuchUserException();
}


