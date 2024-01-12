#include <stdio.h>
#include <math.h>

int gcd(int n1, int n2, int *opCount) {
    int gcd = 1;
    int x = n1 < n2 ? n1 : n2;
    int y = n1 > n2 ? n1 : n2;
    
    for (int i = 2; i <= x; i++) {
        (*opCount)++;
        if (x % i == 0 && y % i == 0) {
            x /= i;
            y /= i;
            gcd *= i;
            i--;
        }
    }
    
    return gcd;
}

int main() {
    int n1, n2, opCount = 0;
    printf("Enter the two numbers: ");
    scanf("%d %d", &n1, &n2);
    
    int result = gcd(n1, n2, &opCount);
    
    printf("The GCD of %d and %d is: %d\n", n1, n2, result);
    printf("Operation Count: %d\n", opCount);
    
    return 0;
}
