#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Counting Valleys\n";

    string hike_input = "UDDDUDUU";

    int valley_count = 0;
    int sea_level = 0;
    int current_level = sea_level;
    bool in_valley = false;

    for(char& c : hike_input) {
        if (c == 'U') {
            ++current_level;
	}
	else if (c == 'D') {
            --current_level;
	}

	if (current_level < sea_level && !in_valley) {
            in_valley = true;
	    ++valley_count;
	}

	if (current_level == sea_level) {
            in_valley = false;
        }
    }

    cout << "Valley count: " << valley_count << endl;

    return 0;
}

