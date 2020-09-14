//
// Created by Aaron Liu on 9/12/20.
//

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class LC751 {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> ret;
        long ipNum = 0;
        string buffer;
        // convert ip from string to long type
        for (int i = 0 ; i <= ip.size(); i++) {
            if (i == ip.size() || ip[i] == '.') {
                cout << "buffer: " << buffer << " ";
                ipNum |= stoi(buffer);
                cout << "ipNum :" << ipNum << endl;
                if (i != ip.size()) ipNum <<= 8;
                buffer.clear();
            } else {
                buffer.append(1, ip[i]);
            }
        }

        // edage cases: ip: "0.0.0.0"
        if (ipNum == 0) {
            for (int i = 0; i < n; i++) {
                string tmp = "0.0.0.";
                tmp += to_string(i);
                tmp += "/32";
                ret.push_back(tmp);
            }
            return ret;
        }

        while (n > 0) {
            long delta = ipNum & -ipNum;
            cout << "delta: " << delta << " ";
            while (delta > n) delta /= 2;
            string tmp = convert(ipNum, delta);
            ret.push_back(tmp);
            ipNum += delta;
            n -= delta;
        }
        return ret;
    }

    string convert(long ipNum, int delta) {
        return to_string((ipNum >> 24) & 255) + "." +
                to_string((ipNum >> 16) & 255) + "." +
                to_string((ipNum >> 8) & 255) + "." +
                to_string(ipNum & 255) + "/" +
                to_string(32 - (int)log2(delta));
    }

};

/*
int main() {
    LC751 inst;
    string myip = "0.0.0.0";
    int n = 2;
    vector<string> ret = inst.ipToCIDR(myip, n);
    for (auto &item : ret) {
        cout << item << endl;
    }
    return 0;

}
*/
