#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char s[MAX_SIZE] = "dog";
char a[MAX_SIZE] = "hello";
int main() {
    strcat(s,a);
    printf("%s", &s);
//    printf("%s", &a);
    return 0;
}