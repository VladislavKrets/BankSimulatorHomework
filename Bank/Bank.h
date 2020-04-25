#ifndef BANKSIMULATOR_BANK_H
#define BANKSIMULATOR_BANK_H

#include "utils/List.h"
#include "Bill.h"

class Client;

class Bank{
    long cash = 0;
    List<Client *> *  clients;
    List<Bill *> * bills;

public:
    Bank(long cash);

    long getCash() const;

    void setCash(long cash);

    List<Client *> *getClients() const;

    void setClients(List<Client *> *clients);

    List<Bill *> *getBills() const;

    void execute();

    Client * getClientByUsername(String * username);
};


#endif //BANKSIMULATOR_BANK_H
