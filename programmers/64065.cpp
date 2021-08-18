#include <bits/stdc++.h>

using namespace std;

typedef struct node {
  int cnt;
  int number;
}node;

bool cmp(const node& l, const node& r) {
  if(l.cnt == r.cnt) return l.number > r.number;
  return l.cnt > r.cnt;
}

vector<int> solutions(string s) {
  vector<int> answer;
  map<int, int> mp;
  vector<node> vt;
  string tmp = "";
  for(char c : s) {
    if(c >= '0' && c <= '9')
      tmp += c;
    else if(!tmp.empty()) {
      mp[stoi(tmp)]++;
      tmp = "";
    }
  }
  for(auto it=mp.begin(); it!=mp.end(); ++it) {
    node n;
    n.cnt = it->second;
    n.number = it->first;
    vt.push_back(n);
  }
  sort(vt.begin(), vt.end(), cmp);
  for(node n : vt)
    answer.push_back(n.number);
  return answer;
}
