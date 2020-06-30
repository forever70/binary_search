#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){     /* counting spear */
  int spear = 0;
  for(int i=0;i<n;i++){
    spear += A[i] / x;  /* floor(A[i]/x) */
  }
  return k > spear;    /* meet a requirement(k <= spear) -> 0 */
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9 + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n",lb);  /* meet a requirement -> lb */

  return 0;
}
