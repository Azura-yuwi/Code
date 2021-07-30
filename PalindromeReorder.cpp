//CSES Intro Set;
//Strings

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s; 
    cin >> s;

    vector<char> vec;
    unordered_set<char> set;

    for(int i = 0; i < s.length(); i++)
    {
        if(set.find(s[i]) != set.end())
        {
            set.erase(s[i]);
            vec.push_back(s[i]);
        }
        else
        {
            set.insert(s[i]);
        }
    }

    if(set.size() > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }

    for(char a : set)
    {
        cout << a;
    }

    for(int i = vec.size() - 1; i >= 0; i--)
    {
        cout << vec[i];
    }

}