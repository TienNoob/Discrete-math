//Define Terminals for leaves in tree


//Include guards
#ifndef TERMINAL_SET_H
#define TERMINAL_SET_H


#include "problem.h"

//Machines Related
long double NIQ(Machine &m, Job &j)
{
    return 1;
}

long double WIQ(Machine &m, Job &j)
{
    return 1;
}

long double MWT(Machine &m, Job &j)
{
    return 1;
}
long double PT(Machine &m, Job &j)
{
    return 1;
}

//Job related
long double NPT(Machine &m, Job &j)
{
    return 1;
}
long double OWT(Machine &m, Job &j)
{
    return 1;
}
long double WKR(Machine &m, Job &j)
{
    return 1;
}
long double NOR(Machine &m, Job &j)
{
    return 1;
}

//Convert these terminals into array
long double (*TerminalSet[]) (Machine &, Job &) = {NIQ, WIQ, MWT, PT, NPT, OWT, WKR, NOR};


#endif