#include <climits>
#include <cstddef>
#include <iomanip>
#include <ios>
#include <limits>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include "map"

// using namespace std;

typedef long long ll;

#define all(v) v.begin(), v.end()


class DisjointSet{ public:

    std::vector<int> parent;

    DisjointSet(int n): parent(n) { for(int i=0; i<n; i++) parent[i] = i; }

    void join(int a, int b) { parent[find(b)] = find(a); }

    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

    bool check(int a, int b){ return find(a) == find(b); }
};
class Solution {
public:

    std::vector<std::pair<uint32_t, uint32_t>> dir = {{0,-1},{-1,0}};

    int numIslands(std::vector<uint32_t>& grid, int m, int n)
    {
        std::swap(n,m);
        int all = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                uint32_t ind = i * m + j;
                if (grid[ind] == 1) {
                    ++all;
                }
            }
        }

        DisjointSet dsu(n*m);

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                uint32_t ind = i * m + j;
                if (grid[ind] == 0) {
                    continue;
                }

                for(const auto& [dx,dy] : dir) {
                    uint32_t nx = i + dx;
                    uint32_t ny = j + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    uint32_t nind = nx * m + ny;
                    if (grid[nind] == 1) {
                        if(dsu.check(ind, nind)){
                            continue;
                        }
                        dsu.join(ind, nind);
                        all--;
                    }
                }
            }
        }        
        return all;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}