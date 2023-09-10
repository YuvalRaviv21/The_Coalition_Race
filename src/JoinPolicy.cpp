#include "JoinPolicy.h"
JoinPolicy::JoinPolicy(string type): _type(type){}
JoinPolicy* JoinPolicy::copyValue(){return nullptr;};

MandatesJoinPolicy ::MandatesJoinPolicy(): JoinPolicy("mandate") {}
JoinPolicy* MandatesJoinPolicy::copyValue(){return new MandatesJoinPolicy();};

int MandatesJoinPolicy::join(vector<int> &offers,Simulation &s){
    int currAgentId = offers[0];
    int agentCoalitionId = (s.getAgents()[currAgentId]).getCoalitionId();
    int coalitionMandate = s.getCoalitions()[agentCoalitionId].getCoalitionMandates();
    for(int a: offers){
         int tmpAgentCoalitionId = (s.getAgents()[a]).getCoalitionId();
        int tmpCoalitionMandate = s.getCoalitions()[tmpAgentCoalitionId].getCoalitionMandates();
        if(tmpCoalitionMandate > coalitionMandate){
            coalitionMandate = tmpCoalitionMandate;
            currAgentId = a;
        }
    }
    return currAgentId;
}

LastOfferJoinPolicy :: LastOfferJoinPolicy():JoinPolicy("offer"){}
JoinPolicy* LastOfferJoinPolicy::copyValue(){return new LastOfferJoinPolicy();};
int LastOfferJoinPolicy::join(vector<int> &offers,Simulation &s){
    return (offers[offers.size()-1]);
}