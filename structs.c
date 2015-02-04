#include <stdio.h>
struct account 
{
	char *account_holder; 
	double balance; 
	double interest_rate;
};

int main(int argc, char* argv[]) 
{
// Structs have a special initialization syntax:
	struct account my_account = {"John Smith" , 1000.0 , 0.03}; 
	printf("Account holder: %s\n", my_account.account_holder); 
	printf("Account balance: %f\n", my_account.balance);
// Withdraw some funds :
	my_account.balance = my_account.balance - 35.0;
	printf("New account balance: %f\n", my_account.balance);
}