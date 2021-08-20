#include <bits/stdc++.h>

using namespace std;

bool _balanced(string s) {
  int cnt_open = 0, cnt_close = 0;
  for(char c : s) {
    cnt_open += c=='(';
    cnt_close += c==')';
  }
  return cnt_open == cnt_close;
}

bool _correct(string s) {
  stack<char> st;
  for(char c : s) {
    if(c==')') {
      if(st.empty()) return false;
      st.pop();
    } else
      st.push(c);
  }
  return st.empty();
}

string f(string& w) {
  if(w.empty()) return "";
  string u = "", v = "";
  int i;
  for(i=0; i<w.size(); ++i) {
    u += w[i];
    if(_balanced(u)) break;
  }
  v = w.substr(i+1);
  if(_correct(u))
    return u + f(v);
  string ret = "(";
  ret += f(v);
  ret += ")";
  string new_u = "";
  for(int i=1; i<u.size()-1; ++i)
    new_u += u[i];
  string tmp = "";
  for(char c : new_u) {
    if(c==')') tmp += '(';
    else tmp += ')';
  }
  return ret + tmp;
}

string solution(string p) {
  return f(p);
}
