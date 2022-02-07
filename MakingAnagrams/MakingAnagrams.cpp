#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int makeAnagram(string a, string b) {
    int delete_count = 0;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    string::iterator s1_it = a.begin();
    string::iterator s2_it = b.begin();

    while(s1_it != a.end() || s2_it != b.end())
    {
        if(s1_it == a.end()) {
            delete_count++;
            s2_it++;
            continue;
        }
        else if(s2_it == b.end()) {
            delete_count++;
            s1_it++;
            continue;
        }

        if(*s1_it == *s2_it) {
            s1_it++;
            s2_it++;
        }
        else if (int(*s1_it) > int(*s2_it)) {
            delete_count++;
            s2_it++;
        }
        else {
            delete_count++;
            s1_it++;
        }
    }
    
    return delete_count;
}


int main()
{

    // 4
    string a = "abc";
    string b = "cde";
    int res = makeAnagram(a, b);
    std::cout << res << "\n";

    // 30
    a = "fcrxzwscanmligyxyvym";
    b = "jxwtrhvujlmrpdoqbisbwhmgpmeoke";
    res = makeAnagram(a, b);
    std::cout << res << "\n";

    // 2
    a = "showman";
    b = "woman";
    res = makeAnagram(a, b);
    std::cout << res << "\n";

    return 0;
}

