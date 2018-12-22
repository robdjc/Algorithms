#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Jumping Clouds\n";

    // 0, 1, 0, 0, 0, 1, 0 = 3
    // 0, 0, 1, 0, 0, 1, 0 = 4
    // 0, 0, 0, 1, 0, 0    = 3
    // 0, 0, 0, 0, 1, 0    = 3
    // 0, 0, 1, 0, 0, 1, 0 = 4

    vector<int> c{ 0, 0, 1, 0, 0, 1, 0 };


    int jump_count = 0;

    vector<int>::iterator it = c.begin();

    while (it != c.end()) {
	if ( (it + 1) != c.end() && (it + 2) != c.end() && *(it + 2) == 0) {
            it += 2;
            ++jump_count;
	}
	else if ( (it + 1) != c.end() && *(it + 1) == 0) {
            ++it;
            ++jump_count;
        }
	else {
            ++it;
	}
    }

    cout << "Jump count: " << jump_count << endl;

    return 0;
}

