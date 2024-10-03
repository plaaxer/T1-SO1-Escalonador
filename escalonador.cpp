#include "escalonador.h"

int Scheduling::binary_search(Job listJobs[], int i) {
    int start = 0;
    int end = i-1;

    while (start <= end) {
        int middle = (start + end)/2;
        if (listJobs[middle].finish <= listJobs[i].begin) {
            if (listJobs[middle+1].finish <= listJobs[i].begin){
                start = middle+1;
            }
            else {
                return middle;
            }
        }
        else {
            end = middle-1;
        }
    };
return -1;
}

bool Scheduling::jobCompare(Job a, Job b) {
    return (a.finish < b.finish);
}

int Scheduling::jobScheduling(vector<int>&startTime, vector<int>&endTime, vector<int>&profit) {
    int n = startTime.size();
    Job listJobs[n];

    for (int i = 0; i<=n; i++) {
        listJobs[i] = {{startTime[i]}, {endTime[i]}, {profit[i]}};
    };
    
    sort(listJobs, listJobs+n, jobCompare);

    int currentProfit = 0;

    for (int i = 1; i < n; i++) {
        currentProfit = listJobs[i].profit;
        int previousJob = binary_search(listJobs, i);
        if (previousJob != -1) {
            currentProfit += listJobs[previousJob].profit;
            } 
        listJobs[i].profit = max(currentProfit, listJobs[i-1].profit);
    }
    return listJobs[n-1].profit;
}


