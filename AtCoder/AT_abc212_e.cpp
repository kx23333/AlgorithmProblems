// Problem: [ABC212E] Safety Journey
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_abc212_e
// Memory Limit: 1 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(s) s.begin(), s.end()
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

int dx[]={0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={1, 0, -1, 0, 1, -1, 1, -1};

template <typename T>
void read(T &x)
{
	x=0; char ch=getchar(); ll f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template <typename T, typename...Args>
void read(T &first, Args &...args)
{
	read(first);
	read(args...);
}

const int N=5010, MOD=998244353;

int n, m, k;
int f[N][N];// f[i, j] j-time i-point
// f[i, j] = f[1~n, j-1] - f[1~n, j-1](cant arrive) - f[i, j-1]
// ans f[1, k]
vector<int> g[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m, k);
	For(i, 1, m)
	{
		int u, v; rd(u, v);
		g[u].eb(v); g[v].eb(u);
	}
	f[1][0]=1;
	For(j, 1, k)
	{
		int sum=0;
		For(i, 1, n) sum=(sum+f[i][j-1])%MOD;
		For(i, 1, n) f[i][j]=(sum-f[i][j-1]+MOD)%MOD;
		For(i, 1, n)
			for(auto ne: g[i])
				f[i][j]=(f[i][j]-f[ne][j-1]+MOD)%MOD;
	}
	cout<<f[1][k]<<endl;
	return 0;
}