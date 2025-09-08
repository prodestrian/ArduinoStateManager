#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class StateManager
{
public:
    void update();
    bool set(int newState);
    bool set(int newState, bool force);
    int current();
    int previous();
    bool is(int state);
    bool was(int state);
    bool changed();
    bool changedFrom(int fromState);
    bool changedTo(int toState);
    bool changedBetween(int fromState, int toState);
    int currentDuration();

private:
    void _changeState(int state);

    int _currentState;
    int _previousState;

    bool _hasChanged;

    unsigned long _currentMillis;
    unsigned long _lastChanged = 0;
};

#endif //STATEMANAGER_H
