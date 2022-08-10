#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9+7;
int H, W, X;
int x[2];
int y[2];

ll fact[2000001];
ll inv[2000001];

ll modInv(ll hold)
{
  ll ans = 1;
  ll power = MOD-2;
  
  while(power > 0)
  {
      if(power%2 == 1)
      {
        ans *= hold; ans %= MOD;
      }

    hold *= hold; hold %= MOD;
    power /= 2;
  }

  return ans;  
}

ll choose(int n, int r)
{
    return ((((fact[n]*inv[r])%MOD)*inv[n-r])%MOD);
}

int main() {

  cin >> H >> W >> X;

  fact[0] = 1;
  inv[0] = 1;

  for(int i = 1; i <= W+H-2; i++)
  {
      fact[i] = (fact[i-1] * i) % MOD;
      inv[i] = modInv(fact[i]);    
  }

  ll total = choose(W+H-2, W-1);
  
  for (int i = 0; i < X; i++) {
    cin >> x[i] >> y[i];
   ll bin = choose(x[i] + y[i] - 2, x[i] - 1)*choose(H+W-x[i] - y[i], H-x[i]); bin %= MOD;
   total = (total-bin+MOD)%MOD;
  }

  if(X == 2)
  {
      if(x[1] <= x[0] && y[1] <= y[0])
      {
        swap(x[1],x[0]); swap(y[1], y[0]); //lazy move
      }
    
      if(x[0] <= x[1] && y[0] <= y[1])
      {
          ll bin = choose(x[0] + y[0] - 2, x[0]-1)*choose(x[1] +  y[1] - y[0] - x[0], x[1] - x[0]); bin %= MOD;
          bin *= choose(H+W-x[1] - y[1], H-x[1]); bin %= MOD;

        total = (total + bin)%MOD;
      }
  }

  cout << total;
}

