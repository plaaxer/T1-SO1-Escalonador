
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Arquivo separado em que as funções são públicas.
JobSchedulling() possui assinatura idêntica à proposta pelo trabalho.
*/

struct Job{
    int begin, finish, profit;
};

static bool jobCompare(Job a, Job b) {
    return a.finish < b.finish;
}

int binary_search(Job listJobs[], int i) {
    int start = 0;
    int end = i - 1;

    while (start <= end) {
        int middle = (start + end) / 2;
        if (listJobs[middle].finish <= listJobs[i].begin) {
            if (listJobs[middle + 1].finish <= listJobs[i].begin) {
                start = middle + 1;
            } else {
                return middle;
            }
        } else {
            end = middle - 1;
        }
    }
    return -1;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

    if (startTime.size() != endTime.size() || startTime.size() != profit.size()) {
        return 0;
    }

    int n = startTime.size();

    if (n == 0) {
        return 0;
    }

    for (int index = 0; index < n; index++) {
        if (startTime[index] < 0 || endTime[index] < 0 || profit[index] < 0) {
            return 0;
        }
        if (startTime[index] > endTime[index]) {
            return 0;
        }
    }

    Job listJobs[n];

    for (int i = 0; i < n; i++) {
        listJobs[i] = {startTime[i], endTime[i], profit[i]};
    }

    sort(listJobs, listJobs + n, jobCompare);

    int currentProfit = 0;

    for (int i = 1; i < n; i++) {

        currentProfit = listJobs[i].profit;

        int previousJob = binary_search(listJobs, i);

        if (previousJob != -1) {
            currentProfit += listJobs[previousJob].profit;
            } 

        if (currentProfit > listJobs[i - 1].profit) {
            listJobs[i].profit = currentProfit;
        } else {
            listJobs[i].profit = listJobs[i - 1].profit;
        }
    }
    return listJobs[n-1].profit;
}
