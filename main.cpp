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

class Solution {
public:

    std::vector<std::vector<bool>> used;
    std::vector<std::pair<uint32_t, uint32_t>> dir = {{0,1},{0,-1},{1,0},{-1,0}};


    void dfs(ll i,ll j){
        used[i][j] = true;
        for(auto d : dir){
            ll x = i + d.first;
            ll y = j + d.second;
            if(x >= 0 && x < used.size() && y >= 0 && y < used[0].size() && !used[x][y]){
                dfs(x,y);
            }
        }
    }
    int numIslands(std::vector<uint32_t>& grid, int m, int n)
    {
        used.assign(n,std::vector<bool>(m,false));
        int ans = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                uint32_t ind = i * m + j;
                if (grid[ind] == 1 && !used[i][j]) {
                    dfs(i, j);
                    ++ans;
                }
            }
        }
        return ans;
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