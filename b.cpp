#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n,x;
	cin >> n >> x;
	string s;cin >> s;
	for(int i = 0;i<n;i++){
		if(s[i]=='o')x++;
		else{
			x = max(0,x-1);
		}
	}
	cout<<x<<endl;
}
