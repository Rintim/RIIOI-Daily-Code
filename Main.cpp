#include <bits/stdc++.h>

using namespace std;

int parse(const string &str) {
	const int size = (int) str.size();
	int result = 0;
	for (size_t i = size - 1, j = 1; i <= size - 1; --i, j *= 10) {
		const char now = str[i];
		if (now < '0' || now > '9') return size;
		result += (int) ((now - '0') * j);
	}
	return result;
}

class Solution {
public:
#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

	int maximumValue(vector<string> &strs) {
		int result = 0;
		for (const auto &str: strs) {
			int size = parse(str);
			result = (size > result) ? size : result;
		}
		return result;
	}

#pragma clang diagnostic pop
};

