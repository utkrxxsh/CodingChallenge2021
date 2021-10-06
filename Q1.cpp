using namespace std;
#include <string>
#include <iostream>

int solution(int n){
	int ones,twos;
	if(n%3==0){
		ones=n/3;
		twos=n/3;
	}else if(n%3==1){
		ones=(n/3)+1;
		twos=n/3;
	}else{
		ones=n/3;
		twos=(n/3)+1;
	}
	return ones+twos;
}

/*  Do not edit below code */
int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}