/*
 * Banking System Ver 0.4
 * 작성자: 김민수
 * 내용: Account 클래스의 사용
*/ 

#include <iostream>
#include "Account.h"
#include "menu.h"
#define ACC_MAX 100
using std::cout;
using std::endl;

class Account;
Account * accArr[ACC_MAX];
int Account::accNum = 0;

int main(int argc, char** argv) {
	while(1)
	{
		switch(ShowMenu())
		{
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				DepositMoney();
				break;
			case WITHDRAW:
				WithdrawMoney();
				break;
			case INQUIRE:
				ShowAllAccInfo();
				break;
			case EXIT:
				for(int i=0; i<Account::accNum; i++)
					delete accArr[i];
				return 0;
			default:
				cout<<"??"<<endl;
		}
	}
	return 0;
}
