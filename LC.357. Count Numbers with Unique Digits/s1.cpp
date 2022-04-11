#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<string>
#include<unordered_set>
#include<set>
#include<map>
#include<cmath>
#include<memory>

using namespace std;

class Solution {
	void getPerm(vector<vector<int>>& all_perms, vector<int>& perms, unordered_set<int>& digit, int k) {
        if (k == 0) {
            //
            for (int i : perms) {
                cout << i;
            }
			cout << endl;
            //
            all_perms.push_back(perms);
        }
        else {
            vector<int> ud;
            for (int i : digit) {
                ud.push_back(i);
            }
            for (int i : ud) {
                perms.push_back(i);
                digit.erase(i);
                getPerm(all_perms, perms, digit, k - 1);
                perms.pop_back();
                digit.insert(i);
            }
        }
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        vector<vector<int>> all_perms;
		unordered_set<int> digit{ 0,1,2,3,4,5,6,7,8,9 };
        //1~n位数
        for (int i = 1; i <= n; ++i) {
            vector<int> perms;
			for (int j = i == 1 ? 0 : 1; j <= 9; ++j) {
                perms.push_back(j);//第1位为1~9
                digit.erase(j);
				getPerm(all_perms, perms, digit, i - 1);
                perms.pop_back();
                digit.insert(j);
            }
        }

        return all_perms.size();
    }
};

int main() {
    Solution s;
	cout << endl << "count:" << s.countNumbersWithUniqueDigits(3);
}