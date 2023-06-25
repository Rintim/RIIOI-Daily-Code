namespace DailyCode;

internal static class Test {
	private static readonly int[] Ms = {
		2,
		3,
		2
	};
	
	private static readonly int[] Ns = {
		3,
		1,
		2
	};
	
	private static readonly int[] IntrovertsCounts = {
		1,
		2,
		4
	};
	
	private static readonly int[] ExtrovertsCounts = {
		2,
		1,
		0
	};

	private static readonly int[] Answers = {
		240,
		260,
		240
	};

	private static bool Judge(int result, int ans) {
		return result == ans;
	}

	internal static int Main() {
		var solve = new Solution();
		var size =
			(new int[] { Ms.Length, Ns.Length, IntrovertsCounts.Length, ExtrovertsCounts.Length, Answers.Length })
			.Min();
		for (var i = 0; i < size; ++i) {
			var result = solve.GetMaxGridHappiness(Ms[i], Ns[i], IntrovertsCounts[i], ExtrovertsCounts[i]);
			if (!Judge(result, Answers[i])) return 1;
		}

		return 0;
	}
}
