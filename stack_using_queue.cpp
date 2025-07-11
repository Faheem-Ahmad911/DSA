#include<iostream>
#include<queue>
using namespace std;
queue<int> q1;
void push(int val){
    q1.push(val);
    int n = q1.size();
    for (int i = 0; i < n - 1; i++) {
        q1.push(q1.front());
        q1.pop();
    }
}
void remove(){
    int val =q1.front();
    cout<<val<< " is popped"<<endl;
    q1.pop();
}
int main()
{   push(1);
    push(2);
    push(3);
    remove();

      return 0;
}