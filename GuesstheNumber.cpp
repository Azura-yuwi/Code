#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, find;
    cin >> n >> find;

    int left = 1;
    int right = n+1;

    while(left != right)
    {
        int mid = (left + right)/2;

        if(mid > find)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }

        cout << left << " " << right << " " << mid << " " << find << endl;
    }
    cout << "ANSWER IS " << (left-1);
}