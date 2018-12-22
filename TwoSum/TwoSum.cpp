#include <iostream>
#include <vector>
#include <algorithm>

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


vector<int> check_for_target2(vector<int> &nums, const int target)
{
    vector<int> return_val;

    std::sort(nums.begin(), nums.end());

    std::size_t i = 0;
    auto j = nums.size() -1;

    while (i<j) {
        if (nums[i] + nums[j] == target) {
            return_val.push_back(nums[i]);
            return_val.push_back(nums[j]);
	    return return_val;
	}
	else if (nums[i] + nums[j] > target) {
            --j;
	}
	else {
            ++i;
	}
    }

    return return_val;
}


void print_answer(const vector<int>& answer, const int target)
{
    if(!answer.empty()) {
        cout << "Target found: " << answer[0] << " and " << answer[1] << " equal " << target << "\n";
    }
    else {
        cout << "Target not found\n";
    }
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

    vector<int> answer = check_for_target2(nums, target);
    print_answer(answer, target);

    return 0;
}

