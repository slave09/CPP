/*
	* Problem :  We are given array of jobs, Job contains the job's deadline and it's profit. We need to find the maximum profit that can be gained.
	* Solution :  we take that job first whose profit is max and will do it on it's deadline.  
	* if deadline slot is occupied look for previous empty slots
	* Assumption : Each job can be done in one slot.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int>sequene;

struct jobs{
	int id;
	int profit;
	int deadline;
};

bool comparator(jobs max, jobs min){
	return max.profit >  min.profit;
}

int findMaxDeadline(vector<jobs>jobsArray){
	int maxDeadline = -1;
	for(auto job : jobsArray){
		maxDeadline = max(maxDeadline, job.deadline);
	}
	return maxDeadline;
}

int maxJobProfit(vector<jobs>jobsArray){
	sort(jobsArray.begin(), jobsArray.end(), comparator);
	int noOfSlots = findMaxDeadline(jobsArray);
	vector<int>isSlotAvailable(noOfSlots, 1);
	int maxProfit = 0;
	for(auto job : jobsArray){
		if(isSlotAvailable[job.deadline - 1]){
			sequene.push_back(job.id);
			isSlotAvailable[job.deadline - 1] = 0;
			maxProfit += job.profit;
		}
		else{
			for(int index = job.deadline - 2; index >= 0; index--){
				if(isSlotAvailable[index]){
					sequene.push_back(job.id);
					isSlotAvailable[index] = 0;
					maxProfit += job.profit;
					break;
				}
			}
		}
	}
	return maxProfit;
}

int main(){
	vector<jobs>arr = {{1, 20, 2}, {2, 15, 2}, {3, 10, 1}, {4, 5, 3}, {5, 1, 3}};
	cout << "MaxProfit : " << maxJobProfit(arr) << endl;
	cout << "Sequence of choosen Job : " << endl;
	for(auto seq : sequene){
		cout << seq << endl;
	}
	return 0;
}