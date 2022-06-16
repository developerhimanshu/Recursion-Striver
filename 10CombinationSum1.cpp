#include <bits/stdc++.h>
using namespace std;
void findCombination(int ind, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds) {
    if (ind == arr.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    //picking up the element
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);

        //as we are backtracking we will have to pop back the element from the data structure
        ds.pop_back();
    }
    //not picking up the element
    findCombination(ind + 1, target, arr, ans, ds);

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main() {
    int n, target;
    cin >> n;
    vector<int>candidates(n);
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    cin >> target;
    vector<vector<int>> res = combinationSum(candidates, target);
    for (auto x : res) {
        for (auto p : x) {
            cout << p << " ";
        }
        cout << endl;
    }

}
