#include <iostream>
#include <fstream>
#include <string>

std::string inputCommand;

std::string fileNameCheck;
std::string username;

void CreateUserFile()
{
	//incase you want a file for multiple usernames stored
	std::ofstream MyWriteFile("user.txt");
}

void CreateTextFile()
{
	//text file that stores all messages sent
	std::ofstream MyWriteFile("text.txt");
}

void UserLogin()
{

	std::cout << "Write username: ";

	std::cin >> inputCommand;

	//adds username to text file if you want to check document in the future
	std::ofstream filename("user.txt", std::ios::app);

	filename << inputCommand;

	username = inputCommand;
}

void ClearFile()
{
	//removes all messages from the text file
	std::ofstream clearfile("text.txt");
}

void WriteFile(std::string user, std::string text)
{
	std::ofstream WriteFile("text.txt", std::ios::app);

	//current logged in user + message
	WriteFile << user << ": " << text << "\n";

	WriteFile.close();
}

void ReadFile()
{

	std::string myText;

	std::ifstream MyReadFile("text.txt");

	while (std::getline(MyReadFile, myText))
	{
		std::cout << myText << "\n";
	}

	MyReadFile.close();

}


int main()
{
	CreateUserFile();

	UserLogin();

	while (1)
	{
		std::cout << "\n\n read / write / clear / logout / quit   YOUR CHOICE \n";
		std::cin >> inputCommand;

		if (inputCommand == "read")
		{
			std::cout << "\n Reading File: \n";
			ReadFile();
		}

		else if (inputCommand == "write")
		{
			std::cout << "Write comment: ";
			std::cin >> inputCommand;

			WriteFile(username, inputCommand);

			std::cout << "\n";
		}

		else if (inputCommand == "clear")
		{
			ClearFile();
			std::cout << "FILE HAS BEEN CLEARED \n";
		}

		else if (inputCommand == "logout")
		{
			UserLogin();
		}

		else if (inputCommand == "quit")
		{
			break;
		}

	}
	return 0;
}
