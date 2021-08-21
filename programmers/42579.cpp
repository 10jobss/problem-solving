#include <bits/stdc++.h>

using namespace std;

typedef struct music {
  int gen, play_cnt, idx;
  music() {}
  music(int _gen, int _play_cnt, int _idx) : gen(_gen), play_cnt(_play_cnt), idx(_idx) {}
}music;

bool cmp(const music& l, const music& r) {
  if(l.gen == r.gen) {
    if(l.play_cnt == r.play_cnt) return l.idx < r.idx;
    return l.play_cnt > r.play_cnt;
  }
  return l.gen > r.gen;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> ans;
  vector<music> music_list;
  unordered_map<string, int> mp;
  unordered_map<int, int> pick;
  for(int i=0; i<genres.size(); ++i) {
      music_list.push_back(music(mp[genres[i]], plays[i], i));
  }
  sort(music_list.begin(), music_list.end(), cmp);
  for(music m : music_list) {
    if(pick[m.gen] <2) {
      ans.push_back(m.idx);
      pick[m.gen]++;
    }
  }
  return ans;
}
