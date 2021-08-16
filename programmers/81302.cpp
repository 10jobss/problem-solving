#include <string>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;

int dy[]={0,0,-1,1}, dx[]={1,-1,0,0};
int d[5][5];

void dfs(int y, int x, vector<string>& place) {
  for(int i=0; i<4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny<0 || ny>=5 || nx<0 || nx>=5) continue;
    if(place[ny][nx] == 'X') continue;
    if(d[ny][nx]<0 || (d[ny][nx]>=0 && d[ny][nx]>=d[y][x]+1)) {
      d[ny][nx] = d[y][x] + 1;
      dfs(ny, nx, place);
    }
  }
}

vector<int> solution(vector<vector<string>> places) {
  vector<int> answer;
  for(int i=0; i<places.size(); ++i) {
    vector<pii> person;
    for(int j=0; j<5; ++j) {
      for(int k=0; k<5; ++k)
        if(places[i][j][k]=='P')
          person.push_back({j,k});
    }
    int result = 1;
    for(pii s : person) {
      memset(d, -1, sizeof(d));
      d[s.first][s.second] = 0;
      dfs(s.first, s.second, places[i]);
      for(pii p : person) {
        if(s.first == p.first && s.second == p.second) continue;
        if(d[p.first][p.second]>0 && d[p.first][p.second] <= 2) {
          result = 0;
          break;
        }
      }
      if(!result) break;
    }
    answer.push_back(result);
  }
  return answer;
}
