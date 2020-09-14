//
// solution idea: https://www.acwing.com/solution/content/101/
//

#include <vector>
#include <string>
using namespace std;

class IntegerToRoman {
public:
    string intToRoman(int num) {
        // create value - chars mapping
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> sms = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string ret;
        for (int i = 0; i < values.size(); i++) {
            while (num > values[i]) {
                num -= values[i];
                ret += sms[i];
            }
        }
        return ret;
    }
};
