/*
  Note that R should be init as 10^7, got stuck here for long time :(
  Tags: binary search, priority queue, greedy
 */
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define MP make_pair
#define PB push_back

const int N = 10010;
struct Node {
  int r, d, w, w2;
  friend bool operator < (Node n1, Node n2) {
    return n1.d > n2.d;
  }
} a[N];
int n;

bool cmp(Node n1, Node n2) {
  return n1.r < n2.r;
}

bool ok(int k) {
  priority_queue<Node> q;
  int j = 0;
  for(int i = 1; i <= 20000; i++) {
    for(; j < n; j++) {
      if(a[j].r < i) {
	a[j].w2 = a[j].w;
	q.push(a[j]);	
      }
      else break;
    }
    int kk = k;
    while(kk && !q.empty()) {
      Node node = q.top();
      q.pop();
      if(node.d < i) return false;
      if(node.w2 > kk) {
	node.w2 -= kk;
	q.push(node);
	break;
      }
      else kk -= node.w2;
    }
  }
  return q.empty();
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      Node node;
      cin >> node.r >> node.d >> node.w;
      a[i] = node;
    }
    sort(a, a + n, cmp);
    int L = 1, R = 10000000;
    while(L < R) {
      int mid = (L + R) / 2;
      if(ok(mid)) R = mid;
      else L = mid + 1;
    }
    printf("%d\n", L);
  }
  return 0;
}
