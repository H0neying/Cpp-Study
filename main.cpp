#include <iostream>
using namespace std;

int num[10][10];
bool check_row[10][10];
bool check_col[10][10];
bool check_sq[10][10];

int n = 9;

int square(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

bool fill_board(int z) {
	if (z == 81) {
		cout << endl << "-----------------" << endl << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << num[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	int x = z / n;
	int y = z % n;
	int sq = square(x, y);
	if (num[x][y] != 0) {
		return fill_board(z + 1);
	}
	else {
		num[x][y]++;
		if (check_row[x][num[x][y]] || check_col[y][num[x][y]] || check_sq[sq][num[x][y]])
			return fill_board(0);
		else 
			return fill_board(z + 1);
	}
	return false;
}

int main(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num[i][j];
			if (num[i][j] != 0) {
				check_row[i][num[i][j]] = true;
				check_col[j][num[i][j]] = true;
				check_sq[square(i, j)][num[i][j]] = true;
			}
		}
	}
	fill_board(0);
	return 0;
}