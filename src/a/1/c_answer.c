#include <stdio.h>

void makeOne(int arr[100]) {
 for (int i = 0; i < 100; i++) {
  arr[i] = 1;
 }
}
int isLucky(int n) {
 while (n > 0) {
  if (n % 10 == 4 || n % 10 == 7) {
   if (n == 4 || n == 7) {
    return 0;
   }
   n = n / 10;
  }
  else {
   n = -1;
  }
 }
 return 0;
}
int main() {
 int luck, a = 0, i = 0;
 scanf("%d", &luck);
 int arr[100];
 makeOne(arr);
 for (int i = 4; i < 777; i++) {
  if (isLucky(i) == 0) {
   arr[a] = i;
   a++;
  }
 }
 for (i = 0; i < a; i++) {
  if (luck % arr[i] == 0) {
   printf("YES");
   return 0;
  }
 }
 if (i == a) {
  printf("NO");
 }
 return 0;
}
