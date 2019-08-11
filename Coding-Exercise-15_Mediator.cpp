#include <iostream>
#include <vector>
using namespace std;

struct IParticipant {
    virtual void send(IParticipant* p, int value) = 0;
};

struct Mediator {
    vector<IParticipant*> participants;
};

struct Participant : IParticipant
{
    int value{0};
    Mediator& mediator;
    
    Participant(Mediator &mediator) : mediator(mediator)
    {
        mediator.participants.push_back(this);
    }
    
    void send(IParticipant* p, int value) override
    {
        if(p != this) this->value += value;
    }
    
    void say(int value) {
        for (auto p :mediator.participants) {
            p->send(this, value);
        }
        return;
    }
};
