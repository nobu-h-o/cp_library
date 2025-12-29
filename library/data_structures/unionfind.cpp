///{{{ UF
struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
  	a = find(a), b = find(b);
  	if (a == b) return false;
  	if (e[a] > e[b]) swap(a, b);
  	e[a] += e[b]; e[b] = a;
  	return true;
  }
  vvi groups() {
    int n = e.size();
    map<int,vi> group_map;
    for (int i = 0; i < n; i++) {
        group_map[find(i)].push_back(i);
    }
    vvi result;
    for (const auto& pair : group_map) {
    result.push_back(pair.second);
    }
    return result;
  }
};
///}}}
