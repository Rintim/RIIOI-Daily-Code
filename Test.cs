namespace DailyCode;

internal static class Test {
	private static readonly string[][] Strs = {
		new[] { "alic3", "bob", "3", "4", "00000" },
		new[] { "1", "01", "001", "0001" },
		new[] { "alic35", "bob4", "3", "4", "200000" }
	};

	private static readonly int[] Answers = {
		5,
		1,
		200000
	};

	private static bool Judge(int result, int ans) {
		return result == ans;
	}

	internal static int Main() {
		var solve = new Solution();
		var size = Math.Min(Strs.Length, Answers.Length);
		for (var i = 0; i < size; ++i) {
			var result = solve.MaximumValue(Strs[i]);
			if (!Judge(result, Answers[i])) return 1;
		}

		return 0;
	}
}

