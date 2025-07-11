#include<iostream>
#include<stack>
using namespace std;
void isPalindrome(string s){
    stack<char> s1;
    for (char c : s){
        s1.push(c);
    }
    bool isPalin = true;
    for (char c : s){
        if (s1.top() == c){
            s1.pop();
            continue;
        }
        else{
            cout << "Not Palindrome" << endl;
            isPalin = false;
            break;
        }
    }
    if (isPalin) {
        cout << "Palindrome" << endl;
    }
}
int main()
{   isPalindrome("LeveL");
      return 0;
}