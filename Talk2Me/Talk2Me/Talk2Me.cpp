#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ActiveUser
{
	string CurrentUser;
};

struct UsernamesData
{
	vector<string> Usernames;
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
	ActiveUser User;
	UsernamesData ListUsernames;

	vector<MessageData> Folder;

	void Login()
	{
		string userInput;

		cout << "Enter Username: ";
		cin >> userInput;
		User.CurrentUser.append(userInput);

	}

	void SendMessage()
	{
		MessageData messageToSend;

		string userInput;

		cout << "To: ";
		cin >> userInput;
		messageToSend.To = userInput;

		cout << "From: ";
		cin >> userInput;
		messageToSend.From = userInput;

		cout << "Message: ";
		getline(cin, userInput);
		messageToSend.Message = userInput;
		//messagedata asset
		//3 strings

		Folder.push_back(messageToSend);
		//put into folder
	}

	void PrintMessages()
	{
		for (MessageData data : Folder)
		{
			if (data.To == User.CurrentUser)
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
		User.CurrentUser.clear();
	}

	void PrintUsers()
	{
		cout << "print users: \n";
		for (int i = 0; i < ListUsernames.Usernames.size(); i++)
		{
			cout << ListUsernames.Usernames[i];
		}
	}


};

//Next steps
//Error messages if I enter something wrong
//Don't make me type so much for the menu
//How do I know who I'm logged in as?
//mAKE IT CASE insenstive
// 
// 
//clear screen system("cls");----------


int main()
{
	UserCommands commands;

	string userInput;

	while (1)
	{
			system("CLS");
			if(!commands.User.CurrentUser.empty())
			{
				cout << "Logged in as: " + commands.User.CurrentUser;
				cout << "\nYour options are: Send, Read, Logout \n";

				cin >> userInput;

				if (userInput == "send")
				{
					commands.SendMessage();
				}

				if (userInput == "read")
				{
					commands.PrintMessages();
				}

				if (userInput == "users")
				{
					commands.PrintUsers();
				}

				if (userInput == "logout")
				{
					commands.Logout();
				}
			}
			else
			{
				commands.Login();
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
