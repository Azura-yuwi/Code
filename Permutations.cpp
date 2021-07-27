//CSES Intro Set
//Number Theory???

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n; 
    cin >> n;

    if(n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << flush;
    }
    else
    {
        for(int i = 2; i <= n; i++)
        {
            cout << i << " ";
            i++;
        }

        cout << "1";

        for(int i = 3; i <= n; i++)
        {
            cout << " " << i;
            i++;
        }
    }
}