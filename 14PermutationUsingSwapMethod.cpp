//Here we aren't using any extra space

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void permute(int ind, vector<int>&nums, vector<vector<int>>&ans)
	{
		if (ind == nums.size()) {
			ans.push_back(nums);
			return;
		}
		for (int i = ind; i < nums.size(); i++) {
			swap(nums[ind], nums[i]);
			permute(ind + 1, nums, ans);
			swap(nums[ind], nums[i]); // Here we are doing this because when we will backtrack we have the be in the unswapped position
		}
	}
public:
	vector<vector<int>> permutations(vector<int>nums) {
		vector<vector<int>>ans;
		permute(0, nums, ans);
		return ans;
	}
};


int main()
{
	Solution s;
	vector<int>nums = {1, 2, 3};
	vector<vector<int>>ans = s.permutations(nums);
	for (auto x : ans) {
		for (auto ele : x) {
			cout << ele << " ";
		}
		cout << endl;
	}

}
