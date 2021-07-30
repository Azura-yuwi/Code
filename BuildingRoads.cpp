//CSES Graph
//UnionFind
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int head[100001];

int find(int src)
{
    if(head[src] == src)
    {
        return src;
    }

    head[src] = find(head[src]);
    return head[src];
}

bool unite(int a, int b) //true if connected
{
    a = find(a);
    b = find(b);

    if(a == b)
    {
        return true;
    }

    head[a] = b;

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int roads = n - 1;

    for(int i = 0; i < n; i++)
    {
        head[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        
        if(unite(a-1, b-1))
        {
            continue;
        }
        else
        {
            roads--;
        }
    }

    if(roads == 0)
    {
        cout << roads;
    }
    else
    {
        cout << roads << endl;
        vector<int> tops;

        for(int i = 0; i < n; i++)
        {
            if(find(i) == i)
            {
                tops.push_back(i);
            }
        }

        for(int i = 1; i < tops.size(); i++)
        {
            cout << (tops[0]+1) << " " << (tops[i]+1) << endl;
        }
    }

}