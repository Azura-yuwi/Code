//USACO Gold 2020 February
//Bitmask DP

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main()
{
    //ifstream fin("exercise.in");
    string s; 
    cin >> s;
    map<char, int> indexes;

    for(char c : s)
    {
        if(indexes.find(c) == indexes.end()) //not exist in there yet
        {
            indexes[c] = indexes.size() - 1;
        }
    }

    int uniq = indexes.size();
    int dp[1 << uniq];
    int pre[uniq][uniq];

    for(int i = 0; i < uniq; i++)
    {
        for(int j = 0; j < uniq; j++)
        {
            pre[i][j] = 0;
        }
    }
    
    for(int i = 1; i < s.length(); i++)
    {
        pre[indexes[s[i-1]]][indexes[s[i]]]++;
    }

    dp[0] = 1;

    for(int i = 1; i < (1 << uniq); i++) //mask
    {
        dp[i] = s.length();

        for(int j = 0; j < uniq; j++)
        {
            if((i & (1<<j)) != 0) //contains j
            {
                int sum = dp[i ^ (1<<j)]; 

                for(int k = 0; k < uniq; ++k)
                {
                    if((i & (1<<k)) != 0)
                    {
                        sum += pre[j][k];
                    }
                }

                dp[i] = min(dp[i], sum);
            }  
        }
    }

    cout << dp[(1<<uniq) - 1] << endl;
}