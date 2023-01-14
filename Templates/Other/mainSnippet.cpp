/*

     YOU WON'T FAIL UNLESS
     AND UNTIL YOU STOP TRYING
            -->Sarthak Gokhale
*/

#include "stdc++.h"
// #include<bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii> >
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define pqb priority_queue<int>
#define endl "\n"
#define all(p) p.begin(), p.end()
#define sz(x) ((int)x.size())
#define double long double
#define mod 1000000007
#define inf 1e18
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int> >
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define rep(i, j, n) for (int i = j; i < n; i++)
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
#define print_pair(a) \
    for (auto p : a)  \
        cout << p.ff << " " << p.ss << endl;
#define print1(a, x, y)         \
    for (int i = x; i < y; i++) \
        cout << a[i] << " ";    \
    cout << endl;
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

si s;

int powermod(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int powermod2(int x, int y)
{
    int res = 1;
    // x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

void VIPER_619()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    freopen("debugg.txt", "w", stderr);
#endif
}
int gcd(int n1, int n2)
{
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}

int bs(vi &v, int key)
{
    int l = 0, h = v.size() - 1, mid;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}
int nextPowerOf2(int n)
{
    int p = 1;
    if (n && !(n & (n - 1)))
        return n;

    while (p < n)
        p <<= 1;

    return p;
}
ll gcd3(ll a, ll b, ll c)
{
    return gcd(a, gcd(b, c));
}
ll gcd4(ll a, ll b, ll c, ll d)
{
    return gcd(gcd(a, b), gcd(c, d));
}
ll lcm2(ll a, ll b) { return (a * b) / gcd(a, b); }
ll lcm3(ll a, ll b, ll c) { return lcm2(a, lcm2(b, c)); }
ll lcm4(ll a, ll b, ll c, ll d) { return lcm2(lcm2(a, b), lcm2(c, d)); }
vi fibo;
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
void solve()
{
}
int32_t main()
{
    clock_t z = clock();

    VIPER_619();
    int t = 1;
    // cin>>t;

    while (t--)
    {
        solve();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
