//Include guards
//Define a node in GP Tree
#ifndef GP_NODE_H
#define GP_NODE_H


struct GP_Node
{
    long double val; // Value of the node
    GP_Node *l, *r; // Left, right child
    int t; // t < 0 : terminal, t > 0: operator 
    GP_Node ()
    {
        l = nullptr;
        r = nullptr;
        val = 0;
        t = -1;
    }
};

// Define operators for the GP Node in GP tree
long double sum(GP_Node &a, GP_Node &b)
{
    return a.val + b.val;
}
long double dif(GP_Node &a, GP_Node &b)
{
    return a.val - b.val;
}
long double divide(GP_Node &a, GP_Node &b)
{
    if (b.val == 0)
    {
        return a.val;
    }
    return a.val / b.val;
}
long double mul (GP_Node &a, GP_Node &b)
{
    return a.val * b.val;
}

long double Max(GP_Node &a, GP_Node &b)
{
    return a.val > b.val ? a.val : b.val;
}

long double Min(GP_Node &a, GP_Node &b)
{
    return a.val < b.val ? a.val : b.val;
}

// Convert those functions into array (For crossover and mutating)

long double (*OperatorList[])(GP_Node &, GP_Node &)= {sum, dif, divide, mul, Max, Min};
void link(GP_Node &p, GP_Node &a, GP_Node &b)
{
    p.l = &a;
    p.r = &b;
}

#endif