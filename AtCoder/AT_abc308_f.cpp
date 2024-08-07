//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define mtp make_tuple
#define pb push_back
#define eb emplace_back
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

int dx[]={0, 0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={0, 1, 0, -1, 0, 1, -1, 1, -1};

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

int n, m;
ll sum;

signed main()
{
	cin.tie(0); cout.tie(0);
    rd(n, m);
    vector<int> a(n+1);
    vector<pii> v(m+1);
    For(i, 1, n)
    {
        rd(a[i]);
        sum+=a[i];
    }
    For(i, 1, m) rd(v[i].fi);
    For(i, 1, m) rd(v[i].se);
	sort(a.begin()+1, a.begin()+n+1, greater<int>());
	sort(v.begin()+1, v.begin()+m+1, [](pii x, pii y){ return x.fi>y.fi; });
	priority_queue<int, vector<int>, greater<int>> heap;
	int ptr=1, cnt=0;
	For(i, 1, m)
	{
		while(ptr<=n && a[ptr]>=v[i].fi) ptr++, cnt++;
		if(cnt) cnt--, sum-=v[i].se, heap.push(v[i].se);
		else if(heap.size() && heap.top()<v[i].se) sum-=(v[i].se-heap.top()), heap.pop(), heap.push(v[i].se);
	}
	cout<<sum<<endl;
	return 0;
}