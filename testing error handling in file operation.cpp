#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<bits/stdc++.h>
#include<unistd.h>
#include<time.h>
#include<windef.h>
#include<windows.h>
#include<conio.h>
using namespace std;
void mainmenu();
void time()
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t"<<asctime (timeinfo);
}
void time_for_details()
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  cout<<"\t"<<asctime (timeinfo);
}
void feedback_form(int option)
{
	//mainmenu();
	char f_select;
	char feed[200];
	ofstream read_feedback;
	if(option==1)
	{
		cout<<"\nTo give Feedback Press Y else Press N\n";
	cin>>f_select;
	//cout<<f_select;
	if(f_select=='Y'||f_select=='y')
	cout<<"Please give an honest Feedback in about 100 words\n";
	}
	else
	{
		cout<<"Please give an honest Feedback in about 100 words\n";
		f_select='y';
	}
	if(f_select=='Y'||f_select=='y')
	{
	  //getline(cin,feed);
	  read_feedback.open("feeback_from_users",ios::app);
	  //read_feedback<<username_for_feedback;
	  getchar();
	  cin.get(feed,200,'\n');
	  read_feedback<<feed<<'\n';
	}
	else
	{
		read_feedback<<'*'<<'*';
	}
	read_feedback<<"\n";
	read_feedback.close();
	if(f_select!='n'||f_select!='N')
	cout<<"\nThanks for the Feedback\n";
	sleep(2);
	system("cls");
	cout<<"Redirecting...";
	mainmenu();
	//cout<<"$$$";
	sleep(2);	
	system("cls");
	time();
	
}
void cart_show();
class vendor
{
	private:
		char restro_name[50];
	public:
		void add_menu();
		void display_menu_vendor();
		void delete_menu();
		int vendor_sign_in();
};
class user
{
	private:
		void cart();
		char username_for_feedback[30];
	public:
		int signup_and_signout(int opti);
		void location_search();
};
class Admin:public user
{
	public:
		void delete_user();
		//void make_admin();
		void add_restaurants();
	//	void make_vendor();
};
int user:: signup_and_signout(int option)
{
	if(option==2)
	{
		ofstream fout,pfout;
		ifstream checkout;
		ifstream fin,pfin;
		char username[30];
		char password[30];
	/*	fout.open("username");
		fout.close();
		pfout.open("checker_for_same_username",ios::in);
		pfout.close();*/
		tryagain:
		cout<<"Username:\t";
		cin>>username;
		system("cls");
		cout<<"Checking...";
		sleep(2);
		system("cls");
		time();
		checkout.open("checker_for_same_username",ios::in);
		char checking[30];
		int flag=0;
		while(checkout)
		{
			checkout.getline(checking,10000);
			if(strcmp(checking,username)==0)
			{
				flag=1;
			}
		}
		checkout.close();
		if(flag==0)
		{
			char answer;
			cout<<"User Doesn't Exist";
			sleep(2);
			system("cls");
			time();
			cout<<"Are you new to zomato IIIT ,if yes then press y\n";
			cin>>answer;
			if(answer=='y')
			{
				imp:
			cout<<"\nenter username\n";
			cin>>username;
			system("cls");
			time();
			pfin.open("checker_for_same_username",ios::in);
			char checker[30];
			while(pfin)
			{
				pfin.getline(checker,10000);
				if(strcmp(checker,username)==0)
				{
					cout<<"Username already exist";
					sleep(1);
					system("cls");
					time();
					pfin.close();
					goto imp;
				}
			}
			fout.open("username",ios::app);
			pfin.close();
			pfout.open("checker_for_same_username",ios::app);
			cout<<"enter password\n";
			int index;
		for(index=0; index<30; index++)
	       {
			password[index]=_getch();
			_putch('*');
			if(password[index]==13)
			break;
	        }
	        password[index]='\0';
			/*
			int index=0;
			while(1)
			{
			cin>>p-32
			}*/
			fout<<username;
			pfout<<username;
			pfout<<endl;
			pfout.close();
			fout<<password;
			fout<<endl;
			cout<<"\nHurray you are a customer of zomato iiit \n";
			fout.close();
			system("cls");
			cout<<"\n Redirecting you to Login page...\n";
			sleep(2);
			system("cls");
			time();
			goto tryagain;
			}
			else
			cout<<"Redirecting you to Login Page...";
			sleep(2);
			system("cls");
			time();
			goto tryagain;
		}
		cout<<"\n";
		cout<<"Password:";
		int index;
		for(index=0; index<30; index++)
	       {
			password[index]=_getch();
			_putch('*');
			if(password[index]==13)
			break;
	        }
	        password[index]='\0';
		cout<<"\n";
		char username_copy[30];
		strcpy(username_copy,username);
		strcat(username,password);
		system("cls");
		time();
		//fout<<username;
	//	fout.close();
	//opening file for reading purpose only hence using ios::in
		//checking if user exists or not
		fin.open("username",ios::in);
		int check=0;
		char check_username[30];
		int i=0;
		//cout<<username;
		while(fin)
		{
			fin.getline(check_username,10000);
			check=0;
			i=0;
		//	cout<<check_username;
					while(1)
			       {
					//cout<<a[i]<<b[i];
			        if(username[i]!=check_username[i])
			            check=1;
			            if(username[i]=='\0')
			            break;
			            i++;
			       }
				   if(check==0)
				   break;
		}
		fin.close();
		if(check==1)
		{
			system("cls");
			cout<<"\nIncorrect Credentials\n";
			sleep(1);
			cout<<"Redirecting...";
			sleep(2);
			system("cls");
			time();
			goto tryagain;

		}

			//cout<<"\n--user found----\n";
			cout<<"\nWelcome user "<<username_copy;
			cout<<"\n";
			ofstream read_feedback_1;
			//cout<<"\nWelcome user "<<username_copy;
			strcpy(username_for_feedback,username_copy);
			read_feedback_1.open("feeback_from_users",ios::app);
	        read_feedback_1<<username_for_feedback;
	        read_feedback_1<<"\n";
	        read_feedback_1.close();
			cout<<"\n";	
			return 2;

	}
	if(option==1)
	{
	ofstream open_admin_file;
		/*open_admin_file.open("admins");
		open_admin_file.close();*/
		ifstream read_admin,read_admin_password;
		string admin_user;
		string check_admin;
		string check_admin_name;
		string check_admin_password;
		string admin_password;
		read_admin.open("admins",ios::in);
		cout<<"Admin Username: ";
		cin>>admin_user;
		cout<<"\nAdmin Password: ";
		cin>>admin_password;
		int check=0;
		//cout<<admin_user;
		while(read_admin)
		{
			getline(read_admin,check_admin_name,',');
			getline(read_admin,check_admin_password,'\n');
			if(((check_admin_name.compare(admin_user))==0)&&((check_admin_password.compare(admin_password))==0))
			check=1;
		//	cout<<"! ";
		}
		if(check==1)
		{
			system("cls");
			time();
			cout<<"Welcome Admin";
			return 1;
		}
		else
		{
			system("color 4e");
			cout<<"Sorry you are not an admin or you have entered incorrect crediantials\n";
			cout<<"Redirecting...\n";
			sleep(3);
			mainmenu();
			system("cls");

			return 0;
		}
	}
}
void Admin::delete_user()
{
	char find_user[30];
	char is_this_the_user[30];
	char searched_user;
	char users[30];
	char copying[30];
	char show_user[30];
	ifstream viewing_users;
	viewing_users.open("checker_for_same_username",ios::in);
	while(viewing_users)
	{
		viewing_users.getline(users,10000);
		strcpy(show_user,users);
		if(strcmp(show_user,"*")!=0)
		cout<<show_user<<"\n";
	//	if(users!='\n')
		//cout<<"\n";

	}
	//sleep(4);
	//system("cls");
	viewing_users.close();
	delete_again:
	cout<<"\nPlease enter username to delete\n";
	cin>>find_user;
	system("cls");
	time();
	
try
	{
		int checkerr=0;
		ifstream check_for_exist_of_user;
		check_for_exist_of_user.open("checker_for_same_username",ios::in);
		while(check_for_exist_of_user)
		{
			check_for_exist_of_user.getline(is_this_the_user,10000);
			if(strcmp(find_user,is_this_the_user)==0)
			{
				checkerr=1;
			}
		}
		if(checkerr==0)
		 throw(1);
	}
	catch(int i)
	{
		if(i==1)
		{
			cout<<"\nEntered user is not found.\n\n\nEnter again\n";
			sleep(2);
			system("cls");
			goto delete_again;
		} 
	}
	
	ifstream delete_user;
	ofstream temporary_delete;
	temporary_delete.open("temporary");
	delete_user.open("checker_for_same_username",ios::in);
	while(delete_user)
	{
		delete_user.getline(is_this_the_user,10000);
		if(strcmp(find_user,is_this_the_user)==0)
		{
			temporary_delete<<'*';
		}
		else
		{
			temporary_delete<<is_this_the_user;
		}
		temporary_delete<<"\n";
    }
    temporary_delete.close();
    delete_user.close();
/*
    ifstream test;
    test.open("temporary",ios::in);
    char jackoff[100];
    while(test)
    {
    	test.getline(jackoff,10000);
    	cout<<jackoff;
	}
	test.close();*/
    ifstream after_temporary_delete_file_created;
    ofstream after_deleted_user;
    after_temporary_delete_file_created.open("temporary",ios::in);
    after_deleted_user.open("checker_for_same_username");
    while(after_temporary_delete_file_created)
    {
    	after_temporary_delete_file_created.getline(copying,10000);
    	after_deleted_user<<copying<<"\n";
	}
	after_temporary_delete_file_created.close();
    after_deleted_user.close();
	cout<<"\nUser is being deleted...\n";
	sleep(2);
	system("cls");
	time();
	cout<<"\nUser Deleted\n";
	sleep(1);
	system("cls");
	time();
	cout<<"\nDisplaying the leftover users\n";
	sleep(1);
	system("cls");
	cout<<"Loading...";
	sleep(2);
	//ifstream viewing_users;
	system("cls");
	viewing_users.open("checker_for_same_username",ios::in);
	while(viewing_users)
	{
		viewing_users.getline(users,10000);
		strcpy(show_user,users);
		if(strcmp(users,"*")!=0)
		cout<<show_user<<"\n";

	}
	viewing_users.close();
   sleep(4);
    system("cls");
    time();


}
void Admin:: add_restaurants()
{
	//time();
	char selection;
	char restaurants[30];
	char password_vendor[30];
	string pincode;
	main_men:
	cout<<"\nDo you want to add restaurants in existing pincode? y or n\n";
	cin>>selection;
	system("cls");
	time();
	if(selection=='Y'||selection=='y')
	{
		try_again:
		cout<<"\nEnter pincode\n";
		cin>>pincode;
		try
		{
			ifstream fin;
			fin.open(pincode.c_str(), ios::in);
			if(fin.fail())
			throw(1);
		}
		catch(int i)
		{
			if(i==1)
			{
				char choice;
				cout<<"\nPincode does not exist.\n press 'y' to add new pincode and 'n' for try again\n ";
				cin>>choice;
				if(choice=='y' || choice=='Y')
					goto new_pincode;
				else
					goto try_again;
			}
		}
		system("cls");
		time();
		ofstream open_pincode;
		open_pincode.open(pincode.c_str(),ios::app);
		cout<<"Enter restaurants name\n";
		cin>>restaurants;
		system("cls");
		time();
		open_pincode<<restaurants;
		open_pincode<<"\n";
		open_pincode.close();
		cout<<"\nRestaurant added\n";
		cout<<"\nPlease add a temporary password for vendor to login\n";
		ofstream input_username_for_vendor;
		input_username_for_vendor.open("vendors",ios::app);
		cin>>password_vendor;
		system("cls");
		time();
		input_username_for_vendor<<pincode<<restaurants<<password_vendor<<"\n";
		input_username_for_vendor.close();
		
	}
	else
	{
		cout<<"\nWarning!! If pincode already exist then all the data for that pincode will be deleted\n";
		new_pincode:
		cout<<"\nEnter the pincode\n";
		cin>>pincode;
		system("cls");
		time();
		ofstream open_pincode;
		open_pincode.open(pincode.c_str());
		open_pincode.close();
		cout<<"\nNew pincode created\n";
		cout<<"\nPlease go to main menu and type y\n";
		goto main_men;
	}

}
void user :: location_search()
{
	char restaurants[30];
	string pincode;
	string restaurant_name;
	char display[30];
	reenter_location:
	cout<<"\nEnter your location pincode\n";
	cin>>pincode;
	try
	{
		ifstream fin;
		fin.open(pincode.c_str(), ios::in);
		if(fin.fail())
		throw(1);
	}
	catch(int i)
	{
		if(i==1)
		{
			system("cls");
			time();
			char choice;
			cout<<"\nSorry! We don't serve there yet.\nWant to order somewhere else? y/n\n";
			cin>>choice;
			if(choice=='y'|| choice=='Y')
				goto reenter_location;
			else 
				cout<<"\n Thank You for using APPP.";
				exit(0);
		}
	}
	system("cls");
	time();
	restaurant_again:
	ifstream open_restaurants_for_pincode;
	open_restaurants_for_pincode.open(pincode.c_str(), ios::in);  //error handling to be included.
	while(open_restaurants_for_pincode)
	{
		open_restaurants_for_pincode.getline(restaurants,10000);
//		strcpy(display,restaurants);
		cout<<restaurants<<"\n";

	}
	open_restaurants_for_pincode.close();
	cout<<"\nEnter restaurants name as above\n";
	cin>>restaurant_name;
	system("cls");
	time();
	try
	{
		ifstream open_rest;
		open_rest.open(restaurant_name.c_str(),ios::in);
		if(open_rest.fail())
		 throw(1);
	}
	catch(int i)
	{
		if(i==1)
		{
			cout<<"\nWrong restaurant input.\n\n\nEnter again\n";
			sleep(2);
			system("cls");
			goto restaurant_again;
		} 
	}
	ifstream open_rest;
	open_rest.open(restaurant_name.c_str(),ios::in);
	string item_name[100];
	string price[100];
	int i=0;
	while(open_rest)
	{
		getline(open_rest,item_name[i],',');
		getline(open_rest,price[i],'\n');
		cout<<item_name[i]<<"-------"<<price[i]<<"\n";
		i++;
	}
	int j=i-1;
//	cout<<j;
	char opt;
	open_rest.close();
	cout<<"\n***************************************************************************\n";
	cout<<"\n-------------------Please select the items from the menu-------------------\n";
	cout<<"\n->To add any item press a<-\n";
	cout<<"\n->To delete any item at any time press d<-\n";
	cout<<"\n->To conform your order press r<-\n";
	cout<<"\n->Select items by their index number<-\n";
	cout<<"\n->Index number starts from 0<-\n";
	cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
//	int j=0;
	int total=0;
	int quantity[100]={0};
	fstream cart;
	cart.open("cart", ios::out);
	while(1)
	{
		phirsetry:
		cout<<"\nEnter choice\n";
		cin>>opt;
		if(opt=='a'||opt=='A')
		{
			cout<<"\nEnter item number\n";
			cin>>i;
			quantity[i]++;
			cout<<item_name[i]<<"--"<<quantity[i]<<"\n";
			total = total+atoi(price[i].c_str());
		}
		if(opt=='d'||opt=='D')
		{
			cout<<"\nEnter item number\n";
			cin>>i;
			quantity[i]--;
			cout<<item_name[i]<<"--"<<quantity[i]<<"\n";
			total = total-atoi(price[i].c_str());
		}
		if(opt=='r'||opt=='R')
		{
			char address[200];
			cout<<"Please Enter your Address Details for delivery\n";
			getchar();
			cin.getline(address,200,'\n');
			system("cls");
			cout<<"\nConfirming your order from Restaurant\n...";
			sleep(2);
			cout<<"Hurray your order is confirmed\n";
			sleep(1);
			system("cls");
			system("color 3e");
			cout<<"Ordered at :";time_for_details();cout<<"\n";
			cout<<"Food will be delivered in 30 Minutes at \n"<<address<<"\n\n";
			cout<<"HERE'S YOUR ORDER\n\n";
			for(int k=0; k<j; k++)
			{
				if(quantity[k]!=0)
				{
					cout<<item_name[k]<<"--------"<<quantity[k]<<"----->"<<atoi(price[k].c_str())*quantity[k]<<"\n";
					cart<<item_name[k]<<','<<quantity[k]<<','<<atoi(price[k].c_str())*quantity[k]<<'\n';

				}
			}
			cart.close();
			//cart_show();
			break;	
		}
		

	}
	cout<<"\nTotal amount---"<<total<<"\n\n\n";
    int sending=1;
    
	feedback_form(sending);
}
int vendor::vendor_sign_in()
{
	char pincode[30];
//	char restaurants_name[30];
	char found[30];
	char password[30];
	cout<<"\nSign in first\n";
	cout<<"\nEnter your pincode\n";
	cin>>pincode;
	system("cls");
	time();
	cout<<"\nEnter restaurants name in lowercase characters\n";
	cin>>restro_name;
	system("cls");
	time();
	strcat(pincode,restro_name);
	cout<<"\nEnter your password\n";
	cin>>password;
	system("cls");
	time();
	strcat(pincode,password);
	ifstream find_vendor;
	find_vendor.open("vendors",ios::in);
	int check=0;
	while(find_vendor)
	{
		find_vendor.getline(found,10000);
		if(strcmp(found,pincode)==0)
		{
			check=1;
			break;
		}
	}
	find_vendor.close();
	vendor v1;
	if(check==1)
	{

		cout<<"\nWelcome vendor of "<<restro_name<<endl;
		return check;
	}
	else
	{
		cout<<"\nSorry you are still not a vendor please contact the admin\n";
		system("cls");
		return check;
	}
}
void vendor::add_menu()
{
	char item_name[30];
	char price[30];
	string display;
	//char copying[30];
	string itemname,itemprice;
	string restaurant_name(restro_name);
	system("cls");
	time();
	ifstream checker;
	checker.open(restaurant_name.c_str(),ios::in);
	while(checker)
	{
		getline(checker,itemname,',');
		getline(checker,itemprice,'\n');
		display = itemname;
		cout<<display;
		display = itemprice;
		cout<<display;
	}
	checker.close();
	char select;
	cout<<"\nPlease start adding item name and their price\n";
	ofstream add_item;
	add_item.open(restaurant_name.c_str(),ios::app);
	while(1)
	{
		cout<<"\nDo you want to add item?\n";
		cin>>select;
		system("cls");
		time();
		if(select=='n'||select=='N')
		{ //{break;
		cout<<"\nMenu has been updated if changed\n";
		break;
		}
		cout<<"\nEnter item name\n";
		cin>>item_name;
		cout<<"\nEnter price\n";
		cin>>price;

			add_item<<item_name;
			add_item<<',';
			add_item<<price;
			add_item<<"\n";
		system("cls");
		time();
	}
	add_item.close();
}

void vendor::display_menu_vendor()
{
	string restaurant_name(restro_name);
	string data;
	ifstream vendor_menu;
	vendor_menu.open(restaurant_name.c_str());
	while(vendor_menu)
	{
		getline(vendor_menu, data, ',');
		cout<<data<<"\t\t\t";
		getline(vendor_menu, data, '\n');
		cout<<data<<"\n";	
	}	
	vendor_menu.close();
}

void vendor::delete_menu()
{
	string restaurant_name(restro_name);
	char select;
	ifstream display_items;
	ofstream temporary_delete;
	string display1,display2,itemprice,itemname;
	display_items.open(restaurant_name.c_str(),ios::in);
	temporary_delete.open("temporary_file_deletion");
    cout<<"\n--+--+--+--+--+--+--+--+--+\n";
	cout<<"\n|Press i to update item   |\n";
	cout<<"\n|Press p to update price|\n";
	cout<<"\n|Press b to update both |\n";
	cout<<"\n|Press any key to move to next item|\n";
	//cout<<"\n|Press e to go to vendor main menu |\n";
	while(display_items)
	{
		getline(display_items,itemname,',');
		display1 = itemname;
		cout<<"\n"<<display1<<" ";
		getline(display_items,itemprice,'\n');
		display2 = itemprice;
		cout<<display2<<endl;
		cout<<"\nEnter choice\n";
		cin>>select;
		system("cls");
		time();
		if(select=='i')
		{
			cout<<"\nEnter the item name to update\n";
			cin>>display1;
		}
		if(select=='p')
		{
			cout<<"\nEnter the item price to update\n";
			cin>>display2;
		}
		if(select=='b')
		{
			cout<<"\nEnter the item name to update\n";
			cin>>display1;
			cout<<"\nEnter the item price to update\n";
			cin>>display2;
		}
	    temporary_delete<<display1;
		temporary_delete<<',';
		temporary_delete<<display2;
		temporary_delete<<'\n';
	}
	//cout<<"hdfgbdhfgbhdkbf";
	string copied_text;
	temporary_delete.close();
	display_items.close();
	ofstream copying_back;
	copying_back.open(restaurant_name.c_str());
	ifstream source_file;
	source_file.open("temporary_file_deletion",ios::in);
	while(source_file)
	{
		getline(source_file,copied_text,',');
		display1 = copied_text;
		copying_back<<display1;
		copying_back<<',';
		getline(source_file,copied_text,'\n');
		display2 = copied_text;
		copying_back<<display2;
		copying_back<<'\n';
	}
	//cout<<"fdfshvbjhsbfvjhsdfguhjsdfbv";
	source_file.close();
	copying_back.close();
}
int main()
{
	mainmenu();
	int option;
    Admin a1;
    user u1;
    vendor v;
    time();
    first_screen:
 cout<<"                       **********************"<<endl;
 cout<<"******************   WelCome to APPP Restaurant   **************"<<endl;
 cout<<"                       ************************\t\t\t\t\t"<<endl;

 cout<<"*************************************************************************"<<endl<<endl;
 cout<<"** Press 1 for Adminstrator         1::Admin                           **"<<endl<<endl;
 cout<<"**                                                                     **"<<endl<<endl;
 cout<<"** Press 2 for Customer             2::Customer                        **"<<endl<<endl;
 cout<<"**                                                                     **"<<endl<<endl;
 cout<<"** Press 3  for Vendor              3::Vendor                          **"<<endl<<endl;
 cout<<"**                                                                     **"<<endl<<endl;
 cout<<"** Press 4 for  Exit                4:EXIT                             **"<<endl<<endl;
 cout<<"*************************************************************************"<<endl<<endl;
	cin>>option;
	system("cls");
	time();
	int returner;
	switch(option)
	{
		case 1:
			returner = a1.signup_and_signout(option);
			if(returner!=1)
			goto first_screen;
			else
			{
				//start admin options;
				int admin_options;
				admin_options_menu:
				//cout<<"hello admin\n";
				cout<<"\n--+--+--+--+--+--+--+--+--+\n";
				cout<<"\n|Press 1 for removing a user   |\n";
				cout<<"\n|Press 2 for adding restaurants|\n";
				cout<<"\n|Press 3 for signout           |\n";
				cout<<"\n|Press 4 to exit               |\n";
				//cout<<"press 3 for adding vendors";
				//cout<<"press 3 for  order food from your own software";
			//	cout<<"press 3 adding or removing admins";
				cin>>admin_options;
				system("cls");
				time();
				switch(admin_options)
				{
					case 1:
						a1.delete_user();
						goto admin_options_menu;
						break;
					case 2:
						a1.add_restaurants();
						goto admin_options_menu;
						break;
					case 3:
						goto first_screen;
					case 4:
						return 0;
					default:
						goto admin_options_menu;
						break;
				}
			}
			break;
		case 2:
			//cout<<option;
			returner = a1.signup_and_signout(option);
			if(returner!=2)
			goto first_screen;
			else
			{
				int u_option;
				user_main_menu:
				cout<<"\nPress 1 to Order Food\nPress 2 to view your cart";
				cout<<"\nPress 3 to signout\nPress 4 to give Feedback\n";
				cin>>u_option;
				system("cls");
				time();
				switch(u_option)
				{
					case 1:
						u1.location_search();
						goto user_main_menu;
					case 2:
						cart_show();
						goto user_main_menu;
					case 3:
						goto first_screen;
					case 4:
						int acha=4;
						feedback_form(acha);
						goto user_main_menu;
				}

				//cout<<"\nto clear your previous cart press 2";
			}
			break;
		case 3:
			returner = v.vendor_sign_in();
			if(returner==1)
			{
				vendor_main_menu:
		cout<<"\n--+--+--+--+--+--+--+--+--+\n";
				cout<<"\n|Press 1 for adding items  |\n";
				cout<<"\n|Press 2 for display all items|\n";
				cout<<"\n|Press 3 for deleting items|\n";
			//	cout<<"\n|Press 4 to go to main menu|\n";
				cout<<"\n|Press 4 to signout|\n";
		cin>>option;
		system("cls");
		time();
		switch(option)
		{
			case 1:
				v.add_menu();
				goto vendor_main_menu;
			case 2:
				v.display_menu_vendor();
//				sleep(3);
				goto vendor_main_menu;
			case 3:
			  	v.delete_menu();
				goto vendor_main_menu;
			case 4:
				cout<<"\nRedirecting...\n";
				sleep(2);
				system("cls");
				time();
				break;
			default:
				goto vendor_main_menu;
		}
			}
			goto first_screen;
		case 4:
			cout<<"\nThanks for using  APPP :)\n";
			return 0;
			break;
		default:
			cout<<"\nOption not found\n";
			goto first_screen;
			break;

	}


}

void cart_show()
{
	ifstream cart;
	string cart_item;
	cart.open("cart", ios::in);
	while(cart)
	{
		getline(cart, cart_item, ',');
		cout<<"\n"<<cart_item<<"\t";
		getline(cart, cart_item);
		cout<<cart_item;
	}
	cart.close();
}

void mainmenu()
{
	system("color 5e");
}
