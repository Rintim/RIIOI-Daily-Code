#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maximumSum(vector<int>& arr) {
		int 
			unremove = arr[0], 
			remove = 0, 
			result = arr[0];
		for (size_t i = 1; i < arr.size(); ++i) {
			remove = fmax(unremove, remove + arr[i]);
			unremove = fmax(unremove, 0) + arr[i];
			result = fmax(result, fmax(unremove, remove));
		}
		return result;
	}
};
