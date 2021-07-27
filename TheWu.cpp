#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lar = 2050;

int binary(string get)
{
    int base = 1;
    int ans = 0;

    for(int i = get.size() -1; i >= 0; i--)
    {
        if(get.at(i) == '1')
        {
            ans += base;
        }

        base *= 2;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m ,q;
    cin >> n >> m >> q;

    int val[n];

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
        cout << i << " " << val[i] << endl;
    }

    int tot[m];

    for(int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        int sbin = binary(s);
        tot[i] = sbin; //could optimize here
        //cout << s << " " << sbin << endl;
    }

    int wus[lar];

    cout << (1 << 1) << endl;

    for(int i = 0; i < pow(2,n); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i&(1<<j)) != 0)
            {
                wus[i] += val[n-j-1];
                //cout << i << " ADDED" << j << " " << val[n-j-1] << endl;
            }
        }
        //cout << i << " " << wus[i] << endl;
    }

    for(int i = 0; i < q; i++)
    {
        string query;
        cin >> query;
        int qbin = binary(query);
        int wuVal;
        cin >> wuVal;
        int ans = 0;

        cout << "Query " << qbin << endl;

        for(int j = 0; j < m; j++)
        {
            int overlap = (~(qbin^tot[j]));

            cout << overlap << " " << tot[j] << endl;

            if(wus[overlap] <= wuVal)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }

}