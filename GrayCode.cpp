//CSES Intro Set;
//Strings/AdHoc

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    vector<string> gc[17];

    gc[0].pb("");

    for(int i = 1; i < 17; i++)
    {
        for(int j = 0; j < gc[i-1].size(); j++)
        {
            gc[i].pb("0"+gc[i-1][j]);
        }

        for(int j = gc[i-1].size()-1; j >= 0; j--)
        {
            gc[i].pb("1"+gc[i-1][j]);
        }
    }

    int n;
    cin >> n;

    for(string s : gc[n])
    {
        cout << s << endl;
    }

}