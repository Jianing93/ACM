#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define N 210

struct Edge {
  int next, cap, f, v, i;
};
Edge p[N];

int n;
int a[N];

const int inf = ~0U>>1;

bool vis[N];

vector<Edge> e[N];
vector<int> g[N];

bool is_prime(int p) {
  if(p % 2 == 0) return false;
  for(int i = 2; i * i <= p; i++) {
    if(p % i == 0) return false;
  }
  return true;
}

int bfs() {
  int res = 0;
  while(true) {
    int m = inf;
    queue<int> q;
    q.push(0);
    for(int i = 0; i < N; i++) {
      p[i].v = -1;
    }
    
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j < e[i].size(); j++) {
	Edge edge = e[i][j];
	printf("%d-%d cap:%d f:%d\n", edge.v, edge.next, edge.cap, edge.f);
      }
    }
    puts("");
    
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(int i = 0; i < e[u].size(); i++) {
	Edge edge = e[u][i];
	if(edge.cap > edge.f && p[edge.next].v == -1) {
	  p[edge.next] = edge;
	  q.push(edge.next);
	}
      }
    }
    
    if(p[n + 1].v == -1) return res;

    int df = inf;
    for(int u = n + 1; u; u = p[u].v) {
      df = min(df, p[u].cap - p[u].f);
    }
    for(int u = n + 1; u; u = p[u].v) {
      e[p[u].v][p[u].i].f += df;
    }
    res += df;
  }
}

int main() {
  cin >> n;
  for(int i = 1 ; i <= n; i++) {
    cin >> a[i];
  }

  memset(p, -1, sizeof(p));

  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      if(i == j) continue;
      if(is_prime(a[i] + a[j])) {
	Edge edge1, edge2;
	edge1.cap = 1;
	edge1.f = 0;
	edge1.i = e[i].size();
	edge1.v = i;
	edge1.next = j;

	edge2.cap = 1;
	edge2.f = 0;
	edge2.i = e[j].size();
	edge2.v = j;
	edge2.next = i;

	e[i].push_back(edge1);
	e[j].push_back(edge2);
	/*
	if(a[i] & 1) {
	  edge.next = j;
	  edge.v = i;
	  edge.i = e[i].size();
	  e[i].push_back(edge);
	} else {
	  edge.next = i;
	  edge.v = j;
	  edge.i = e[j].size();
	  e[j].push_back(edge);
	}
	*/
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    Edge edge;
    edge.cap = 2;
    edge.f = 0;
    if(a[i] & 1) {
      edge.next = i;
      edge.v = 0;
      edge.i = e[0].size();
      e[0].push_back(edge);
    } else {
      edge.next = n + 1;
      edge.v = i;
      edge.i = e[i].size();
      e[i].push_back(edge);
    }
  }

  
  if(bfs() == n) {
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < e[i].size(); j++) {
	Edge edge = e[i][j];
	if(edge.f == 1) {
	  g[edge.v].push_back(edge.next);
	  g[edge.next].push_back(edge.v);
	}
      }
    }

    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < g[i].size(); j++) {
	printf("%d %d\n", i, g[i][j]);
      }
      puts("");
    }
    
    for(int i = 1; i <= n; i++) {
      if(vis[i]) continue;
      int k = i;
      int ans[N], cnt = 0;
      while(!vis[k]) {
	vis[k] = true;
	ans[cnt++] = k;
	for(int j = 0; j < g[k].size(); j++)
	  if(!vis[g[k][j]]){
	    k = g[k][j];
	    break;
	  }
	//	if(!vis[g[k][0]]) k = g[k][0];
	//else if(!vis[g[k][1]]) k = g[k][1];
	//else break;
      }
      printf("%d", cnt);
      for(int j = 0; j < cnt; j++) {
	printf(" %d", ans[j]);
      }
      puts("");
    }
  } else {
    puts("Impossible");
  }

  
  return 0;
}
