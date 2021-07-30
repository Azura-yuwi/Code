//USACO Guide
//Topological Sort

//could be modulized better...

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    int n1, n2, m1, m2;
    cin >> n1  >> n2 >> m1 >> m2;

    int in1[n1];
    int in2[n2];

    vector<int> adj1[n1];
    vector<int> adj2[n2];

    unordered_set<int> path1[n1];
    unordered_set<int> path2[n2];

    for(int i = 0; i < n1; i++)
    {
        in1[i] = 0;
    }

    for(int i = 0; i < n2; i++)
    {
        in2[i] = 0;
    }

    for(int i = 0; i < m1; i++)
    {
        int a,b;
        cin >> a >> b;
        adj1[a-1].pb(b-1);
        in1[b-1]++;
    }

    for(int i = 0; i < m2; i++)
    {
        int a,b;
        cin >> a >> b;
        adj2[a-1].pb(b-1);
        in2[b-1]++;
    }

    queue<int> q1;

    for(int i = 0; i < n1; i++)
    {
        if(in1[i] == 0)
        {
            q1.push(i);

            if(i == 0)
            {
                path1[i].insert(0);
            }
        }
    }

   // cout << "START PROCESS 1" << endl;

    while(!q1.empty())
    {
        int get = q1.front();
        q1.pop();
        
        //cout << "GET "  << get << endl;

        for(int i : adj1[get])
        {
            if(in1[i] > 0) //if == 0, you would have visited before
            {
                in1[i]--;

                for(int j : path1[get])
                {
                    path1[i].insert((j+1));
                }
                
                if(in1[i] == 0)
                {
                    q1.push(i);
                }
            }
        } 
    }

    //cout << "END PROCESS 1" << endl;
    //cout << endl;

    queue<int> q2;

    for(int i = 0; i < n2; i++)
    {
        if(in2[i] == 0)
        {
            q2.push(i);

            if(i == 0)
            {
                path2[i].insert(0);
            }
        }
    }

    //cout << "START PROCESS 2" << endl;

    while(!q2.empty())
    {
        int get = q2.front();
        //cout << "GET " << get << endl;
        q2.pop();

        for(int i : adj2[get])
        {
            if(in2[i] > 0) //if == 0, you would have visited before
            {
                in2[i]--;

                for(int j : path2[get])
                {
                    path2[i].insert((j+1));
                }
                
                if(in2[i] == 0)
                {
                    q2.push(i);
                }
            }
        } 
    }

    //cout << "END PROCESS 2 " << endl;

    unordered_set<int> allpos;

    for(int i : path1[n1-1])
    {
        for(int j : path2[n2-1])
        {
            allpos.insert((i+j));
        }
    }

    int queries;
    cin >> queries;

    for(int i = 0; i < queries; i++)
    {
        int sum;
        cin >> sum;

        if(allpos.find(sum) == allpos.end())
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }

}