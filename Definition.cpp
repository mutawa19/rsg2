#include "Definition.h"

// the default constructor
Definition::Definition() {
    // always start with a state that is waiting for curly brace
    this->state = WAITING_FOR_START;
}

// accept a string as a possibility and add it to the list
void Definition::addTerminal(string text) {
    this->terminals.push_back(util::trim(text));
}

// accessor method for name property
string Definition::getName() {
    return this->name;
}

int Definition::getTerminalCount() {
  return this->terminals.size();
}
string Definition::getTerminal(int j) {
  return this->terminals[j];
}


string Definition::getRandomTerminal() {
    // get a random index between 0 and the current number of possibilities
    // random() is defined in util.cpp
    int randomIndex = util::random(terminals.size()-1);

    // return the possibility at that random index
    return terminals[randomIndex];
}


// definitions of methods that read and modify the state
bool Definition::isWaitingToStart() {
    return this->state == WAITING_FOR_START;
}
void Definition::start() {
    // only change the state after validating the previous state
    if(this->state == WAITING_FOR_START) {
        this->state = WAITING_FOR_NAME;
    }
}

bool Definition::isWaitingForName() {
    return this->state == WAITING_FOR_NAME;
}

void Definition::setName(string name) {
    // validate previoud state before chaning
    if(this->state == WAITING_FOR_NAME) {
        this->name = name; this->state = WAITING_FOR_TERMINALS;
    }

}

bool Definition::isWaitingForTerminals() {
    return this->state == WAITING_FOR_TERMINALS;
}

bool Definition::isEnded() {
    return this->state == ENDED;
}

void Definition::end() {
    // always validate previoud state
    if(this->state == WAITING_FOR_TERMINALS) {
        this->state = ENDED;
    }
}
