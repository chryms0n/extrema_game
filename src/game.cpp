#include "game.h"

std::stack<Devve> devveStack;
std::stack<Devve> backup;

void createStack()
{
    for (int i = 0; i <= 5; i++)
    {
        devveStack.push(Devve(i));
    }
}

void showStack()
{
    while (!devveStack.empty())
    {
        Devve tempDevve = popTopStack();
        std::cout << tempDevve.getId() << "   ";
        backup.push(tempDevve);

    }
    std::cout << std::endl;
    flipStacks();
}

void push(const Devve& devve)
{
    devveStack.push(devve);
}

Devve popTopStack()
{
    Devve tempDevve = devveStack.top();
    devveStack.pop();
    return tempDevve;
}

Devve topStack()
{
    return devveStack.top();
}

void changeStack()
{
    devveStack.top().setId(9);
}

void flipStacks()
{
    if (devveStack.empty())
    {
        devveStack = backup;
        backup = std::stack<Devve>();
    }
}
