#include "Coalition.h"

Coalition::Coalition(int coacoalitionMandateToAdd, int firstAgentToAdd, int idToAdd):agentsInCoalition(),coalitionId(idToAdd),coalitionMandate(coacoalitionMandateToAdd) /*,numParties(1)*/
{
    agentsInCoalition.push_back(firstAgentToAdd); //adding first agent into the vector
}

vector<int> Coalition::getAgentsInCoalition(){
    return(agentsInCoalition);
}


void Coalition::addAgent(int toAdd){
    agentsInCoalition.push_back(toAdd);
}
    
int Coalition::getCoalitionIdC(){
    return(coalitionId);
} 

int Coalition::getCoalitionMandates()const {
    return(coalitionMandate);
}

void Coalition::AddMandatesToCoalition(int numberOfMandatesToAdd){
    coalitionMandate += numberOfMandatesToAdd;
}


