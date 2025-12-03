#include <bits/stdc++.h>
using namespace std;

/*
 Group Anagrams
 Key idea: use sorted string as the hash key.
 Time: O(n * k log k), where k = max length of a word
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (auto& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& p : mp) result.push_back(move(p.second));
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) cin >> strs[i];

    vector<vector<string>> res = groupAnagrams(strs);

    for (auto& group : res) {
        for (auto& w : group) cout << w << " ";
        cout << "\n";
    }

    return 0;
}
