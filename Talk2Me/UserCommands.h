#pragma once
#include <string>
#include "UserInformation.h"

class UserCommands
{
public:
    void UserLogin();
    void ClearFile();
    void WriteMessage(std::string user, std::string text);
    void ReadMessages();

    std::string inputCommand;
    std::string* ptrinputCommand = &inputCommand;

    std::string fileNameCheck;
     
    UserInformation userInfo;
};
