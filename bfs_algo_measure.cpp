/*
Problem statement: Measure a target with given glasses. The glass capacities are also given.
Possible operations:
    FILL_GLASS1,
    FILL_GLASS2,
    EMPTY_GLASS1,
    EMPTY_GLASS2,
    TRANSFER_GLASS1_TO_GLASS2,
    TRANSFER_GLASS2_TO_GLASS1

Algorithm:

Terminology:
    State: Water available in each glass
    Node: Node contains "State" , "parent node", other parameters required for the algorithm.

Algo steps:

    Stage A: BFS traversal for reaching target
        1. Based on given operations, try generating new node from the previous node.
        2. Using BFS reach to the target. Queue and hash map are used for BFS implementation.
        3. Also keep pushing these new nodes(ids)in to a stack for showing final results.
        4. As BFS results may not give a sequential operations,
        using stack in next stage for actual path retrieval.

    Stag B: Print steps required for reaching the target
        1. Stage 1 stack contains all the visited nodes with parent node information.
        2. Stage 2 stack is used to extract the actual nodes which involved in reaching target
        from stage 1 stack.
        3. Print the steps involved using stage 2 stack.
*/


#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
using namespace std;



/********* User defined data types ***************/
/*
    Possible actions
*/
typedef enum Action
{
    INITIAL_STATE = 0,
    FILL_GLASS1,
    FILL_GLASS2,
    EMPTY_GLASS1,
    EMPTY_GLASS2,
    TRANSFER_GLASS1_TO_GLASS2,
    TRANSFER_GLASS2_TO_GLASS1,

}Action;

//For traversing through enum
#define FIRST_ACTION    FILL_GLASS1
#define LAST_ACTION     TRANSFER_GLASS2_TO_GLASS1

/*
    Node class which contains all the state information
*/
class Node
{
public:
    //state : water level in each glass
    int s1;
    int s2;
    //action
    Action action;
    //parent node id
    int parent_id;

    //constructor
    Node(int s1, int s2, Action act, int parent_id)
    {
        this->s1 = s1;
        this->s2 = s2;
        this->action = act;
        this->parent_id = parent_id;
    }
};


/************* Method declarations ******************/
/*
    Get current state from the node
    Inputs: current node
*/
pair<int, int> current_state(Node n);
/*
    Get next state given action and current state
    Inputs: current node, action, capacity
*/
void print_state( Node n);
/*
    Get next state given action and current state
    Inputs: current node, action, capacity
*/
pair<int, int> next_state(Node n, Action act, int c1, int c2);
/*
    Get next state given action and current state
    Inputs: current node, action, capacity
*/
pair<int, int> next_state(Node n, Action act, int c1, int c2);
/*
    Check if the target measurement is achieved
    Inputs: state, target
*/
int check_target(pair<int, int> state, int target);
/*
    Measure given target with given scales
    Inputs: capacity of each glass, target measurement
*/
void measure(int c1, int c2, int target);



/***** Method definitions ************************/

/*
    Get current state from the node
    Inputs: current node
*/
pair<int, int> current_state(Node n)
{
    return make_pair(n.s1, n.s2);
}

/*
    Get next state given action and current state
    Inputs: current node, action, capacity
*/
void print_state( Node n)
{
    string action_str;
    switch(n.action)
    {
    case INITIAL_STATE:
        action_str.assign("INITIAL_STATE");
        break;
    case FILL_GLASS1:
        action_str.assign("FILL_GLASS1");
        break;
    case FILL_GLASS2:
        action_str.assign("FILL_GLASS2");
        break;
    case EMPTY_GLASS1:
        action_str.assign("EMPTY_GLASS1");
        break;
    case EMPTY_GLASS2:
        action_str.assign("EMPTY_GLASS2");
        break;
    case TRANSFER_GLASS1_TO_GLASS2:
        action_str.assign("TRANSFER_GLASS1_TO_GLASS2");
        break;
    case TRANSFER_GLASS2_TO_GLASS1:
        action_str.assign("TRANSFER_GLASS2_TO_GLASS1");
        break;
    }

    cout << "g1 = " << n.s1 << " g2 = " << n.s2 << " action = " << action_str << endl;
}

/*
    Get next state given action and current state
    Inputs: current node, action, capacity
*/
pair<int, int> next_state(Node n, Action act, int c1, int c2)
{
    int next_s1 = n.s1;
    int next_s2 = n.s2;

    switch(act)
    {
    case INITIAL_STATE:
        break;
    case FILL_GLASS1:
        next_s1 = c1;
        break;
    case FILL_GLASS2:
        next_s2 = c2;
        break;
    case EMPTY_GLASS1:
        next_s1 = 0;
        break;
    case EMPTY_GLASS2:
        next_s2 = 0;
        break;
    case TRANSFER_GLASS1_TO_GLASS2:
        next_s2 += next_s1;
        next_s1 = 0;
        if(next_s2 > c2)
        {
            next_s1 = next_s2 - c2;
            next_s2 = c2;
        }
        break;
    case TRANSFER_GLASS2_TO_GLASS1:
        next_s1 += next_s2;
        next_s2 = 0;
        if(next_s1 > c1)
        {
            next_s2 = next_s1 - c1;
            next_s1 = c1;
        }
        break;
    }

    return make_pair(next_s1, next_s2);
}

/*
    Check if the target measurement is achieved
    Inputs: state, target
*/
int check_target(pair<int, int> state, int target)
{
    if(state.first == target && state.second == 0 ||
       state.first == 0 && state.second == target ||
       state.first + state.second == target)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*
    Measure given target with given scales
    Inputs: capacity of each glass, target measurement
*/
void measure(int c1, int c2, int target)
{
    /********* Boundary condition check **************/
    if((c1 < 0 || c2 < 0 || (c1 + c2 < target)) ||
       (c1 == 0 && c2 == 0 ))
    {
        cout << "Invalid inputs." << endl;
        return;
    }

    /********* Required data structures **************/

    //Vector : Memory for valid states
    vector<Node> v;
    //Queue : For keeping only new nodes(ids) for BFS
    queue <int> q;
    //Map/Dictionary : Hash map to check for new states
    map <pair<int, int>, int> m;
    //Stack 1 : For keeping all the visited nodes(ids)
    stack <int> stk1;
    //Stack 2 : For keeping nodes(ids) which form path form start to target node
    stack <int> stk2;

    /********* State 1: BFS algo for connecting valid nodes ***********/

    //To stop the BFS algo after reaching the target
    int flag_target_reached = 0;

    //Starting state : (0, 0)
    Node node = Node(0, 0, INITIAL_STATE, 0); //Current node
    pair<int, int> state = current_state(node); //Current node state
    int node_id = 0;

    //Push Root node in to queue to start BFS
    v.push_back(node);  node_id = v.size() -1;
    q.push(node_id);
    m[state] = 1;

    //Print initial state
    cout << "Measure target " << target << " with given scales : " << c1 << ", " << c2 << endl;
    cout << endl;
    print_state(v[node_id]);


    //BFS queue traversal
    while(!q.empty())
    {
        node_id = q.front();
        q.pop();

        //Get next possible state from the given action
        //Push valid states in to queue for further process

        for(int i = FIRST_ACTION; i <= LAST_ACTION; i++)
        {
            Action action = (Action)i;

            //Get next possible state
            state = next_state(v[node_id], action, c1, c2);

            //check whether the node is visited or not
            if(m[state] == 0)
            {
                m[state] = 1;

                //create new node and push in to the queue for new state
                Node new_node = Node(state.first, state.second, action, node_id);

                v.push_back(new_node);  node_id = v.size() -1;
                q.push(node_id);
                stk1.push(node_id);

                //check for target condition
                if(check_target(state, target))
                {
                    flag_target_reached = 1;
                    break;
                }
            }
        }
        if(flag_target_reached)
            break;
    }


    /******** Stage 2 : Printing state transition **********/

    if(!flag_target_reached)
    {
       cout << "Can not measure the target." << endl;
       return;
    }

    //In stack2, keep nodes which form target path

    //Target node
    node_id = stk1.top();
    stk1.pop();
    stk2.push(node_id);

    //For remaining nodes check for valid parent node
    while(!stk1.empty())
    {
        //Discard invalid target paths
        while(v[stk2.top()].parent_id != stk1.top())
        {
            if(stk1.empty())
                break; //transfer done

            stk1.pop();
        }
        //valid parent node
        stk2.push(stk1.top());
        stk1.pop();
    }

    //Print all the sates which form the target
    while(!stk2.empty())
    {
        node_id = stk2.top();
        print_state(v[node_id]);
        stk2.pop();
    }

    cout << endl << "Target reached !!" << endl;
}

/******** main function ***********/

int main()
{
    //Measure a target with given scales. inputs : c1, c2, target
    measure(3, 4, 6);

    return 0;
}

