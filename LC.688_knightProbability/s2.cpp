#include<iostream>
#include<vector>

using namespace std;

/*
算出剩余k步的点移动1步在棋盘的概率
（例：8个方向，向每个方向移动概率相等
剩0步的点，在棋盘上return 1，不在return 0
剩1步的点，return 周围8个方向的点的概率除以8后的和）
以此类推
*/

class Solution {
private:
	vector<vector<int>> dirs = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };
	int n;//棋盘: n x n
	int step;//总共移动次数
	double dfs(int k, int row, int column) {
		if (inBoard(row, column)) {
			if (k != 0) {
				double prob = 0;
				for (int d = 0; d < dirs.size(); ++d) {
					//int nr = row + dirs[d][0];
					//int nc = column + dirs[d][1];
					prob += dfs(k - 1, row + dirs[d][0], column + dirs[d][1]) / dirs.size();
				}
				//printf("坐标%d,%d  剩%d步  概率%lf \n", row, column, k, prob);
				return prob;
			}else {
				return 1;
			}
		}
		else return 0;
	}

	bool inBoard(int r, int c) {
		return r >= 0 && r < n&& c >= 0 && c < n;
	}

public:
	double knightProbability(int n, int k, int row, int column) {
		this->n = n;
		this->step = k;
		return dfs(k, row, column);
	}
};

int main() {

	Solution s;
	cout << s.knightProbability(3,2,0,0);



}