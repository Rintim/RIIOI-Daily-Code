#include "Main.cpp"
#define LENGTH(ary) (sizeof(ary) / sizeof(*ary))

constexpr int radii[] = {
	1,
	1,
	1
};

constexpr int xCenters[] = {
	0,
	1,
	0
};

constexpr int yCenters[] = {
	0,
	1,
	0
};

constexpr int x1s[] = {
	1,
	1,
	-1
};

constexpr int y1s[] = {
	-1,
	-3,
	0
};

constexpr int x2s[] = {
	3,
	2,
	0
};

constexpr int y2s[] = {
	1,
	-1,
	1
};

constexpr bool answers[] = {
	true,
	false,
	true
};

bool judge(bool result, bool ans) {
	return result == ans;
}


int main() {
	size_t size = min({LENGTH(radii), LENGTH(xCenters), LENGTH(yCenters), LENGTH(x1s), LENGTH(x2s), LENGTH(y1s), LENGTH(y2s), LENGTH(answers)});
	Solution solve;
	for (size_t i = 0; i < size; ++i) {
		const auto result = solve.checkOverlap(radii[i], xCenters[i], yCenters[i], x1s[i], y1s[i], x2s[i], y2s[i]);
		if (!judge(result, answers[i])) return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
