// Talk2Me.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct User
{
	vector<string> Username;
};

struct Coworkers
{
	vector<string> coworkernames;
};

struct MessageData
{
	string To;
	string From;
	string Message;
};

class UserCommands
{
public:
	string inputCommand;

	vector<MessageData> message;
	MessageData data;

	User user;

	void Login()
	{
		cin >> inputCommand;
		user.Username.push_back(inputCommand + "\n");


	}

	void PrintUsers()
	{
		for (int i = 0; i < user.Username.size(); i++)
		{
			cout << user.Username.at(i);
		}
	}

	void SendMessage()
	{

	}
};

int main()
{

	User user;
	Coworkers coworkers;
	UserCommands commands;



	while (1)
	{
		cin >> commands.inputCommand;

		if (commands.inputCommand == "login")
		{
			cout << "Username: ";
			commands.Login();
		}


		if (commands.inputCommand == "users")
		{
			cout << "print users: \n";
			commands.PrintUsers();
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
