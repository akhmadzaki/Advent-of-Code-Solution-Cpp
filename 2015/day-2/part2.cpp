#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inFile("in.txt");

    vector<string> dimensions;
    string dimension;

    while(getline(inFile,dimension)) //Read puzzle input line by line
    { 
        dimensions.push_back(dimension); //Insert each line into the vector for further processing
    }

    int ribbon = 0;

    for(auto dimension:dimensions) //Process each line of present's dimension
    {
        stringstream dims(dimension);
        string dim;
        vector<int> boxDim;
        while(getline(dims,dim,'x')) //Split each line of box dimension by delimiter 'x'
        {
            boxDim.push_back(stoi(dim));
        }
        sort(boxDim.begin(),boxDim.end()); //Sort the box dim value
        ribbon += 2*boxDim[0] + 2*boxDim[1] + boxDim[0]*boxDim[1]*boxDim[2]; // Smallest perimeter of the box + Box's volume
    }
    cout << ribbon << endl;
}