cmake_minimum_required(VERSION 3.12)
project(BankSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankSimulator main.cpp Bank/Bank.cpp Bank/Bank.h Bank/clients/Client.cpp Bank/clients/Client.h Bank/utils/String.cpp Bank/utils/Utils.cpp Bank/utils/Utils.h Bank/utils/String.h Bank/utils/List.cpp Bank/utils/List.h Bank/Bill.cpp Bank/Bill.h Bank/clients/Admin.cpp Bank/clients/Admin.h Bank/clients/User.cpp Bank/clients/User.h Bank/exceptions/NoSuchUserException.h Bank/exceptions/WrongCommandException.h Bank/exceptions/NoSuchUserException.cpp Bank/exceptions/NoSuchBillException.cpp Bank/exceptions/NoSuchBillException.h Bank/exceptions/BillAlreadyExistsException.cpp Bank/exceptions/BillAlreadyExistsException.h)