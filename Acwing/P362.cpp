// Problem: 区间
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/364/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=50010, T=50001;

//差分约束(min): 求最长路
//si >= si-1 -> si - si-1 >= 0 : i-1 -> i, w=0
//si - si-1 <= 1 -> si-1 - si >= -1 : i -> i-1, w=-1
//sb - sa-1 >= c : a-1 -> b, w=c

vector<pii> g[N];

int n;
int dist[N];
bool ins[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=T; i++)
	{
		g[i-1].eb(mp(i, 0));
		g[i].eb(mp(i-1, -1));
	}
	for(int i=1, a, b, c; i<=n; i++)
	{
		cin>>a>>b>>c;
		g[a-1].eb(mp(b, c));
	}
	fill(dist+1, dist+T+1, -inf);
	queue<int> q;
	q.push(0); ins[0]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		ins[u]=0;
		each(t, g[u])
		{
			int v=t.fi, w=t.se;
			if(dist[v]<dist[u]+w)
			{
				dist[v]=dist[u]+w;
				if(!ins[v]) q.push(v), ins[v]=1;
			}
		}
	}
	cout<<dist[T]<<endl;
	return 0;
}
