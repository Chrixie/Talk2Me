#include "UserCommands.h"
#include <iostream>
#include <fstream>


void UserCommands::UserLogin()
{

    std::cout << "Write username: ";

    std::cin >> inputCommand;

    userInfo.username = inputCommand;
}

void UserCommands::ClearFile()
{

    userInfo.myMessages.clear();

    std::cout << "FILE HAS BEEN CLEARED \n";
}

void UserCommands::WriteMessage(std::string user, std::string text)
{
    std::cout << "Write comment: ";
    std::cin >> inputCommand;


    userInfo.myMessages.emplace_back(user + ": " + text + "");
}

void UserCommands::ReadMessages()
{
    if (userInfo.myMessages.empty())
        std::cout << "No messages found";
    else
        std::cout << "\n Reading File: \n";
    for (std::string::size_type i = 0; i < userInfo.myMessages.size(); i++)
    {
        std::cout << userInfo.myMessages[i];
    }

}