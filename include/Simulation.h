#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"
//--------BY ME----------
#include "Coalition.h"
//-----------------------

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;

    //added by me
    Graph& getGraphNC();
    vector<Agent>& getAgentsNC();
    vector<Coalition>& getCoalitions();
    void addNewAgent(Agent& toAdd);
    void addToCoalition(int idxCoalToAdd, int agentIdToAdd,int addedPartyMandates);


private:
    Graph mGraph;
    vector<Agent> mAgents;

    //added by me
    vector<Coalition> coalitions;
   

};
