# Compiler, c++ version and flags
CC = g++
STD = -std=c++20
CXXFLAGS = -O2 -Wall $(STD)

# Target executable
PROG = a

# Source and object files
SRC = a.cpp
OBJ = a.o

# Default target
all: $(PROG)

# Link the object file to create the executable
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

# Compile the source file into an object file
$(OBJ): $(SRC)
	$(CC) -c $< $(CXXFLAGS)

# Run the executable
run: $(PROG)
	./$(PROG)

# Clean up generated files
clean:
	rm -f $(PROG) $(OBJ)

# Phony targets to prevent conflicts with files named 'all', 'clean', or 'test'
.PHONY: all clean run

reset:
	echo '// Grass Block' > a.cpp
	echo ' ' >> a.cpp
	echo '#include <bits/stdc++.h>' >> a.cpp
	echo 'using namespace std;' >> a.cpp
	echo '#define vi vector<int>' >> a.cpp
	echo '#define vvi vector<vector<int>>' >> a.cpp
	echo '#define vvvi vector<vector<vector<int>>>' >> a.cpp
	echo '#define vd vector<double>' >> a.cpp
	echo '#define vvd vector<vector<double>>' >> a.cpp
	echo '#define vvvd vector<vector<vector<double>>>' >> a.cpp
	echo '#define vmi vector<mint>' >> a.cpp
	echo '#define vvmi vector<vector<mint>>' >> a.cpp
	echo '#define vvvmi vector<vector<vector<mint>>>' >> a.cpp
	echo '#define vb vector<bool>' >> a.cpp
	echo '#define vs vector<string>' >> a.cpp
	echo '#define vc vector<char>' >> a.cpp
	echo '#define vvc vector<vector<char>>' >> a.cpp
	echo '#define pi pair<int,int>' >> a.cpp
	echo '#define vpi vector<pair<int,int>>' >> a.cpp
	echo '#define vvpi vector<vector<pair<int,int>>>' >> a.cpp
	echo '#define gi greater<int>' >> a.cpp
	echo '#define gpi greater<pair<int,int>>' >> a.cpp
	echo '#define eb emplace_back' >> a.cpp
	echo '#define ef emplace_front' >> a.cpp
	echo '#define pq priority_queue' >> a.cpp
	echo '#define umap unordered_map' >> a.cpp
	echo '#define uset unordered_set' >> a.cpp
	echo '#define int long long' >> a.cpp
	echo '#define MAX LLONG_MAX' >> a.cpp
	echo '#define MIN LLONG_MIN' >> a.cpp
	echo '#define all(a) (a).begin(), (a).end()' >> a.cpp
	echo '#define rall(a) (a).rbegin(), (a).rend()' >> a.cpp
	echo '#define rep(...) overload_rep(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)' >> a.cpp
	echo '#define overload_rep(_1, _2, _3, NAME, ...) NAME' >> a.cpp
	echo '#define rep1(i, n) for (int i = 0; i < (n); ++i)' >> a.cpp
	echo '#define rep2(i, a, b) for (int i = (a); i < (b); ++i)' >> a.cpp
	echo 'template< typename T >' >> a.cpp
	echo 'istream &operator>>(istream &is, vector< T > &v) {' >> a.cpp
	echo '    for(T &in : v) is >> in;' >> a.cpp
	echo '    return is;' >> a.cpp
	echo '}' >> a.cpp
	echo '' >> a.cpp
	echo 'void solve() {' >> a.cpp
	echo '  int n = 0;' >> a.cpp
	echo '  cin >> n;' >> a.cpp
	echo '  if (n == 0) exit(0);' >> a.cpp
	echo '  ' >> a.cpp
	echo '}' >> a.cpp
	echo '' >> a.cpp
	echo 'signed main() {' >> a.cpp
	echo '  cin.tie(nullptr);' >> a.cpp
	echo '  ios::sync_with_stdio(false);' >> a.cpp
	echo '  while(1) solve();' >> a.cpp
	echo '}' >> a.cpp
