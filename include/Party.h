#pragma once
#include <string>

using std::string;

//ours------------
#include <vector>
using std::vector;
class Agent;
//--------------

class Simulation;
class JoinPolicy;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;

    //--------rule of five-----------
    
    Party(const Party& other); //copy constructor
    ~Party(); //destructor
    Party& operator=(const Party& other); //copy assignment operator
    Party(Party&& other); //move constructor
    Party& operator=(Party&& other); //move assignment operator

    //-------------------------------
    
    // our funcs
    bool OffersIsEmpty();
    //Party();
    //void addOffer(Agent* toAdd);
    void addOffer(int idToAdd);
    const int getId();
    //vector<Agent*> getOffersUs() const;
    vector<int> getOffersUs() const;
    const int getTimer();
    void updateTimer();
    //bool coalitionOfferExist(int coalitionId);


private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;

    // our vars;
    int timer;
    //vector<Agent*> offers;
    vector<int> offers; //holds agentId
};