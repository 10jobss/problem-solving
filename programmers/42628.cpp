#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
  vector<int> answer;
  vector<int> list;

  priority_queue<int> max_heap, tmp;

  for(string s : operations) {
    if(s[0]=='I') {
      max_heap.push(stoi(s.substr(2)));
    } else if(s[2]=='1') {
      if(!max_heap.empty())
        max_heap.pop();
    } else {
      if(!max_heap.empty()) {
        int k;
        while(!max_heap.empty()) {
          k = max_heap.top();
          max_heap.pop();
          if(!max_heap.empty())
            tmp.push(k);
        }
        while(!tmp.empty()) {
          max_heap.push(tmp.top());
          tmp.pop();
        }
      }
    }
  }
  while(!max_heap.empty()) {
    list.push_back(max_heap.top());
    max_heap.top();
  }
  sort(list.begin(), list.end());
  if(!list.size()) {
    list.push_back(0);
    list.push_back(0);
  }
  answer.push_back(list.back());
  answer.push_back(list.front());
  return answer;
}
