#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accId;
	int balance;
	char* cusName;

public:
	static int accNum;
	Account(int id, int money, char* name);
	Account(const Account &);
	int GetAccId(void) const;
	int GetBalance(void) const;
	char* GetCusName(void) const;
	void Deposit(int);
	int Withdraw(int);
	void ShowAccInfo(void) const;
	~Account(void);
};

#endif
