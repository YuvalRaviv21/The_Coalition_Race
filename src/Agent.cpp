#include "Agent.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),coalitionId(agentId)
{

    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    //SEND relevantNeighbors TO SELECTION POLICY FOR IT TO select PARTY
    int chosenPartyIndex = mSelectionPolicy->select(mPartyId,coalitionId,sim);
    
    if(chosenPartyIndex != -1){ //agent adding its adress to the party's offers list
        Party* selectedP = &(sim.getGraphNC().getParties().at(chosenPartyIndex));
        selectedP->addOffer(mAgentId); //adding the original agent to the offers list
    }

}

//added by me
void Agent::setCopyIDS(int id,int party_id,int coalition){
    mAgentId = id;
    mPartyId = party_id;
    coalitionId = coalition;
}


const int Agent::getCoalitionId() const{
    return(coalitionId);
}


Agent::Agent(const Agent& other): mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(nullptr),coalitionId(other.coalitionId){
    mSelectionPolicy = other.mSelectionPolicy->copyValue();
}

Agent::Agent(Agent&& other):mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy),coalitionId(other.coalitionId){
    other.mSelectionPolicy = nullptr;
}

Agent::~Agent(){
    if(mSelectionPolicy){
        delete mSelectionPolicy;
    }

}

Agent& Agent::operator=(const Agent& other){
    if(this != &other){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        coalitionId = other.coalitionId;

        if(mSelectionPolicy) delete mSelectionPolicy;
        mSelectionPolicy = other.mSelectionPolicy->copyValue();
    }
    return(*this);
}

Agent& Agent::operator=( Agent&& other){
    if(mSelectionPolicy) delete mSelectionPolicy;
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    coalitionId = other.coalitionId;

    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    return(*this);
}
