#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

#define int long long
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define ii pair<int,int> 
#define F first
#define S second
#define all(a) a.begin(),a.end()

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


void dfs(int i, int j, int k, vector<vector<int> >& vis , vector<ii>& curr_comp, vector<vector<int> >& arr){
    if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || vis[i][j] || arr[i][j] == 0) return;

    vis[i][j] = 1;
    curr_comp.push_back(ii(i,j));
    
    for(int d=0;d<4;d++){
        for(int l = 0; l <= k; l++){
            dfs(i + dx[d]*l, j + dy[d]*l, k, vis, curr_comp, arr);
        }
    }
}

int get_area(vector<ii> &comp){
    int top_left_x = 1e9;
    int top_left_y = 1e9;
    int bottom_right_x = -1;
    int bottom_right_y = -1;

    for(auto point : comp){
        top_left_x = min(top_left_x,point.F);
        top_left_y = min(top_left_y,point.S);
        bottom_right_x = max(bottom_right_x,point.F);
        bottom_right_y = max(bottom_right_y,point.S);
    }
    return (bottom_right_x - top_left_x + 1) * (bottom_right_y - top_left_y + 1);
}

void solve(){
    int n,m,k; cin>>n>>m>>k;
    vector<vector<int> > arr(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans = 0; 

    vector< vector<int> > vis(n,vector<int>(m,0));

    vector<pair<int,int> > curr_comp;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] && !vis[i][j]){
                dfs(i,j,k,vis,curr_comp,arr);
                ans += get_area(curr_comp);
                curr_comp.clear();
            }
        }
    }

    cout << ans << endl;

}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     #ifndef ONLINE_JUDGE
     freopen("./tests/test3/test_file_1.txt.txt", "r", stdin);
     freopen("./output/test3/output1.txt", "w", stdout);
     #endif
    int _t;cin>>_t;while(_t--)
    solve();
    // cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}