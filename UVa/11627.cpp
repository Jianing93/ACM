#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define MP make_pair
#define PB push_back

const int N = 1000010;

struct Gate {
  int x, y;
} g[100010];

int s[N], speed[N], S, vh, W, n;

bool ok(double sp) {
  double l = g[0].x, r = g[0].x + W;
  for(int i = 0; i < n - 1; i++) {
    double offset = (g[i + 1].y - g[i].y) / sp * vh;
    if(l - offset > g[i + 1].x + W || r + offset < g[i + 1].x) return false;
    l = max(l - offset, g[i + 1].x + 0.0);
    r = min(r + offset, g[i + 1].x + W + 0.0);
  }
  return true;
}


int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    cin >> W >> vh >> n;
    for(int i = 0; i < n; i++) {
      Gate gate;
      cin >> gate.x >> gate.y;
      g[i] = gate;
    }
    cin >> S;
    for(int i = 0; i < S; i++) {
      int x;
      cin >> x;
      speed[x]++;
    }
    int j = 0;
    for(int i = 0; i < N; i++) {
      while(speed[i]--) {
	s[j++] = i;
      }
      speed[i] = 0;
    }

    int L = 0, R = S - 1;
    int ans = -1;
    while(L <= R) {
      int mid = (L + R) / 2;
      if(ok(s[mid])) L = mid + 1, ans = mid;
      else R = mid - 1;
    }
    if(ans != -1) printf("%d\n", s[ans]);
    else puts("IMPOSSIBLE");
  }
  return 0;
}
