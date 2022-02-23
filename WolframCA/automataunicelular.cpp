#include "automataunicelular.h"

AutomataUnicelular::AutomataUnicelular(unsigned pRule, unsigned colonySize)
{
    size = colonySize;
    cells.resize(size);
    mask.resize(size);
    cleanAll();
    changeRule(pRule);
}

void AutomataUnicelular::changeRule(unsigned newRule)
{
    rule = newRule;
    ruleBook.resize(8);

    for (auto i=0; i<8; ++i){
        ruleBook[i] = (state)(newRule%2);
        newRule /= 2;
    }
}

unsigned AutomataUnicelular::getSize()
{
    return size;
}

void AutomataUnicelular::nextEpoch()
{
    // Cinta unidimensional (lazo cerrado/ "toroidal")
    for (auto i=0; i<size; ++i) {
        mask[i] = applyRule(cells[(i-1+size)%size], cells[i], cells[(i+1)%size]);
    }

    for (auto i=0; i<size; ++i) {
        cells[i] = mask[i];
    }
}

state AutomataUnicelular::applyRule(state first, state second, state third)
{
    unsigned index = first*4 + second*2 + third;
    return ruleBook[index];
}

state AutomataUnicelular::getState(unsigned index)
{
    return cells[index];
}

void AutomataUnicelular::switchState(int index)
{
    cells[index] = (state) (1- cells[index]);
}

void AutomataUnicelular::cleanAll()
{
    for (auto i=0; i<size; ++i)
        cells[i] = off;
}
