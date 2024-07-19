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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=11;
int g[N][N];

void solve()
{
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>g[i][j];
    if(n==1 && m==1)
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=m; j++)
            cout<<g[i][j]<<' ';
        cout<<g[i][1]<<endl;
    }
    for(int j=2; j<=m; j++)
            cout<<g[1][j]<<' ';
    cout<<g[1][1]<<endl;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
    cin>>T;
    while(T--) solve();
	return 0;
}
