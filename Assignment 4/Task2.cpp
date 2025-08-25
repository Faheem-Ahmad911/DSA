#include <bits/stdc++.h>
using namespace std;

int maxproduct_heap(vector<int>& nums) {
    priority_queue<int> pq(nums.begin(), nums.end());
    int first = pq.top(); pq.pop();
    int second = pq.top(); pq.pop();
    return (first - 1) * (second - 1);
}

int main() {
    vector<int> nums = {3, 4, 5, 2};
    cout << "Heap Approach: " << maxproduct_heap(nums) << endl;
    return 0;
}
