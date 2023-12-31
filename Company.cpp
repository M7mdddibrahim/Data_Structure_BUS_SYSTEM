#include "Company.h"
#include"Stations.h"
#include "ArrivalEvent.h"
#include "LeaveEvent.h"

Company::Company()
{
	ui = new UI;
	Timer.SetHours(4);
	Timer.SetMin(0);
	no_ofStations = 0;
	Time_Between_Stations = 0;
	WBusses_Count = 0;
	MBusses_Count = 0;
	WBus_Capacity = 0;
	MBus_Capacity = 0;
	no_ofTrips = 0;
	WBus_CheckupTime = 0;
	MBus_CheckupTime = 0;
	WaitingMin = 0;
	get_on_off_Time = 0;
	NumofEvents = 0;
	timerH = 4;
	timerM = 0;
	SStation = 0;
	EStation = 0;
	hour = 0;
	min = 0;
	current_station = 0;

}

void Company::simulation()
{
	int FC = Completed.GetSize();
	while (NumofEvents == FC)
	{
		if (timerH >= 4 && timerH <= 22)
		{
			int x;
			cout << "Welcome to the Bus Company " << endl;
			cout << "Choose Mode: " << endl << "1) Interactive Mode " << endl << "2) Silent Mode " << endl;
			cin >> x;
			while ((x != 1))
			{
				system("CLS"); //clears the console 
				cout << "Please enter 1 for phase (1): ";
				cin >> x;
			}

			loadFile();
			randomleave();
			output();
			system("CLS"); //clears the console 
		}
		Timer.IncrementMin();
		//TODO: after incrementing the time you need to increment the hours, look at function timeConverter to understand,
		// how we manage the time for the passengers
	}

}


void Company::addPassenger(Passengers* P)
{
	stationArray[P->getSStaion()].AddPassengers(P);
}

void Company::Leave_Passenger(int STARTS, int id)
{

	if (stationArray[STARTS].RemovePassenger(stationArray[STARTS].getNormalPF(), id))
	{
		return;
	}

	if (stationArray[STARTS].RemovePassenger(stationArray[STARTS].getNormalPB(), id))
	{
		return;
	}

}

void Company::randomleave()
{
	srand((unsigned)time(NULL));
	Passengers* P;
	for (int i = 0; i < no_ofStations; i++)
	{
		int random_number = rand() % 100;
		if ((random_number >= 1) && (random_number <= 25))
		{
			if (!stationArray[i].getSpecialPF().IsEmpty())
			{
				stationArray[i].getSpecialPF().Dequeue(P);
				Completed.Enqueue(P);
			}
			else if (!stationArray[i].getSpecialPB().IsEmpty())
			{
				stationArray[i].getSpecialPB().Dequeue(P);
				Completed.Enqueue(P);
			}
		}
		if ((random_number >= 35) && (random_number <= 45))
		{
			if (!stationArray[i].getWheelPF().IsEmpty())
			{
				stationArray[i].getWheelPF().Dequeue(P);
				Completed.Enqueue(P);
			}
			else if (!stationArray[i].getWheelPB().IsEmpty())
			{
				stationArray[i].getWheelPB().Dequeue(P);
				Completed.Enqueue(P);
			}
		}
		if ((random_number >= 50) && (random_number <= 60))
		{
			if (!stationArray[i].getNormalPF().IsEmpty())
			{
				stationArray[i].getNormalPF().Dequeue(P);
				Completed.Enqueue(P);
			}
			else if (!stationArray[i].getNormalPB().IsEmpty())
			{
				stationArray[i].getNormalPB().Dequeue(P);
				Completed.Enqueue(P);
			}
		}
		//Next_station();
	}
}

void Company::Next_station()
{
	if (current_station == no_ofStations)
		current_station = 1;
	else
		current_station++;
}


void Company::timeConverter(ifstream& input)
{
	input >> hour;
	input.ignore();
	input >> min;
	//Timer.SetHours(hour);
	//Timer.SetMin(min);
}

void Company::releaseBusFromStationZero(Queue<Buses*> MGB, Queue<Buses*> WGB)
{
	Buses* TempBus;
	if (Timer.getMin() == 0 || Timer.getMin() == 30)
	{
		if (MGB.peek(TempBus))
		{
			MGB.Dequeue(TempBus);
			MBMovingFW.Enqueue(TempBus);
		}
		else
		{
			WGB.Dequeue(TempBus);
			WBMovingFW.Enqueue(TempBus);
		}
	}
	else if (Timer.getMin() == 15 || Timer.getMin() == 45)
	{
		if (WGB.peek(TempBus))
		{
			WGB.Dequeue(TempBus);
			WBMovingFW.Enqueue(TempBus);
		}
		else
		{
			MGB.Dequeue(TempBus);
			MBMovingFW.Enqueue(TempBus);
		}
	}
}

void Company::BoardingWPassengers()
{
	for (int i = 0; i < no_ofStations; i++)
	{
		stationArray[i].BoardingWP(stationArray[i].getWheelPF(), stationArray[i].getWheelPB(), stationArray[i].getFWBusList(), stationArray[i].getBWBusList());
	}
}

void Company::AddPassToFinishList(Queue<Passengers*>& Completed)
{
	Stations s;
	s.FinishPass(Completed);
	Completed.Display();
}

void Company::loadFile()
{
	string Filename = "input.txt";
	ifstream input;
	input.open(Filename, ios::in);
	if (input.is_open())
	{
		Buses B;
		Stations S;
		input >> no_ofStations >> Time_Between_Stations;
		S.setStationsnumber(no_ofStations);     S.SetTimeBetweenSta(Time_Between_Stations);
		input >> WBusses_Count >> MBusses_Count;
		input >> WBus_Capacity >> MBus_Capacity;
		input >> no_ofTrips >> WBus_CheckupTime >> MBus_CheckupTime;
		input >> WaitingMin >> get_on_off_Time;
		B.Set_MBusCount(MBusses_Count);              B.Set_WBusCount(WBusses_Count);
		B.Set_MBusCapacity(MBus_Capacity);           B.Set_WBusCapacity(WBus_Capacity);
		B.Set_MCheckupTime(MBus_CheckupTime);         B.Set_WCheckupTime(WBus_CheckupTime);
		MBus.insertNode(B);
		WBus.insertNode(B);
		for (int i = 0; i < no_ofStations; i++)
		{
			stationArray[i] = Stations(i);
		}
		input >> NumofEvents;

		for (int i = 0; i < NumofEvents; i++)
		{
			Time time;
			string Special_Type;
			string Dir;
			Passengers* P = new Passengers();
			input >> Event_type;
			if (Event_type == 'A')
			{
				input >> Pass_type;
				if (Pass_type == "NP")
				{
					char H;
					input >> hour >> H >> min;
					time.SetHours(hour);
					time.SetMin(min);
					input >> ID >> SStation >> EStation;
					ArrivalEvent* PassengerArrived = new ArrivalEvent(Pass_type, SStation, EStation, time, ID);
					EventList.Enqueue(PassengerArrived);


				}
				if (Pass_type == "WP")
				{
					char H;
					input >> hour >> H >> min;
					time.SetHours(hour);
					time.SetMin(min);
					input >> ID >> SStation >> EStation;
					ArrivalEvent* PassengerArrived = new ArrivalEvent(Pass_type, SStation, EStation, time, ID);
					EventList.Enqueue(PassengerArrived);
				}
				if (Pass_type == "SP")
				{
					char H;
					input >> hour >> H >> min;
					time.SetHours(hour);
					time.SetMin(min);
					input >> ID >> SStation >> EStation;
					input >> Special_Type;
					ArrivalEvent* PassengerArrived = new ArrivalEvent(Special_Type, Pass_type, SStation, EStation, time, ID);
					EventList.Enqueue(PassengerArrived);

				}
				//time = timeConverter(input);
			}
			else if (Event_type == 'L')
			{
				/*timeConverter(input);*/
				char H;
				input >> hour >> H >> min;
				time.SetHours(hour);
				time.SetMin(min);
				//P->setLT(LTime);
				input >> ID >> SStation;
				/*P->setID(ID);
				P->setSStaion(SStation);
				Leave_Passenger( SStation, P->getID());*/
				cout << ID;
				LeaveEvent* PassengereLeaving = new LeaveEvent(time, ID, SStation);
				EventList.Enqueue(PassengereLeaving);
			}
		}

	}

}
void Company::Outputfile()
{
	Passengers P;
	Buses B;
	string Filename = "output.txt";
	ofstream output;
	output.open(Filename, ios::out);
	output << "FT" << setw(6) << "ID" << setw(6) << "AT" << setw(6) << "WT" << setw(6) << "TT" << endl;
	output << "passengers: " << endl;
	output << "passenger Avg Wait time= " << endl;
	output << "passenger Avg trip time= " << endl;
	output << "Auto-promoted passengers: " << endl;
	output << "buses: " << B.Get_TotalNumberofBuses() << "[ WBus: " << B.Get_WBus_Count() << ", MBus: " << B.Get_MBus_Count() << endl;
	output << "Avg Busy time=  " << endl;
	output << "Avg utilization=  " << endl;

}
void Company::output()
{
	Stations S;
	int i = 0;
	Event* TempE;
	while (EventList.peek(TempE))
	{
		if (TempE->getTime() == Timer)
		{
			/*EventList.peek(TempE);*/
			//if (TempE->getTime()  == Timer)
			TempE->excute(this);
			ui->PrintTime(Timer);
			ui->PrintStation(TempE->getStartS());
			ui->PrintPassengers(stationArray[TempE->getStartS()].getNormalPF(), stationArray[TempE->getStartS()].getNormalPB(), stationArray[TempE->getStartS()].getWheelPF(), stationArray[TempE->getStartS()].getWheelPB(), stationArray[TempE->getStartS()].getSpecialPF(), stationArray[TempE->getStartS()].getSpecialPB());
			ui->PrintBuses(MBus, WBus);
			ui->PrintLine();
			//randomleave();
			AddPassToFinishList(Completed);
			ui->PrintFinishedPass(Completed);
			Timer.IncrementMin();
			Next_station();
			EventList.Dequeue(TempE);
			delete TempE;
			//output();

		}
		else
		{
			ui->PrintTime(Timer);
			ui->PrintStation(current_station);
			ui->PrintPassengers(stationArray[current_station].getNormalPF(), stationArray[current_station].getNormalPB(), stationArray[current_station].getWheelPF(), stationArray[current_station].getWheelPB(), stationArray[current_station].getSpecialPF(), stationArray[current_station].getSpecialPB());
			ui->PrintBuses(MBus, WBus);
			ui->PrintLine();
			randomleave();
			AddPassToFinishList(Completed);
			ui->PrintFinishedPass(Completed);
			Timer.IncrementMin();
			Next_station();
		}
	}
	Outputfile();
}