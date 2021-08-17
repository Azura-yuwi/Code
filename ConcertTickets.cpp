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

    vector<int> price;

    for(int i = 0; i < n; i++)
    {
        int get; cin >> get; price.pb(get);
    }
    
    price.pb(0); 
    price.pb(INT_MAX);
    sort(price.begin(), price.end());

    for(int i = 0; i < m; i++)
    {
        int want;
        cin >> want;

        int ind = lower_bound(price.begin(), price.end(), want) - price.begin();

        if(price[ind] != want)
        {
            ind--;
        }

        //cout << ind << " " << price[ind] << endl;
        
        if(ind > 0)
        {
            cout << price[ind] << endl;
            price.erase(price.begin() + ind);
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
