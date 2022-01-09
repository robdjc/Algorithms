#include <iostream>
#include <string>
#include <stack>

using namespace std;


/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {

    stack<char> left_side;

    for(char& c : s) {
        if (c == '{' || c == '[' || c == '(') {
            // cout << "Left" << endl;
            left_side.push(c);
            // cout << "Stack size: " << left_side.size() << endl;
        }
        else if (c == '}' || c == ']' || c == ')') {

            if (left_side.empty()) {
                return "NO";
            }
            else {
                char lc = left_side.top();
                left_side.pop();

                if ((lc == '{' && c == '}') || 
                    (lc == '[' && c == ']') || 
                    (lc == '(' && c == ')')) {
                    // cout << "good, lc=" << lc << ", c=" << c << endl;
                }
                else {
                    return "NO";
                }
            }
        }
    }

    if(!left_side.empty()) {
        return "NO";
    }

    return "YES";
}

int main()
{
    string s = "}";
    cout << isBalanced(s) << endl;

    s = "asdf [[asdf[((({{{aaa}}})ghgh))]]]  1 asdf";
    cout << isBalanced(s) << endl;
    return 0;
}
