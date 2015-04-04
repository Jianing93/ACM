/*
  Note: No need to use priority queue, but I did it :( 
        sort, then an arithmetic sequence will do the same.(To minimize the total number of bags in any one piece that must be carried).
  Tags: greedy
 */
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define MP make_pair
#define PB push_back
#define REP(i, n) for(int i = 0; i < (n); i++)

const int N = 1000010;
const int inf = ~0U >> 1;
int a[N], n;
vector<int> v[10010];

int main() {
  ios::sync_with_stdio(false);
  bool f = true;
  while(cin >> n && n) {
    if(!f) puts("");
    f = false;
    memset(a, 0, sizeof(a));
    int cnt = 0;
    REP(i, n) {
      int x;
      cin >> x;
      a[x]++;
      cnt = max(cnt, a[x]);
      v[i].clear();
    }
    priority_queue< pii > q;
    REP(i, cnt) q.push(MP(0, -i));
    for(int i = 0; i < N; i++) {
      while(a[i]--) {
	pii p = q.top(); q.pop();
	v[-p.second].PB(i);
	q.push(MP(-SZ(v[-p.second]), p.second));
      }
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
      for(int j = 0; j < SZ(v[i]); j++) {
	printf("%d%c", v[i][j], j == SZ(v[i]) - 1 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
