#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool countVowel(string input)
{
    int vowelCount=0;
    for(auto letter:input)
    {
        if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            vowelCount++;
    }
    return (vowelCount>=3);
}

bool countDouble(string input)
{
    vector<string> doubleLetters{"aa","bb","cc","dd",
                                  "ee","ff","gg","hh",
                                  "ii","jj","kk","ll",
                                  "mm","nn","oo","pp",
                                  "qq","rr","ss","tt",
                                  "uu","vv","ww","xx",
                                  "yy","zz"};
    int doubleCount=0;
    for(auto doubleLetter:doubleLetters)
    {
        if(input.find(doubleLetter,0)!=string::npos) doubleCount++;
    }
    return doubleCount>0;
}

bool noForbiddenStr(string input)
{
    vector<string> forbiddenStr{"ab","cd","pq","xy"};
    int forbidCount=0;
    for(auto forbid:forbiddenStr)
    {
        if(input.find(forbid,0)!=string::npos) forbidCount++;
    }
    return !(forbidCount>0);
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
        if(countVowel(word) && countDouble(word) && noForbiddenStr(word))
            niceStr++;
    }

    cout << niceStr << endl;
    
}