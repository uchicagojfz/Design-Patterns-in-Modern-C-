#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct IRat {
    virtual void enter(IRat* sender) = 0;
    virtual void leave(IRat* sender) = 0;
    virtual void notify(IRat* sender) = 0;
};


struct Game {
    vector<IRat*> rats;
    
    void enter(IRat* r) {
        for (IRat* rat : rats) {
            rat->enter(r);
        }
    }
    
    void leave(IRat* r) {
        for (IRat* rat : rats) {
            rat->leave(r);
        }
    }
    
    void notify(IRat* r) {
        for (IRat* rat : rats) {
            rat->notify(r);
        }
    }
};

struct Rat : IRat {
    Game& game;
    int attack{1};
    
    Rat(Game &game) : game(game) {
        game.rats.emplace_back(this);
        game.enter(this);
    }
    
    ~Rat() {
        game.leave(this);
        game.rats.erase(remove(game.rats.begin(),game.rats.end(), this));
    }
    
    void enter(IRat* sender) override {
        if(sender!=this) {
            attack++;
            game.notify(sender);
        }
    }
    
    void leave(IRat* sender) override {
        attack--;
    }
    
    void notify(IRat* sender) override {
        if(sender == this) {
            attack++;
        }
    }
};
