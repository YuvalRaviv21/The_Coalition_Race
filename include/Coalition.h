#pragma once

#include <vector>
using std::vector;

class Coalition
{
public:
    Coalition(int coacoalitionMandateToAdd, int firstAgentToAdd,int idToAdd);//sometype of constructor
    void addAgent(int toAdd); //adding agent to coalition and updating mandates
    int getCoalitionIdC(); //returns id of this coalition
    int getCoalitionMandates() const;
    void AddMandatesToCoalition(int numberOfMandatesToAdd);
    vector<int> getAgentsInCoalition();    

private:
    vector<int> agentsInCoalition; //coalition's agents
    int coalitionId; //its ID 
    int coalitionMandate; //numbre of mandates this coalition has
    
};