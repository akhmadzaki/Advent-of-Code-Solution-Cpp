#include <iostream>
#include <set>
#include <vector>
#include <fstream>

using namespace std;

void deliverPresent(char command, set<vector<int>> &visitedHouse, vector<int> &house)
{
    if(command=='>')
        {
            house[0]++;
            visitedHouse.insert(house); 
        }
        else if(command=='^')
        {
            house[1]++;
            visitedHouse.insert(house); 
        }
        else if(command=='<')
        {
            house[0]--;
            visitedHouse.insert(house); 
        }
        else if(command=='v')
        {
            house[1]--;
            visitedHouse.insert(house); 
        }
}

int main()
{
    ifstream inFile("in.txt");

    string directions;
    directions = string((istreambuf_iterator<char>(inFile)),istreambuf_iterator<char>());

    set<vector<int>> visitedHouse;
    vector<int> santaHouse{0,0}; //House at origin
    vector<int> roboHouse{0,0}; //House at origin
    visitedHouse.insert(santaHouse); //House at origin both visited by Santa and Robo at the start

    for(int i=0; i<directions.length(); i++)
    {
        if(i%2==0)
            deliverPresent(directions[i],visitedHouse,santaHouse);
        else
            deliverPresent(directions[i],visitedHouse,roboHouse);
    }
    cout << visitedHouse.size() << endl;
}