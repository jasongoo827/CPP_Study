#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

  int n, i;

  scanf("%d", &n);
  int arr[10000] = { 0, };

  for(i = 0; i < n; i++) scanf("%d", &arr[i]);
 
  if (prev_permutation(arr, arr+n)) for(i = 0; i < n; i++) printf("%d ", arr[i]);
  else printf("-1");

  printf("\n");

  return 0;
}