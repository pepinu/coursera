#include <iostream>
#include <vector>

using namespace std;


long quickSort(vector<int>& ar, int lo, int hi) {
  long inversions = hi-lo-1;
  if(lo >= hi - 1)
    return 0;
  int pivot = ar[lo];
  int i = lo+1;
  for(int j = lo+1; j != hi; ++j) {
    if (ar[j] < pivot) {
      cout << ar[i] << " " << ar[j] << endl;
      swap(ar[j], ar[i]);
      ++i;
    }
  }
  swap(ar[lo], ar[i-1]);
  inversions += quickSort(ar, lo, i-1);
  inversions += quickSort(ar, i, hi);

  return inversions;
}

int main() {
  constexpr int n = 1000;
  vector<int> arr(n);
  for(int i = 0; i != n; ++i) {
    cin >> arr[i];
  }
  long inv = quickSort(arr, 0, n);
  for(auto i : arr) cout << i << " ";
  cout << endl << inv << endl;
  return 0;
}
