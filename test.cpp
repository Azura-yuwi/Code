#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
	int t; cin >> t;

	for(int test = 0; test < t; test++)
	{
		int n; cin >> n;
		ll k = 1; bool done = false;
		int a1 = 0; int b1 = 0; int c1 = 0;

		while(!done)
		{
			for(int a = n; a > 0; a--)
			{
				for(int b = n; b < 1e9; b++)
				{
					ll al = (ll)a; ll bl = (ll)b;
					ll sum = bl*bl - al*al + al + (bl+k)*(bl+k) - k;
					ll c = sqrt(sum);

					if(c*(c+1) == sum)
					{
						done = true;
						a1 = a; b1 = b; c1 = c;
						cout << a1 << " " << b1 << " " << (b1+k) << " " << c1 << endl;
						break;
					}

					if(a > k)
					{
						ll lsum = (al-k)*(al-k) + al*al - bl*bl - k - bl;
						//cout << "lsum " << lsum << endl;

						if(lsum >= 0)
						{
							ll cl = sqrt(lsum) + 1;
							
							if(cl*(cl-1) == lsum)
							{
								done = true;
								cout << a << " " << b << " " << cl << " " << (a-k) << endl;
								break;
							}
						}
					}

					if(c > 1e9)
					{
						break;
					}
				}

				if(done)
				{
					break;
				}
			}

			k++;
		}
	}
}