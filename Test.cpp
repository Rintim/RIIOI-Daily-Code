#include "Main.cpp"

const vector<int> Ms = {
	2,
	3,
	2
};

const vector<int> Ns = {
	3,
	1,
	2
};

const vector<int> introvertsCounts = {
	1,
	2,
	4
};

const vector<int> extrovertsCounts = {
	2,
	1,
	0
};

const vector<int> answers = {
	240,
	260,
	240
};

bool judge(int result, int ans) {
	return result == ans;
}


int main() {
	size_t len = min({ Ms.size(), Ns.size(), introvertsCounts.size(), extrovertsCounts.size(), answers.size() });
	Solution solve;
	for (size_t i = 0; i < len; ++i) {
		int result = solve.getMaxGridHappiness(Ms[i], Ns[i], introvertsCounts[i], extrovertsCounts[i]);
		if (!judge(result, answers[i])) return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
