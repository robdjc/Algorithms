#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "SockMerchant\n";

    vector<int> ar{ 1, 2, 1, 2, 1, 3, 2 };

    sort(ar.begin(), ar.end());

    int pair_count = 0;

    vector<int>::iterator it;
    for (it = ar.begin(); it != ar.end(); ++it) {
        if (it != ar.end()) {
	    cout << (*it) << " " << *(it + 1) << endl;
	    if (*(it) == *(it + 1)) {
	        ++pair_count;
		++it;
	    }
	}
    }

    cout << "Pair count: " << pair_count << endl;

    return 0;
}

