//USACO Guide
//Topological Sort

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
   ifstream fin("milkorder.in");
   ofstream fout("milkorder.out");
   int n, m;
   cin >> n >> m;

   int in[n];
   vector<int> adj[n];

   for(int i = 0; i < n; i++)
   {
      in[i] = 0;
   }

   for(int i = 0; i < m; i++)
   {
      int a, prev; cin >> a >> prev;
      prev--;

      int check = 0;
      
      for(int i = 1; i < a; i++)
      {
         int next; cin >> next; next--;
         in[next]++;
         adj[prev].pb(next);
         prev = next;
      }
   }

   priority_queue<int, vector<int>, greater<int>> pq;

   for(int i = 0; i < n; i++)
   {
      if(in[i] == 0)
      {
         pq.push(i);
      }
   }

   while(!pq.empty())
   {
      int get = pq.top(); pq.pop();
      cout << (get+1) << " ";

      for(int to : adj[get])
      {
         in[to]--;
         if(in[to] == 0)
         {
            pq.push(to);
         }
      }
   }
}