#include <vector>

using namespace std;

class LC119 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret; // 不需要初始化长度 每次在循环中增加长度即可
        for (int i = 0; i <= rowIndex; i++) {
            ret.emplace_back(1); // 最后一个数肯定是1 每次先把最后一个1加进去
            for (int j = i - 1; j >= 1; j--) {
                // 第一个数和最后一个数肯定都是1 所以从倒数第二个开始算 一直算到第二个数(下标为1)
                ret[j] += ret[j - 1];
            }
        }
        return ret;
    }
};

/*
 *  1
 *  1 1
 *  1 2 1
 *  1 3 3 1
 */