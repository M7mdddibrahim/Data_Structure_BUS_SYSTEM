#pragma once
#include "Queue.h"
#include "Passengers.h"
template <class T>
class NPQ : public Queue<T>
{
private:
    bool flag;
    int id;
    Passengers p;
public:
    NPQ()
    {
    }
	~NPQ()
    {
    }

    // Remove passenger from a generic queue using ID
    bool removePassengerUsingID(Queue<Passengers*>& p, int id)
    {
        bool flag = false;

        Queue<Passengers*>temp;
        Passengers* x = nullptr;
        while (!p.IsEmpty()) {
            p.Dequeue(x);
            if (x->getID() != id) {
                temp.Enqueue(x);
            }
            flag = x->getID() == id;
        }
        while (!temp.IsEmpty()) {
            temp.Dequeue(x);
            p.Enqueue(x);
        }
        return flag;
    }



};


