#include <iostream>
using namespace std;


struct process {
	int procID;
	int burst_time;
	int treatment_burst;
	int waiting_time;
	int Turn_around_time;
};

class RR {

public:
	void findavg(int n, process pr[], int quantum)
	{
		int Average_waiting_time = 0;

		int Average_turn_around_time = 0;


		WaitingTime(n, pr, quantum);


		TurnAroundTime(n, pr);


		cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";


		for (int i = 0; i < n; i++)
		{
			Average_waiting_time = Average_waiting_time + pr[i].waiting_time;
			Average_turn_around_time = Average_turn_around_time + pr[i].Turn_around_time;
			cout << " " << i + 1 << "\t\t " << pr[i].burst_time << "\t  " << pr[i].waiting_time << "\t \t " << pr[i].Turn_around_time << endl;
		}

		cout << "Average waiting time = " << (float)Average_waiting_time / (float)n;
		cout << "\nAverage turn around time = " << (float)Average_turn_around_time / (float)n;
	}


private: 
	void procrsing(process pr, int Current_time) {

		cout << "---------" << endl;
		cout << "| " << pr.procID << " | " << Current_time << " |" << endl;
		cout << "---------" << endl;
	}
	void WaitingTime(int n, process pr[], int quantum)
	{

		cout << "PrID Time" << endl;
		int Current_time = 0;
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

						Current_time += quantum;


						pr[i].treatment_burst -= quantum;

						procrsing(pr[i], Current_time);

					}


					else
					{

						Current_time = Current_time + pr[i].treatment_burst;


						pr[i].waiting_time = Current_time - pr[i].burst_time;


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
};