#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool bruteForce(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }

    return false;
}

bool sorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}

bool hashSet(vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }

    return false;
}

bool hashMap(vector<int>& nums) {
    unordered_map<int, int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen[num] = 1;
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << (hashMap(nums) ? "true" : "false") << endl;
    return 0;
}