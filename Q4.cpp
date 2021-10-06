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
#define int long long

using namespace std;
int totalPairs(int n, vector<int>& values) {
	vector<int> ngr(n),dp(n,0);
	stack<pair<int,int>> st;
	for(int i=n-1;i>=0;i--){
		while(!st.empty() && st.top().first<=values[i]){
			st.pop();
		}
		if(st.empty()){
			ngr[i]=-1;
		}else{
			ngr[i]=st.top().second;
		}
		st.push({values[i],i});
	}
	int ans=0;
	for(int i=n-2;i>=0;i--){
		int curr=i+1;
		int val=ngr[i];
		if(val==-1){
			val=n-1;
		}
		while(curr!=-1 && curr<=val){
			dp[i]++;
			curr=ngr[curr];
		}
		ans+=dp[i];
	}
    return ans;
}

int32_t main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
	int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}