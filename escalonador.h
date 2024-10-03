#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Scheduling {
    private:
        struct Job{
            int begin, finish, profit;
        };

        int binary_search(Job listJobs[], int i);
        static bool jobCompare(Job a, Job b);

    public:

        int jobScheduling(vector<int>&startTime, vector<int>&endTime, vector<int>&profit);
};
