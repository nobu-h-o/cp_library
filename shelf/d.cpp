// Grass Block
 
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvvd vector<vector<vector<double>>>
#define vmi vector<mint>
#define vvmi vector<vector<mint>>
#define vvvmi vector<vector<vector<mint>>>
#define vb vector<bool>
#define vvb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pi pair<int,int>
#define vpi vector<pair<int,int>>
#define vvpi vector<vector<pair<int,int>>>
#define gi greater<int>
#define gpi greater<pair<int,int>>
#define eb emplace_back
#define ef emplace_front
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define rep(...) overload_rep(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define overload_rep(_1, _2, _3, NAME, ...) NAME
#define rep1(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}
#define int long long

void solve() {
  int n;
  cin >> n;
  if (n == 0) exit(0);
  int m; cin >> m;
  int x=-1, y=-1, l=-1;
  int ans = 0;
  vvc grid(n, vc(m));
  bool alb = true, alw = true;
  rep (i, n) rep(j, m){
    cin >> grid[i][j];
    if (grid[i][j] == '#') alw = false;
    else alb = false;
  }

  int cnt = 0;
  umap<int, vi> mx; 
  umap<int, vi> my; 
  rep (i, n-1){
    rep(j, m-1){
    if ((grid[i][j]=='#' && grid[i][j+1]=='.' && grid[i+1][j]=='#' && grid[i+1][j+1]=='#') ||
      (grid[i][j]=='#' && grid[i][j+1]=='#' && grid[i+1][j]=='.' && grid[i+1][j+1]=='#') ||
      (grid[i][j]=='.' && grid[i][j+1]=='#' && grid[i+1][j]=='#' && grid[i+1][j+1]=='#') ||
      (grid[i][j]=='#' && grid[i][j+1]=='#' && grid[i+1][j]=='#' && grid[i+1][j+1]=='.') ||
      (grid[i][j]=='#' && grid[i][j+1]=='.' && grid[i+1][j]=='.' && grid[i+1][j+1]=='.') ||
      (grid[i][j]=='.' && grid[i][j+1]=='.' && grid[i+1][j]=='.' && grid[i+1][j+1]=='#') ||
      (grid[i][j]=='.' && grid[i][j+1]=='#' && grid[i+1][j]=='.' && grid[i+1][j+1]=='.') ||
      (grid[i][j]=='.' && grid[i][j+1]=='.' && grid[i+1][j]=='#' && grid[i+1][j+1]=='.')){
        cout << -1 << endl; return;
      }


    if ((grid[i][j]=='#' && grid[i][j+1]=='.' && grid[i+1][j]=='.' && grid[i+1][j+1]=='#')
      || (grid[i][j]=='.' && grid[i][j+1]=='#' && grid[i+1][j]=='#' && grid[i+1][j+1]=='.')){
        mx[i].emplace_back(j);
        my[j].emplace_back(i);
        cnt++;
        if (cnt == 2){
          if (x == j) l = i - y;
          else if (y == i) l = j - x;
          else{
            cout << -2 << endl; return;
          }
        }
        x = j; y = i;
      }
    }
  }

  if (cnt == 0){
    if (alb || alw) {cout << 0 << endl; return;}
  }
  else if (cnt == 1){
    cout << 0 << endl; return;
  }else{
    for (auto [k, v]: mx){
      int size = v.size();
      int prev, index = 1;
      if (v[0] > l - 1 || m - v[size - 1] - 1 > l){
        cout << -1 << endl; return;
      }else{
        prev = v[0];
      }
      while (index < size - 1){
        if (v[index] - prev != l){
          cout << -1 << endl; return;
        }
        prev = v[index];
        index++;
      }
    }
    for (auto [k, v]: my){
      int size = v.size();
      int prev, index = 1;
      if (v[0] > l - 1|| n - v[size - 1] - 1 > l){
        cout << -1 << endl; return;
      }else{
        prev = v[0];
      }
      while (index < size - 1){
        if (v[index] - prev != l){
          cout << -1 << endl; return;
        }
        prev = v[index];
        index++;
      }
    }
  }

  cout << l << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  while(1) solve();
}
