#include <bits/stdc++.h>
#define VALUE_BETWEEN_RANGE(value, min, max, beforeMin, betweenValue, afterMax) ((value < min) ? beforeMin : ((value <= max) ? betweenValue : afterMax))
#define POW_DOUBLE(num) ((num) * (num))

using namespace std;

class Solution {
public:
	bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
		const int xNearest = VALUE_BETWEEN_RANGE(xCenter, x1, x2, x1, xCenter, x2);
		const int yNearest = VALUE_BETWEEN_RANGE(yCenter, y1, y2, y1, yCenter, y2);
		const int distance = POW_DOUBLE(xNearest - xCenter) + POW_DOUBLE(yNearest - yCenter);
		return distance <= POW_DOUBLE(radius);
	}
};
