#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

string lola[2000];
string dawn[2000];
int l,d;

bool sim(int i, int len, int who)
{
    if(who == 0)
    {
        bool overall = false;

        for(int j = 0; j < d; j++)
        {
            if(dawn[j].length() > len && dawn[j].substr(0, len) == lola[i].substr(0,len))
            {
                bool get = sim(j, len+1, 1);

                if(get == true)
                {
                    overall = true; 
                    return false;
                    //break;
                }
            }
        }

        return true;
    }
    else
    {
        bool overall = false;

        for(int j = 0; j < l; j++)
        {
            if(lola[j].length() > len && lola[j].substr(0, len) == dawn[i].substr(0,len))
            {
                bool get = sim(j, len+1, 0);

                if(get == true)
                {
                    overall = true; 
                    return false;
                }
            }
        }
        
        return true;
    }

    return true;
}

bool simulate()
{
    for(int i = 0; i < l; i++)
    {
        bool get = sim(i,1,0);

        if(get)
        {
            return true;
        }    
    }

    return false;
}

int main()
{
    cin >> l;

    for(int i = 0; i < l; i++)
    {
        cin >> lola[i];
    }

    cin >> d;
    for(int i = 0; i < d; i++)
    {
        cin >> dawn[i];
    }

    bool ans = simulate();

    if(ans)
    {
        cout << "Lola" << endl;
    }
    else
    {
        cout << "Dawn" << endl;
    }
}