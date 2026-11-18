#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

struct ActiveUser
{
	string CurrentUser;
};

struct UserCredentials
{
	string Username;
	string Password;
	int ID{};
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
	void Login();
	void CreateUser();
	void SendMessage();
	void ReadMessages();
	void Logout();


	string GetUser() { return activeUser.CurrentUser; }

private:
	ActiveUser activeUser;
	vector<MessageData> Folder;
	vector<UserCredentials> Users;
};

class ProgramUI
{
public:
	void UILoggedInHeader(string user);
	void UIStartScreen(UserCommands& commands);

};


class ProgramLoop
{
public:
	void Run();

private:
	UserCommands commands;
	ProgramUI ui;

	char userKey = ' ';

};

void UserCommands::Login()
{
	system("CLS");
	string username;
	string password;

	bool loggedIn = false;

	cout << "Enter Username: ";
	cin >> username;

	system("CLS");

	cout << "Enter Password: ";
	cin >> password;

	for (UserCredentials users : Users)
	{
		if (users.Username == username && users.Password == password)
		{
			activeUser.CurrentUser.append(username);
			loggedIn = true;
		}
	}


	if (!loggedIn)
	{
		system("CLS");

		cout << "incorrect username or password\n";
	}

}

void UserCommands::CreateUser()
{
	system("CLS");

	UserCredentials loginInfo;

	string userInput;

	cout << "Username: ";
	cin >> userInput;

	loginInfo.Username = userInput;

	system("CLS");

	cout << "Password: ";
	cin >> userInput;

	loginInfo.Password = userInput;

	loginInfo.ID += 1;

	Users.push_back(loginInfo);

	system("CLS");
}

void UserCommands::SendMessage()
{
	MessageData messageToSend;

	string userInput;


	cout << "To: ";
	cin >> userInput;
	messageToSend.To = userInput;

	//Inputs current logged in person and puts as "from"
	messageToSend.From = GetUser();

	cout << "Message: ";

	cin.ignore();
	getline(cin, userInput);
	messageToSend.Message = userInput;

	Folder.push_back(messageToSend);

	system("CLS");
}

void UserCommands::ReadMessages()
{
	cout << "|Messages| \n\n";

	for (MessageData data : Folder)
	{
		if (data.To == activeUser.CurrentUser)
		{
			/*cout << "To: " << data.To + "\n";*/
			cout << "From: " + data.From + "\n";
			cout << "Message: " + data.Message + "\n\n";
		}
	}
}

void UserCommands::Logout()
{
	cout << "You have logged out \n";
	activeUser.CurrentUser.clear();

	system("CLS");
}

void ProgramUI::UILoggedInHeader(string user)
{
	string lines;

	for (int i = 0; i < user.size(); i++)
	{
		lines.append("-");
	}
	cout << lines + "-----------------\n";
	cout << "| Logged in as: " + user + "|\n";
	cout << "-----------------------------------------------------------------------------------------------------";
	cout << "\n|Press corrosponding key: s = SendMessage, r = Read messages, c = Clear Window,  l = Logout, q = quit|\n";
	cout << "-----------------------------------------------------------------------------------------------------\n";
}

void ProgramUI::UIStartScreen(UserCommands& commands)
{
	char userKey{};

	cout << "-----------------------------------------------------";
	cout << "\n|Press corrosponding key: l = Login, c = Create User|\n";
	cout << "-----------------------------------------------------\n";

	userKey = _getch();


	userKey = tolower(userKey);

	switch (userKey)
	{
	case 'l':
		commands.Login();
		break;

	case 'c':
		commands.CreateUser();
		break;

	default:
		system("CLS");
		break;
	}
}

void ProgramLoop::Run()
{
	while (true)
	{
		if (!commands.GetUser().empty())
		{
			ui.UILoggedInHeader(commands.GetUser());

			userKey = _getch();


			userKey = tolower(userKey);

			switch (userKey)
			{
			case 's':
				commands.SendMessage();
				break;

			case 'r':
				commands.ReadMessages();
				break;

			case 'c':
				system("CLS");
				break;

			case 'l':
				commands.Logout();
				break;

			case 'q':
				return;

			default:
				system("CLS");
				cout << "INVALID COMMAND\n";
				break;
			}
		}
		else
		{
			ui.UIStartScreen(commands);
		}
	}
}
int main()
{
	ProgramLoop Program;

	Program.Run();
	return 0;
}