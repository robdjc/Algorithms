#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(vector<int> q) {
    if (q.size() > 1)
	{
	    int bribes = 0;
		bool too_chaotic = false;
		int n = q.size();

		for(int i = 0; i < n; i++)
		{
			// check for too many bribes
			if(q[i]-(i+1) > 2)
			{               
				too_chaotic = true;
				break;     
			}

            // can skip the first non chaotic and anything in the right place
			if(i==0 || q[i]-(i+1) == 0)
			{               
				continue;     
			}

			int var = max(0, q[i]-2);
			// cout << "i=" << i << ", " << "q[i]=" << q[i] << ", " << "var=" << var << endl;

			for (int j = var; j < i; j++)
			{
				if (q[j] > q[i]) 
				{
					// cout << "  " << q[j] << " is greater than " << q[i] << endl;
					bribes++;
			    }
			}
		}

		if(too_chaotic)
			cout << "Too chaotic" << endl;
		else
			cout << bribes << endl;
		}
    else
    {
		cout << 0 << endl;
    }
}


int main()
{
    vector<int> nums;

    nums = {2, 1, 5, 3, 4};  // 3
    minimumBribes(nums);

    nums = {2, 5, 1, 3, 4};  // Too chaotic
    minimumBribes(nums);

    nums = {5, 1, 2, 3, 7, 8, 6, 4}; // Too chaotic
    minimumBribes(nums);

    nums = {1, 2, 5, 3, 7, 8, 6, 4}; // 7
    minimumBribes(nums);

	nums = {5, 1, 2, 3, 7, 8, 6, 4}; // Too chaotic
    minimumBribes(nums);

    return 0;
}
