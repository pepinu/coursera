#include <iostream>
#include <vector>

using namespace std;

int median (vector<int> ar, int a, int b) {
  int c = (b-1+a)/2;
  if(ar[a] >= ar[b-1] && ar[a] <= ar[c] || ar[a] >= ar[c] && ar[a] <= ar[b-1] ) {
    return a;
  }
  else if (ar[b-1] >= ar[c] && ar[b-1] <= ar[a] || ar[b-1] <= ar[c] && ar[b-1] >= ar[a]) {
    return b-1;
  }
  else
    return c;
}

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

long quickSort3(vector<int>& ar, int lo, int hi) {
  long inversions = hi-lo-1;
  if(lo >= hi - 1)
    return 0;
  int med = median(ar, lo, hi);

  swap(ar[lo], ar[med]);
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
  inversions += quickSort3(ar, lo, i-1);
  inversions += quickSort3(ar, i, hi);

  return inversions;
}

int main() {
  constexpr int n = 10000;
  vector<int> arr(n);
  for(int i = 0; i != n; ++i) {
    cin >> arr[i];
  }
  vector<int> ar2 = arr;
  vector<int> ar3 = arr;
  //long inv1 = quickSort1(arr, 0, n);
  //for(auto i : arr) cout << i << " ";
  //cout << endl << inv1 << endl;

  long inv = quickSort1(arr, 0, n);
  long inv2 = quickSort2(ar2, 0, n);
  long inv3 = quickSort3(ar3, 0, n);
  cout << endl << "First " << inv << endl;
  cout << endl << "Second " << inv2 << endl;
  cout << endl << "Third " << inv3 << endl;
  return 0;
}
