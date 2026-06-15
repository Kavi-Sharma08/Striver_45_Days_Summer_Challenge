#include<bits/stdc++.h>
using namespace std;

class Job {
public:    
    int jobId;
    int completionDeadline;
    int earningValue;
    Job(int jobId, int completionDeadline, int earningValue){
        this->jobId = jobId;
        this->completionDeadline = completionDeadline;
        this->earningValue = earningValue;
    }
};

class Solution {
public:
    static bool compareByProfit(Job a, Job b) {
        return (a.earningValue > b.earningValue); 
    }
    
    pair<int, int> scheduleJobs(vector<Job*>& jobList) {
        sort(jobList.begin(), jobList.end(), [](Job* x, Job* y) {
            return x->earningValue > y->earningValue;
        });
        
        int maxDeadline = 0;
        for(Job* task : jobList) {
            maxDeadline = max(maxDeadline, task->completionDeadline);
        }
        
        vector<int> timeSlots(maxDeadline + 1, -1);
        int completedJobCount = 0;
        int totalEarning = 0;
        
        for(Job* currentJob : jobList) {
            for(int slotTime = currentJob->completionDeadline; slotTime > 0; slotTime--) {
                if(timeSlots[slotTime] == -1) {
                    timeSlots[slotTime] = currentJob->jobId;
                    completedJobCount++;
                    totalEarning += currentJob->earningValue;
                    break;
                }
            }
        }
        
        return make_pair(completedJobCount, totalEarning);
    }
};

int main(){
    int totalJobs = 4;
    
    Job* taskOne = new Job(1, 2, 20);
    Job* taskTwo = new Job(2, 1, 10);
    Job* taskThree = new Job(3, 2, 40);
    Job* taskFour = new Job(4, 2, 30);
    
    vector<Job*> jobCollection;
    jobCollection.push_back(taskOne);
    jobCollection.push_back(taskTwo);
    jobCollection.push_back(taskThree);
    jobCollection.push_back(taskFour);
    
    Solution scheduler;
    pair<int, int> result = scheduler.scheduleJobs(jobCollection);
    
    cout << "Jobs Completed: " << result.first << " | Total Profit: " << result.second << endl;
    
    for(Job* task : jobCollection) {
        delete task;
    }
    
    return 0;
}