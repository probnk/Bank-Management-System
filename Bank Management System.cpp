#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstdio>

using namespace std; 	
	
	// ===========================================User Defined Functions
	int menu();// =====================================to show menu
	
	void Exit();// ===================================to exit program
	
	int withDraw(string Q,double L);//============= to withdraw money
	
	string getAccount();//=================to set account type as current or saving
	
	string accountNumberGenerator();//==========to generate account number
	
	void setUserDetail();//=======================input details from user
	
	void getUserDetail(string R);//=============display user account detail
	
	bool checkCNIC(string check);//================to check CNIC length
	
	bool check_ph(int*);//=================check phone number length and validity
	
	string getPhNo();//=========================input phone number from user
	
	int deposit(double T,string C);//===========deposit amount in an account
	
	string properCNIC(char*);//=======================make CNIC proper
	
	string setCNIC();//=============================input CNIC from user
	
	void search();//=====================================search a user
	
	//Main function
	int main(){
		system("cls");//built in function to clear screen
		menu();//function call for menu()
	}
	
	
	//Function to generate account number for new user
	string accountNumberGenerator(){
	
	    static int n = 0 ;
	    ++n ;
	
	    string str = "0000000000000" + std::to_string(n);//converting int to string by using built in function to_string()
	    return str;
	
	}
	
	
	
	//function for account creation .......gets details of user
	void setUserDetail(){
		system("cls");
	
	//input cnic
		string cnicname=setCNIC();
		string files=cnicname+".txt";
		ofstream file(files,ios::app);
		file<<"CNIC_Number===>"<<cnicname;
		
		
		file<<'\n';
		//input first name
		string name;
		cout<<"\nEnter your first name : ";
		cin>>name;
		file<<"First_Name===>"<<name;
		file<<'\n';
		
		//input last name
		cout<<"Enter your Last name : ";
		cin>>name;
		file<<"Last_Name===>"<<name;
		file<<'\n';
		
		//input phone number
		string phoneNumber=getPhNo();
		file<<"Phone_Number===>"<<phoneNumber;
		file<<'\n';
		
		//account type 
		string acc=getAccount();
		file<<"Account_Type===>"<<acc;
		file<<'\n';
		
		//setting gender
		while(true){
		
		int gender;
		cout<<"Enter your gender : \n 1.Male \n 2.Female";
		cin>>gender;
		if(gender==1)
		file<<"Gender===>Male";
		else if(gender==2)
		file<<"Gender===>Female";
		else
		{
			cout<<"Enter a valid gender ";
			continue;
		}
		file<<'\n';
		break;
	}
		
		//set Date Of Birth
		while(true){
		
		int dob1,dob2,dob3;
		cout<<"Enter your date of birth : ";
		cout<<"Enter day : ";
		cin>>dob1;
		if(dob1>31 || dob1<1){
			cout<<"Enter a valid day ";
			continue;
		}
		
		
		cout<<"Enter month : ";
		cin>>dob2;
		if(dob2>12 || dob2<1){
			cout<<"Enter a valid month ";
			continue;
		}
		
		
		cout<<"Enter year (1920-2004): ";
		cin>>dob3;
		if(dob3>2004 || dob3<1920){
			cout<<"Enter a year within given range ";
			continue;
		}
		file<<"Date_Of_Birth===>"<<dob1<<"/"<<dob2<<"/"<<dob3;
		file<<'\n';
		file<<"Account_Number===>"<<accountNumberGenerator();
		
		 
		file<<'\n';
		break;
	}
		//initializing account balance as 0.00
		file<<"Current_Balance===>\n";
		file<<0.00;
		file.close();
		
		double balance=0.000;
		int check;
		//asking to deposit money
		cout<<"Your initial balance is : "<<balance<<" To deposit money in your account press 1 .....to continue press any other key :  ";
		cin>>check;
		//using if to check selected option
		if(check==1){
			cout<<"Enter amount to deposit : ";
			cin>>balance;
			deposit(balance,cnicname);//function call for deposit()
			
		}
	}
	
	
	
	
	//Function to check CNIC
	bool checkCNIC(string check){
		if(check.size()!=15)
		return false;
		else
		return true;
	}
	
	
	
	
	//Function to make CNIC proper
	string properCNIC(char* a){
		char temp[15];
		for(int i=0;i<15;i++){
			if(i==5){
				temp[i]='-';
				continue;
			}
			if(i==13){
			 	temp[i]='-';
			 	continue;
			}
			if(i>13)
			{
				temp[i]=a[i-2];
				continue;
			}
			if(i>5)
			{
				temp[i]=a[i-1];
				continue;
			}
			
			temp[i]=a[i];
		}
		
		string final=temp;
		return final;
	}
	
	
	
	
	
	
	
	//Function to input CNIC
	string setCNIC(){
		string proper;
		while(true){
		char CNIC[13];
		cout<<"Enter your CNIC (dont include hyphen): ";
		cin>>CNIC;
		proper=properCNIC(CNIC);
		if(!(checkCNIC(proper))){
			cout<<"please Enter Proper CNIC";
			continue;
	}
		else
		break;
	}
	
		string fileName=proper;
		
	
		return fileName;
	}
	
	
	//Function to search a user
	void search(){
		system("cls");
		cout<<"Enter CNIC of person : (include hyphens) : ";
		string find;
		cin>>find;
		find=find+".txt";
		ifstream f;
		f.open(find);
		string getDetail;
		int l=0;
		while(l<3){
		cout<<"------------------------------------------\n";
		f>>getDetail;
		cout<<getDetail;
		cout<<endl;
		l++;
	}
	cout<<"\n        The restof the detail is confidential \n";
	}
	
	
	
	//Function to exit the program
	void Exit(){
		system("cls");
		cout<<"   --------THANK--------\n        ----YOU----    \n --------VERY MUCH--------\n";
		exit(0);
	}
	
	
	
	
	
	
	
	//Function to deposit money and updating money details 
	int deposit(double T,string C){
		C=C+".txt";
		ifstream read(C);
		string arr[9];
		int amount;
		
		int i=0;
		while(read){
			if(i>8){
				read>>amount;
			}
			else
			read>>arr[i];
			i++;
		}
		
		amount=amount+T;
		read.close();
		ofstream update;
		update.open(C);
		i=0;
		while(i<=9){
			if(i>8)
			update<<amount;
			else
			update<<arr[i]<<'\n';
			i++;
		}
		update.close();
		//updateBalance(C,T);
		cout<<"\n Successfully added \n";
		
	}
	
	
	
	
	
	
	//Function to check phone number
	bool check_ph(string ph){
		string temp=ph.substr(0,2);
			if(temp!="03"){
				cout<<"Please enter a number that starts with 03 ";
				return false;
			}
			else if(ph.size()!=11){
				cout<<"Please enter a number containing 11 letters ";
				return false;
			}	else
			return true;
	}
	string getPhNo(){
		string Ph_No;
		while(true){
		
		
		cout<<"Enter your Ph-No : ";
		cin>>Ph_No;
	
		if(!check_ph(Ph_No)){//calling function to check phone number validity
			continue;
		}
		else{
			break;
		}
	}
	return Ph_No;
		
	}
	
	
	
	
	
	
	
	//Function to get account type
	string getAccount(){
		int type;
		string type1="current";
		string type2="saving";
		cout<<"Enter your account type \n 1. current \n 2. savings ......(press either 1 or 2)";
		cin>>type;
		if(!(cin)>>type)
		   return getAccount();
		else if(type==1){
			return type1;
		}
		else if(type==2){
			return type2;
		}
		else{
			cout<<"Please enter a valid option ";
			return getAccount();
		}
	}
	
	
	
	
	
	
	
	
	//Function to display menu
	int menu(){
		cout<<"					WELCOME					";
		cout<<"\nPress the corresponding number to select your operation \n";
		cout<<"1.Create account\n2.Search a user\n3.Deposit money\n4.Withdraw money\n5.See Your account Details\n6.Exit\n ------------ :  ";
		int option;
		string acc;
		string s;
		double amn;
		
		cin>>option;
		switch(option){//Switch cases to call the specified function
			case 1:
				setUserDetail();
				cout<<"Press 1 to continue to main menu......any other key to exit : ";
				cin>>amn;
				if(amn==1)
				return main();
				else
				exit(0);
			case 2:
				system("cls");
				cout<<"Enter cnic number to search a user :";
				search();
				cout<<"Press 1 to continue to main menu......any other key to exit : ";
				cin>>amn;
				if(amn==1)
				return main();
				else
				exit(0);
			case 3:
				system("cls");
				cout<<"Enter amount to deposit ";
				
				cin>>amn;
				cout<<"Enter CNIC number of account holder ";
				
				cin>>s;
				cout<<"Enter account number ";
				cin>>acc;
				deposit(amn,s);
				cout<<"Press 1 to continue to main menu......any other key to exit : ";
				cin>>amn;
				if(amn==1)
				return main();
				else
				exit(0);
			case 4:
				system("cls");
				cout<<"Enter your CNIC : ";
				cin>>s;
				cout<<"Enter amount to withdraw : ";
				cin>>amn;
				if(withDraw(s,amn)){
					cout<<"Successfully Withdrawn \n";
				}
				cout<<"Press 1 to continue to main menu......any other key to exit : ";
				cin>>amn;
				if(amn==1)
				return main();
				else
				exit(0);
			case 5:
				system("cls");
				cout<<"Enter CNIC Number : ";
				cin>>s;
				getUserDetail(s);
				cout<<"Press 1 to continue to main menu......any other key to exit : ";
				cin>>amn;
				if(amn==1)
				return main();
				else
				exit(0);
			case 6:
				Exit();
				break;
			default:
				system("cls");
				cout<<"please select a valid option ";
				cout<<"Press 1 to continue to main menu......any other key to exit : ";
				cin>>amn;
				if(amn==1)
				return main();
				else
				exit(0);
		}
	}
	
	
	
	
	
	//Function to display user account detail
	void getUserDetail(string R){
		
		string print;
		string file=R+".txt";
		ifstream get(file);
		 while(get){
		 	cout<<"\n------------------------------------------\n";
		 	get>>print;
		 	cout<<print;
		 }
	}
	
	
	//Function to withdraw money from account and updating money details
	int withDraw(string Q ,double L){
		Q=Q+".txt";
		fstream read_file(Q);
		string arr[9];
		int amount;
		
		int i=0;
		while(read_file){
			if(i>8){
				read_file>>amount;
			}
			else
			read_file>>arr[i];
			i++;
		}
		
		
		if(amount<L){
			cout<<"Low Balance ..............";
			return main();
		}
		
		
		amount=amount-L;
		read_file.close();
		ofstream update;
		update.open(Q);
		i=0;
		while(i<=9){
			if(i>8)
			update<<amount;
			else
			update<<arr[i]<<'\n';
			i++;
		}
		return 1;
	}
