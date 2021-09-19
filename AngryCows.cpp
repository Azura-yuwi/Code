//USACO Gold 2016 January
//greedyish/dp ish

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    int n; fin >> n;

    int val[n];
    int left[n];
    int right[n];

    for(int i = 0; i < n; i++)
    {
        left[i] = INT_MAX - 100; 
        right[i] = INT_MAX - 100;
        fin >> val[i];
    }

    sort(val, val+n);

    left[0] = 0;
    int last = 0;

    for(int i = 1; i < n; i++) //left should be non-decreasing, val[i] - val[lst] is nonincreasing
    {
        if(val[i-1] == val[i]) //didn't move
        {
            left[i] = left[i-1];
        }
        else
        {  
            while(last + 1 < i && val[i] - val[last+1] > left[last+1] + 1) //**at one point, only update left[i] = left[prev] + 1; look for this point
            {
                last++; //otherwise, you get two segments that are stictly increasing/decreasing
            }

            left[i] = min(val[i] - val[last], left[last+1]+1); //denote last vs denote last+1
        }
    }

    right[n-1] = 0;
    last = n-1;

    for(int i = n-2; i >= 0; i--)
    {
        if(val[i] == val[i+1])//didn't move
        {
            right[i] = right[i+1];
        }
        else
        {
            while(last - 1 > i && val[last-1] - val[i] > right[last-1] + 1)
            {
                last--;
            }

            right[i] = min(val[last] - val[i], right[last-1] + 1);
        }
    }

    double ans = 1e9;
    int i = 0;
    int j = n-1;

    while(i < j)
    {
        double mid = (double(val[j] - val[i]))/2;
        ans = min(ans, max(mid, max(left[i], right[j]) + (double)1));

        if(left[i+1] < right[j-1])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    fout << fixed << setprecision(1) << ans;
}
