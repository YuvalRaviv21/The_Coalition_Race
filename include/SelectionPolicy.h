#pragma once
#include "Simulation.h" //i added to avoid bugs
#include "Party.h"

class SelectionPolicy{
    public:
        SelectionPolicy(string type);
        virtual int select(int agent_party_ID,int agentCoalitionID,Simulation &sim) = 0;
        virtual ~SelectionPolicy() = default;
        virtual SelectionPolicy* copyValue();
        string _type;
    private:
};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        virtual int select(int agent_party_ID,int agentCoalitionID,Simulation &sim);
        virtual SelectionPolicy* copyValue();
    private:
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        EdgeWeightSelectionPolicy();
        virtual int select(int agent_party_ID,int agentCoalitionID,Simulation &sim);
        virtual SelectionPolicy* copyValue();
    private:
};