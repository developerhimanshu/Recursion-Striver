#include <bits/stdc++.h>
using namespace std;

void combinationSum(int ind, int target, vector<int>&arr, vector<int>&ds, vector<vector<int>>&ans) {
	if (target == 0)
	{
		ans.push_back(ds);
		return;
	}
	//We are checking for every index that is it possible to do the combination sum
	for (int i = ind; i < arr.size(); i++) {
		if (i > ind && arr[i] == arr[i - 1])continue; //if the combination sum for the previous same element is done then we don't need for next element
		if (arr[i] > target)break;
		ds.push_back(arr[i]);
		combinationSum(i + 1, target - arr[i], arr, ds, ans);
		ds.pop_back(); //As we will backTrack so for getting the previous form we would remove top element
	}

}

vector<vector<int>>combinationSum2(vector<int>&candidate, int target) {
	sort(candidate.begin(), candidate.end());
	vector<vector<int>>ans;
	vector<int>ds;
	combinationSum(0, target, candidate, ds, ans);
	return ans;
}
int main()
{
	int  target;

	vector<int>candidates;
	for (int i = 0; i < 7; i++) {
		int x;
		cin >> x;
		candidates.push_back(x);
	}
	cin >> target;
	vector<vector<int>> ans = combinationSum2(candidates, target);
	for (auto x : ans) {
		for (auto ele : x)
			cout << ele << " ";
		cout << endl;
	}
	return 0;
}
