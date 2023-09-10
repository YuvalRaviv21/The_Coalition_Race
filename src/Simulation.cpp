#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents),coalitions()
{
    // You can change the implementation of the constructor, but not the signature!
      
    //add and create all coalitions atttemps at the beggining by agents from mAgents into coalitions.
    for(Agent x: mAgents){
        Coalition c(mGraph.getMandates(x.getPartyId()),x.getId(),x.getId()); 
        coalitions.push_back(c);
    }
    
}

void Simulation::step()
{
    // TODO: implement this method
    for(Party& x : mGraph.getParties()){
        x.step(*this);
    }
        
    for(Agent& x: mAgents){
        x.step(*this);
    }
}




        
        
        

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    bool anyHas61 = false, noMoreAvailableParties = false;
    //go through all coalitions and see if one has 61 mandates
    for(int i = 0; (i < (int)coalitions.size()) & !anyHas61;i++){
        anyHas61 = coalitions.at(i).getCoalitionMandates() >= 61;
    }

    //go through all parties and see if there are any remaining non joined one
    if(!anyHas61){
        bool anyAvailableParty = false;
        for(int i = 0 ; (i < mGraph.getNumVertices()) & !anyAvailableParty ; i++){
            State s = getParty(i).getState();
            anyAvailableParty = s != Joined;
        }

        noMoreAvailableParties = !anyAvailableParty;
    }

    return noMoreAvailableParties || anyHas61;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> coals;
    int currId;
    vector<int> partiesInCoalition;
    for(Coalition c: coalitions){ 
        for(int agentId: c.getAgentsInCoalition()){ //going through coalition's agents and getting their partie's ID
            currId = mAgents.at(agentId).getPartyId();
            partiesInCoalition.push_back(currId); 
        }

        coals.push_back(partiesInCoalition);
        partiesInCoalition.clear();
    }

    return coals;
}



//be me

vector<Coalition>& Simulation::getCoalitions(){
    return coalitions;
}

vector<Agent>& Simulation::getAgentsNC(){
    return(mAgents);
}

Graph& Simulation::getGraphNC(){
    return(mGraph);
}
void Simulation::addNewAgent(Agent& toAdd){
    mAgents.push_back(toAdd);
}


void Simulation::addToCoalition(int idxCoalToAdd, int agentIdToAdd,int addedPartyMandates){
    Coalition& toAdd = coalitions.at(idxCoalToAdd);
    toAdd.addAgent(agentIdToAdd);
    toAdd.AddMandatesToCoalition(addedPartyMandates);
}
