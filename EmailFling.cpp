#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int main()
{
    int t; cin >> t;

    for(int test = 0; test < t; test++)
    {
        int m,n,k; cin >> m >> n >> k;

        vector<int> inFold[m];
        bool work = true;
        int stat[n];
        int fold[n];
        queue<int> q; //range
        unordered_set<int> range;
        stack<int> above;
        bool down = true;
        int add = k;
        int added = k-1;

        for(int i = 0; i < n; i++)
        {
            if(i < k)
            {
                stat[i] = 0; //in range
                range.insert(i);
                q.push(i);
            }
            else
            {
                stat[i] = 1; // below
            }
        }

        for(int i = 0; i < n; i++)
        {
            int folder; cin >> folder; folder--;
            fold[i] = folder;
            inFold[folder].pb(i);
        }

        for(int folder = 0; folder < m; folder++)
        {
         //   cout << "On folder " << folder << endl;

            for(int f : inFold[folder])
            {
                //cout << "size " << range.size() << endl;
                //cout << "on file " << f << endl;
                if(stat[f] == 2)
                {
                    continue;
                }

                if(stat[f] == 0) 
                {
                   // cout << "can be filed " << endl;
                    stat[f] = 2;
                    range.erase(f); //range should only ever have stuff that is not filed yet
                    added = add;
                    //cout << "try to add " << add << endl;

                    if(add == -1)
                    {
                        continue;
                    }

                    //update range
                    if(down)
                    {
                        q.push(add);
                        range.insert(add);
                       // cout << "added " << add << endl;
                        stat[add] = 0;
                        add++; //next one
                       // cout << "next one " << add << endl;

                        if(add == n)
                        {
                            //cout << "going up"<< endl;
                            down = false;

                            if(above.empty()) //then everything is in range
                            {
                                add = -1;
                            }
                            else
                            {
                                add = above.top();
                            }
                        }  
                    }
                    else
                    {
                        range.insert(add);
                        above.pop();

                        if(!above.empty())
                        {
                            add = above.top();
                        }
                        else
                        {
                            add = -1;
                        }
                    }

                    continue;
                }
                
                //need to move range to look for file

                while(added != f) //have not added f yet
                {
                    added = add; //added is the last one we add
                    //cout << "try to add " << add << endl;

                    if(down)
                    {
                        while(stat[q.front()] == 2) //get rid of filler stuff in q; there is always something in range not filed yet
                        {
                            q.pop();
                        }

                        int top = q.front();
                       // cout << "top is " << q.front() << endl;

                       if(fold[top] < folder + k) //can be filed
                        {
                            stat[top] = 2;
                            //cout << "top can be filed " << endl;
                        }
                        else
                        {                                
                            stat[top] = -1;
                            //cout << "top " << top << " is now above " << endl;
                            above.push(top);
                        }

                        //update range
                        q.pop();
                        range.erase(top);
                        range.insert(add);
                        q.push(add);
                        //cout << "added " << add << " to range" << endl;
                        stat[add] = 0;
                        add++; //next one
                        //cout << "next to add is " << add << endl;

                        if(add == n)
                        {
                            down = false;
                           //cout << "going up" << endl;

                            if(above.empty())
                            {
                                add = -1;
                            }
                            else
                            {
                                add = above.top();
                            }

                           //cout << "next to add is " << add << endl;
                        }  
                    }
                    else
                    {
                        bool canFile = false;

                        for(int get : range)
                        {
                           //cout << "check if can file " << get << endl;

                            if(fold[get] < folder + k) //can file
                            {
                                range.erase(get);
                                stat[get] = 2;
                                canFile = true;
                                break;
                            }
                        }
                        
                        if(!canFile) //no way to reach the file
                        {
                            work = false;
                            break;
                        }

                        range.insert(add);
                        above.pop();

                        if(!above.empty())
                        {
                            add = above.top();
                        }
                        else
                        {
                            add = -1;
                        }
                    }
                }

                if(!work)
                {
                    break;
                }
            }

            if(!work)
            {
                break;
            }
        }

        if(work)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}