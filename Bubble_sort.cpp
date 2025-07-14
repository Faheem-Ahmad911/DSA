#include<iostream>
using namespace std;
void Bubble_sort(int arr[]){
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{   int arr[5]={5,4,3,2,1};
      Bubble_sort(arr);
      cout<<"Sorted array is"<<endl;
      for(int i=0;i<5;i++){
          cout<<arr[i]<<endl;
      }
    cout<<"Enter 5 elements of array"<<endl;
      Bubble_sort(arr);
      cout<<"Sorted array is"<<endl;
      for(int i=0;i<5;i++){
          cout<<arr[i]<<endl;
      }
      return 0;
}