#ifndef __MENU_H__
#define __MENU_H__

#include "Account.h"
extern Account * accArr[];

int ShowMenu(void);		// 메뉴출력 
void MakeAccount(void);		// 계좌 개설 
void DepositMoney(void);	// 입금 
void WithdrawMoney(void);	// 출금 
void ShowAllAccInfo(void);	// 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

#endif 
