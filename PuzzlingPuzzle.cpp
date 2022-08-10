#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

//1 = protruding 0 = hole

vector<int> type11; //1
vector<int> type00; //4
vector<int> type10; //2
vector<int> type01; //3
vector<int> ans;
int start, last, startVal, lastVal;

int main()
{
    int n; cin >> n;

    for(int i = 0; i < n; i++)
    {
        int get, type; cin >> type >> get;

        if(type == 1)
        {
            type11.pb(get);
        }
        else if(type == 2)
        {
            type10.pb(get);
        }
        else if(type == 3)
        {
            type01.pb(get);
        }
        else if(type == 4)
        {
            type00.pb(get);
        }
        else if(type == 5)
        {
            start = 1; startVal = get;
        }
        else if(type == 6)
        {
            start = 0; startVal = get;
        }
        else if(type == 7)
        {
            last = 1; lastVal = get;
        }
        else if(type == 8)
        {
            last = 0; lastVal = get;
        }
    }

    sort(type11.begin(), type11.end());
    sort(type00.begin(), type00.end());
    sort(type10.begin(), type10.end());
    sort(type01.begin(), type01.end());
    ans.pb(startVal);

    if(start == 1)
    {
        start = 0; last = 1^last;
        swap(type11, type00);
        swap(type01, type10);
    }

    //from now start = 0;

    if(start != last) //last = 1
    {
        if(type11.size() != type00.size())
        {
            cout << -1; return 0;
        }

        if(type11.size() == 0)
        {
            if(type01.size() != 0)
            {
                cout << -1; return 0;
            }

            for(int i = 0; i < type10.size(); i++)
            {
                ans.pb(type10[i]);
            }
        }
        else
        {
            int p1 = 0; int p2 = 0;

            for(int i = 0; i < type11.size(); i++)
            {
                while(p1 < type10.size() && type10[p1] < type11[i])
                {
                    ans.pb(type10[p1]); p1++;
                }

                ans.pb(type11[i]);

                while(p2 < type01.size() && (i == type11.size()-1 ||type01[p2] < type00[i]))
                {
                    ans.pb(type01[p2]); p2++;
                }

                ans.pb(type00[i]);
            }

            while(p1 < type10.size())
            {
                ans.pb(type10[p1]); p1++;
            }
        }
    }
    else //last = 0
    {
        if(type11.size() != type00.size()+1)
        {
            cout << -1; return 0;
        }

        int p1 = 0; int p2 = 0;

        for(int i = 0; i < type00.size(); i++)
        {
            while(p1 < type10.size() && type10[p1] < type11[i])
            {
                ans.pb(type10[p1]); p1++;
            }

            ans.pb(type11[i]);

            while(p2 < type01.size() && type01[p2] < type00[i])
            {
                ans.pb(type01[p2]); p2++;
            }

            ans.pb(type00[i]);
        }

        while(p1 < type10.size())
        {
            ans.pb(type10[p1]); p1++;
        }

        ans.pb(type11[type11.size()-1]);

        while(p2 < type01.size())
        {
            ans.pb(type01[p2]); p2++;
        }
    }

    ans.pb(lastVal);

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}