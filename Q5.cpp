using namespace std;
#include <string>
#include <iostream>

string solution(string n){
	int mx=0,cnt=0,times=0;
    for(char ch:n){
    	if(ch=='0'){
    		cnt++;
    	}else{
    		if(mx<cnt){
    			mx=cnt;
    			times=1;
    		}else if(mx==cnt){
    			times++;
    		}
    		cnt=0;
    	}
    }
    if(mx<cnt){
    	mx=cnt;
    	times=1;
    }else if(mx==cnt){
    	times++;
    }
    if(times>1){
    	return "B";
    }
    if(mx%2==0){
    	return "B";
    }
    return "A";

}

/*  Do not edit below code */
int main() {
	string  n;
	cin >> n;	
    string answer=solution(n);
	cout << answer << endl;	
}