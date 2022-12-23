//Recursive Complete Search 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int diag1[8][8];
int diag2[8][8];
bool r[8];
bool fd1[15];
bool fd2[15];
bool oc[8][8];
int tot;

void build()
{
    for(int i = 0; i < 8; i++)
    {
        r[i] = false;
    }

    for(int i = 0; i < 15; i++)
    {
        fd1[i] = false;
        fd2[i] = false;
    }
    
    tot = 0;
}

void search(int y)
{
    if(y == 8)
    {
        tot++; return;
    }

    for(int i = 0; i < 8; i++) // try to put queen in (y, i);
    {
        if(r[i] || fd1[i+y] || fd2[i+7-y] || oc[i][y]) //space is occupied
        {
            continue;
        }

        r[i] = true; fd1[i+y] = true; fd2[i+7-y] = true;
        search(y+1);
        r[i] = false; fd1[i+y] = false; fd2[i+7-y]= false; 
    }
}

int main()
{
    for(int i = 0; i < 8; i++)
    {
        string str; cin >> str; 
        for(int j = 0; j < 8; j++)
        {
            if(str[j] == '*')
            {
                oc[i][j] = true;
            }
            else
            {
                oc[i][j] = false;
            }
        }
    }

    build();

    search(0);

    cout << tot;

}