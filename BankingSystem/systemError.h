#ifndef systemError
#define systemError
#define MIN_BALANCE 500

class InsufficientBalance{
	public : 
	void message(){
		std :: cout << "\nYou have to deposit atleast "  << MIN_BALANCE << " to open an account !!" << std :: endl;
		std :: cout << std :: endl;
	}
	void withdrawalUnsuccess(){
		std :: cout << "\nTransaction Failed" << std :: endl;
		std :: cout << "Insufficient Balance !!" << std :: endl << std :: endl;
	}
};

class AccountNotFound{
public:
	void notFound(){
		std :: cout << "\nAccount Not Found !" << std :: endl << std :: endl;
	}

	void noAccountFound(){
		std :: cout << "\n No Account Found !" << std :: endl << std :: endl;
	}
};

#endif