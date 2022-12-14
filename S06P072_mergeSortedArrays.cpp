#include <iostream>
#include <array>

using namespace std;

// I am aware of the sort() function, but I was only made aware after researching my problems. Since using that would mean my solution would devolve to copying someone else, I wanted to see if I could make my own O(n) solution for merging two sorted arrays.
// That said, if the instructor pops the "what if they're not sorted" question during answer review, I'm gonna flip.

void mergeSortedArrays(int arr1[], int arr2[], int arr3[], int arr1Size, int arr2Size) {
  int i = 0, j = 0;
  while(i+j < arr1Size+arr2Size) {
    // If arr1[i] is valid AND (arr1 is less than arr2 OR arr2[j] is invalid)
    if((arr1[i] < arr2[j] || j == arr2Size) && i != arr1Size) {
      arr3[i+j] = arr1[i];
      i++;
    } else {
      arr3[i+j] = arr2[j];
      j++;
} } }

int main(void) {
  // expected result: { 0, 3, 4, 4, 6, 30, 31 }
  int array1[] = {0,3,4,31};
  int array2[] = {4,6,30};
  int array1Size = sizeof(array1) / sizeof(int);
  int array2Size = sizeof(array2) / sizeof(int);
  int array3[array1Size + array2Size];
  
  mergeSortedArrays(array1,array2,array3,array1Size,array2Size);
  
  for(int i = 0; i < array1Size+array2Size; i++) {
    cout << array3[i] << " ";
  }
  cout << "\n";
}
