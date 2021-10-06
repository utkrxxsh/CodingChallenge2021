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

using namespace std;
vector<vector<int>> time1;
int dp[12][22];
int numBankers,numClients;
const int UNDEFINED=-1;

int solve(int bn,int cn){
	if(bn==numBankers-1){
		int sum=0;
		for(int i=cn;i<numClients;i++){
			sum+=time1[bn][i];
		}
		return sum;
	}
	if(dp[bn][cn]!=UNDEFINED){
		return dp[bn][cn];
	}
	int ans=INT_MAX;
	int sum=0;
	for(int j=cn;j<numClients;j++){
		sum+=time1[bn][j];
		ans=min(ans,sum+solve(bn+1,j+1));
	}
	return dp[bn][cn]=ans;
}
int bankersAndClients(int c, int b,vector<vector<int>> &time) {
	time1=time;
	numBankers=time.size();
	numClients=time[0].size();
	for(int i=0;i<=numBankers;i++){
		for(int j=0;j<=numClients;j++){
			dp[i][j]=UNDEFINED;
		}
	}
	return solve(0,0);
}

int main(){
    int b,c;
    cin >> c>>b;
    int answer;
    vector<vector<int>> time(b,vector<int>(c));
    for(int i = 0; i < b; i++){
        
        for(int j = 0;j < c;j++){
          cin>>time[i][j];
        }
    }
	answer = bankersAndClients(c,b,time);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}