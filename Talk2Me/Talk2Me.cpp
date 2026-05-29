#include <iostream>
#include "FileCreation.h"
#include "UserCommands.h"
#include "UserInformation.h"

int main()
{
    UserCommands userCommands;
    UserInformation userInfo;

    userCommands.UserLogin();
        std::cout << userInfo.username;
    

    while (1)
    {
        std::cout << "\n\n read / write / clear / logout / quit   YOUR CHOICE \n";
        std::cout << userInfo.username;
        std::cin >> userCommands.inputCommand;
    

        if (userCommands.inputCommand == "read")
        {
            userCommands.ReadMessages();
        }
    
        else if (userCommands.inputCommand == "write")
        {
            userCommands.WriteMessage(userInfo.username, userCommands.inputCommand);
        }
    
        else if (userCommands.inputCommand == "clear")
        {
            userCommands.ClearFile();
        }
    
        else if (userCommands.inputCommand == "logout")
        {
            userCommands.UserLogin();
        }
    
        else if (userCommands.inputCommand == "quit")
        {
            break;
        }
    
    }


    return 0;
}
