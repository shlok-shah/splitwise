#include <iostream>
using namespace std;

#define NUM_PEOPLE 3

int findMinIndex(int arr[])
{
    int minIdx = 0;
    for (int i = 1; i < NUM_PEOPLE; i++)
    {
        if (arr[i] < arr[minIdx])
            minIdx = i;
    }
    return minIdx; 
}

int findMaxIndex(int arr[])
{
    int maxIdx = 0;
    for (int i = 1; i < NUM_PEOPLE; i++)
    {
        if (arr[i] > arr[maxIdx])
            maxIdx = i;
    }
    return maxIdx; 
}

int minOfTwo(int num1, int num2)
{
    return (num1 < num2) ? num1 : num2;
}


void settleAmounts(int amount[])
{
    int maxCredit = findMaxIndex(amount), maxDebit = findMinIndex(amount);

    if (amount[maxCredit] == 0 && amount[maxDebit] == 0)
        return;

    int minAmount = minOfTwo(-amount[maxDebit], amount[maxCredit]);
    amount[maxCredit] -= minAmount;
    amount[maxDebit] += minAmount;

    
    cout << "Person " << maxDebit << " pays " << minAmount << " to Person " << maxCredit << "." << endl;

    
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
