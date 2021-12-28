#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

string twoStrings(string s1, string s2) {

    int s1_len = s1.length();
	int s2_len = s2.length();

    if (s1_len > 0 && s2_len > 0)
	{
		std::sort(s1.begin(), s1.end());
		std::sort(s2.begin(), s2.end());

		int i = 0;
		int j = 0;

		string::iterator s1_it = s1.begin();
		string::iterator s2_it = s2.begin();

		while(s1_it != s1.end() && s2_it != s2.end())
		{
			if(*s1_it == *s2_it)
			{
				return "YES";
			}
			else if(int(*s1_it) > int(*s2_it))
			{
				s2_it++;
			}
			else
			{
				s1_it++;
			}
		}
	}
	return "NO";
}

string twoStrings_using_sets(string s1, string s2) {

	set<char> set1(s1.begin(), s1.end());
	set<char> set2(s2.begin(), s2.end());

	set<char> set_intersection;
    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          inserter(set_intersection, set_intersection.begin()));
 
    // for(char c : set_intersection)
    //     cout << c << endl;

	if(set_intersection.size() > 0) {
		return "YES";
	}

    return "NO";
}

int main()
{
    // cout << twoStrings("and", "art") << endl; // YES
    // cout << twoStrings("be", "cat") << endl; // NO
    // cout << twoStrings("hello", "world") << endl; // YES
    // cout << twoStrings("hi", "world") << endl; // NO
    // cout << twoStrings("writetoyourparents", "fghmqzldbc") << endl; // NO

    cout << twoStrings_using_sets("and", "art") << endl; // YES
    cout << twoStrings_using_sets("be", "cat") << endl; // NO
    cout << twoStrings_using_sets("hello", "world") << endl; // YES
    cout << twoStrings_using_sets("hi", "world") << endl; // NO
    cout << twoStrings_using_sets("writetoyourparents", "fghmqzldbc") << endl; // NO

    return 0;
}
