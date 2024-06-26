#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 4 
int minCost(int costMatrix[N][N], int assignment[N], int agent, int totalCost, int count, int* finalCost, int used[N]) {
    if (count == N) {
        if (totalCost < *finalCost)
            *finalCost = totalCost;
        return *finalCost;
    }

    for (int job = 0; job < N; job++) {
        if (used[job] == 0 && (totalCost + costMatrix[agent][job]) < *finalCost) {
            used[job] = 1;
            minCost(costMatrix, assignment, agent + 1, totalCost + costMatrix[agent][job], count + 1, finalCost, used);
            used[job] = 0;
        }
    }
    return *finalCost;
}
int solveAssignmentProblem(int costMatrix[N][N]) {
    int assignment[N];
    int finalCost = INT_MAX;
    int used[N] = {0}; 
    minCost(costMatrix, assignment, 0, 0, 0, &finalCost, used);
    return finalCost;
}
int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    int minCost = solveAssignmentProblem(costMatrix);
    printf("Minimum cost of assignment is: %d\n", minCost);
    return 0;
}