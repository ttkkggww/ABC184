#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

double memo[101][101][101];

double dfs(int g,int s,int c,double per,int time){
	
	if(memo[g][s][c]!=-1)return memo[g][s][c];
	if(g==100||s==100||c==100){
		return memo[g][s][c]=per*time;
	}
	double res = 0;
	double all = g+s+c;
	res += dfs(g+1,s,c,per*(g)/(all),time+1);
	res += dfs(g,s+1,c,per*(s)/(all),time+1);
	res += dfs(g,s,c+1,per*(c)/(all),time+1);
	return  memo[g][s][c]=res;
}

int main()
{
	for(int i = 0;i<101;i++)
	for(int j = 0;j<101;j++)
	for(int k = 0;k<101;k++)
		memo[i][j][k]=-1;
	int g,s,c;
	cin >> g >> s >> c;
	printf("%.10lf\n",dfs(g,s,c,1,0));
}
