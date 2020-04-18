#include "Admin.h"
#include "iostream"
#include "../Bank.h"
#include "../exceptions/NoSuchUserException.h"
#include "../exceptions/WrongCommandException.h"

namespace AdminParams {
    const char * CHANGE_USERNAME = "change_username";
    const char * CHANGE_PASSWORD = "change_password";
    const char * GET_USER_BILLS = "get_user_bills";
    const char * GET_ALL_CLIENTS = "get_all_clients";
};

void Admin::changeUserPassword(String *username, String *newPassword) {
    List<Client *> * clients = getAllClients();

    for(int i = 0; i < clients->getSize(); i++){
        if (isLinesEquals(clients->get(i)->getUsername()->getLine(),
                          username->getLine())){
            clients->get(i)->setPassword(newPassword);
            return;
        }
    }
    throw NoSuchUserException(username);
}

void Admin::changeUserUsername(String *username, String *newUsername) {
    List<Client *> * clients = getAllClients();

    for(int i = 0; i < clients->getSize(); i++){
        if (isLinesEquals(clients->get(i)->getUsername()->getLine(),
                          username->getLine())){
            clients->get(i)->setUsername(newUsername);
            return;
        }
    }
    throw NoSuchUserException(username);
}

Admin::Admin(String *username, String *password, Bank *bank)
: Client(username, password, bank) {
    std::cout << "You have been authorized as administrator" << std::endl;
}

void Admin::execute(String * comm) {
    String * username = new String();
    String * newUsername = new String();
    List<Bill *> * bills  = nullptr;
    List<Client *> * clients = nullptr;
    String command = *comm;

    if (command == AdminParams::CHANGE_USERNAME){
        std::cout << "Enter username:" << std::endl;
        std::cin >> *username;
        std::cout << "Enter new username:" << std::endl;
        std::cin >> *newUsername;
        changeUserUsername(new String(username->getLine()),
                new String(newUsername->getLine()));
        std::cout << "Ok" << std::endl;
    } else if (command == AdminParams::CHANGE_PASSWORD){
        std::cout << "Enter username:" << std::endl;
        std::cin >> *username;
        std::cout << "Enter new password:" << std::endl;
        std::cin >> *newUsername;
        changeUserPassword(new String(username->getLine()),
                new String(newUsername->getLine()));
        std::cout << "Ok" << std::endl;
    } else if (command == AdminParams::GET_USER_BILLS){
        std::cout << "Enter username:" << std::endl;
        std::cin >> *username;
        bills = this->getUserBills(username);
        for (int i = 0; i < bills->getSize(); i++){
            bills->get(i)->toString();
        }
    } else if (command == AdminParams::GET_ALL_CLIENTS){
        clients = getAllClients();
        for (int i = 0; i < clients->getSize(); i++){
            std::cout << *clients->get(i)->getUsername() << std::endl;
        }
    } else {
        delete username;
        delete  newUsername;
        throw WrongCommandException();
    }
    delete username;
    delete  newUsername;
}

List<Client *> *Admin::getAllClients() {
    return this->getBank()->getClients();
}

List<Bill *> *Admin::getUserBills(String *username) {
    List<Client *> * clients = getAllClients();

    for(int i = 0; i < clients->getSize(); i++){
        if (instanceof<User *>(clients->get(i))
                && isLinesEquals(clients->get(i)->getUsername()->getLine(),
                          username->getLine())){
            User * user = (User *) clients->get(i);
            return user->getBills();
        }
    }
    throw NoSuchUserException(username);
}

void Admin::printCommands() {
    std::cout << "This is your command panel. You can enter some of this commands" << std::endl;
    std::cout << "(change_username, change_password, get_user_bills, get_all_clients)" << std::endl;
}
