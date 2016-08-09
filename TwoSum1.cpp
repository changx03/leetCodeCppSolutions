#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> indices;
    for(int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        if(m.find(target - x) != m.end()){
            indices.push_back(i);
            indices.push_back(m[target - x]);
            return indices;
        }
        m[x] = i;
    }
    return indices;
}

int main(int argc, char *argv[]) {
    int t[] = {1, 2, 3, 4, 9};
    vector<int> nums(t, t+5);
    int target = 6;
    vector<int> indices = twoSum(nums, target);
    cout << indices[0] << ", " << indices[1] << endl;
    return 0;
}
