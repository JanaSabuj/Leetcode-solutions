class Solution {
	// vector<vector<string>> ways;
	int cnt;
public:
	bool isValid(vector<string>& board, int n, int row, int col) {
		//Col up
		for (int i = row - 1; i >= 0; i--) {
			if (board[i][col] == 'Q')
				return false;
		}

		// Left up diagonal
		for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--) {
			if (board[i][j] == 'Q')
				return false;
		}

		// Right up diagonal
		for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++) {
			if (board[i][j] == 'Q')
				return false;
		}

		return true;
	}

	void nQueenHelper(vector<string>& board, int n, int row) {
		if (row == n) {
			// ways.push_back(board);
			cnt++;
			return;
		}
		for (int j = 0; j < n; j++) {
			if (isValid(board, n, row, j)) {
				board[row][j] = 'Q';
				nQueenHelper(board, n, row + 1);
				board[row][j] = '.';
			}
		}
		return;
	}

	void nQueen(int n, vector<string>& board) {
		nQueenHelper(board, n, 0);// start with row 0
		return;
	}
	int totalNQueens(int n) {
		cnt = 0;
		string ini = "";
		for (int i = 0; i < n; ++i) {
			ini += '.';
		}

		vector<string> board(n, ini);
		nQueen(n, board);
		return cnt;
	}
};
