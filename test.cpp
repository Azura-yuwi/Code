#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int gcd(int a, int b)
{
    if (a > b)
    {
        int temp = a;
        a = b; b = temp;
    }

    while(b%a != 0)
    {
        int temp = a;
        a = b%a; b = temp;
    }

    return a;
}

int main()
{
    ofstream fout ("windows.out");
    ifstream fin ("windows.in");

    int a,b; cin >> a >> b;
    cout << gcd(a,b) << endl;

}