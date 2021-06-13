#include <bits/stdc++.h>
using namespace std;
#define MAX 1005

stack <string> s;

int main() {
	string w; getline(cin, w);
	string cur = "";
	for (int i = 0; i < w.size(); i++) {
        //cout << w[i] << " FIN" << endl;
		if (w[i] != ' ') 
        {
            cur += w[i];
            //cout << "cur is " << cur << endl;
        }
		if (w[i] == ' ' || i == w.size() - 1)
        {
            s.push(cur);
            //cout <<"PUSHED " << cur << endl;
            cur = "";
        } 
	}

    //cout << "START PRINT " << endl;

	while (!s.empty()) 
    {
		string str = s.top();
        //cout << "POPPED " << str << endl;
        s.pop();
		int len = str.size();

		if (str[0] >= 'A' && str[0] <= 'Z')
        {
            //cout << "CAP " << str[0] << " " << str[len-1] << endl;

            //str[0] = tolower(str[0]);
            str[0] = str[0] - 'A' + 'a';
            //str[len - 1] = toupper(str[len - 1]);
            
            if(str[len-1]>='a' && str[len-1]<='z')
            {
                str[len-1] = str[len-1]-'a' + 'A';
            }

            //cout << "CHANGE " << str[0] << " " << str[len-1] << endl;
        }

		for (int i = len - 1; i >= 0; i--) cout << str[i];
		if (!s.empty()) cout << " ";
	}
}