#include <bits/stdc++.h>
using namespace std;

// 生成随机字符串，包含至少k种不同字符
string generate_string(int n, int k) {
    string s;
    vector<char> chars;
    
    // 确保至少有k种不同字符
    for (int i = 0; i < k; i++) {
        chars.push_back('a' + i);
    }
    
    // 填充剩余字符
    for (int i = k; i < n; i++) {
        chars.push_back('a' + rand() % 26);
    }
    
    // 打乱字符顺序
    random_shuffle(chars.begin(), chars.end());
    
    // 构建字符串
    for (char c : chars) {
        s += c;
    }
    
    return s;
}

int main() {
    ofstream out("E:\problem\problem1\test.zip\\3.txt");
    srand(time(0));
    
    // 测试组数T (1 ≤ T ≤ 1e3)
    int T = 10 + rand() % 10;  // 生成10-20组测试数据
    out << T << endl;
    
    int total_n = 0;  // 总字符串长度
    
    for (int i = 0; i < T; i++) {
        // 字符串长度n (1 ≤ n ≤ 1e5)，且总长度不超过1e6
        int max_possible = min(100000, 1000000 - total_n);
        if (max_possible <= 0) {
            // 如果已经达到总长度限制，生成空字符串
            out << "0\n";
            out << "" << endl;
            continue;
        }
        
        int n;
        //if (i == 0) n = 1;                  // 第一组: 最小长度
        //else if (i == 1) n = 100000;         // 第二组: 最大长度
        //else if (i == 2) n = 2;              // 第三组: 最小无法构成三元组的情况
        //else if (i == 3) n = 3;              // 第四组: 最小可以构成三元组的情况
         n = 1 + rand() % max_possible;  // 其他组: 随机长度
        
        total_n += n;
        
        string s;
        //if (i == 0) s = "a";                       // 最小输入
        //else if (i == 1) s = string(100000, 'a');  // 最大长度但无法构成三元组
        //else if (i == 2) s = "ab";                  // 无法构成三元组
        //else if (i == 3) s = "abc";                // 最小可以构成三元组的情况
        //else if (i == 4) s = "aabb";               // 两种颜色
        //else if (i == 5) s = "aabc";               // 三种颜色但有重复
        //else if (i == 6) s = string(n, 'a');       // 全部相同字符
        //else {
            // 随机生成字符串，确保有足够的不同字符
            int k = 1 + rand() % min(26, n);       // 1到26种不同字符
            s = generate_string(n, k);
        //}
        
        out << n << endl;
        out << s << endl;
    }
    
    return 0;
}