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
    if(c == ')')
        return 3;
    else if(c == ']')
        return 57;
    else if(c == '}')
        return 1197;
    else if(c == '>')
        return 25137;
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
    ll total = 0;
    while(true)
    {
        string line;
        cin >> line;
        if(line == "end")
            break;
        stack<char> brackets;
        brackets.push(line[0]);
        for(ll i = 1; i < line.length(); ++i)
        {
            if(isClosing(line[i]))
            {
                if(brackets.top() != getMatching(line[i]))
                {
                    // cout << "illegal " << line[i] << endl;
                    total += getPoints(line[i]);
                    break;
                }
                brackets.pop();
            }
            else
                brackets.push(line[i]);
        }

    }

    cout << total << endl;
    return 0;
}