using System.Runtime.InteropServices;

namespace DailyCode;

public class Solution {
	// ReSharper disable once MemberCanBeMadeStatic.Global
#pragma warning disable CA1822
	public bool CheckOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
#pragma warning restore CA1822
		var xNearest = ((xCenter < x1) ? x1 : ((xCenter <= x2) ? xCenter : x2));
		var yNearest = ((yCenter < y1) ? y1 : ((yCenter <= y2) ? yCenter : y2));
		var distance = Math.Pow(xNearest - xCenter, 2) + Math.Pow(yNearest - yCenter, 2);
		return distance <= Math.Pow(radius, 2);
	}
}
