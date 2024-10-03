#include "escalonador.cpp"

int main() {
    vector<int>startTime = {6,24,45,27,13,43,47,36,14,11,11,12}, endTime = {31,27,48,46,44,46,50,49,24,42,13,27}, profit = {14,4,16,12,20,3,18,6,9,1,2,13};
    Scheduling s;
    cout << s.jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}
