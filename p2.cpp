#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    int n; cin >> n;  ll h[n]; int q;

    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cin >> q;

    for(int k = 0; k < q; k++)
    {
        int ind; ll inc; cin >> ind >> inc; ind--;
        h[ind] += inc;
        int tot = 0;

        for(int i = 0; i < n; i++)
        {
            int hiInd = -1; int loInd = -1; int eqInd = -1; 

            for(int j = i+1; j < n; j++)
            {
                if(h[j] > h[i])
                {
                    if(hiInd == -1 || (h[j]-h[i])*(hiInd-i) >= (h[hiInd] - h[i])*(j-i))
                    {  
                        hiInd = j; tot++;// cout << "(" << i << "," << j << "), ";
                    }
                }
                else if(h[j] == h[i])
                {
                    if(hiInd == -1)
                    {
                        eqInd = j; tot++; //cout << "(" << i << "," << j << "), ";
                    }
                }
                else //h[j] < h[i]
                {
                    if(hiInd == -1 && eqInd == -1)
                    {
                        if(loInd == -1 || (h[i] - h[j])*(loInd - i) <= (h[i] - h[loInd])*(j-i))
                        {
                            loInd = j; tot++; //cout << "(" << i << "," << j << "), ";
                        }
                    }
                }
            }
        }
      //  cout << endl;
        cout << tot << endl;
    }
}