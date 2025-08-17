#include <iostream>
#include <vector>
using namespace std;

const int arrsize = 20;

struct Student {
    int rollno;
    string name;
};

struct HashTable {
public:
    vector<Student> table[arrsize];
    int collisionCount = 0;

    int computeHash(int rollno) {
        int key = rollno % 10;
        return key;
    }

    void addStudent(int rno, string sname) {
        int index = computeHash(rno);
        if (!table[index].empty()) {
            collisionCount++;
        }
        table[index].push_back({rno, sname});
    }

    void findStudent(int rno) {
        int index = computeHash(rno);
        for (auto &student : table[index]) {
            if (student.rollno == rno) {
                cout << "Found: Roll No " << student.rollno
                     << " -> " << student.name << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void deleteStudent(int rno) {
        int index = computeHash(rno);
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].rollno == rno) {
                table[index].erase(table[index].begin() + i);
                cout << "Element is Removed " << rno << endl;
                return;
            }
        }
        cout << "Student not found" << endl;
    }

    void modifyStudentName(int rno, string newname) {
        int key = computeHash(rno);
        for (auto &student : table[key]) {
            if (student.rollno == rno) {
                student.name = newname;
                cout << "Name is Updated" << endl;
                return;
            }
        }
        cout << "Element not found" << endl;
    }

    void displayTable() {
        for (int i = 0; i < arrsize; i++) {
            for (auto &s : table[i]) {
                cout << "Roll No: " << s.rollno << "    "
                     << "Name: " << s.name << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.addStudent(101, "Alice");   // 101 % 10 = 1
    ht.addStudent(111, "Bob");     // 111 % 10 = 1 (collision with Alice)
    ht.addStudent(121, "Charlie"); // 121 % 10 = 1 (collision with Alice & Bob)
    ht.addStudent(102, "David");   // 102 % 10 = 2 (no collision)

    ht.findStudent(101); // Should find Alice
    ht.findStudent(121); // Should find Charlie
    ht.findStudent(130); // Should not find

    ht.displayTable();

    ht.modifyStudentName(111, "Bobby");
    ht.findStudent(111);

    ht.deleteStudent(121);
    ht.findStudent(121);

    cout << "Total collisions: " << ht.collisionCount << endl;
    return 0;
}
