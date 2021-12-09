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
            sort(x.begin(), x.end());
            ordered[x.length()].push_back(x);
        }

        // Assume c and f
        signals['c'] = ordered[2][0][0];
        signals['f'] = ordered[2][0][1];
        signals['a'] = getFirstDiff(ordered[2][0], ordered[3][0]);
        string bd;
        for(auto c: ordered[4][0])
            if(c != signals['c'] && c != signals['f'])
                bd += (c);
        signals['b'] = bd[0];
        signals['d'] = bd[1];

        string threeString;
        for(auto fives: ordered[5])
        {
            if(fives.find(signals['c']) != string::npos && fives.find(signals['f']) != string::npos)
            {
                threeString = fives;
                break;
            }
        }
        for(auto c: threeString)
        {
            if(c == signals['b']) // guess was wrong
            {
                signals['b'] = signals['d'];
                signals['d'] = c;
            }
            else if(c != signals['c'] && c != signals['f'] && c != signals['a'] && c != signals['d'])
            {
                signals['g'] = c;
            }
        }

        // now we know a, b, d, g for sure and c and f maybe
        string fiveString;
        for(auto fives: ordered[5])
        {
            if(fives.find(signals['b']) != string::npos)
            {
                fiveString = fives;
                break;
            }
        }

        for(auto c: fiveString)
        {
            if(c == signals['c']) // guessed wrong
            {
                signals['c'] = signals['f'];
                signals['f'] = c;
            }
        }

        string full = "abcdefg";
        map <char, char> reverseSignals;
        for(auto c: full)
            reverseSignals[signals[c]] = c;

        for(auto c: full)
            if(reverseSignals[c] == 0)
            {
                cout << "stopped at " << c << endl;
                reverseSignals[c] = 'e';
            }

        for(auto c: full)
            cout << c << " -> " << reverseSignals[c] << endl;


        char waste; infile >> waste;
        ll multiplier = 1000;
        ll num = 0;
        for(ll i = 0; i < 4; ++i)
        {
            string word; infile >> word;
            cout << "x: " << word << endl;
            string digitString = "";

            for(auto c: word)
                digitString += reverseSignals[c];
            sort(digitString.begin(), digitString.end());
            cout << digitString << endl;
            ll digit = getDigit(digitString);
            num += digit * multiplier;
            multiplier /= 10;
        }
        total += num;

    }

    cout << total << endl;
    return 0;
}