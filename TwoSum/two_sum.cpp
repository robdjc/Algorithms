#include <iostream>
#include <vector>

using namespace std;

vector<int> check_for_target(const vector<int> &nums, const int target)
{
    vector<int> return_val;

    // brute force method, O(n^2)
    for (auto i : nums) {
        for (auto j : nums) {
            if (i != j) {
                if (i + j == target) {
		    return_val.push_back(i);
		    return_val.push_back(j);
                    return return_val;
                }
            }
        }
    }

    return return_val;
}

int main()
{
    cout << "TwoSum test\n\n";

    vector<int> nums = {2, 7, 11, 15};

    cout << "Input: ";
    for (auto x : nums) {
        cout << x << " ";
    }
    std::cout << "\n";

    int target = 9;

    cout << "Target: " << target << "\n";

    vector<int> answer = check_for_target(nums, target);

    if(!answer.empty()) {
        cout << "Target found: " << answer[0] << " and " << answer[1] << " equal " << target << "\n";
    }
    else {
        cout << "Target not found\n";
    }

    return 0;
}

