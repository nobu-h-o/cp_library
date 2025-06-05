//https://atcoder.jp/contests/abc218/editorial/2598
vector<vector<char>> rot(const vector<vector<char>>& S) {
  int N = S.size();
  vector<vector<char>> result(N, vector<char>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      result[j][N-1-i] = S[i][j];
    }
  }
  return result;
}

pair<int,int> find_left_top(const vector<vector<char>>& S) {
  int N = S.size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (S[i][j] == '#') {
        return make_pair(i, j);
      }
    }
  }
  return make_pair(-1, -1);
}

bool same(const vector<vector<char>>& S, const vector<vector<char>>& T) {
  int N = S.size();
  pair<int,int> S_pos = find_left_top(S);
  pair<int,int> T_pos = find_left_top(T);
  int Si = S_pos.first, Sj = S_pos.second;
  int Ti = T_pos.first, Tj = T_pos.second;
  int offset_i = Ti - Si;
  int offset_j = Tj - Sj;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int ii = i + offset_i;
      int jj = j + offset_j;
      if (ii >= 0 && ii < N && jj >= 0 && jj < N) {
        if (S[i][j] != T[ii][jj]) return false;
      } else {
        if (S[i][j] == '#') return false;
      }
    }
  }
  return true;
}
