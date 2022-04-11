#include<iostream>
#include<vector>

using namespace std;

/*
���ʣ��k���ĵ��ƶ�1�������̵ĸ���
������8��������ÿ�������ƶ��������
ʣ0���ĵ㣬��������return 1������return 0
ʣ1���ĵ㣬return ��Χ8������ĵ�ĸ��ʳ���8��ĺͣ�
�Դ�����
*/

class Solution {
private:
	vector<vector<int>> dirs = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };
	int n;//����: n x n
	int step;//�ܹ��ƶ�����
	double dfs(int k, int row, int column) {
		if (inBoard(row, column)) {
			if (k != 0) {
				double prob = 0;
				for (int d = 0; d < dirs.size(); ++d) {
					//int nr = row + dirs[d][0];
					//int nc = column + dirs[d][1];
					prob += dfs(k - 1, row + dirs[d][0], column + dirs[d][1]) / dirs.size();
				}
				//printf("����%d,%d  ʣ%d��  ����%lf \n", row, column, k, prob);
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