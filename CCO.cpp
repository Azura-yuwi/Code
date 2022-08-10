#include <bits/stdc++.h>
using namespace std;

int rounds[1048576]; //2^20
//template<class T> struct segment_tree
//{
    int n; 
    vector<pair<int,int>> segTree;

    /*void init(int size)
    {
        n = size; segTree.assign(2*n, make_pair(0,0)); //also to edit
    }*/

    void upd(int p, pair<int,int> v)
    {
        segTree[p += pow(2, n)] = v;
        int level = 0;

        for(p /= 2; p > 0; p /= 2)
        {
            if(segTree[2*p].first < segTree[2*p+1].first)
            {
                segTree[p] = segTree[2*p + 1];
                rounds[segTree[2*p].second] = level;
            }
            else
            {
                segTree[p] = segTree[2*p];
                rounds[segTree[2*p+1].second] = level;
            }
          
            level++;
        }

        rounds[segTree[1].second] = level;
    }

    void build() {
      for (int i = pow(2, n) - 1; i >= 0; i--) {
        segTree[i] = max(segTree[i * 2], segTree[i * 2 + 1]);
        rounds[segTree[i].second]++;
      }
    }

//};

//segment_tree<int> tree;

int main() {
  int m; cin>>n>>m;

  segTree.assign(2*(pow(2,n) + 1), make_pair(0,0));
  
  for (int i = 0; i < pow(2, n); i++) {
    int skill; cin >> skill;
    segTree[i + pow(2, n)] = {skill, i};
  }
  
  build();
  
  for (int i = 0; i < m; i++) {
    char cur;
    cin >> cur;
    if (cur == 'R') {
      int j, S;
      cin >> j >> S; j--;
      upd(j, {S, j});
    }
    else if (cur == 'W') {
      cout << (segTree[1].second + 1) << endl;
    }
    else {
      int j;
      cin >> j; j--;
      cout << rounds[j] << endl;
    }
  }
}