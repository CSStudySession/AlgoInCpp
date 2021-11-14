#include <vector>

using namespace std;

class LC118 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows); // creates numRows*numRows 2-d vector
        if (numRows == 0) return ret;

        for (int i = 0; i < numRows; i++) {
            ret[i].resize(i + 1); // 每行有i+1个数 -> i+1列
            ret[i][0] = ret[i][i] = 1; // 每行收尾都是1

            for (int j = 1; j < i; j++) {
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
        return ret;
    }
};