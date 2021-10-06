#include<bits/stdc++.h>
using namespace std;
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define ll long long
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define MOD 1000000007

namespace number_theory {
	ll gcd(ll x, ll y) {
	  if (x == 0) return y;
	  if (y == 0) return x;
	  return gcd(y, x % y);
	}
	bool isprime(ll n) { 
	  if (n <= 1) return false; 
	  if (n <= 3) return true; 
	  
	  if (n % 2 == 0 || n % 3 == 0) return false; 
	  
	  for (ll i = 5; i * i <= n; i += 6) 
		if (n % i == 0 || n % (i+2) == 0) 
		  return false; 
	  
	  return true; 
	} 
	 
	bool prime[15000105]; 
	void sieve(int n) { 
	  for (ll i = 0; i <= n; i++) prime[i] = 1;
	  for (ll p = 2; p * p <= n; p++) { 
		if (prime[p] == true) { 
		  for (ll i = p * p; i <= n; i += p) 
			prime[i] = false; 
		} 
	  } 
	  prime[1] = prime[0] = 0;
	} 
	 
	vector<ll> primelist;
	bool __primes_generated__ = 0;
	 
	void genprimes(int n) {
	  __primes_generated__ = 1;
	  sieve(n + 1);
	  for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
	}
	 
	vector<ll> factors(ll n) {
	  if (!__primes_generated__) {
		cerr << "Call genprimes you dope" << endl;
		exit(1);
	  }
	  vector<ll> facs;
	 
	  for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
		if (n % primelist[i] == 0) {
		  while (n % primelist[i] == 0) {
			n /= primelist[i];
			facs.push_back(primelist[i]);
		  }
		}
	  }
	  if (n > 1) {
		facs.push_back(n);
	  }
	  sort(facs.begin(), facs.end());
	  return facs;
	}
	
	vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divs.push_back(i);
        divs.push_back(n / i);
      }
    }

    getunique(divs);
    return divs;
  }
}

using namespace number_theory;

unordered_map<int,int> parent;
unordered_map<int,int> sizeOf;


ll mmul(ll a, ll b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

void make_set(int a){
	parent[a]=a;
	sizeOf[a]=1;
}

int find_par(int n){
	if(parent[n]==n){
		return n;
	}
	return parent[n]=find_par(parent[n]);
}

void union_set(int a,int b){
	a=find_par(a);
	b=find_par(b);
	if(a==b){
		return;
	}
	if(sizeOf[a]<sizeOf[b]){
		swap(a,b);
	}
	parent[b]=a;
	sizeOf[a]+=sizeOf[b];
}

void countStablePartitions(ll n, vector<ll>& values) {
	genprimes(1e6);
	ll ttl=0;
	for(ll i=0;i<n;i++){
		if(values[i]==1){
			ttl++;
			continue;
		}
		vector<ll> dvs;
		for(int j=0;;j++){
			if(primelist[j]>values[i]){
				break;
			}
			if(values[i]%primelist[j]==0){
				if(parent[primelist[j]]==0){
					make_set(primelist[j]);
				}
				dvs.push_back(primelist[j]);
			}
		}
		ll from = dvs[0];
		for(int j=1;j<dvs.size();j++){
			union_set(dvs[j],from);
		}
	}
	set<int> s;
	for(auto it:parent){
		s.insert(it.second);
	}
	int totalSets=s.size()+ttl;
	if(totalSets<2){
		cout<<"NO\n0";
		return;
	}
	cout<<"YES\n";
	cout<<mmul(totalSets,totalSets-1);
}

int main(){
   ll n;
   cin >> n;
   vector<ll> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
   countStablePartitions(n, values);
   return 0;
}