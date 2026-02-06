#ifndef _ACCOUNTS_HPP
#define _ACCOUNTS_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include "ServiceFunñtion.hpp"
#include <unordered_set>
extern size_t userSize ;
extern std::string currentStatus;
extern unsigned int currentId;
extern std::string* loginArr;
extern std::string* passArr;
extern std::string* userStatus;
extern double* awardArr;
extern double* fineArr;
extern unsigned int* userId;

extern std::unordered_set<char> loginSymbols;
extern std::unordered_set<char> passSymbols;
extern bool isSetCreated;



void ChangeAccounts();
void CreatNewUser();
void CreatSet();



#endif //!_ACCOUNTS_HPP_
