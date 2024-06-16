#include <iostream>
using namespace std;

// Define the number of people
#define NUM_PEOPLE 3

// Function to find the index of the minimum value in an array
int findMinIndex(int arr[])
{
    int minIdx = 0;
    for (int i = 1; i < NUM_PEOPLE; i++)
    {
        if (arr[i] < arr[minIdx])
            minIdx = i;
    }
    return minIdx; // Return the index of the smallest value
}

// Function to find the index of the maximum value in an array
int findMaxIndex(int arr[])
{
    int maxIdx = 0;
    for (int i = 1; i < NUM_PEOPLE; i++)
    {
        if (arr[i] > arr[maxIdx])
            maxIdx = i;
    }
    return maxIdx; // Return the index of the largest value
}

// Function to find the smaller of two values
int minOfTwo(int num1, int num2)
{
    return (num1 < num2) ? num1 : num2;
}

// Function to minimize the cash flow among people represented by the amount array
void settleAmounts(int amount[])
{
    int maxCredit = findMaxIndex(amount), maxDebit = findMinIndex(amount);

    // If both max credit and max debit are zero, all debts are settled
    if (amount[maxCredit] == 0 && amount[maxDebit] == 0)
        return;

    // Find the minimum of the amounts to be transferred
    int minAmount = minOfTwo(-amount[maxDebit], amount[maxCredit]);
    amount[maxCredit] -= minAmount;
    amount[maxDebit] += minAmount;

    // Display the transaction
    cout << "Person " << maxDebit << " pays " << minAmount << " to Person " << maxCredit << "." << endl;

    // Recursively settle the remaining amounts
    settleAmounts(amount);
}

void calculateMinCashFlow(int graph[][NUM_PEOPLE])
{
    int amount[NUM_PEOPLE] = {0};

    for (int p = 0; p < NUM_PEOPLE; p++)
    {
        for (int i = 0; i < NUM_PEOPLE; i++)
        {
            amount[p] += (graph[i][p] - graph[p][i]);
        }
    }
    settleAmounts(amount);
}

int main()
{
    int graph[NUM_PEOPLE][NUM_PEOPLE] = {{0, 1000, 2000},
                                         {0, 0, 5000},
                                         {0, 0, 0}};

    calculateMinCashFlow(graph);

    return 0;
}