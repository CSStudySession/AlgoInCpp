//
// Created by Aaron Liu on 9/12/20.
//

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    unordered_map<string, Node*> children;
    int val;
};

class FileSystem {
private:
    Node* root;

public:
    FileSystem() {
        root = new Node();
    }

    bool createPath(string path, int value) {
        Node* cur = root;
        vector<string> parts = split(path, '/');
        for (int i = 0; i < parts.size(); i++) {
            if (i == parts.size() - 1 && cur->children.count(parts[i]) != 0) return false;
            if (i != parts.size() - 1 && cur->children.count(parts[i]) == 0) return false;

            if (cur->children.count(parts[i]) != 0) cur = cur->children[parts[i]];
            else {
                cur->children[parts[i]] = new Node();
                cur->children[parts[i]]->val = value;
            }
        }
        return true;
    }

    int get(string path) {
        Node* cur = root;
        vector<string> parts = split(path, '/');
        for (int i = 0; i < parts.size(); i++) {
            if (cur->children.count(parts[i]) == 0) return -1;
            cur = cur->children[parts[i]];
        }
        return cur->val;
    }

    vector<string> split(const string& str, char dlm) {
        vector<string> parts;
        string tmp;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] != dlm) {
                tmp.append(1, str[i]);
            } else {
                parts.push_back(tmp);
                tmp.clear();
            }
        }
        if (!tmp.empty()) parts.push_back(tmp);
        return parts;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */