#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define T pair<int, pair<int,int>>
#define f first
#define s second

struct DSU
{
    vector<int> head;
    DSU(int n) { head.assign(n, -1); }

    int find(int a)
    {
        if(head[a] < 0)
        {
            return a;
        }

        head[a] = find(head[a]);
        return head[a];
    }

    bool unite(int a, int b)
    {
        a = find(a); b = find(b);

        if(a == b)
        {
            return false;
        }

        if(head[a] > head[b]) {swap(a,b);}
        head[a] += head[b]; head[b] = a; 
        return true;
    }
};

int main()
{
    ofstream fout ("moocast.out");
    ifstream fin ("moocast.in");

    int n; fin >> n;
    DSU dsu(n);
    pair<int,int> pts[n];

   // cout << "DONE" << endl;

    for(int i = 0; i < n; i++)
    {
        int a,b; fin >> a >> b;
        pts[i] = mp(a,b);
    }
    
    //cout << "DONE" << endl;

    priority_queue<T, vector<T>, greater<T>> pq;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int dist = pow(pts[i].f - pts[j].f, 2) + pow(pts[i].s - pts[j].s, 2);
            pq.push(mp(dist, mp(i,j)));
        }
    }

    int min = 0; int heads = n;

    while(heads > 1)
    {
        T add = pq.top(); pq.pop();
        //cout << heads << " " << add.f << " " << add.s.f << " " << add.s.s <<endl;
        min = add.f;
        if(dsu.unite(add.s.f, add.s.s))
        {
            heads--;
        }
    }

    fout << min;
}