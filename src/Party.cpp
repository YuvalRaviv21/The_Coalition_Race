#include "Party.h"
#include "JoinPolicy.h"
class JoinPolicy;
//Party::Party():mId(0), mName(0), mMandates(0),mJoinPolicy(nullptr), mState(Waiting) ,timer(0),offers(){};// why?????????????????????
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) ,timer(0),offers()
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    // TODO: implement this method
    if(mState == CollectingOffers)
    {
        updateTimer();
        if(getTimer() == 3)
        {
            
            int joinAIndx = mJoinPolicy->join(offers,s);
            Agent &toJoin = s.getAgentsNC().at(joinAIndx); 
            mState = Joined;
            // implementation of copy agent.
            int agentID = s.getAgents().size(); 
            Agent copyAgent(toJoin);
            s.addToCoalition(toJoin.getCoalitionId(),agentID,mMandates);// updating original coalition's field
            copyAgent.setCopyIDS(agentID,mId,toJoin.getCoalitionId());
            s.addNewAgent(copyAgent);
            
        }
    }
}

//added by us


Party::Party(const Party& other):mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(nullptr), mState(other.mState) ,timer(other.timer),offers(){ 
    for(int x:other.getOffersUs()){
        offers.push_back(x);
    }
    mJoinPolicy = other.mJoinPolicy->copyValue();
}

Party::Party(Party&& other):mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState) ,timer(other.timer),offers(other.offers){ 
    other.mJoinPolicy = nullptr;
}

Party& Party::operator=(Party&& other){
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    timer = other.timer;
    offers.clear();
    for(int x:other.getOffersUs()){
        offers.push_back(x);
    }

    if(mJoinPolicy) delete mJoinPolicy;
    mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
    return(*this);
}

Party& Party::operator=(const Party& other)
{
    if (this != &other){
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mState = other.mState;
        timer = other.timer;
        offers.clear();
        for(int x:other.getOffersUs()){
            offers.push_back(x);
        }
        
        if(mJoinPolicy) delete mJoinPolicy;
        mJoinPolicy = other.mJoinPolicy->copyValue();
    }
    return(*this);
}

Party::~Party(){
    if(mJoinPolicy){
        delete mJoinPolicy;

    }
}

void Party::addOffer(int IdToAdd){
    mState = CollectingOffers;
    offers.push_back(IdToAdd);
}

const int Party::getTimer()
{
    return timer;
}

void Party::updateTimer()
{
    timer++;
}

vector<int> Party::getOffersUs() const{
    return offers;
}

bool Party::OffersIsEmpty(){
    return(offers.empty());
}