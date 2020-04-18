#include "Client.h"

Client::Client(String *username, String *password, Bank *bank) {
    this->username = username;
    this->password = password;
    this->bank = bank;
}

void Client::setUsername(String *username) {
    delete Client::username;
    Client::username = username;
}

void Client::setPassword(String *password) {
    delete Client::password;
    Client::password = password;
}

String *Client::getUsername() const {
    return username;
}

String *Client::getPassword() const {
    return password;
}

Bank *Client::getBank() const {
    return bank;
}

