#include<iostream> 
#include "RHeader.h"
using namespace std;


int main()
{
	int n;
	int quantum;
	cout << "Enter the number of processes: ";
	cin >> n;
	cout << "Enter time quantum: ";
	cin >> quantum;
	RR processes;
	process* pr = new process[n];
	for (int i = 0; i < n; i++) {		
		cout << "Enter burst time of process " << i + 1 << ": ";
		cin >> pr[i].burst_time;
		pr[i].procID = i+1;
		pr[i].treatment_burst = pr[i].burst_time;
		cout << endl;
	}

	processes.findavg(n, pr, quantum);	
	return 0;
}