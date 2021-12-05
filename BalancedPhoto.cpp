#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    ofstream fout ("bphoto.out");
    ifstream fin ("bphoto.in");

    int n; fin >> n;
    int val[n];
    int l[n];
    int r[n];

    for(int i = 0; i < n; i++)
    {
        fin >> val[i]; l[i] = 0; r[i] = 0;
        
        for(int j = 0; j < i; j++)
        {
            if(val[i] > val[j])
            {
                r[j]++; 
            }
            if(val[j] > val[i]) 
            {
                l[i]++;
            }
        }
    }

    int num = 0;

    for(int i = 0; i < n; i++)
    {
       // cout << i << " " << l[i] << " " << r[i] << " " << num << endl;
        if(max(r[i],l[i]) > min(r[i], l[i])*2)
        {
            num++;
        }
    }

    fout << num;
}