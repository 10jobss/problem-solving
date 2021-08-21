#include <bits/stdc++.h>

using namespace std;

typedef struct node {
  int w;
  int time;
  node() {}
  node(int _w, int _time) : w(_w), time(_time) {}
}node;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int t, idx = 0, sum = 0;
  queue<node> q;
  for(t=1; ; ++t) {
    if(!q.empty()) {
      node n = q.front();
      if(t - n.time == bridge_length) {
        sum -= n.w;
        q.pop();
      }
    }

    if(idx==truck_weights.size() && q.empty()) break;

    if(idx < truck_weights.size() && q.size()+1 <= bridge_length && sum + truck_weights[idx] <= weight) {
      q.push(node(truck_weights[idx], t));
      sum += truck_weights[idx];
      idx++;
    }
  }
  return t;
}
