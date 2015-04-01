/*
  Tags: greedy
 */
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define MP make_pair
#define PB push_back

const int mod = 1000000009;
const int N = 11;

int n;
vector<string> v;

bool cmp(string s1, string s2) {
  return (s1 + s2) > (s2 + s1);
}

int main() {
  ios::sync_with_stdio(false);
  while(cin >> n && n) {
    v.clear();
    string s;
    for(int i = 0; i < n; i++) {
      cin >> s;
      v.PB(s);
    }
    sort(v.begin(), v.end(), cmp);
    for(string ss: v) {
      cout << ss;
    }
    cout << endl;
  }
  return 0;
}
