#include <bits/stdc++.h>

using namespace std;

string _convert(int number, int n) {
  if(!number) return "0";
  string ret = "";
  while(number) {
    int x = number%n;
    if(x<10) ret += '0'+x;
    else ret += 'A'+x-10;
    number/=n;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

string solution(int n, int t, int m, int p) {
  string answer = "";
  int cnt = 0, idx = 0, _fin = 0;
  for(int i=0; ; ++i) {
    string result = _convert(i, n);
    for(char c : result) {
      if(idx%m == p-1) {
        answer += c;
        ++cnt;
      }
      if(cnt==t) {
        _fin = 1;
        break;
      }
      ++idx;
    }
    if(_fin) break;
  }
  return answer;
}
