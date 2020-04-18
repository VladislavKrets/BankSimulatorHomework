#ifndef BANKSIMULATOR_ADMIN_H
#define BANKSIMULATOR_ADMIN_H

#include "User.h"

namespace AdminParams{};

class Admin : public Client {
    List<Client *> * getAllClients();

public:
    Admin(String *username, String *password, Bank *bank);
    void execute(String * command) override;
    void changeUserUsername(String * username, String * newUsername);
    void changeUserPassword(String * username, String * newPassword);
    List<Bill *> * getUserBills(String * username);
    void printCommands() override;
};

#endif //BANKSIMULATOR_ADMIN_H
