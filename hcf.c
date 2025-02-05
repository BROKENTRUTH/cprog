#include <stdio.h>

int findHCF(int a, int b) {
    if (b == 0)
        return a;
    return findHCF(b, a % b);
}

int main() {
    int num1, num2, hcf;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    hcf = findHCF(num1, num2);

    printf("HCF of %d and %d is %d\n", num1, num2, hcf);
    return 0;
}