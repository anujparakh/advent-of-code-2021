#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>

#define ll long long

using namespace std;

// ): 3 points.
// ]: 57 points.
// }: 1197 points.
// >: 25137 points.

ll getPoints(char c)
{
    if(c == '(')
        return 1;
    else if(c == '[')
        return 2;
    else if(c == '{')
        return 3;
    else if(c == '<')
        return 4;
    else
        return 0;
}

bool isClosing(char c)
{
    return (c == ')' || c == ']' || c == '>' || c == '}');
}

char getMatching(char c)
{
    if(c == ')')
        return '(';
    else if(c == ']')
        return '[';
    else if(c == '}')
        return '{';
    else if(c == '>')
        return '<';
    else
        return 0;
}

int main()
{
    vector <ll> allPoints;
    while(true)
    {
        string line;
        cin >> line;
        if(line == "end")
            break;
        stack<char> brackets;
        brackets.push(line[0]);
        bool isCorrupt = false;
        for(ll i = 1; i < line.length(); ++i)
        {
            if(isClosing(line[i]))
            {
                if(brackets.top() != getMatching(line[i]))
                {
                    // cout << "illegal " << line[i] << endl;
                    // total += getPoints(line[i]);
                    // corrupted
                    isCorrupt = true;
                    break;
                }
                brackets.pop();
            }
            else
                brackets.push(line[i]);
        }

        if(isCorrupt)
            continue;

        ll points = 0;
        while(!brackets.empty())
        {
            char x = brackets.top();
            brackets.pop();
            points *= 5;
            points += getPoints(x);
        }
        allPoints.push_back(points);
    }

    sort(allPoints.begin(), allPoints.end());
    for(auto x: allPoints)
        cout << x << " ";
    cout << endl;
    cout << allPoints[allPoints.size() / 2] << endl;
    return 0;
}