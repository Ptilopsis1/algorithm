#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<map>
#include<queue>


using namespace std;

class Solution {
	vector<vector<int>> dirs = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };
	typedef vector<pair<int, int>> path_type;
public:
	void dfs(int n, int k, int row, int column,path_type& tmpath, vector<path_type>& paths) {
		if (inBoard(n,row,column)) {
			tmpath.emplace_back(pair<int, int>(row, column));
			if (k == 0) {
				paths.emplace_back(tmpath);
				cout << "path"<<paths.size()<<":\t";
				for (auto i : tmpath) {
					cout << "(" << i.first << ", " << i.second << ") ";
				}
				cout << endl;
			}
			else {
				for (int d = 0; d < dirs.size(); ++d) {
					int nr = row + dirs[d][0];
					int nc = column + dirs[d][1];
					if (inBoard(n, nr, nc)) {
						dfs(n, k - 1, nr, nc, tmpath, paths);
						tmpath.pop_back();
					}
				}
			}
		}
	}

	bool inBoard(int n, int r, int c) {
		return r >= 0 && r < n && c >= 0 && c < n;
	}

	double knightProbability(int n, int k, int row, int column) {
		vector<path_type> paths;
		path_type tmpath;
		dfs(n, k, row, column,tmpath , paths);

		return paths.size() / pow(8, k);
	}
};


int main() {

	Solution s2;
	cout << s2.knightProbability(8, 5, 6, 4);

}