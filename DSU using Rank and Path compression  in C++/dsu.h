#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

using namespace std;
#define ll long long
#define vi vector<ll> 

class dsubyrank
{
private:
	vi ances,setsize,rank;
	ll numberofsets;
public:
	dsubyrank(ll n)
	{
		ances.resize(n);
		setsize.resize(n,1);
		rank.resize(n,1);
		numberofsets=n;
		for(int i=0;i<n;i++)
			ances[i]=i;
	}
	int getPar(int u)
	{
		while(u != ances[u])
		{
			ances[u] = ances[ances[u]];
			u = ances[u];
		}
		return u;
	}

	void add(int v, int p, int x) //Function changes as per question, 
	{
		// setsize.erase(cnt[col[v]]);
		// f[cnt[col[v]]]-=col[v];
		// cnt[col[v]]+=x;
		// setsize.insert(cnt[col[v]]);
		// f[cnt[col[v]]]+=col[v];
		// for(auto u:g[v])
		// {
		// 	if(u!=p && !big[u])
		// 		add(u, v, x);
		// }
	}
	
	ll find(ll a){
		return ances[a]==a?a:ances[a]=find(ances[a]);
	}
	bool issame(ll a,ll b){
		return find(a)==find(b);
	}
	void unionset(ll a,ll b)
	{
		if(issame(a,b))return;
		ll x=find(a);ll y=find(b);
		if(rank[x]>rank[y])
		{
			ances[y]=x;
			setsize[x]+=setsize[y];
		}
		else
		{
			ances[x]=y;
			setsize[y]+=setsize[x];
			if(rank[x]==rank[y])
				rank[y]++;
		}
		numberofsets--;
	}
	ll sizeofset(ll a)
	{
		return setsize[find(a)];
	}
	ll disjointsets()
	{
		return numberofsets;
	}
};