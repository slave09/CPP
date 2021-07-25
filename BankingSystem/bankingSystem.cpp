#include <iostream>
#include <fstream>
#include <map>
#include "systemError.h"
using namespace std;

class Account{
private:
	static long account_id;
	long accountNumber;
	string firstName;
	string lastName;
	float balance;

public:
	Account(){}
	Account(string firstName, string lastName, float balance);

	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setBalance(float balance);
	void setAccountNumber();

	static long getAccoundId(){return account_id;}
	long getAccountNumber(){return accountNumber;}

	void deposite(float amount);
	void withdraw(float amount);

	friend ostream & operator<<(ostream & out, Account &acc);
	friend ofstream & operator<<(ofstream & ofs, Account &acc);
	friend ifstream & operator>>(ifstream & ifs, Account &acc);

	~Account(){}
};

class Bank{
	map<long, Account>customer;
public:
	Bank();
	Account openAccount(string firstName, string lastName, float balance);
	Account BalanceEnquiry(long accountNumber);
	Account withdraw(long accountNumber, float amount);
	Account deposit(long accountNumber, float amount); 
	void closeAccount(long accountNumber);
	void showAllAccounts();

	~Bank();
};

int main()
{	
	int choice;
	string firstName, lastName;
	float balance;
	long accountNumber;
	cout << "Banking System" << endl 	<< endl;
	do{
		cout << "Select one option below." << endl;
		cout << 1 << ". open an account" << endl;
		cout << 2 << ". Balance Enquiry" << endl;
		cout << 3 << ". Deposit" << endl;
		cout << 4 << ". Withdrawal" << endl;
		cout << 5 << ". Close an account" << endl;
		cout << 6 << ". Show all accounts" << endl;
		cout << 7 << ". Quit" << endl << endl;
		cout << "Enter your choice " << endl;
		cin >> choice;
		Bank bank;
		Account account;
		switch(choice){
			case 1 : 
			try{
				cout << "Enter First Name : " << endl;
				cin >> firstName;
				cout << "Enter Last Name : " << endl;
				cin >> lastName;
				cout << "Enter balance : " << endl;
				cin >> balance;
				account = bank.openAccount(firstName, lastName, balance); 
				cout << account << endl;
			}
			catch(InsufficientBalance err) {err.message();}
			break;
			case 2 :
			try{			
				cout << "Enter Account Number : " << endl;
				cin >> accountNumber;
				account = bank.BalanceEnquiry(accountNumber);
				cout << account << endl; 
			}
			catch(AccountNotFound err) {err.notFound();}
			break;
			case 3 :
			try{
				cout << "Enter account number : " << endl;
				cin >> accountNumber;
				cout << "Enter value to be deposited : " << endl;
				cin >> balance;
				account = bank.deposit(accountNumber, balance);
				cout << account << endl;
			}
			catch(AccountNotFound err) {err.notFound();}
			break;
			case 4 :
			try{
				cout << "Enter Account Number " << endl;
				cin >> accountNumber;
				cout << "Enter value to be withdraw : " << endl;
				cin >> balance;
				account = bank.withdraw(accountNumber, balance);
				cout << account << endl;
			}
			catch(AccountNotFound err) {err.notFound();}
			catch(InsufficientBalance err){ err.withdrawalUnsuccess();}
			break;
			case 5 :
			try{
				cout << "Enter Account Number " << endl;
				cin >> accountNumber;
				bank.closeAccount(accountNumber);
			}
			catch(AccountNotFound err) {err.notFound();}
			break;
			case 6 :
			try{bank.showAllAccounts();}
			catch(AccountNotFound err){err.noAccountFound();}
			break;
			case 7 : break;
			default :
			cout << "Invalid choice !" << endl;
			break;
		}
	}while(choice != 7);
	return 0;
}

long Account :: account_id = 0;

Account :: Account(string firstName, string lastName, float balance){

	account_id++;	
	setFirstName(firstName);
	setLastName(lastName);
	setBalance(balance);
	setAccountNumber();
}


void Account :: setFirstName(string firstName){
	this -> firstName = firstName;
}

void Account :: setLastName(string lastName){
	this -> lastName = lastName;
}

void Account :: setBalance(float balance){
	this -> balance = balance >= MIN_BALANCE ? balance : throw InsufficientBalance();
}

void Account :: setAccountNumber(){
	accountNumber = getAccoundId();
}

void Account :: deposite(float balance){
	this -> balance += balance;
}

void Account :: withdraw(float balance){
	if(this -> balance < balance) throw InsufficientBalance();
	this -> balance -= balance;
}

ostream & operator<<(ostream & out, Account &acc){
	out << "Full Name       : " << acc.firstName << " " << acc.lastName << endl;
	out << "Account Number 	: " << acc.getAccountNumber() << endl;
	out << "Current Balance : " << acc.balance << endl;
	return out;
}

ofstream & operator<<(ofstream & ofs, Account &acc){
	ofs << acc.firstName << endl;
	ofs << acc.lastName << endl;
	ofs << acc.accountNumber << endl;
	ofs << acc.balance << endl;
	return ofs;
}

ifstream & operator>>(ifstream & ifs, Account &acc){
	ifs >> acc.firstName ;
	ifs >> acc.lastName;
	ifs >> acc.accountNumber;
	ifs >> acc.balance;
	return ifs;
}

Bank :: Bank(){
	Account account;

	ifstream readfile;
	readfile.open("bank.txt");

	if(!readfile.is_open()) return ;

	while(!readfile.eof()){
		readfile >> account;
		customer[account.getAccountNumber()] = account;
	}
	readfile.close();
}

Account Bank :: openAccount(string firstName, string lastName, float balance){
	Account account(firstName, lastName, balance);

	customer[account.getAccountNumber()] = account;

	ofstream bankFile("bank.txt", ios :: trunc);

	for(auto itr = customer.begin(); itr != customer.end(); ++itr){
		bankFile << itr -> second;
	}

	bankFile.close();
	cout << "\nAccount created successfully " << endl;
	return account;
}

void Bank :: closeAccount(long accountNumber){
	auto itr = customer.find(accountNumber);
	if(itr == customer.end()) throw AccountNotFound();
	customer.erase(itr);
	cout << "Account closed successfully ! " << endl;
}

Account Bank :: BalanceEnquiry(long accountNumber){
	auto itr = customer.find(accountNumber);
	if(itr == customer.end()) throw AccountNotFound();
	return itr -> second;
}

Account Bank :: withdraw (long accountNumber, float amount){
	auto itr = customer.find(accountNumber);
	if(itr == customer.end()) throw AccountNotFound();
	itr -> second.withdraw(amount);
	cout << amount << " Value withdrawn !" << endl;
	return itr -> second;
}

Account Bank :: deposit (long accountNumber, float amount){
	auto itr = customer.find(accountNumber);
	if(itr == customer.end()) throw AccountNotFound();
	itr -> second.deposite(amount);
	cout << amount << " Value deposited ! " << endl;
	return itr -> second;
}

void Bank :: showAllAccounts(){
	if(customer.size() == 0) throw AccountNotFound();
	for(auto itr = customer.begin(); itr != customer.end(); ++itr){
		cout << "Account " << itr -> first << endl;
		cout << itr -> second << endl;
	}
}

Bank :: ~Bank(){
	ofstream bankData("bank.txt", ios :: trunc);
	for(auto i = customer.begin(); i != customer.end(); ++i){
		bankData << i -> second;
	}
	bankData.close();
}

