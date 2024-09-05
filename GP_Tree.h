#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());


//Include guards
#ifndef GP_TREE_H
#define GP_TREE_H


#include "GP_Node.h"
#include "terminal_set.h"


struct GP_Tree
{       
    // root SEQUENCING RULE, 2 : ROUTING RULE;
    GP_Node *seq = new GP_Node;
    GP_Node *route = new GP_Node;
    void cal(GP_Node &cur, Machine &m, Job &j)
    {   
        int t = cur.t; // Type of the node
                       // < 0 : leaf;
                       // > 0 : Operator 
                       // |t| : type of the data
        if (cur.t < 0)
        {   
            t = -t - 1;
            cur.val = TerminalSet[t](m, j);
            return ;
        }
        else 
        {
            cal(* cur.l, m, j); // Calculate 2 children
            cal(* cur.r, m, j);
            t -= 1;
            cur.val = OperatorList[t](*cur.l, *cur.r);
            return ;
        }
    }
    void evaluate(Machine &m, Job &j)
    {
        cal(*seq, m, j);
        cal(*route, m, j);
    }
};
// Define Genetic Programming operators here

void crossover(GP_Tree &a, GP_Tree &b, vector<GP_Tree> & storage)
{
    
}

#endif