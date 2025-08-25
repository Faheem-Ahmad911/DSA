#include <bits/stdc++.h>
using namespace std;


int maxProductUsingHeap(vector<int>& nums) {
    priority_queue<int> pq;
    
    for (int num : nums) {
        pq.push(num);
    }
    
    int first = pq.top(); pq.pop();
    int second = pq.top(); pq.pop();
    
    return (first - 1) * (second - 1);
}

int maxProductManual(vector<int>& nums) {
    int first = INT_MIN, second = INT_MIN;
    
    for (int num : nums) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second) {
            second = num;
        }
    }
    
    return (first - 1) * (second - 1);
}

int main() {
    vector<int> nums = {3, 4, 5, 2};

    cout << "Using Heap: " << maxProductUsingHeap(nums) << endl;
    cout << "Manual Approach: " << maxProductManual(nums) << endl;

    return 0;
}
