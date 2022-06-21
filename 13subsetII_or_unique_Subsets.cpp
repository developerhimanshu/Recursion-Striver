#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void RecSubset(int ind, vector<int>&nums , vector<int>&ds, vector<vector<int>>&ans) {
		ans.push_back(ds);
		for (int i = ind; i < nums.size(); i++) {
			if (i == ind || nums[i] != nums[i - 1]) {
				ds.push_back(nums[i]);
				RecSubset(i + 1, nums, ds, ans);
				ds.pop_back();
			}
		}
	}
public:

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>>ans;
		vector<int>ds;
		sort(nums.begin(), nums.end());
		RecSubset(0, nums, ds, ans);
		return ans;
	}
};

int main()
{
	Solution s;
	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<vector<int>>ans = s.subsetsWithDup(nums);
	for (auto x : ans) {
		for (auto ele : x) {
			cout << ele << " ";
		}
		cout << "\n";
	}
}