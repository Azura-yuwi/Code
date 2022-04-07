#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int t, k;
    cin >> t >> k;

    double comb[t]; //binomial
    comb[0] = 1;

    for (int i = 1; i < t; i++)
    {
        comb[i] = comb[i-1]*(t-i)/i;
    }

    double ev = 0;
    double p = 0;
    int mid = (t+1)/2;

    for (int i = t-1; i >= mid; i--)
    {
        ev += i*comb[i];
        p += comb[i];
    }

    double ans = 1;
    double two = pow(2, t-1);
    double p1 = (double)ev/two; 
    double prob1 = (double)p/two;

    p1 *= (1 - pow(prob1, k-1))/(1-prob1); //geo
    double p2 = (double)(t-1)*pow(prob1, k-1)/2;
    double p3 = 0;

    if (t%2 == 1) 
    {
        mid = (t-1)/2;
        p3 = (double)mid*comb[mid]/two;
    }

    ans += p1 + p2 + p3;

    cout << ans << endl;
}
