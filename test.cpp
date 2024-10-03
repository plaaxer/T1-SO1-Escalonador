#include <iostream>
#include <vector>
#include "solution.cpp"

using namespace std;

void runTest(vector<int> startTime, vector<int> endTime, vector<int> profit, int expected) {
    int result = jobScheduling(startTime, endTime, profit);
    cout << "Result: " << result << ", Expected: " << expected << endl;
    if (result == expected) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }
}

int main() {
    // Test case 1
    vector<int> startTime1 = {1, 2, 3, 4};
    vector<int> endTime1 = {3, 5, 10, 6};
    vector<int> profit1 = {20, 20, 100, 70};
    int expected1 = 150;
    runTest(startTime1, endTime1, profit1, expected1);

    // Test case 2
    vector<int> startTime2 = {1, 2, 3, 3};
    vector<int> endTime2 = {3, 4, 5, 6};
    vector<int> profit2 = {50, 10, 40, 70};
    int expected2 = 120;
    runTest(startTime2, endTime2, profit2, expected2);

    // Test case 3
    vector<int> startTime3 = {1, 2, 3, 4, 6};
    vector<int> endTime3 = {3, 5, 10, 6, 9};
    vector<int> profit3 = {20, 20, 100, 70, 60};
    int expected3 = 150;
    runTest(startTime3, endTime3, profit3, expected3);

    // Test case 4
    vector<int> startTime4 = {1, 1, 1};
    vector<int> endTime4 = {2, 3, 4};
    vector<int> profit4 = {5, 6, 4};
    int expected4 = 6;
    runTest(startTime4, endTime4, profit4, expected4);

    return 0;
}