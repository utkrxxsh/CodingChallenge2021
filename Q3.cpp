#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    for(int i=1;i<a.size();i++){
    	a[i]+=a[i-1];
    }
    int sum=0;
    int ans=0;
    for(int i=0;i<b.size();i++){
    	sum+=b[i];
    	if(sum>maxSum){
    		break;
    	}
    	int left=maxSum-sum;
    	int idx=upper_bound(a.begin(),a.end(),left)-a.begin();
    	ans=max(ans,(i+1)+idx);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}