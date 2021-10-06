#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

unordered_map<string,int> dept;
unordered_map<string,string> parent;
unordered_map<string,int> deptOf[3];

void make_set(string str,int dt){
	parent[str]=str;
	deptOf[0][str]=0;
	deptOf[1][str]=0;
	deptOf[2][str]=0;
	deptOf[dt-1][str]++;
}

string find_set(string emp){
	if(parent[emp]==emp){
		return emp;
	}
	return parent[emp]=find_set(parent[emp]);
}

void union_set(string a,string b){
	a=find_set(a);
	b=find_set(b);
	if(a==b){
		return;
	}
	int sz1=deptOf[0][a]+deptOf[1][a]+deptOf[2][a];
	int sz2=deptOf[0][b]+deptOf[1][b]+deptOf[2][b];
	if(sz1<sz2){
		swap(a,b);
	}
	parent[b]=a;
	deptOf[0][a]+=deptOf[0][b];
	deptOf[1][a]+=deptOf[1][b];
	deptOf[2][a]+=deptOf[2][b];
}

void theHackathon(int n, int m, int a, int b, int f, int s, int t) {
    string empName;
    int empDept;
    for(int i=0;i<n;i++){
    	cin>>empName;
    	cin>>empDept;
    	dept[empName]=empDept;
    }
    for(int i=0;i<m;i++){
    	string e1,e2;
    	cin>>e1>>e2;
    	if(!parent.count(e1)){
    		make_set(e1,dept[e1]);
    	}
    	if(!parent.count(e2)){
    		make_set(e2,dept[e2]);
    	}
    	string parE1=find_set(e1);
    	string parE2=find_set(e2);
    	int f1=deptOf[0][parE1];
    	int f2=deptOf[0][parE2];
    	int s1=deptOf[1][parE1];
    	int s2=deptOf[1][parE2];
    	int t1=deptOf[2][parE1];
    	int t2=deptOf[2][parE2];
    	int sz1=f1+s1+t1;
    	int sz2=f2+s2+t2;
    	if(sz1+sz2>b || f1+f2>f || s1+s2>s || t1+t2>t){
    		continue;
    	}
    	union_set(e1,e2);
    }
    for(auto it:parent){
    	parent[it.first]=find_set(it.first);
    }
	map<string,vector<string>> groups;
	for(auto it:parent){
		groups[it.second].push_back(it.first);
	}
	vector<string> ans;
	for(auto it:groups){
		if(it.second.size()>=a && it.second.size()<=b 
			&& it.second.size()>ans.size()){
			ans=it.second;
		}
	}
	if(ans.empty()){
		cout<<"no groups";
	}
	sort(ans.begin(),ans.end());
	for(auto it:ans){
		cout<<it<<endl;
	}
}

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);

    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}