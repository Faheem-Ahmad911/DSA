#include<iostream>
using namespace std;
int Sum_Numbers(int val) {
    if (val == 1) return 1;
    return val + Sum_Numbers(val - 1);
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = Sum_Numbers(n);
    cout << "Sum of numbers from 1 to " << n << " is: " << result << endl;
}