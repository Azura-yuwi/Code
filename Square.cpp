//GPL Problem 3

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;

    ll dx = bx - ax;
    ll dy = by - ay;

    cout << (ax + dy) << " " << (ay - dx) << endl;
    cout << (bx + dy) << " " << (by - dx) << endl;
}