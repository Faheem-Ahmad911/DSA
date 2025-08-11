#include <iostream>
#include <vector>
using namespace std;
const int arrsize = 20;
struct Student
{
    int rollno;
    string name;
};
struct HashTable
{
public:
    vector<Student> table[arrsize];
    int collisionCount = 0;
    int hashfunction(int rollno)
    {
        int key = rollno % 10;
        return key;
    }

    void insert(int rno, string sname)
    {
        int index = hashfunction(rno);
        if (!table[index].empty())
        {
            collisionCount++;
        }
        table[index].push_back({rno, sname});
    }
    void search(int rno)
    {
        int index = hashfunction(rno);
        for (auto &student : table[index])
        {
            if (student.rollno == rno)
            {
                cout << "Found: Roll No " << student.rollno
                     << " -> " << student.name << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
    void remove(int rno)
    {
        int index = hashfunction(rno);
        for (int i = 0; i < table[index].size(); i++)
        {
            if (table[index][i].rollno == rno)
            {
                table[index].erase(table[index].begin() + i);
                cout << "Element is Removed " << rno << endl;
                return;
            }
        }
        cout << "Student not found" << endl;
    }
    void update(int rno, string newname)
    {
        int key = hashfunction(rno);
        for (auto &student : table[key])
        {
            if (student.rollno == rno)
            {
                student.name = newname;
                cout << "Name is Updated" << endl;
                return;
            }
        }
        cout << "element not found" << endl;
    }
    void Display(){
        for (int i =0;i<arrsize;i++){
            for (auto & s: table[i]){
                cout<<"srollno  :: "<<s.rollno<<"    "<<"sname  "<<s.name<<endl;
            }
            cout<<endl;
        }
    }
};

int main()
{
    HashTable ht;
    ht.insert(101, "Alice");   // 101 % 10 = 1
    ht.insert(111, "Bob");     // 111 % 10 = 1 (collision with Alice)
    ht.insert(121, "Charlie"); // 121 % 10 = 1 (collision with Alice & Bob)
    ht.insert(102, "David");   // 102 % 10 = 2 (no collision)

    ht.search(101); // Should find Alice
    ht.search(121); // Should find Charlie
    ht.search(130); // Should not find

    ht.Display();

    ht.update(111, "Bobby");
    ht.search(111);

    ht.remove(121);
    ht.search(121);

    cout << "Total collisions: " << ht.collisionCount << endl;
    return 0;
}