#ifndef BANKSIMULATOR_USER_H
#define BANKSIMULATOR_USER_H

#include "Client.h"
#include "iostream"
#include "../utils/List.h"

class Bill;
namespace UserParams{
};
class User : public Client {
    List<Bill *> * bills;

public:
    User(String *username, String *password, Bank *bank);

    void execute(String * command) override;

    List<Bill *> *getBills() const;

    Bill * addBill(long number);

    Bill * addBill(long number, long cash);

    Bill * getBillByNumber(List<Bill *> * bills, long number);

    void sendMoney (long billNumber, long currentBillNumber, long cash);

    void printCommands() override;
};



#endif //BANKSIMULATOR_USER_H
