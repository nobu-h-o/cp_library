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
#define int long long
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

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
  int n = (int)graph.size();
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(n, MAX);
  dist[start] = 0;
  pq.emplace(dist[start], start);
  while(!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();
    int v = p.second;
    if(dist[v] < p.first) continue;
    for(auto e : graph[v]) {
      if(dist[e.first] > dist[v] + e.second) {
        dist[e.first] = dist[v] + e.second;
        pq.emplace(dist[e.first], e.first);
      }
    }
  }
  return dist;
}

void solve() {
  int n = 0;
  cin >> n;
  if (n == 0) exit(0);

  // pair<node,cost>
  vvpi g(n+1);

  uset<int>leaf;
  for(int i=1;i<=n;i++)leaf.insert(i);

  for(int i=2;i<=n;i++){
    int p,e;cin>>p>>e;
    g[i].eb(p,e);
    g[p].eb(i,e);
    if(leaf.contains(p))leaf.erase(p);
  }

  vi dis=dijkstra(g,1);
  // map<dis,leaf> (ordered)
  map<int,int>mp;
  for(int num:leaf)mp[dis[num]]=num;

  for(int i=1;i<=n;i++)std::sort(g[i].begin(),g[i].end());

  // for(auto [first,second]:g[5])cout<<first<<endl;


  // traversal
  vi ans;
  int t=0;
  uset<int>vis({1});
  for(auto [dis,leaf]:mp){
    // get route to leaf
    vi route;
    while(leaf!=1){
      route.eb(leaf);
      leaf = g[leaf][0].first;
    }
    reverse(route.begin(),route.end());
    for(int l:route)cout<<l<<" ";
    cout<<endl;
    
    // int prevLeaf=1;
    // for(int lvs:route){
    //   if(vis.contains(lvs)){
    //     ans.eb(lvs);
    //   }else{
    //     t++;
    //     if(g[lvs][prevLeaf].second<t){
    //       cout<<g[lvs][prevLeaf].second<<endl;
    //       cout<<"no"<<endl;
    //       return;
    //     }
    //   }
    //   prevLeaf=lvs;
    // }
    int sz=route.size();
    for(int i=0;i<sz-1;i++){
      if(vis.contains(route[i])){
        ans.eb(route[i]);
      }else{
        t++;
        // cout<<g[route[i]][route[i+1]].second<<endl;
        // if(g[route[i]][route[i+1]].second<t){
        //   cout<<"no"<<endl;
        //   return;
        // }
      }
    }
  }
  for(int i:ans)cout<<i<<" ";
  cout<<endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  while(1) solve();
}