#include <iostream>
using namespace std;
const int arrsize = 20;
struct Student
{
    int rollno;
    string name;
};
struct HashTable
{
    Student table[arrsize];
    int hashfunction(int rollno)
    {
        int key = rollno % 10;
    }
public:
HashTable(){
    for (int i=0;i<arrsize;i++){
        
    }
}
};

int main()
{
    return 0;
}