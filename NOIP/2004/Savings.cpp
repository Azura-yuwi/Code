#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair


int main()
{
    int budget[12];

    for(int i = 0; i < 12; i++)
    {
        cin >> budget[i];
    }

    int tot = 0; 
    int ans = -1;
    int gave = 0;

    for(int i = 0; i < 12; i++)
    {
       // tot %= 100;
        tot += (300 - budget[i]);
        
        if(tot < 0)
        {
            ans = (i+1); break;
        }

        gave += tot/100;
        tot %= 100;
        //cout << budget[i] << " " << tot << " " << gave << endl;
    }

    if(ans != -1)
    {
        cout << (-1)*ans;
    }
    else
    {
        cout << tot + gave*120;
    }
}