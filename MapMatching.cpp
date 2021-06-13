#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;

    for(int tcase = 0; tcase < t; tcase++)
    {
        cin >> n;
        ll cor1x[n];
        ll cor2x[n];
        ll cor1y[n];
        ll cor2y[n];

        int src1 = 0;
        int src2 = 0;

        for(int read = 0; read < n; read++)
        {
            cin >> cor1x[read] >> cor1y[read];

            if(cor1x[read] <= cor1x[src1] || (cor1x[read] == cor1x[src1] && cor1y[read] < cor1y[src1])) //take top left
            {
                src1 = read; //find start
            }
        }

        for(int read = 0; read < n; read++)
        {
            cin >> cor2x[read] >> cor2y[read];

            if(cor2x[read] < cor2x[src2] || (cor2x[read] == cor2x[src2] && cor2y[read] < cor2y[src2])) //top left
            {
                src2 = read;
            }
        }

        //SET scale

        ll dx1 = cor1x[(src1+1)%n] - cor1x[src1];
        ll dy1 = cor1y[(src1+1)%n] - cor1y[src1];
        ll dx2 = cor2x[(src2+1)%n] - cor2x[src2];
        ll dy2 = cor2y[(src2+1)%n] - cor2y[src2];

        bool work = false;

        if(dx1*dy2 == dx2*dy1)
        {
            work = true;
            ll sc1 = dx1; //scales
            ll sc2 = dx2;

            if(dx1 == 0)
            {
                sc1 = dy1;
                sc2 = dy2;
            }


            for(int i = 1; i < n; i++)
            {
                dx1 = cor1x[(src1+i+1)%n] - cor1x[(src1+i)%n];
                dy1 = cor1y[(src1+i+1)%n] - cor1y[(src1+i)%n];
                dx2 = cor2x[(src2+i+1)%n] - cor2x[(src2+i)%n];
                dy2 = cor2y[(src2+i+1)%n] - cor2y[(src2+i)%n];

                if(dx1*sc2 != dx2*sc1 || dy1*sc2 != dy2*sc1)
                {  
                    work = false;
                    break;
                }
            }
        }

        if(work)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

}