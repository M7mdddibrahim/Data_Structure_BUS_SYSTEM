#include "UI.h"


UI::UI()
{

}
void UI::ChoosingMode(int x)
{
	if (x == 1)
	{
		InteractiveMode();
	}
	else if (x == 2)
	{
		SilentMode();
	}
}

void UI::RunningProgram()
{
	int x = 0;   // For Choosing the Modes
	int y = 1;   // For Runinng the Program
	cout << "Welcome to the Bus Company " << endl;
	while (y == 1)
	{
		cout << "Choose Mode: " << endl << "1) Interactive Mode " << endl << "2) Silent Mode " << endl;
		cin >> x;
		while ((x != 1) && (x != 2))
		{
			cout << "Please enter a valid number: ";
			cin >> x;
		}
		ChoosingMode(x);
		/*cout << "Do you want to run the program again? " << endl << "Enter 1 for yes && 0 for no" << endl;
		cin >> y;
		while ((y != 0) || (y != 1))
		{
			cout << "Please enter a valid number: ";
			cin >> y;
		}
		system("CLS");
		if (y == 1)
		{
			RunningProgram();
		}
		else if (y == 0)
		{
			cout << "Thank you for using our program, Good Bye" << endl;
			break;
		}*/
	}
}
void UI::PrintTime(int hour, int min)
{
	cout << "Current Time (Hour:Min) ==> " << hour << ":" << min << endl;
}
void UI::PrintBuses(List<Buses> MBus, List<Buses>WBus)
{
	cout << MBus.getCount() + WBus.getCount() << " Buses at this Station" << endl;

	//	//int TNB = BS.Get_TotalNumberofBuses();
	//	cout << TNB << " Buses at this Station: " << endl;
	//	/*int n;
	//	if (BS.Getbustype() == WBUS)
	//	{
	//		n = BS.Get_Wheel_Bus_Capacity();
	//	}
	//	else if (BS.Getbustype() == MBUS)
	//	{
	//		n = BS.Get_Mixed_Bus_Capacity();
	//	}
	//	cout << "B " << BS.GetID() << "[ " << BS.GetBusDirection() << " , " << BS.Getbustype() << " , " << n << " ] " << " { ";*/
}
void UI::PrintLine()
{
	cout << "----------------------------------" << endl;
}
void UI::PrintStation(int station)
{
	cout << "==============  STATION " << station << " ============== " << endl;
	CurrentStation = station;
}
int UI::getStation()
{
	return CurrentStation;
}

void UI::PrintPassengers(List<Passengers> NPF, List<Passengers> NPB, List<Passengers> WPF, List<Passengers> WPB, List<Passengers> SPF, List<Passengers> SPB)
{
	Node<Passengers>* temp = SPF.getHead();
	Node<Passengers>* t = SPB.getHead();
	cout << SPF.getCount() + SPB.getCount() << " Waiting SP: ";
	cout << "FWD[ ";
	for (int i = 0; i < SPF.getCount(); i++)
	{
		if (temp->GetData().getSStaion() == CurrentStation)
		{
			cout << temp->GetData();
			cout << "(" << temp->GetData().getSPtyp() << ")";
			if (temp->GetNext())
				cout << " , ";
		}
		temp = temp->GetNext();
	}
	cout << "] BCK[";
	for (int i = 0; i < SPB.getCount(); i++)
	{
		if (t->GetData().getSStaion() == CurrentStation)
		{
			cout << t->GetData();
			cout << "(" << t->GetData().getSPtyp() << ")";
			if (t->GetNext())
				cout << " , ";
		}
		t = t->GetNext();
	}
	cout << "]" << endl;
	cout << endl;
	cout << WPF.getCount() + WPB.getCount() << " Waiting WP: FWD[";
	WPF.Print();
	cout << "] BCK[";
	WPB.Print();
	cout << "]" << endl;
	cout << endl;
	cout << NPF.getCount() + NPB.getCount() << " Waiting NP: FWD[";
	NPF.Print();
	cout << "] BCK[";
	NPB.Print();
	cout << "]" << endl;
	cout << endl;

}
void UI::PrintFinishedPass(List<Passengers> Finishing_list)
{
	cout << Finishing_list.getCount() << " Finished Passengers: ";
	Finishing_list.Print();
	cout << endl;
	cout << "Press any key to display next station" << endl;
	int getch();
	


}
void UI::InteractiveMode()
{

	PrintTime(0, 0);
	PrintStation(0);
	//PrintPassengers();
	//PrintBuses();
	PrintLine();
	//PrintFinishedPass();
	cout << "Press any key to display next station " << endl;
	//getch();

}
void UI::SilentMode()
{
	cout << "Silent Mode" << endl;
	cout << "Simulation Starts... " << endl;
	cout << "Simulation ends, Output file created " << endl;
}
