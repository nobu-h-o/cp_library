bool topological_sort(vector<vector<int>>& edge, vector<int>& inedge, int n) {
  vector<int> ans;
  priority_queue<int, vector<int>, greater<int>> que; // min-heap
  
  // Add all vertices with no incoming edges
  for (int i = 0; i < n; i++) {
    if (inedge[i] == 0) {
      que.push(i);
    }
  }
  
  while (!que.empty()) {
    int q = que.top();
    que.pop();
    ans.push_back(q + 1); // Convert back to 1-indexed
    
    for (int e : edge[q]) {
      inedge[e]--;
      if (inedge[e] == 0) {
        que.push(e);
      }
    }
  }
  return (int)ans.size()==n;
}
