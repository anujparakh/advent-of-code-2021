#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>

#define ll unsigned long long
using namespace std;

struct charPair {
    char first, second;
    charPair(char a, char b)
    {
        first = a; second = b;
    }

    charPair(string x)
    {
        first = x[0]; second = x[1];
    }

    bool operator==(const charPair &o) const {
        return first == o.first && second == o.second;
	}

	bool operator<(const charPair &o)  const {
        return first < o.first || (first == o.first && second < o.second);
	}
};


int main()
{
    map<charPair, char> insertionRules;
    vector<charPair> currentPairs;
    map<charPair, ll> mapPairs;
    string current; cin >> current;
    char firstLetter = current[0]; char lastLetter = current[current.size() - 1];
    for(ll i = 0; i < current.size() - 1; ++i)
    {
        ++mapPairs[charPair(current[i], current[i + 1])];
    }

    while(true)
    {
        string aPair; cin >> aPair;
        if(aPair == "end")
            break;
        string waste; cin >> waste;
        char insert; cin >> insert;
        insertionRules[charPair(aPair)] = insert;
    }

    for(ll i = 0; i < 40; ++i)
    {
        // vector<charPair> newPairs;
        // for(auto x: currentPairs)
        // {
        //     char insertion = insertionRules[x];
        //     newPairs.push_back(charPair(x.first, insertion));
        //     newPairs.push_back(charPair(insertion, x.second));
        // }
        // currentPairs = newPairs;
        map<charPair, ll> newPairs;
        for(auto x: mapPairs)
        {
            char insertion = insertionRules[x.first];
            newPairs[charPair(x.first.first, insertion)] += x.second;
            newPairs[charPair(insertion, x.first.second)] += x.second;
        }
        mapPairs = newPairs;
        cout << " step " << i + 1 << " finished\n";
    }

    map<char, ll> charCounts;
    for(auto x: mapPairs)
    {
        charCounts[x.first.first] += x.second;
        charCounts[x.first.second] += x.second;
    }
    // --charCounts[firstLetter];
    // --charCounts[lastLetter];

    ll lowest = -1; ll highest = 0;
    for(auto &x: charCounts)
    {
        x.second = ceil(x.second / 2.0);
        cout << x.first << "->" << x.second << endl;
        if(x.second < lowest || lowest == -1)
            lowest = x.second;
        if(x.second > highest)
            highest = x.second;
    }

    cout << highest << " " << lowest << endl;
    cout << highest - lowest << endl;

    return 0;
}