#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<bool>>& board, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << (board[i][j] ? "Q " : "X ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<bool>>& board, int row, int col) {
    for (int i = 0; i < board.size(); ++i) {
        if (board[i][col]) {
            return false;
        }
    }

    int i, j;

    // Check backward slash (\) diagonal only in above direction
    for (i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check backward slash (\) diagonal only in below direction
    for (i = row, j = col; i < board.size() && j < board.size(); ++i, ++j) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check forward slash (/) diagonal only in above direction
    for (i = row, j = col; i >= 0 && j < board.size(); --i, ++j) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check forward slash (/) diagonal only in below direction
    for (i = row, j = col; i < board.size() && j >= 0; ++i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void solveNQueens(vector<vector<bool>>& board, int row, int size, int& count) {
    if (row == size) {
        count++;
        printBoard(board, size);
        return;
    }

    bool hasQueen = false;
    for (int col = 0; col < size; ++col) {
        if (board[row][col]) {
            hasQueen = true;
            break;
        }
    }

    if (hasQueen) {
        solveNQueens(board, row + 1, size, count);
        return;
    }

    for (int col = 0; col < size; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = true;
            solveNQueens(board, row + 1, size, count);
            board[row][col] = false;
        }
    }
}

int main() {
    int size;
    cout << "Enter size of chessboard: ";
    cin >> size;

    vector<vector<bool>> board(size, vector<bool>(size, false));
    int count = 0;

    cout << "Enter coordinates of the first queen: " << endl;
    int row, col;
    cout << "Enter row (1-" << size << "): ";
    cin >> row;
    cout << "Enter column (1-" << size << "): ";
    cin >> col;
    board[row - 1][col - 1] = true;

    solveNQueens(board, 0, size, count);

    if (count > 0) {
        cout << "Solution exists for the given position of the queen." << endl;
    } else {
        cout << "Solution doesn't exist for the given position of the queen." << endl;
    }

    return 0;
}