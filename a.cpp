#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define MP make_pair
#define PB push_back

struct Edge {
  int ind, next, cost;

  Edge(int _ind, int _next, int _cost) {
    ind = _ind; next = _next; cost = _cost;
  }
};

const int inf = ~0U >> 1;
const int N = 100010;
int n, m, a[N], b[N], c[N], d[N];
vector<Edge> e[N];
bool vis[N], cover[N];
int ans1[N], ans2[N], ans3[N];

int main () {
  cin >> n >> m;

  for(int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d%d%d", a + i, b + i, c + i);
    x = a[i] - 1; y = b[i] - 1;
    e[x].PB(Edge(i, y, c[i]));
    e[y].PB(Edge(i, x, c[i]));
  }

  priority_queue<pii > q;
  q.push(MP(0, 0));
  for(int i = 0; i < n; i++) d[i] = inf;
  d[0] = 0;

  while(!q.empty()) {
    pii p = q.top();
    q.pop();
    int u = p.second;
    if(vis[u]) continue;
    vis[u] = true;
    for(auto edge: e[u]) {
      if(d[edge.next] > d[u] + edge.cost) {
	d[edge.next] = d[u] + edge.cost;
	cover[edge.ind] = true;
	q.push(MP(-d[edge.next], edge.next));
      }
    }
  }

  int k = 0;
  //printf("min dist: %d\n", d[n - 1]);
  for(int i = 0; i < m; i++) {
    //printf("cover %d %d\n", i, cover[i]);
    if(!cover[i] && c[i]) {
      ans1[k] = a[i]; ans2[k] = b[i]; ans3[k] = 0;
      k++;
      //printf("%d %d 0\n", a[i], b[i]);
    } else if(cover[i] && !c[i]) {
      ans1[k] = a[i]; ans2[k] = b[i]; ans3[k] = 1;
      k++;
      //printf("%d %d 1\n", a[i], b[i]);
    }
  }

  printf("%d\n", k);
  for(int i = 0; i < k; i++) {
    printf("%d %d %d\n", ans1[i], ans2[i], ans3[i]);
  }
  return 0;
}
