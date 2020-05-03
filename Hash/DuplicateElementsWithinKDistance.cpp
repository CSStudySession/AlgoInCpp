//
// link: https://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/
//

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
  1) Create an empty hashtable.
  2) Traverse all elements from left from right. Let the current element be ‘arr[i]’
     .a) If current element ‘arr[i]’ is present in hashtable, then return true.
     .b) Else add arr[i] to hash and remove arr[i-k] from hash if i is greater than or equal to k
 */
bool checkDupsWithinK(vector<int>& nums, int k) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++) {
        // If already present n hash, then we found
        // a duplicate within k distance
        if (set.find(nums[i]) != set.end())
            return true;

        // Add this item to hashset
        set.insert(nums[i]);

        // Remove the k+1 distant item
        if (i >= k) set.erase(nums[i-k]);
    }

    return false;
}

int main () {
    vector<int> nums = {10, 5, 3, 4, 3, 5, 6};
    if (checkDupsWithinK(nums, 3))
        cout << "Yes";
    else
        cout << "No";
}