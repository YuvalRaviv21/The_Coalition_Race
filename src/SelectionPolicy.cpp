#include "SelectionPolicy.h"

SelectionPolicy::SelectionPolicy(string type):_type(type){}
SelectionPolicy* SelectionPolicy::copyValue(){return nullptr;};

MandatesSelectionPolicy::MandatesSelectionPolicy():SelectionPolicy("mandate"){}
SelectionPolicy* MandatesSelectionPolicy::copyValue(){return new MandatesSelectionPolicy();};

int MandatesSelectionPolicy::select(int agent_party_ID,int agentCoalitionID,Simulation &sim){
    
    int weight;
    bool offerAlreadyExists = false;
    int partyMandates,maxPartyMandates = 0,partyIndex = -1,aId;
    Graph thisGraph = sim.getGraph();

    for(int i = 0; i < thisGraph.getNumVertices();i++){
        
        if(agent_party_ID != i){ //no edge between same party
            weight = thisGraph.getEdgeWeight(agent_party_ID,i);
            
            if((weight != 0) & (sim.getParty(i).getState() != Joined) ){ //making sure they are neighbors and in correct state
                partyMandates = 0;
                for(int j = 0; (j < (int)sim.getParty(i).getOffersUs().size()) & !offerAlreadyExists;j++){ //going through all offers made to the party
                    aId = sim.getParty(i).getOffersUs().at(j); //ID of current agent
                    offerAlreadyExists = agentCoalitionID == sim.getAgentsNC().at(aId).getCoalitionId(); 
                }
                
                if(!offerAlreadyExists){ //case no offer was made from the agent's coalition

                    partyMandates = thisGraph.getMandates(i);
                    if(partyMandates > maxPartyMandates){
                        maxPartyMandates = partyMandates;
                        partyIndex = i;
                        
                    }

                }
                offerAlreadyExists = false;
                
            }
        }
    }
    return(partyIndex);
}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy():SelectionPolicy("edge weight"){};
SelectionPolicy* EdgeWeightSelectionPolicy::copyValue(){return new EdgeWeightSelectionPolicy();};
int EdgeWeightSelectionPolicy::select(int agent_party_ID,int agentCoalitionID, Simulation &sim){
    
    
    int weight;
    bool offerAlreadyExists = false;
    int maxPartyMandates = 0,partyIndex = -1,aId;
    Graph thisGraph = sim.getGraph();

    for(int i = 0; i < thisGraph.getNumVertices();i++){
        
        if(agent_party_ID != i){ //no edge between same party
            weight = thisGraph.getEdgeWeight(agent_party_ID,i);
            
            if((weight != 0) & (sim.getParty(i).getState() != Joined)  ){ //making sure they are neighbors and in correct state
               
                for(int j = 0; (j < (int)sim.getParty(i).getOffersUs().size()) & !offerAlreadyExists;j++){ //going through all offers made to the party
                    aId = sim.getParty(i).getOffersUs().at(j);
                    offerAlreadyExists = agentCoalitionID == sim.getAgentsNC().at(aId).getCoalitionId(); 
                }
                
                if(!offerAlreadyExists){ //case no offer was made from the agent's coalition

                    if(weight > maxPartyMandates){
                        maxPartyMandates = weight;
                        partyIndex = i;
                        
                    }

                }
                offerAlreadyExists = false;
                
            }
        }
    }
    return(partyIndex);

}