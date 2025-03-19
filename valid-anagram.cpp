#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> seen;

    for (char c : s) {
        seen[c]++;
    }

    for (char c : t) {
        if (seen.find(c) == seen.end() || seen[c] == 0) {
            return false;
        }
        seen[c]--;
    }
    
    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    cout << (isAnagram(s, t) ? "true" : "false") << endl;

    return 0;
}