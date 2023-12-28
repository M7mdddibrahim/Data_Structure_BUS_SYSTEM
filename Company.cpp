#include "Company.h"


Company::Company()
{
	ui = new UI;
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
	int FC = Finishing_list.getCount();
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
			randomleave(NPF, NPB, WPF, WPB, SPF, SPB);
			output();
			system("CLS"); //clears the console 
		}

		timeIncremeter();
		//TODO: after incrementing the time you need to increment the hours, look at function timeConverter to understand,
		// how we manage the time for the passengers
	}

}

void Company::timeIncremeter()
{
	if (timerM == 59)
		timerH++;
	timerM++;
}
bool Company::Leave_List(List<Passengers>current)
{
	Passengers p;
	for (int i = 0; i < current.getCount(); i++)
	{
		Node<Passengers>* temp = current.getHead();
		if ((temp->GetData().getSStaion() == current_station) && (timerH * 60 + timerM) == temp->GetData().getAT())
		{
			p = temp->GetData();
			current.DeleteNode(p);
			Finishing_list.insertNode(p);
			return (true);
		}
		temp = temp->GetNext();
	}
	return false;
}
void Company::addPassenger(Passengers* P)
{
	stationArray[P->getSStaion()].AddPassengers(P);
}
//bool Company::Leave_Passenger(int id)

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
	//if (stationArray[STARTS].removePassengerUsingID(stationArray[STARTS].getNormalPassengerB(), id)) return;
	//if (stationArray[STARTS].removePassengerUsingID(stationArray[STARTS].getNormalPassengerF(), id)) return;

	//if (stationArray[STARTS].removePassengerUsingID(stationArray[STARTS].getWheelChairPassengerF(), id)) return;
	//if (stationArray[STARTS].removePassengerUsingID(stationArray[STARTS].getWheelChairPassengerB(), id)) return;
	//if (stationArray[STARTS].removeSpecialPassengerUsingId(stationArray[STARTS].getSpecialPassengerF(), id)) return;
	//if (stationArray[STARTS].removeSpecialPassengerUsingId(stationArray[STARTS].getSpecialPassengerB(), id)) return;
	/*Passengers P;
	for (int i = 0; i < NPF.getCount(); i++)
	{
		Node<Passengers>* temp = NPF.getHead();
		if (temp->GetData().getID() == id)
		{
			P = temp->GetData();
			NPF.DeleteNode(P);
			return true;
		}
		temp = temp->GetNext();
	}
	for (int i = 0; i < NPB.getCount(); i++)
	{
		Node<Passengers>* t = NPB.getHead();
		if (t->GetData().getID() == id)
		{
			P = t->GetData();
			NPB.DeleteNode(P);
			return true;
		}
		t = t->GetNext();
	}
	return false;*/

}

void Company::randomleave(List<Passengers> NPF, List<Passengers> NPB, List<Passengers> WPF, List<Passengers> WPB, List<Passengers> SPF, List<Passengers> SPB)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < no_ofStations; i++)
	{
		int random_number = rand() % 100;
		if ((random_number >= 1) && (random_number <= 25))
		{
			if (Leave_List(SPF))
				return;
			else
				Leave_List(SPB);
		}
		if ((random_number >= 35) && (random_number <= 45))
		{
			if (Leave_List(WPF))
				return;
			else
				Leave_List(WPB);
		}
		if ((random_number >= 50) && (random_number <= 60))
		{
			if (Leave_List(NPF))
				return;
			else
				Leave_List(NPB);
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


int Company::timeConverter(ifstream& input)
{
	input >> hour;
	input.ignore();
	input >> min;
	min += hour * 60;
	return min;
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
			int time;
			string Special_Type;
			string Dir;
			Passengers P;
			input >> Event_type;
			if (Event_type == 'A')
			{
				input >> Pass_type;
				if (Pass_type == "NP")
				{
					time = timeConverter(input);
					P.setAT(time);
					P.setTyp(Pass_type);
					input >> ID >> SStation >> EStation;
					int i = ID;
					P.setID(ID);
					P.setSStaion(SStation);
					P.setEStaion(EStation);
					P.setPassengerDir();
					Dir = P.getPassengerDir();
					if (Dir == "FWD")
					{
						NPF.insertNode(P);
					}
					else if (Dir == "BCK")
					{
						NPB.insertNode(P);
					}

				}
				if (Pass_type == "WP")
				{
					time = timeConverter(input);
					P.setAT(time);
					P.setTyp(Pass_type);
					input >> ID >> SStation >> EStation;
					P.setID(ID);
					P.setSStaion(SStation);
					P.setEStaion(EStation);
					P.setPassengerDir();
					Dir = P.getPassengerDir();
					if (Dir == "FWD")
					{
						WPF.insertNode(P);
					}
					else if (Dir == "BCK")
					{
						WPB.insertNode(P);
					}

				}
				if (Pass_type == "SP")
				{
					time = timeConverter(input);
					P.setAT(time);
					P.setTyp(Pass_type);
					input >> ID >> SStation >> EStation;
					P.setID(ID);
					P.setEStaion(EStation);
					P.setSStaion(SStation);
					input >> Special_Type;
					P.setSPtyp(Special_Type);
					P.setPassengerDir();
					Dir = P.getPassengerDir();
					if (Dir == "FWD")
					{
						SPF.insertNode(P);
					}
					else if (Dir == "BCK")
					{
						SPB.insertNode(P);
					}
					continue;
				}
				//time = timeConverter(input);
			}
			else if (Event_type == 'L')
			{
				LTime = timeConverter(input);
				P.setLT(LTime);
				input >> ID >> SStation;
				P.setID(ID);
				P.setSStaion(SStation);
				Leave_Passenger( SStation, P.getID());
			}
		}
	}
}


void Company::output()
{
	while (current_station <= no_ofStations)
	{
		ui->PrintTime(timerH, timerM);
		ui->PrintStation(current_station);
		ui->PrintPassengers(NPF, NPB, WPF, WPB, SPF, SPB);
		ui->PrintBuses(MBus, WBus);
		ui->PrintLine();
		ui->PrintFinishedPass(Finishing_list);
		timeIncremeter();
		Next_station();
		randomleave(NPF,NPB,WPF,WPB,SPF,SPB);
		output();
	}

}





	/*if (NPF.head->GetData().getAT() == (timerH * 60 + timerM))
	{
		ui->PrintPassengers(NPF, NPB, WPF, WPB, SPF, SPB);
		ui->PrintLine();
		ui->PrintFinishedPass(Finishing_list);
	}
	else
	{
		List<Passengers> NP;
		ui->PrintPassengers(NP, NPB, WPF, WPB, SPF, SPB);
		ui->PrintLine();
		ui->PrintFinishedPass(Finishing_list);
	}*/

