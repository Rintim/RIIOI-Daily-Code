#include <bits/stdc++.h>

#define MAX(a, b) max(a, b)
#define MIN(a, b) min(a, b)

using namespace std;

constexpr int influence[3][3] = {
	{ 0, 0, 0 },
	{ 0, -60, -10 },
	{ 0, -10, 40 }
};

constexpr int
	maxArea = 25,
	maxPeopleCount = 6,
	maxState = 729,
	initNum = -2147483648;

class recorder {
	int state[maxArea + 1][maxPeopleCount + 1][maxPeopleCount + 1][maxState] {};

	size_t
		maxSize,
		width,
		highRate,
		stateCount,
		negSize,
		positSize;

public:
	recorder(const int size, const int negCount, const int positCount, const int width) {
		maxSize = size;
		this->width = width;
		highRate = (int) pow(3, width - 1);
		stateCount = (int) pow(3, width);
		negSize = negCount;
		positSize = positCount;
		for (size_t pos = 0; pos < size; ++pos) {
			for (size_t negUsed = 0; negUsed <= negCount; ++negUsed) {
				for (size_t positUsed = 0; positUsed <= positCount; ++positUsed) {
					for (size_t statePos = 0; statePos <= stateCount; ++statePos) {
						state[pos][negUsed][positUsed][statePos] = initNum;
					}
				}
			}
		}
		state[0][0][0][0] = 0;
	}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

	int search() {
		return search(0, negSize, positSize, 0);
	}

	int search(size_t pos, size_t negLeft, size_t positLeft, size_t statePos) {
		if (pos == maxSize) return 0;
		if (state[pos][negLeft][positLeft][statePos] != initNum) return state[pos][negLeft][positLeft][statePos];
		const size_t
			x = pos % width,
			up = statePos / highRate,
			left = (x == 0) ? 0 : statePos % 3,
			next = statePos * 3 % stateCount;
		int result = search(pos + 1, negLeft, positLeft, next), ans;

		if (negLeft > 0) {
			ans = search(pos + 1, negLeft - 1, positLeft, next + 1) + 120 + influence[1][up] + influence[1][left];
			result = MAX(ans, result);
		}

		if (positLeft > 0) {
			ans = search(pos + 1, negLeft, positLeft - 1, next + 2) + 40 + influence[2][up] + influence[2][left];
			result = MAX(ans, result);
		}

		state[pos][negLeft][positLeft][statePos] = result;
		return result;
	}

#pragma clang diagnostic pop

	int searchV2() {
		int *ans;
		for (size_t pos = 0; pos < maxSize; ++pos) {
			for (size_t statePos = 0; statePos < stateCount; ++statePos) {
				const size_t
					x = pos % width,
					up = statePos / highRate,
					left = (x == 0) ? 0 : statePos % 3,
					next = statePos * 3 % stateCount;

				for (size_t negUsed = 0; negUsed <= negSize; ++negUsed) {
					for (size_t positUsed = 0; positUsed <= positSize; ++positUsed) {
						ans = &state[pos + 1][negUsed][positUsed][next];
						*ans = MAX(*ans, state[pos][negUsed][positUsed][statePos]);

						if (negUsed < negSize) {
							ans = &state[pos + 1][negUsed + 1][positUsed][next + 1];
							*ans = MAX(*ans, state[pos][negUsed][positUsed][statePos] + 120 + influence[1][up] +
							                 influence[1][left]);
						}

						if (positUsed < positSize) {
							ans = &state[pos + 1][negUsed][positUsed + 1][next + 2];
							*ans = MAX(*ans, state[pos][negUsed][positUsed][statePos] + 40 + influence[2][up] +
							                 influence[2][left]);
						}
					}
				}
			}
		}

		int result = 0;

		for (size_t negUsed = 0; negUsed <= negSize; ++negUsed) {
			for (size_t positUsed = 0; positUsed <= positSize; ++positUsed) {
				for (size_t statePos = 0; statePos < stateCount; ++statePos) {
					result = MAX(result, state[maxSize][negUsed][positUsed][statePos]);
				}
			}
		}

		return result;
	}
};

class Solution {
public:
#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

	int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
		recorder record(m * n, introvertsCount, extrovertsCount, MIN(m, n));

		return record.search();
	}

#pragma clang diagnostic pop
};
