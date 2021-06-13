#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;

    int n = s.size();
    int num[26] = {0};

    for(int i = 0; i < n; i++)
    {
        int get = s.at(i) - 'a';
        num[get]++;
    }

    int getmin = INT_MAX;

    for(int i = 0; i < 26; i++)
    {
        if(num[i] > 0)
        {
            getmin = min(getmin, num[i]);
        }
    }

    //cout << getmin << endl;

    bool div = false;
    int divNum = 0;

    for(int i = 2; i <= getmin; i++)
    {
        div = true;
        divNum = i;

        for(int j = 0; j < 26; j++)
        {
            if(num[j]%i != 0)
            {
                div = false;
                break;
            }
        }

        if(div)
        {
            break;
        }
    }

    if(div)
    {  
        for(int i = 0; i < divNum; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                char print = 'a' + j;

                for(int mult = 0; mult < (num[j]/divNum); mult++)
                {
                    cout << print;
                }
            }
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}