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
void UI::PrintTime(Time T)
{
	cout << "Current Time (Hour:Min) ==> " << T.getHours() << ":" << T.getMin() << endl;
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

void UI::PrintPassengers(Queue<Passengers*> WNPFW, Queue<Passengers*> WNPBW, Queue<Passengers*> WWPFW, Queue<Passengers*> WWPBW, PriorityQueue<Passengers*> WSPFW,PriorityQueue<Passengers*> WSPBW)
{
	//Node<Passengers>* temp = SPF.getHead();
	//Node<Passengers>* t = SPB.getHead();
	Passengers* P;
	Queue<Passengers*> Lltfry8FW;
	Queue<Passengers*> Lltfry8BW;
	Passengers* PFW;
	cout << WSPFW.GetCount() + WSPBW.GetCount() << " Waiting SP: ";
	cout << "FWD[ ";
	while (WSPFW.Dequeue(P))
	{
		if (P->getSStaion() == CurrentStation) 
		{
			cout << P->getID();
			cout << "(" << P->getSPtyp() << ")";
			//Lltfry8FW.Enqueue(P);
		}
		else
		{
			cout << " ";
		}
	}
	/*while (!Lltfry8FW.IsEmpty())
	{
		Lltfry8FW.Dequeue(P);
		WSPFW.Enqueue(P, P->getPrio());
	}*/
	cout << "] BCK[";
	/*while(!WSPBW.IsEmpty())
	{
		if (WSPBW.Peek(P))
		{
			if (P->getSStaion() == CurrentStation)
			{
				cout << P->getID();
				cout << "(" << P->getSPtyp() << ")";
				WSPBW.Dequeue(P);
				Lltfry8BW.Enqueue(P);
			}
			else
			{
				WSPBW.Dequeue(P);
				Lltfry8BW.Enqueue(P);
			}
		}
	}
	while (!Lltfry8BW.IsEmpty())
	{
		Lltfry8BW.Dequeue(P);
		WSPBW.Enqueue(P,P->getPrio());
	}*/
	while (WSPBW.Dequeue(P))
	{
		if (P->getSStaion() == CurrentStation) 
		{
			cout << P->getID();
			cout << "(" << P->getSPtyp() << ")";
			//Lltfry8BW.Enqueue(P);
		}
		else
		{
			cout << " ";
		}
	}
	//while (!Lltfry8BW.IsEmpty())
	//{
	//	Lltfry8BW.Dequeue(P);
	//	WSPBW.Enqueue(P, P->getPrio());
	//}
	cout << " ]" << endl;
	cout << endl;
	cout << WWPFW.GetSize() + WWPBW.GetSize() << " Waiting WP: FWD[";

	while (WWPFW.Dequeue(P))
	{
		if (P->getSStaion() == CurrentStation)
		{
			cout << P->getID();
			//WWPFW.Display();
		}
		else 
		{
			cout << " ";
		}
	}
	cout << "] BCK[";
	if (!WWPBW.IsEmpty())
	{
		while (WWPBW.Dequeue(P))
		{
			if (P->getSStaion() == CurrentStation)
			{
				cout << P->getID();
				//WWPBW.Display();
			}
			else
			{
				cout << " ";
			}
		}
	}
	else
	{
		cout << " ";
	}
	cout << "]" << endl;
	cout << endl;
	cout << WNPFW.GetSize() + WNPBW.GetSize() << " Waiting NP: FWD[";
	while (WNPFW.Dequeue(P))
	{
		if (P->getSStaion() == CurrentStation)
		{
			cout << P->getID();
			//WNPFW.Display();
		}
		else
		{
			cout << " ";
		}
	}
	cout << "] BCK[";
	while (WNPBW.Dequeue(P))
	{
		if (P->getSStaion() == CurrentStation)
		{
			cout << P->getID();
			//WNPBW.Display();
		}
		else
		{
			cout << " ";
		}
	}
	cout << "]" << endl;
	cout << endl;

}
void UI::PrintFinishedPass(Queue<Passengers*> Completed)
{
	cout << Completed.GetSize() << " Finished Passengers: ";
	Completed.Display();
	cout << endl;
	cout << "Press any key to display next station" << endl;
	cin.get();
	


}
void UI::InteractiveMode()
{

	//PrintTime();
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