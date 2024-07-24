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
constexpr int MOD=998244353;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
    cin>>n;
    vector<char> s(n+1);
    for(int i=1; i<=n; i++) cin>>s[i];
    for(int i=1; i<n; i++)
        if(s[i]>'1' && s[i+1]>'1')
        {
            cout<<-1<<endl;
            return 0;
        }
    ll ans=0;
    for(int i=n; i>1; i--)
        ans=(ans+1)*(s[i]-'0')%MOD;
    cout<<ans<<endl;
	return 0;
}
