#include <iostream>
#include <cstring>
#include "Account.h"
using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

Account::Account(int id, int money, char* name)
	: accId(id), balance(money)
{
	cusName = new char[strlen(name)+1];
	strcpy(cusName, name);
};

Account::Account(const Account & copy)
	: accId(copy.accId), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName)+1];
	strcpy(cusName, copy.cusName);
};

int Account::GetAccId() const	{ return accId;	}

int Account::GetBalance() const	{ return balance; }

char* Account::GetCusName() const	{ return cusName; }

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if(balance < money)
		return 0;
	
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout<<"°èÁÂID: "<<GetAccId()<<endl;
	cout<<"ÀÌ ¸§: "<<GetCusName()<<endl;
	cout<<"ÀÜ ¾×: "<<GetBalance()<<endl;
}

Account::~Account()
{
	delete []cusName;
}
