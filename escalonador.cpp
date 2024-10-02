#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Scheduling {
    private:
        struct Job{
            int beggin, finish, profit;
        };

        int binary_search(vector<Job>&listJobs, int i) {
            int start = 0;
            int end = i-1;

            while (start <= end) {
                int middle = (start + end)/2;
                if (listJobs[middle].finish <= listJobs[i].beggin) {
                    if (listJobs[middle+1].finish <= listJobs[i].beggin){
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

        bool jobCompare(Job a, Job b) {
            return (a.finish < b.finish);
        }

    public:

        int jobScheduling(vector<int>&startTime, vector<int>&endTime, vector<int>&profit) {
            int n = startTime.size();
            Job listJobs[n];

            for (int i = 0; i<=n; i++) {
                listJobs[i] = {{startTime[i]}, {endTime[i]}, {profit[i]}};
            };
            
            sort(listJobs, listJobs+n, jobCompare);

        }
    
};

int main(){
    vector<int>startTime = {6,24,45,27,13,43,47,36,14,11,11,12}, endTime = {31,27,48,46,44,46,50,49,24,42,13,27}, profit = {14,4,16,12,20,3,18,6,9,1,2,8};
    Scheduling s;
    cout << s.jobScheduling(startTime, endTime, profit);
    return 0;
}

  
