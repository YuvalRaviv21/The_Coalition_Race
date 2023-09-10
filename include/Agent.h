#pragma once

//#include <vector>
//#include "Graph.h"

class SelectionPolicy;

//---------added be me------
#include "Simulation.h"
//#include "Coalition.h"

//--------------------------

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    
    //--------rule of five-----------
    Agent(const Agent& other); //copy constructor
    ~Agent(); //destructor
    Agent& operator=(const Agent &other); //copy assigh operator
    Agent(Agent&& other); //move constructor
    Agent& operator=(Agent&& other); // move assigh operator

    //-------------------------------

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    //my func
    const int getCoalitionId() const;

    //seters
    void setCopyIDS(int id,int party_id,int coalition);
    //int getCoalitionMandates(); 

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    //the coalition that the agent represents
    int coalitionId;
};
