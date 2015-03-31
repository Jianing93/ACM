/*
  note:
  use double to prevent overflow when calculate sqrt(r * r - w * w / 4.0)
 */
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define MP make_pair
#define PB push_back

const int mod = 1000000009;
const int N = 100010;

pair<double, double> a[N];

int main() {
  int n, l, w;
  while(~scanf("%d%d%d", &n, &l, &w)) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
      double p, r;
      scanf("%lf%lf", &p, &r);
      double k = sqrt(r * r - w * w / 4.0);
      a[i] = MP(p - k, p + k);
    }
    sort(a, a + n);
    double x = 0;
    int i = 0;
    while(x < l) {
      double nx = x;
      bool ok = false;
      for(; i < n; i++) {
	if(a[i].first > x) break;
	if(nx < a[i].second) {
	  ok = true;
	  nx = a[i].second;
	}
      }
      if(!ok) break;
      ans++;
      x = nx;
    }
    if(x < l) puts("-1");
    else printf("%d\n", ans);
  }
  return 0;
}
