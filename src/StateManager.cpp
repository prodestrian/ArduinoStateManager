#include <Arduino.h>
#include "StateManager.h"

void StateManager::update()
{
    _currentMillis = millis();
    _hasChanged = false;
};

bool StateManager::set(int newState)
{
    return set(newState, false);
};

bool StateManager::set(int newState, bool force)
{
    if (is(newState) && !force)
    {
        // Current state is already the new state, and we are not forcing the change
        return false;
    }

    _changeState(newState);

    return true;
};

int StateManager::current()
{
    return _currentState;
};

int StateManager::previous()
{
    return _previousState;
};

bool StateManager::is(int state)
{
    return _currentState == state;
};

bool StateManager::was(int state)
{
    return _previousState == state;
};

bool StateManager::changed()
{
    return _hasChanged;
};

bool StateManager::changedFrom(int fromState)
{
    return changed() && was(fromState);
};

bool StateManager::changedTo(int toState)
{
    return changed() && is(toState);
};

bool StateManager::changedBetween(int fromState, int toState)
{
    return changed() && was(fromState) && is(toState);
};

int StateManager::currentDuration()
{
    return (int) (_currentMillis - _lastChanged);
};

void StateManager::_changeState(int state)
{
    _previousState = _currentState;
    _currentState = state;
    _lastChanged = _currentMillis;
    _hasChanged = true;
};
