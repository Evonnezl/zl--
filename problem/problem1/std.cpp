#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;// 1 <= n <= 1e5;
    string s;
    cin >> s;// s[i]只会是小写字母
    ll hash[26]{};
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a']++;
    }
    ll sum = n;
    ll ans = 0;
    for(int i = 0; i < 26; i++){
        if(hash[i] == 0) continue;
        for(int j = 0; j < 26; j++){
            if(hash[j] == 0 || j == i) continue;
            ans = (ans + hash[i] * hash[j] * (sum - hash[i] - hash[j]) % mod) % mod;
           // cout << ans << " ";
        }
    }
    cout << ans % mod << endl;
}

int main(){
    int t;
    cin >> t;//  1 <= t <= 1e3;
    while(t--) solve();
    return 0;
}
//∑n ≤ 1e6
/*程序功能
该程序计算给定字符串中所有满足以下条件的有序三元组 (p1, p2, p3) 的数量（模 1e9+7）：

三个位置互不相同（p1, p2, p3 是字符串中不同位置）

三个位置上的字符互不相同（s[p1], s[p2], s[p3] 是三个不同的字母）

总时间复杂度：O(∑n + t × 26²)

∑n：所有字符串总长度（≤ 1e6）

t × 26²：测试用例数 × 676
*/