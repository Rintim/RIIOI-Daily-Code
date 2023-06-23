namespace DailyCode;

public class Solution {
	private static int Parse(string str) {
		var size = str.Length;
		var result = 0;
		for (int i = size - 1, j = 1; i >= 0; --i, j *= 10) {
			var now = str[i];
			if (now is < '0' or > '9') return size;
			result += (now - '0') * j;
		}

		return result;
	}

	public int MaximumValue(string[] strs) {
		return strs.Select(Parse).Aggregate(0, (current, size) => (size > current) ? size : current);
	}
}

