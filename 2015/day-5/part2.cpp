#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool repeatLetter(string input)
{
    for(int i=0;i<input.length()-2;i++)
    {
        if(input[i]==input[i+2]) return true;
    }
    return false;
}

bool pairLetter(string input)
{
    for(int i=0;i<input.length()-2;i++)
    {
        string pair=input.substr(i,2);
        string leftSubstr = "";
        string rightSubstr = "";
        if(i>=2)
            leftSubstr = input.substr(0,i);
        if(i<=input.length()-3)
            rightSubstr = input.substr(i+2,string::npos);
        if(leftSubstr.find(pair)!=string::npos || rightSubstr.find(pair)!=string::npos)
            return true;
    }
    return false;
}

int main()
{
    ifstream inFile("in.txt");
    string input;
    vector<string> inputWords;
    int niceStr=0;

    while(getline(inFile,input))
    {
        inputWords.push_back(input);
    }

    for(auto word:inputWords)
    {
        if(repeatLetter(word) && pairLetter(word))
            niceStr++;
    }
    cout << niceStr << endl;
    
}