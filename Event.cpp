#include "Event.h"

Event::Event()
{

}

void Event::set_Event_type(char e)
{
    event_type = e;
}
char Event::get_EventType()
{
    return(event_type);
}

int Event::convertToTimeStep(int hours, int minutes)
{
    int totalSeconds = hours * 3600 + minutes * 60;
    int timeStep = totalSeconds / 5; // Assuming each time step is 5 seconds

    return timeStep;
}
int Event::main() {
    int hours, minutes;
    std::cout << "Enter the time (in hours, minutes): ";
    std::cin >> hours >> minutes;

    int timeStep = convertToTimeStep(hours, minutes);

    std::cout << "The time step is: " << timeStep << std::endl;

    return(0);
}