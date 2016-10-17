#include <iostream>
#include <vector>

using namespace std;


long quickSort1(vector<int>& ar, int lo, int hi) {
  long inversions = hi-lo-1;
  if(lo >= hi - 1)
    return 0;
  int pivot = ar[lo];
  int i = lo+1;
  for(int j = lo+1; j != hi; ++j) {
    if (ar[j] < pivot) {
      //cout << ar[i] << " " << ar[j] << endl;
      swap(ar[j], ar[i]);
      ++i;
    }
  }
  swap(ar[lo], ar[i-1]);
  inversions += quickSort1(ar, lo, i-1);
  inversions += quickSort1(ar, i, hi);

  return inversions;
}

long quickSort2(vector<int>& ar, int lo, int hi) {
  long inversions = hi-lo-1;
  if(lo >= hi - 1)
    return 0;
  swap(ar[lo], ar[hi-1]);
  int pivot = ar[lo];
  int i = lo+1;
  for(int j = lo+1; j != hi; ++j) {
    if (ar[j] < pivot) {
      //cout << ar[i] << " " << ar[j] << endl;
      swap(ar[j], ar[i]);
      ++i;
    }
  }
  swap(ar[lo], ar[i-1]);
  inversions += quickSort2(ar, lo, i-1);
  inversions += quickSort2(ar, i, hi);

  return inversions;
}

int main() {
  constexpr int n = 1000;
  vector<int> arr(n);
  for(int i = 0; i != n; ++i) {
    cin >> arr[i];
  }
  //long inv1 = quickSort1(arr, 0, n);
  //for(auto i : arr) cout << i << " ";
  //cout << endl << inv1 << endl;
  long inv2 = quickSort2(arr, 0, n);
  cout << endl << "dwójka " << inv2 << endl;
  return 0;
}
