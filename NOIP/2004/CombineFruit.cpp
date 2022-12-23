#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pq; 

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a; pq.push(a);
    }   

    ll tot = 0;

    for(int i = 1; i < n; i++)
    {
        ll g1 = pq.top(); pq.pop(); ll g2 = pq.top(); pq.pop();
        ll sum = g1+g2;
        tot += sum; pq.push(sum);
    }

    cout << tot;
}