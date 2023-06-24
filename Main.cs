using System.Runtime.InteropServices;

namespace DailyCode;

public class Solution {
	private readonly int[,] _influence;
	private readonly int[,,,] _state;

	private const int
		MaxArea = 25,
		MaxPeopleCount = 6,
		MaxState = 729,
		InitNum = int.MinValue;

	private int
		_size,
		_negSize,
		_positSize,
		_width,
		_stateSize,
		_highRate;
	
	public Solution() {
		_influence = new[,] {
			{ 0, 0, 0 },
			{ 0, -60, -10 },
			{ 0, -10, 40 }
		};
		_state = new int[MaxArea, MaxPeopleCount + 1, MaxPeopleCount + 1, MaxState];
	}

	private void Init(int size, int negSize, int positSize, int width) {
		_size = size;
		_negSize = negSize;
		_positSize = positSize;
		_width = width;
		_stateSize = (int) Math.Pow(3, _width);
		_highRate = (int) Math.Pow(3, _width - 1);
		for (var pos = 0; pos < size; ++pos)
			for (var negUsed = 0; negUsed <= negSize; ++negUsed)
				for (var positUsed = 0; positUsed <= positSize; ++positUsed)
					for (var statePos = 0; statePos < _stateSize; ++statePos)
						_state[pos, negUsed, positUsed, statePos] = InitNum;
	}

	private int Search() => Search(0, _negSize, _positSize, 0);
	private int Search(int pos, int negLeft, int positLeft, int statePos) {
		if (pos == _size) return 0;
		if (_state[pos, negLeft, positLeft, statePos] != InitNum) return _state[pos, negLeft, positLeft, statePos];
		
		int
			x = pos % _width,
			up = statePos / _highRate,
			left = (x == 0) ? 0 : statePos % 3,
			next = statePos * 3 % _stateSize;

		int ans, result = Search(pos + 1, negLeft, positLeft, next);
		
		if (negLeft > 0) {
			ans = Search(pos + 1, negLeft - 1, positLeft, next + 1) + 120 + _influence[1, up] + _influence[1, left];
			result = Math.Max(ans, result);
		}

		if (positLeft > 0) {
			ans = Search(pos + 1, negLeft, positLeft - 1, next + 2) + 40 + _influence[2, up] + _influence[2, left];
			result = Math.Max(ans, result);
		}

		_state[pos, negLeft, positLeft, statePos] = result;
		return result;
	}
	
	public int GetMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
		Init(m * n, introvertsCount, extrovertsCount, Math.Min(m, n));

		return Search();
	}
}
