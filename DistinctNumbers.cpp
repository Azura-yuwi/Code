//CSES Sorting and Searching Set
//Binary Search?

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    unordered_set<int> set;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int get;
        cin >> get;
        set.insert(get);
    }

    cout << set.size();
}