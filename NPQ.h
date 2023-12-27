#pragma once
#include "Queue.h"
template <class T>
class NPQ : public Queue<T>
{
private:
    bool flag 
public:
	NPQ();
	~NPQ();

  /*  bool Station::removePassengerByID(Queue<Passengers*>& p, int id)
    {
        bool flag = false;
        Queue<Passengers*> temp;
        Passengers* x = nullptr;
        while (!p.isempty()) {
            p.dequeue(x);
            if (x->getID() != id) {
                temp.enqueue(x);
            }
            flag = x->getID() == id;
        }
        while (!temp.isempty()) {
            temp.dequeue(x);
            p.enqueue(x);
        }
        return flag;
    }*/




};


