#include <stdio.h>
#include <stdbool.h>
void sieveOfEratosthenes(int n) {
    bool prime[n + 1];
    for (int i = 0; i <= n; i++)
        prime[i] = true;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            printf("%d ", p);
    printf("\n");
}
int main() {
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d are: \n", n);
    sieveOfEratosthenes(n);
    return 0;
}