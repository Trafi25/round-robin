#include<iostream> 
using namespace std;
struct process {
	int num_process;
	int burst_time;
	int treatment_burst;
	int waiting_time;
	int Turn_around_time;
};
  
void procrsing(process pr, int Current_time) {

	cout << "---------"<< endl;
	cout << "| " << pr.num_process << " | " << Current_time << " |" << endl;
	cout << "---------"<< endl;
}

void WaitingTime(int n, process pr[], int quantum)
{
		
	cout << " Pr  Time"<<endl;
	int Current_time  = 0; 
	bool chekcer;
	do
	{
		chekcer = true;

		
		for (int i = 0; i < n; i++)
		{
			
			if (pr[i].treatment_burst > 0)
			{
				chekcer = false; 

				if (pr[i].treatment_burst > quantum)
				{
					
					Current_time  += quantum;

					
					pr[i].treatment_burst -= quantum;

					procrsing(pr[i], Current_time);
					
				}

				
				else
				{
					
					Current_time  = Current_time  + pr[i].treatment_burst;

					
					pr[i].waiting_time = Current_time  - pr[i].burst_time;

				
					pr[i].treatment_burst = 0; 

					procrsing(pr[i], Current_time);
					
				}
			}
		}

		
		
	} while (chekcer != true);
}




void TurnAroundTime(int n, process pr[])
{
	for (int i = 0; i < n; i++)
		pr[i].Turn_around_time = pr[i].burst_time + pr[i].waiting_time;
}


void findavg(int n, process pr[], int quantum)
{
	int Average_waiting_time = 0;
		
	int Average_turn_around_time = 0;

	
	WaitingTime(n, pr, quantum);

	
	TurnAroundTime(n, pr);

	
	cout << "Processes " <<   " Burst time "  << " Waiting time " <<  " Turn around time\n";

	
	for (int i = 0; i < n; i++)
	{
		Average_waiting_time = Average_waiting_time + pr[i].waiting_time;
		Average_turn_around_time = Average_turn_around_time + pr[i].Turn_around_time;
		cout << " " << i + 1 << "\t\t " << pr[i].burst_time << "\t  "<< pr[i].waiting_time << "\t \t " << pr[i].Turn_around_time << endl;
	}

	cout << "Average waiting time = "<< (float)Average_waiting_time / (float)n;
	cout << "\nAverage turn around time = "	<< (float)Average_turn_around_time / (float)n;
}


int main()
{
	
	
	int n = 3;
	int quantum;
	struct process pr [30];	

	cout << "Enter the number of processes: ";
	cin >> n;
	cout << "Enter time quantum: ";
	cin >> quantum;

	for (int i = 0; i < n; i++) {		
		cout << "Enter burst time of process " << i + 1 << ": ";
		cin >> pr[i].burst_time;
		pr[i].num_process = i+1;
		pr[i].treatment_burst = pr[i].burst_time;
		cout << endl;
	}

	
	findavg(n, pr, quantum);
	return 0;
}