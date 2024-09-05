#//Include guards
#ifndef PROBLEM_H
#define PROBLEM_H


#include <vector>
#define vector std::vector // Less typing std
#define pair std::pair
struct Operation
{
    vector<int> candidate_machine;
    vector<int> Time;
};
struct Job
{
    vector<Operation> O;
};
struct Machine
{
    vector<pair<int, int> > Queue; // Running Queue
};

#endif