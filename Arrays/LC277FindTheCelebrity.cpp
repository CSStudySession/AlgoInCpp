/* The knows API is defined for you.
      bool knows(int a, int b); */

class LC277 {
public:
    int findCelebrity(int n) {
        int ret = 0; // 假设0是celebrity
        for (int i = 1; i < n; i++) {
            if (knows(ret, i)) { // ret 如果认识i, ret一定不会是celebrity了 i可能是
                ret = i;
            }
        }

        for (int j = 0; j < n; j++) {
            // 如果ret认识另一个j 或者 j不认识ret 就一定没有celebrity了
            if (j != ret && (knows(ret, j) || !knows(j, ret))) return -1;
        }

        // 所有人都认识ret, ret不认识所有人
        return ret;
    }

    bool knows(int a, int b) {
        return true;
    }
};
