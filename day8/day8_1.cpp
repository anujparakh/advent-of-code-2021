#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <fstream>
#include <sstream>

#define ll long long

using namespace std;

char getFirstDiff(string smaller, string larger)
{
    for(ll i = 0; i < smaller.length(); ++i)
        if(smaller[i] != larger[i])
            return larger[i];
    return larger[larger.length() - 1];
}

ll getDigit(string text) {
    if(text == "abcefg")
        return 0;
    else if(text == "cf")
        return 1;
    else if(text == "acdeg")
        return 2;
    else if(text == "acdfg")
        return 3;
    else if(text == "bcdf")
        return 4;
    else if(text == "abdfg")
        return 5;
    else if(text == "abdefg")
        return 6;
    else if(text == "acf")
        return 7;
    else if(text == "abcdefg")
        return 8;
    else
        return 9;

}

int main()
{
    ifstream infile("input.txt");
    ll total = 0;
    while(!infile.eof())
    {
        map<ll, vector<string> > ordered;
        map<char, char> signals;
        for(ll i = 0; i < 10; ++i)
        {
            string x; infile >> x;
        }

        char waste; infile >> waste;
        for(ll i = 0; i < 4; ++i)
        {
            string word; infile >> word;
            if(word.length() == 2 || word.length() == 4 || word.length() == 3 || word.length() == 7)
                ++total;
        }
    }

    cout << total << endl;
    return 0;
}