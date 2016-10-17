#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long count_inversions(vector<int>&);
long long count_inversions(vector<int>&, int, int, vector<int>&);
long long merge(vector<int>&, int, int, int, vector<int>&);

long long count_inversions(vector<int>& a) {
  vector<int> b = a;
  return count_inversions(a, 0, a.size()-1, b);
}

long long count_inversions(vector<int>& a, int lo, int hi, vector<int>& b) {
  if (lo >= hi) return 0;
  int mid = lo + (hi - lo) / 2;
  
  long long inversions = 0;
  inversions += count_inversions(b, lo, mid, a);
  inversions += count_inversions(b, mid+1, hi, a);
  inversions += merge(a, lo, mid, hi, b);
  
  return inversions;
}

long long merge(vector<int>& a, int lo, int mid, int hi, vector<int>& b) {
  long long inversions = 0;
  int i = lo, j = mid + 1, k = lo;
  while(i <= mid || j <= hi){
    if (i > mid) {
      a[k++] = b[j++];
    } else if (j > hi) {
      a[k++] = b[i++];
    } else if (b[i] <= b[j]) {
      a[k++] = b[i++];
    } else {
      a[k++] = b[j++];
      inversions += mid + 1 - i;
    }
  }
  return inversions;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}