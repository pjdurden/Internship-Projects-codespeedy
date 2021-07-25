// input multiple numbers from single line
// string input;
// getline(cin, input);
// istringstream is(input);
// int num;
// while(is>>num) nums.push_back(num);

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
// #pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)

#include <bits/stdc++.h>
#include "headerfilechess.h"
// #include<time.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=  1e9+ 7;
#define endl "\n"
#define eps 1e-7
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define vpi vector<pi>
#define vi vector<ll>
#define pi pair<ll,ll>
#define mk make_pair
#define pb push_back
#define ppb pop_back
#define umap unordered_map
#define uset unordered_set
#define vvi vector<vector<ll>>
#define minheap priority_queue<ll,vi,greater<ll>>
#define maxheap priority_queue<ll>
#define minheapi priority_queue<pi,vpi,greater<pi>>
#define maxheapi priority_queue<pi>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define fo(i, n) for(i=0;i<n;i++)
#define fox(i,a,b) for(i=a;i<b;i++)
#define deb1(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deblp(i, a, n) fo(i, n){cout << a[i] << " ";}
#define clr(x,a) memset(x, a, sizeof(x))
#define fills(a,val) fill_n(a, sizeof(a)/sizeof(a[0]), val)
#define sq(x) ((x)*(x))

ll powmod(ll x,ll y){ll t; for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod; return t;}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x*(y/gcd(x,y)); }
ll modd(ll a){return (a%mod + mod)%mod;}
double findMod(double a, double b)
{
    double mods;
    if (a < 0)
        mods = -a;
    else
        mods =  a;
    if (b < 0)
        b = -b;    
    while (mods >= b)
        mods = mods - b;
    if (a < 0)
        return -mods;
    return mods;
}
ll add(ll a,ll b){return modd(modd(a)+modd(b));}
ll mul(ll a,ll b){return modd(modd(a)*modd(b));}
int smask(int i,int pos){ return (i|(1<<pos)); }
int clmask(int i,int pos){return (i&(~(1<<pos))) ; }
bool chmask(int i,int pos){return (i&(1<<pos))!=0 ;}
double cordist(pair<double,double> a,pair<double,double> b)
{return sqrt(sq(a.first-b.first)+sq(a.second-b.second));}

long long binpow(long long a, long long b) {
    if (b <= 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return mul(mul(res, res), a);
    else
        return mul(res,res);
}





int main()
{
	Board b;
	string s;
	bool newgame = true;
	cout<<"Simple Chess game in c++";
	cin >> s;

	while(newgame){
		b.setBoard();
		while (b.playGame());
		cout << "Do you want to play again? y or n ";
		cin >> s;
		if (s != "y")
			newgame = false;
	}


	return 0;
}