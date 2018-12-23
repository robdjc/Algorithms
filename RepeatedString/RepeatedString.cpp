#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Repeated String\n";

    string s = "a";
    size_t n = 1000000000000;



    size_t occurrences = 0;

    if (n > s.size())
    {
	size_t occurrences_in_one = std::count(s.begin(), s.end(), 'a');

        if (occurrences_in_one > 0)
	{
            size_t multiplier = n / s.size();
	    occurrences = occurrences_in_one * multiplier;

            size_t leftover = n - (multiplier * s.size());

            if (leftover > 0)
	    {
	        size_t count = std::count(s.begin(), s.begin() + leftover, 'a');
		occurrences += count;
	    }
	}
    }
    else
    {
	occurrences = std::count(s.begin(), s.begin() + n, 'a');
    }

    cout << "occurrences " << occurrences << endl;

    return 0;
}

