#include "Main.cpp"

const vector<vector<string>> strs = {
	{"alic3", "bob", "3", "4", "00000"},
	{"1", "01", "001", "0001"},
	{"alic35", "bob4", "3", "4", "200000"}
};

const vector<int> answers = {
	5,
	1,
	200000
};

bool judge(int result, int ans) {
	return result == ans;
}

int main() {
	size_t len = min(strs.size(), answers.size());
	Solution solve;
	for (size_t i = 0; i < len; ++i) {
		int result = solve.maximumValue(const_cast<vector<std::string> &>(strs[i]));
		if (!judge(result, answers[i])) return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

