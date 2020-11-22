#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main()
{
	int h,w;
	cin >> h >> w;
	vector<string> G(h);
	for(auto &i:G)cin >> i;

	vector<vector<int>> dis(h,vector<int>(w,-1));
	deque<pair<int,int>> dq;
	map<char,vector<pair<int,int>>> mp;

	for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			if(G[i][j]=='S'){
				dq.emplace_back(i,j);
				dis[i][j]=0;
			}
			if('a'<=G[i][j]&&G[i][j]<='z'){
				mp[G[i][j]].emplace_back(i,j);
			}
		}
	}
	map<char,int> used;
	while(dq.size()){
		auto now = dq.front();
		dq.pop_front();
		for(int i = 0;i<4;i++){
			auto next = now;
			next.first += dx[i];next.second += dy[i];
			if(next.first<0||next.first>=h||next.second<0||next.second>=w||G[next.first][next.second]=='#')continue;
			if(dis[next.first][next.second]!=-1)continue;
			dis[next.first][next.second] = dis[now.first][now.second] + 1;
			dq.emplace_back(next);
		}
		if('a'<=G[now.first][now.second]&&G[now.first][now.second]<='z'){
			if(used[G[now.first][now.second]])continue;
			used[G[now.first][now.second]]=1;
			for(auto &i:mp[G[now.first][now.second]]){
				auto next = i;
				if(dis[next.first][next.second]!=-1)continue;
				dis[next.first][next.second] = dis[now.first][now.second] + 1;
				dq.emplace_back(next);
			}
		}
	}
	for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){if(G[i][j]=='G'){
			cout<<dis[i][j]<<endl;
		}}
	}

}
