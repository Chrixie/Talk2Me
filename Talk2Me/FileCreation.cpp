#include "Filecreation.h"
#include <fstream>


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