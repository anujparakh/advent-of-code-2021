#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <algorithm>

#define ll long long

using namespace std;


void tokenize(const std::string &s, const char delim,
            std::vector<std::string> &out)
{
    std::string::size_type beg = 0;
    for (auto end = 0; (end = s.find(delim, end)) != std::string::npos; ++end)
    {
        out.push_back(s.substr(beg, end - beg));
        beg = end + 1;
    }

    out.push_back(s.substr(beg));
}

bool isSmall(string x)
{
    return (x[0] >= 'a' && x[0] <= 'z');
}

ll countPaths(map<string, vector<string> > &connections, map<string, bool> visited, string current, bool oneChance)
{
    ll toReturn = 0;

    if(current == "end")
        return 1;
    else if(isSmall(current) && visited[current])
    {
        // if(oneChance)
        //     return 0;
        // else
        //     oneChance = true;
        return 0;
    }

    visited[current] = true;

    for(auto connection: connections[current])
    {
        if(connection == "start") // Skip
            continue;
        // Recursive
        toReturn += countPaths(connections, visited, connection, oneChance);
    }

    return toReturn;
}

int main()
{
    map<string, vector<string> > connections;
    while(true)
    {
        string line;
        vector<string> out;
        cin >> line;
        if(line == "end")
            break;
        tokenize(line, '-', out);
        // Create 2 way connection
        connections[out[0]].push_back(out[1]);
        connections[out[1]].push_back(out[0]);

        // cout << "created " << out[0] << " -> " << out[1] << endl;
    }

    map<string, bool> visited;
    cout << countPaths(connections, visited, "start", false) << endl;

    return 0;
}