//CSES Sorting and Searching

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n,m; 
    cin >> n >> m;

    multiset<int, greater<int>> set;

    for(int i = 0; i < n; i++)
    {
        int get; cin >> get;
        set.insert(get);
    }

    for(int i = 0; i < m; i++)
    {
        int get; cin >> get;
        auto to = set.lower_bound(get); //this works now b/c we sorted set from large to small

        if(to == set.end()) 
        {
            cout << -1 << endl;
        }
        else 
        {
            cout << *to << endl;
            set.erase(to);
        }
    }

}

//multiset -> deletion = log n ; find = log n; lower_bound = log n -> overall mlogn not nm