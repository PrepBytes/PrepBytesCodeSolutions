#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > vec;
vector<int> vec1;
void dfs(int i,vector<int>graph[],int vis[])
{
    vis[i]=1;
    vec1.emplace_back(i);
    for(vector<int>::iterator it=graph[i].begin();it!=graph[i].end();it++)
    {
        if(vis[*it]!=1)
            dfs(*it,graph,vis);
    }
}
int main()
{

        int n,e;
        cin>>n>>e;
        int u,v;
        vector<int> graph[n];
        for(int i=0;i<e;i++)
        {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int vis[n];
        for(int i=0;i<n;i++)
        {
            vis[i]=0;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {

                dfs(i,graph,vis);
                vec.emplace_back(vec1);
                vec1.clear();
                count++;
            }
        }
        int s = n*(n-1)/2;
        for(auto ele:vec)
        {
            int s1 = ele.size();
            s = s- s1*(s1-1)/2;
        }
        cout<<s<<endl;
    return 0;
}
