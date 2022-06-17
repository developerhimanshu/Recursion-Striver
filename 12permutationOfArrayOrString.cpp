#include <bits/stdc++.h>
using namespace std;


void findPermutations(vector<int>&ds, vector<int>&arr, int freq[], vector<vector<int>>&ans) {
	if (ds.size() >= arr.size()) {
		ans.push_back(ds);
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (!freq[i]) {
			ds.push_back(arr[i]);
			freq[i] = 1;
			findPermutations(ds, arr, freq, ans);
			freq[i] = 0;
			ds.pop_back();
		}
	}
}

vector<vector<int>>permute(vector<int>&nums) {
	vector<vector<int>>ans;
	vector<int>ds;
	int freq[nums.size()] = {0};
	for (int i = 0; i < nums.size(); i++)freq[i] = 0;
	findPermutations(ds, nums, freq, ans);
	return ans;
}
int main()
{

	vector<int>nums = {1, 2, 3, 4};
	vector<vector<int>>res = permute(nums);
	for (auto x : res) {
		for (auto ele : x) {
			cout << ele << " ";
		}
		cout << endl;
	}
	return 0;
}
