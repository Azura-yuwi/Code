//USACO Gold 2015 December
//Greedy

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");

    int n; fin >> n;
    bool me[2*n];

    for(int i = 0; i < 2*n; i++)
    {
        me[i] = true;
    }

    vector<int> front;
    vector<int> back;

    for(int i = 0; i < n/2; i++)
    {
        int a; fin >> a; a--; front.pb(a); me[a] = false;
    }

    for(int i = 0; i < n/2; i++)
    {
        int a; fin >> a; a--; back.pb(a); me[a] = false;
    }

    sort(front.begin(), front.end(), greater<int>());
    sort(back.begin(), back.end());

    vector<int> card;

    for(int i = 0; i < 2*n; i++)
    {
        if(me[i]) {card.pb(i);} //ordered small to large
    }

    int at = 0;
    int pts = 0;

    for(int i = 0; i < n/2; i++)
    {
        while(at < n/2 && back[at] < card[i])
        {
            at++;
        }

        if(at < n/2)
        {
            pts++;
            //cout << "ADD POINTS MATCH " << back[at] << " " << card[i] << endl;
            at++;
        }
    }

    at = 0;

    for(int i = n-1; i >= n/2; i--)
    {
        while(at < n/2 && front[at] > card[i])
        {
            at++;
        }

        if(at < n/2)
        {
            pts++;
            //cout << "ADD POINTS MATCH " << front[at] << " " << card[i] << endl;
            at++;
        }
    }

    fout << pts;
}

