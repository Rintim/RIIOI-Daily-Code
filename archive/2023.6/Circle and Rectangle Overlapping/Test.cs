namespace DailyCode;

internal static class Test {
	private static readonly int[] Radii = {
		1,
		1,
		1
	};

	private static readonly int[] XCenters = {
		0,
		1,
		0
	};

	private static readonly int[] YCenters = {
		0,
		1,
		0
	};

	private static readonly int[] X1S = {
		1,
		1,
		-1
	};

	private static readonly int[] Y1S = {
		-1,
		-3,
		0
	};

	private static readonly int[] X2S = {
		3,
		2,
		0
	};

	private static readonly int[] Y2S = {
		1,
		-1,
		1
	};

	private static readonly bool[] Answers = {
		true,
		false,
		true
	};

	private static bool Judge(bool result, bool ans) {
		return result == ans;
	}


	internal static int Main() {
		var solve = new Solution();
		var size =
			new[] { Radii.Length, XCenters.Length, YCenters.Length, X1S.Length, X2S.Length, Y1S.Length, Y2S.Length, Answers.Length }
				.Min();
		for (var i = 0; i < size; ++i) {
			var result = solve.CheckOverlap(Radii[i], XCenters[i], YCenters[i], X1S[i], Y1S[i], X2S[i], Y2S[i]);
			if (!Judge(result, Answers[i])) return 1;
		}

		return 0;
	}
}
