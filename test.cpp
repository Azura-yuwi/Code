#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t; 
    cout << "read " << t << endl;
    
    for(int test = 1; test <= t; test++)
    {
        string s; cin >> s; 
        cout << "read " << s << endl;
        char c = s[s.length() - 1];
        string get; 
		get += c;

		//cout << "build ";
		//cout << get << endl;
        
        for(int i = s.length()-2; i >= 0; i--)
        {
            if(s[i] < c)
            {
                get = s[i] + get;
            }
            else
            {
                c = s[i];
            }
            
            get = s[i] + get;
			cout << "loop " << get<< endl;
        }
        
        cout << "Case #" << test << ": " << get << endl;
    }
}