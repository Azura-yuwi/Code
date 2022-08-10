//literal joke solution
//so made O(1) solution jeez

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    ifstream fin("walk.in");
    ofstream fout("walk.out");
    int n,k; fin >> n >> k;
    int i = k-1; ll ans = 84*i + 48*n;
    fout << 2019201997L - ans;
}
