#include <bits/stdc++.h>
#define BYTE 0x7f
#define NUM 2139062143

using namespace std;

class Solution {
public:
	int minimumIncompatibility(vector<int> &nums, int k) {
		const size_t
			sub_size = 1 << nums.size(),
			group_size = nums.size() / k;
		auto sub_records = new int[sub_size];
		memset((void*) sub_records, BYTE, sizeof(sub_records[0]) * sub_size);
		sub_records[0] = 0;

		for (size_t i = 1; i < sub_size; ++i) {
			if (__builtin_popcount(i) != group_size) continue;
			unordered_set<int> state;
			int max = 0, min = nums.size();
			for (size_t j = 0; j < nums.size(); ++j) {
				if (!(i >> j & 1)) continue;
				if (state.count(nums[j])) break;
				state.insert(nums[j]);
				min = std::min(min, nums[j]);
				max = std::max(max, nums[j]);
			}
			if (state.size() == group_size) sub_records[i] = max - min;
		}

		auto records = new int[sub_size];
		memset((void*) records, BYTE, sizeof(records[0]) * sub_size);
		records[0] = 0;

		for (size_t i = 0; i < sub_size; ++i) {
			if (records[i] == NUM) continue;
			unordered_set<int> state;
			uint32_t sub_begin = 0;
			for (size_t j = 0; j < nums.size(); ++j) {
				if ((i >> j & 1) != 0 || state.count(nums[j])) continue;
				state.insert(nums[j]);
				sub_begin |= 1 << j;
			}
			if (state.size() < group_size) continue;
			for (size_t j = sub_begin; j > 0; j = (j - 1) & sub_begin) {
				if (sub_records[j] == NUM) continue;
				records[i | j] = min(records[i | j], records[i] + sub_records[j]);
			}
		}

		delete[] sub_records;
		const auto result = records[sub_size - 1] == NUM ? -1 : records[sub_size - 1];
		delete[] records;

		return result;
	}
};
