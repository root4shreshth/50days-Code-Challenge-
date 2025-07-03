#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    unordered_set<string> dict;
    string word;
    int maxlen = 0;

    
    for (int i = 0; i < n; ++i) {
        cin >> word;
        dict.insert(word);
        if (word.length() > maxlen)
            maxlen = word.length();
    }

    int len = s.length();
    vector<bool> dp(len + 1, false);
    dp[0] = true; 

    for (int i = 1; i <= len; ++i) {
        for (int j = max(0, i - maxlen); j < i; ++j) {
            if (dp[j] && dict.count(string(s.begin() + j, s.begin() + i))) {
                dp[i] = true;
                break;
            }
        }
    }

    cout << (dp[len] ? "True" : "False") << endl;
    return 0;
}
