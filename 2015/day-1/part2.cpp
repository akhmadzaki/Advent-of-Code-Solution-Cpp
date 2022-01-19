#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string filePath("in.txt");
    string commands;

    ifstream inFile(filePath);

    if(!inFile.is_open())
    {
        cerr << "Could not open the file : " << filePath << endl;
        exit(EXIT_FAILURE);
    }

    commands = string((istreambuf_iterator<char>(inFile)),istreambuf_iterator<char>());

    int currentFloor = 0; //Initial floor is 0
    int currentPosition = 0; 

    for(auto command: commands)
    {
        if(command=='(') currentFloor++;
        else if(command==')')  currentFloor--;
        currentPosition++; //Current command position 
        if(currentFloor==-1) break; //If hit basement (-1), break from the loop
    }

    cout << currentPosition << endl;

}

