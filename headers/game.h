// game.h

#pragma once

#include <iostream>
#include <stack>

#include "devve.h" 

void createStack();

void showStack();

Devve popTopStack();
void push(const Devve& devve);
Devve topStack();

void changeStack();

void flipStacks();
