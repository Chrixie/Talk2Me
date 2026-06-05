#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

struct ActiveUser
{
	string CurrentUser;
};

struct MessageData
{
	string To;
	string From;
	string Message;
};

class UserInterface
{
public:
	void WindowUI();

private:
	UserCommands user;
};

class UserCommands
{
public:

	void Login();
	void SendMessage();
	void ReadMessages();
	void Logout();

	string GetUser() { return User.CurrentUser; }

private:
	ActiveUser User;
	vector<MessageData> Folder;

};

void UserCommands::Login()
{
	string userInput;

	cout << "Enter Username: ";
	cin >> userInput;
	User.CurrentUser.append(userInput);

	system("CLS");
}

void UserCommands::SendMessage()
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

	cin.ignore();
	getline(cin, userInput);
	messageToSend.Message = userInput;

	Folder.push_back(messageToSend);

	system("CLS");
}

void UserCommands::ReadMessages()
{
	for (MessageData data : Folder)
	{
		if (data.To == User.CurrentUser)
		{
			cout << "To: " << data.To + "\n";
			cout << "From: " + data.From + "\n";
			cout << "Message: " + data.Message + "\n\n";
		}
	}
}

void UserCommands::Logout()
{
	cout << "You have logged out \n";
	User.CurrentUser.clear();

	system("CLS");
}

void UserInterface::WindowUI()
{
	string lines;

	for (int i = 0; i < user.GetUser().size(); i++)
	{
		lines.append("-");
	}
	cout << lines + "-----------------\n";
	cout << "| Logged in as: " + user.GetUser() + "|\n";
	cout << "--------------------------------------------------------------------------------------------";
	cout << "\n|Press corrosponding key: s = SendMessage, r = Read messages, c = Clear Window,  l = Logout |\n";
	cout << "--------------------------------------------------------------------------------------------\n";
}

int main()
{
	UserCommands commands;
	UserInterface interface;

	char userKey = ' ';

	while (1)
	{
			if(!commands.User.CurrentUser.empty())
			{

				commands.UserInterface();

				userKey = _getch();

				for (int i = 0; i < userKey; i++)
				{
					userKey = tolower(userKey);
				}

				if (userKey == 's')
				{
					commands.SendMessage();

				}

				else if (userKey == 'r')
				{
					commands.ReadMessages();
				}

				else if (userKey == 'c')
				{
					system("CLS");
				}

				else if (userKey == 'l')
				{
					commands.Logout();
				}

				else
				{
					system("CLS");
					cout << "INVALID COMMAND\n";
				}
			}
			else
			{
				commands.Login();
			}

	}

	return 0;
}