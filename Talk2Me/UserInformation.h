#pragma once
#include <string>
#include <iostream>
#include <list>
#include <vector>

struct UserInformation
{
    std::string username;
    std::string* ptrusername = &username;

    std::string coworker;

    std::vector<std::string> myMessages;

    std::vector <std::string> coworkerMessages;
};