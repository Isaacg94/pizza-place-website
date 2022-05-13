#include <iostream>
using namespace std;
#include<bits/stdc++.h>

typedef long long ll;

#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007

/*
int f(int n)
{
	int sum = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			sum += i;
			if ((n / i) != i)
			{
				sum += (n / i);
			}
		}
	}
	return sum;
}
*/


vector<ll>adj[200008];

void dfs(ll src , ll parent , vector<ll>&ans)
{
 int sum=0;
 for(auto child:adj[src])
 {
   if(child!=parent)
   {
        dfs(child , src , ans);
        sum += (1+ans[child]);
   }

 }

ans[src]= sum;
  
}






int main() 
{
FIO;

ll n;cin>>n;
ll x;
for(ll i=2;i<=n;i++)
{
    cin>>x;
    adj[x].push_back(i);
    adj[i].push_back(x);
}

vector<ll> ans(n+1);
dfs( 1 , -1 ,ans);

for(int i=1;i<=n;i++)
{
 cout<<ans[i]<<" ";   
}


}




