#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n; 
int num[51];
vector<bool> edges; //true = *
int smal[51][51];
int big[51][51];
int MX;
vector<int> ans;

void simulate(int shift)
{
    int at;

    for(int i = 0; i < n; i++)
    {
        at = (i+shift)%n;
        smal[i][i] = num[at];
        big[i][i] = num[at];
    }

    int eInd;
    int v1, v2, v3, v4;

    for(int l = 1; l < n; l++)
    {
        for(int i = 0; i < (n-l); i++)
        {
            smal[i][i+l] = INT_MAX;
            big[i][i+l] = INT_MIN;

            for(int k = i+1; k <= l+i; k++) //edge
            {
                eInd = (k+shift)%n;

                if(edges[eInd]) //multiplication
                {
                    v1 = smal[i][k-1] * smal[k][i+l];
                    v2 = big[i][k-1] * big[k][i+l];
                    v3 = big[i][k-1] * smal[k][i+l];
                    v4 = smal[i][k-1] * big[k][i+l];

                    smal[i][i+l] = min(smal[i][i+l], min(v1, min(v2, min(v3, v4))));
                    big[i][i+l] = max(big[i][i+l], max(v1, max(v2, max(v3, v4))));
                }
                else
                {
                    smal[i][i+l] = min(smal[i][i+l], smal[i][k-1] + smal[k][i+l]);
                    big[i][i+l] = max(big[i][i+l], big[i][k-1] + big[k][i+l]);
                }
            }
        }
    }

    if(big[0][n-1] == MX)
    {
        ans.pb(shift);
    }
    else if(big[0][n-1] > MX)
    {
        MX = big[0][n-1]; ans.clear(); ans.pb(shift);
    }
}

int main()
{
    cin >> n;

    MX = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        char c; int get; cin >> c >> get;

        if(c == 't')
        {
            edges.pb(false);
        }  
        else
        {
            edges.pb(true);
        }

        num[i] = get;
    }

    for(int i = 0; i < n; i++)
    {
        simulate(i);
    }

    cout << MX << endl;
    
    for(int i = 0; i < ans.size(); i++)
    {
        cout << (ans[i]+1) << " ";
    }
}
