#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct User
{
	string CurrentUser;
	string Usernames;
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
	User user;

	vector<MessageData> folder;




	void Login()
	{
		string userInput;

		cout << "Username: ";
		cin >> userInput;
		user.CurrentUser.assign(userInput);

	}

	void SendMessage()
	{
		MessageData messageToSend;

		string userInput;

		cout << "To: ";
		getline(cin, userInput);
		messageToSend.To = userInput;

		cout << "From: ";
		getline(cin, userInput);
		messageToSend.From = userInput;

		cout << "Message: ";
		getline(cin, userInput);
		messageToSend.Message = userInput;
		//messagedata asset
		//3 strings

		folder.push_back(messageToSend);
		//put into folder
	}

	void PrintMessages()
	{
		for (MessageData data : folder)
		{
			if (data.To.compare(user.CurrentUser) == 0)
			{
				cout << "To: " << data.To + "\n";
				cout << "From: " + data.From + "\n";
				cout << "Message: " + data.Message + "\n";
			}
		}

	}

	void Logout()
	{
		cout << "You have logged out \n";
		user.CurrentUser.clear();
	}

	void PrintUsers()
	{
		cout << "print users: \n";
		for (int i = 0; i < user.Usernames.size(); i++)
		{
			cout << user.Usernames.at(i);
		}
	}


};

int main()
{

	User user;
	Coworkers coworkers;
	UserCommands commands;

	string userInput;

	while (1)
	{
		cout << "Your options are: Login, Send Message, Read Message, Logout";
		getline(cin, userInput);

		if (userInput == "Login")
		{
			commands.Login();
		}

		if (userInput == "Send Message")
		{
			commands.SendMessage();
		}

		if (userInput == "Read Message")
		{
			commands.PrintMessages();
		}

		if (userInput == "Users")
		{
			commands.PrintUsers();
		}

		if (userInput == "Logout")
		{
			commands.Logout();
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
