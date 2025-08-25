#include <iostream>
#include <vector>
using namespace std;
struct StudentHeap
{
    int Rollno;
    float Cgpa;
    StudentHeap(int rno, float c)
    {
        Rollno = rno;
        Cgpa = c;
    }
};
class StudentMaxHeap
{
    vector<StudentHeap> heap;

public:
void heapify_up(int ind)
{
    while (ind != 0)
    {
        int pnode = (ind - 1) / 2;
        if (heap[pnode].Cgpa < heap[ind].Cgpa)
        {
                swap(heap[pnode], heap[ind]);
                ind = pnode;
            }
            else
            {
                break;
            }
        }
    }
    void heapify_down(int ind)
    {
        int hsize = heap.size();
        while (true)
        {
            int left_ind = 2 * ind + 1;
            int right_ind = 2 * ind + 2;
            int max = ind;
            if (left_ind < hsize && heap[left_ind].Cgpa > heap[max].Cgpa)
            {
                max = left_ind;
            }
            if (right_ind < hsize && heap[right_ind].Cgpa > heap[max].Cgpa)
            {
                max = right_ind;
            }
            if (max == ind)
            {
                break;
            }
            swap(heap[ind], heap[max]);
            ind = max;
        }
    }
    void insert_student(StudentHeap s)
    {
        heap.push_back(s);
        int ind = heap.size() - 1;
        heapify_up(ind);
    }
    void remove_best_student()
    {
        if (heap.empty())
        {
            cout << "Heap is Empty" << endl;
        }
        else
        {
            swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            heapify_down(0);
        }
    }
    void Display(){
        if (heap.empty()){
            cout<<"Heap is Empty "<< endl;
            return;
        }
        for (auto& student : heap)
        {
            cout << "Roll No: " << student.Rollno << ", CGPA: " << student.Cgpa << endl;
        }
    }
};

int main()
{
    StudentHeap s1(1, 9.5);
    StudentHeap s2(2, 8.5);
    StudentHeap s3(3, 7.5);

    StudentMaxHeap maxHeap;
    maxHeap.insert_student(s1);
    maxHeap.insert_student(s2);
    maxHeap.insert_student(s3);

    cout << "Students in Max Heap (by CGPA):" << endl;
    maxHeap.Display();

    maxHeap.remove_best_student();

    cout << "Students in Max Heap (by CGPA):" << endl;
    maxHeap.Display();

    return 0;
}