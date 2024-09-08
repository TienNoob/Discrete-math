#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r)
{
    int t = rd();
    t = abs(t);
    return l + (t % (r - l + 1));
}
//Include guards
#ifndef GP_TREE_H
#define GP_TREE_H


#include "GP_Node.h"
#include "terminal_set.h"


struct GP_Tree
{       
    // Tree used for sequencing rule and routing rule
    GP_Node rule;
    int sz = 1;
    void cal(GP_Node &cur, Machine &m, Job &j)
    {   
        int t = cur.t; // Type of the node
                       // < 0 : leaf -> Terminal Set;
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
        cal(rule, m, j);
    }
};

GP_Node *Get_At_Preorder(GP_Node &cur_node, int &k)
{   
    --k;
    if (k == 0)
    {
        return &cur_node;
    }
    if (cur_node.l != nullptr)
    {
        GP_Node *ret = Get_At_Preorder(*cur_node.l, k);
        if (ret != nullptr)
        {
            return ret;
        }
    }
    if (cur_node.r != nullptr)
    {
        GP_Node *ret = Get_At_Preorder(*cur_node.r, k);
        if (ret != nullptr)
        {
            return ret;
        }
    }
    return nullptr;
}
void GP_Swapping_Crossover(GP_Tree &a, GP_Tree &b) // Pick 2 random node of 2 trees, swap them
{   
    int t = Rand(1, a.sz);
    GP_Node *random_child_a = Get_At_Preorder(a.rule, t);

    t = Rand(1, b.sz);
    GP_Node *random_child_b = Get_At_Preorder(b.rule, t);

    swap(random_child_a, random_child_b);
}
struct DFJSS_Tree
{   
    // Sequencing rule and Routing rule
    GP_Tree seq, route;
};

void DFJSS_Tree_Swapping_Crossover(DFJSS_Tree &a, DFJSS_Tree&b, vector<DFJSS_Tree> &storage) // Operator described in the paper
{
    int t = Rand(0, 1);
    DFJSS_Tree offspring_1 = a, offspring_2 = b;
    if (t == 0)
    {
        swap(offspring_1.seq, offspring_2.seq);
        GP_Swapping_Crossover(offspring_1.route, offspring_2.route);
    }
    else 
    {
        swap(offspring_1.route, offspring_2.route);
        GP_Swapping_Crossover(offspring_1.seq, offspring_2.seq);
    }
    storage.push_back(offspring_1);
    storage.push_back(offspring_2);
}


#endif