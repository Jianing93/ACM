/*
  Tags: greedy + priority queue
 */
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define MP make_pair
#define PB push_back

const int N = 5010;

struct Node {
  int x1, x2, y1, y2, ind;
  friend bool operator < (Node n1, Node n2) {
    return n1.x2 > n2.x2;
  }
} a[N];

bool cmp(Node n1, Node n2) {
  return n1.x1 < n2.x1 || (n1.x1 == n2.x1 && n1.x2 < n2.x2);
}

int n, ans[N][2];

bool gao() {
  for(int i = 0; i < 2; i++) {
    if(i)
      for(int j = 0; j < n; j++) {
	swap(a[j].x1, a[j].y1);
	swap(a[j].x2, a[j].y2);	  
      }
    sort(a, a + n, cmp);
    priority_queue<Node> q;
    int j = 0, k = 1;
    for(; j < n && a[j].x1 == 1; j++) q.push(a[j]);
    while(!q.empty()) {
      Node node = q.top(); q.pop();
      if(node.x1 <= k && k <= node.x2) {
	ans[node.ind][i] = k;
	k++;
	for(; j < n && a[j].x1 <= k; j++) {
	  q.push(a[j]);
	}
      } else {
	return false;
      }
    }
    if(k != n + 1) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  while(cin >> n && n) {
    for(int i = 0; i < n; i++) {
      cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
      a[i].ind = i;
    }
    if(!gao()) puts("IMPOSSIBLE");
    else {
      for(int i = 0; i < n; i++) {
	printf("%d %d\n", ans[i][0], ans[i][1]);
      }
    }
  }
  return 0;
}
