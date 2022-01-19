#include <iostream>
#include <set>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile("in.txt");

    string directions;
    directions = string((istreambuf_iterator<char>(inFile)),istreambuf_iterator<char>());

    set<vector<int>> visitedHouse;
    vector<int> house{0,0}; //House at origin
    visitedHouse.insert(house); //House at origin already visited

    for(auto direction: directions)
    {
        if(direction=='>')
        {
            house[0]++;
            visitedHouse.insert(house); 
        }
        else if(direction=='^')
        {
            house[1]++;
            visitedHouse.insert(house); 
        }
        else if(direction=='<')
        {
            house[0]--;
            visitedHouse.insert(house); 
        }
        else if(direction=='v')
        {
            house[1]--;
            visitedHouse.insert(house); 
        }
    }
    cout << visitedHouse.size() << endl;
}