#include <stdio.h>

int n;
int k;
int A[100000];

int p(int i){
  return A[i] >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = -1;    /* p(lb) == 0 left */
  ub = n;     /* p(ub) == 1 right */
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;    /* true (lb,ub) -> (lb,mid) */
    else lb = mid;          /* false (lb,ub) -> (mid,ub) */
  }
  printf("%d\n",ub);
  
  return 0;
}
