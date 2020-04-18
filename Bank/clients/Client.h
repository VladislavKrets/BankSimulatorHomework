#ifndef BANKSIMULATOR_CLIENTS_H
#define BANKSIMULATOR_CLIENTS_H

#include "../utils/String.h"
#include "../utils/Utils.h"
class Bank;

class Client {
    String *username;
    String *password;
    Bank *bank;

public:

    Client(String *username, String *password, Bank *bank);

    virtual void execute(String * command) = 0;

    virtual void printCommands() = 0;

    void setUsername(String *username);

    void setPassword(String *password);

    String *getUsername() const;

    String *getPassword() const;

    Bank *getBank() const;

};
#endif //BANKSIMULATOR_CLIENTS_H
