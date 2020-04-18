#pragma comment(linker, "/HEAP:2000000")
#include <iostream>
#include "Bank/utils/List.h"
#include "Bank/Bank.h"

using namespace std;

int main() {

    Bank * bank = new Bank(10000000);
    bank->execute();
    return 0;
}