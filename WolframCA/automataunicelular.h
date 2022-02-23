#ifndef AUTOMATAUNICELULAR_H
#define AUTOMATAUNICELULAR_H
#include <vector>
#include <iostream>

using namespace std;

enum state { off=0, on=1 };

class AutomataUnicelular
{
public:
    AutomataUnicelular(unsigned pRule=110, unsigned colonySize=100);
    void changeRule(unsigned newRule);
    unsigned getSize();

    void nextEpoch();
    state applyRule(state first, state second, state third);

    state getState(unsigned index);
    void switchState(int index);
    void cleanAll();

private:
    unsigned size, rule;
    vector<state> cells;
    vector<state> mask;
    vector<state> ruleBook;
};

#endif // AUTOMATAUNICELULAR_H
