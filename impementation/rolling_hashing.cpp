//hello binaryboy1234
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ll Inf=1e18;
const int Max=4e5+1;
ll powerprime[Max];
ll inverse[Max];
#define p 103


//fast exponentiation
ll power(ll a, ll b){ll res=1; while(b>0){if (b%2==1){res = (res * a) % mod;}b>>=1;a = (a * a) % mod;} return res;}


void calculatepower()
{
	powerprime[0] = 1;
	inverse[0] = power(powerprime[0], mod-2);
	for(int i = 1;i < Max;i++)
	{
	        //this array store the power of prime for i 1 to Max
		powerprime[i] = (powerprime[i-1] * p) % mod;
		
		//this array store the inverse of power of prime for i 1 to Max
		inverse[i] = power(powerprime[i], mod-2);
	}
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	//Precomputation
	calculatepower();  
	
	
	int t;cin>>t;
	while(t--)
	{
	        string s;
		//Take input as a string
		cin>>s;
		
		//string length
		int n=s.length();
		
		//array for calculate prefix hash
		ll hash[n+1];
		
		//Initialize the prefix hash value
		hash[0] = 0;hash[1] = s[0];
		
		//loop to calculate prefix hash
		for(int i = 2; i <= n;i++)
		{
			hash[i] = (hash[i-1] + (s[i-1]*powerprime[i-1]) % mod) % mod;
		}
		
		
		//To calculate the hash value of range L to R
		ll value = (((hash[R+1] - hash[L] + mod) % mod ) * inverse[L]) % mod;
		
	}
	return 0;
}	
