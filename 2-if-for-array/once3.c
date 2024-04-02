int main(){
  int n;
  scanf("%d", &n);
  int i;
  int count[n];
  int x;

  for (i = 1; i <= n; i ++) {
    count[i] = 0;
  }
  scanf("%d", &x);
  for (i = 1; i <= (2*n - 1); i ++){
    count[x] ++;
    scanf("%d", &x);
  }
  for (i = 1; i <= n; i ++){
    if(count[i] == 1){
      printf("%d\n", i);
    }
  }
  return 0;
}
