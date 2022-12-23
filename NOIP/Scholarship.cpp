#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;
    string name[n];
    int num[n];
    int ind = 0;
    int tot = 0;

    for(int i = 0; i < n; i++)
    {
        int grd, eval, pp; char lead, west;
        cin >> name[i] >> grd >> eval >> lead >> west >> pp;
        //cout << name[i] << " " << grd << " " << eval << " " << lead << " " << west << " " << pp << endl;
        num[i] = 0;

        if(grd > 80 && pp > 0) num[i] += 8000;
        if(grd > 85 && eval > 80) num[i] += 4000;
        if(grd > 90) num[i] += 2000;
        if(grd > 85 && west == 'Y') num[i] += 1000;
        if(eval > 80 && lead == 'Y') num[i] += 850;
        
        if(num[ind] < num[i]) ind = i;
        tot += num[i];
    }

    cout << name[ind] << endl;
    cout << num[ind] << endl;
    cout << tot;



}