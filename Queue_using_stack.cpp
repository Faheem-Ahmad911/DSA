#include<iostream>
using namespace std;
struct  Stack
{ public:
    int top;
    int size;
    int* arr;
    Stack(int s){
        size =s;
        arr = new int[size];
        top = -1;
    }
    bool isFull(){
        return top == size -1;
    }
    void Push_using_stack_in_Queue(){
        Stack s2;
        if(isFull()){
            cout<<"Queue is Full"<<endl;
        }

    }
};

int main()
{
      return 0;
}