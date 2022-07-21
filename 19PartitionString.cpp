/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPal(string s, int st, int e){
	while(st<=e){
		if(s[st]!=s[e])
			return false;
		st++;e--;
	}
	return true;
}
void solve(string s, vector<vector<string>>&ans, vector<string>&path,int ind){
	if(ind==s.length())
	{
		ans.push_back(path);
		return;
	}
	for(int i = ind; i<s.length(); i++){
		if(isPal(s, ind, i)){
			path.push_back(s);
			solve(s, ans, path, ind+1);
			path.pop_back();
		}
	}
}

vector<vector<string>>partition(string s){
	vector<vector<string>>ans;
	vector<string>path;
	solve(s, ans,path,  0);
	return ans;
}
int main()
{
	
	
	return 0;
}
