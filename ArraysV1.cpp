#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n;

ll grid[500][500];
ll rpre[500][500];
ll rsuf[500][500];
ll rowSum[500];
ll arow[500][500];
ll cpre[500][500];
ll csuf[500][500];

void printGrid()
{
    cout << "printing" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arow[i][j] << " ";
        }

        cout << endl;
    }
}

void printGrid1()
{
    cout << "printing" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << cpre[i][j] << " ";
        }

        cout << endl;
    }
}


void printGrid2()
{
    cout << "printing" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << csuf[i][j] << " ";
        }

        cout << endl;
    }
}



int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        rowSum[i] = 0;

        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            rpre[i][j] = 0;
            rsuf[i][j] = 0;
            rowSum[i] += grid[i][j];
        }
    } 

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                rpre[i][k] += grid[i][j]*(k-j);
            }
        }
    } 

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = j-1; k >= 0; k--)
            {
                rsuf[i][k] += grid[i][j]*(j-k);
            }
        }
    } 

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arow[i][j] = 0;
            arow[i][j] += rpre[i][j];
            arow[i][j] += rsuf[i][j];
            //arow[i][j] += grid[i][j];

            cpre[i][j] = 0;
            csuf[i][j] = 0;
        }
    }

    //printGrid();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                cpre[k][i] += rowSum[j]*(k-j) + arow[j][i];

                //cpre[k][i] += grid[j][i]*(k-j);
            }
        }
    } 

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = j-1; k >= 0; k--)
            {
                //csuf[k][i] += (arow[j][i])*(j-k);
                //csuf[k][i] += grid[j][i]*(j-k);
                csuf[k][i] += rowSum[j]*(j-k) + arow[j][i];
            }
        }
    } 

    ll ans = LLONG_MAX;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ll get = 0;
            get += cpre[i][j];
            get += csuf[i][j];
            get += arow[i][j];

            ans = min(ans, get);
        }
    }

   //printGrid1();
   //printGrid2();

    cout << ans;
}