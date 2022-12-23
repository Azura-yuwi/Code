#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int m,n,p; cin >> m >> n >> p;
    map<string, int> ind;
    map<string, int> dow; 
    string nm[m];

    dow["Monday."] = 0; dow["Tuesday."] = 1; dow["Wednesday."] = 2; dow["Thursday."] = 3; dow["Friday."] = 4; dow["Saturday."] = 5; dow["Sunday."] = 6;

    for(int i = 0; i < m; i++)
    {
        string str; cin >> str; ind[str] = i; nm[i] = str;
    }
    pair<int, pair<int,int>> stat[p];

    string line; 
    getline(cin, line);

    int who[p];
    int which[p];
    int what[p];
    int at = 0;

    while(at < p) //process the statements
    {
        getline(cin, line);
        stringstream spl(line);
        string tok;
        vector<string> words; 

        while(getline(spl, tok, ' '))
        {
            words.pb(tok);
        }

        string name = words[0].substr(0, words[0].length() - 1);
        who[at] = ind[name];
        int sz = words.size();

        if(sz == 4)
        {
            if(words[sz-1] == "guilty.")
            {
                if(words[1] == "I" && words[2] == "am")
                {
                    which[at] = 0; what[at] = who[at];
                }
                else if(ind.find(words[1]) != ind.end() && words[2] == "is")
                {
                    which[at] = 2; what[at] = ind[words[1]];
                }
                else
                {
                    which[at] = 5;
                }
            }
            else if(words[1] == "Today" && words[2] == "is" && dow.find(words[3]) != ind.end())
            {
                which[at] = 4; what[at] = dow[words[3]];
            }
            else
            {
                which[at] = 5;
            }
        }
        else if(sz == 5)
        {
            if(words[4] == "guilty.")
            {
                if(words[1] == "I" && words[2] == "am" && words[3] == "not")
                {
                    which[at] = 1; what[at] = who[at];
                }
                else if(ind.find(words[1]) != ind.end() && words[2] == "is" && words[3] == "not")
                {
                    which[at] = 3; what[at] = ind[words[1]];
                }
                else
                {
                    which[at] = 5;
                }
            }
            else
            {
                which[at] = 5;
            }
        }
        else
        {
            which[at] = 5;
        }

      //  cout << who[at] << " " << which[at] << " " << what[at] << endl;
        at++;
    }

    int guess[m][7];
    int liar[m];

    for(int i = 0; i < m; i++) //guilty person
    {
        for(int j = 0; j < 7; j++) //day of week
        {
            for(int k = 0; k < m; k++)
            {
                liar[k] = -1; //not known if lying or telling truth
            }

            bool work = true;

            for(int k = 0; k < p; k++)
            {
                if(which[k] == 5) continue;

                if(which[k] == 0 || which[k] == 2)
                {
                    if(what[k] != i) //lying
                    {
                        if(liar[who[k]] == 0) 
                        {
                            work = false;
                            break; //not work
                        }

                        liar[who[k]] = 1;
                    }
                    else 
                    {
                        if(liar[who[k]] == 1)
                        {
                            work = false;
                            break; //not work
                        }

                        liar[who[k]] = 0;
                    }
                }
                else if(which[k] == 1 || which[k] == 3)
                {
                    if(what[k] == i) //lying
                    {
                        if(liar[who[k]] == 0) 
                        {
                            work = false;
                            break; //not work
                        }

                        liar[who[k]] = 1;
                    }
                    else 
                    {
                        if(liar[who[k]] == 1)
                        {
                            work = false;
                            break; //not work
                        }

                        liar[who[k]] = 0;
                    }
                }
                else
                {
                    if(what[k] != j) //lying
                    {
                        if(liar[who[k]] == 0) 
                        {
                            work = false;
                            break; //not work
                        }

                        liar[who[k]] = 1;
                    }
                    else 
                    {
                        if(liar[who[k]] == 1)
                        {
                            work = false;
                            break; //not work
                        }

                        liar[who[k]] = 0;
                    }
                }

                
            }

            if(!work)
            {
                guess[i][j] = -1;
            }
            else
            {
                int l = 0; int t = 0; int u = 0;

                for(int k = 0; k < m; k++)
                {
                    if(liar[k] == 0)
                    {
                        t++;
                    }
                    else if(liar[k] == 1)
                    {
                        l++;
                    }
                    else
                    {
                        u++;
                    }
                }

                if(l <= n && l + u >= n)
                {
                    guess[i][j] = 1; //works
                }
                else
                {
                    guess[i][j] = -1;
                }
            }

            //cout << i << " " << j << " " << work << endl;
        }
    }

    vector<int> crim; 

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(guess[i][j] == 1)
            {
               // cout << i << " " << j << endl;
                crim.pb(i); break;
            }
        }
    }

    if (crim.size() > 1)
    {
        cout << "Cannot Determine";
    }
    else if(crim.size() == 0)
    {
        cout << "Impossible";
    }
    else
    {
        cout << nm[crim[0]];
    }
}