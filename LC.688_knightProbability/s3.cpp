#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
��̬�滮����Ȼ��֪���滮�˸�ɶ��
���Ǹ�����ͣ����������ÿһ��ʱ����λ������һ�����������ϵĸ��ʱ���ʼΪ��0�������������ϣ���ȫ��1��
ʱ�� k*n^2
�ռ� n^2
*/

class Solution {
private:
	vector<vector<int>> dirs = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };

public:
	double knightProbability(int n, int k, int row, int column) {
		if (row >= 0 && row < n && column >= 0 && column < n) {
			vector<vector<double>>* pre_tab = new vector<vector<double>>(n, vector<double>(n, 1.0));//���ʱ�
			vector<vector<double>>* ntab, * tmp;
			int cntdirs = dirs.size();
			for (int step = 1; step <= k; ++step) {
				ntab = new vector<vector<double>>(n, vector<double>(n, 0));
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						for (auto& d : dirs) {
							int ni = i + d[0];
							int nj = j + d[1];
							if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
								(*ntab)[i][j] += (*pre_tab)[ni][nj] / cntdirs;
							}
						}
					}
				}
				tmp = pre_tab;
				pre_tab = ntab;
				delete tmp;
			}
			return (*pre_tab)[row][column];
		}
		else {
			return 0;
		}
	}
};

int main() {

	Solution s;
	cout << s.knightProbability(8, 30, 6, 4);



}