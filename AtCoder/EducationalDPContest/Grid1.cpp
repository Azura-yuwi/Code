//EGOI Training Camp 2022

#include <iostream>

using namespace std;

#define MOD 1000000007

int H, W;
int dp[1001][1001];

int main() {

  cin >> H >> W;

  for (int i = 0; i < 1000; i++){
    dp[0][i] = 0;
  }

  for (int i = 0; i < 1000; i++){
    dp[i][0] = 0;
  }
  
  dp[1][1] = 1;

  for(int i = 1; i < H+1; i++)
  {
    string s; cin >> s;
    
    for(int j = 1; j < W+1; j++)
    {
      dp[i][j] = 0;
      
      if(s[j-1] != '#')
      {
        dp[i][j] = dp[i][j-1]+dp[i-1][j];
        dp[i][j] %= MOD;
        if (i==1 && j==1){
          dp[i][j] = 1;
        }
      }
    }
  }

  cout << dp[H][W] << endl;
}