/*#pragma once
class JoinPolicy {};
class MandatesJoinPolicy : public JoinPolicy {};
class LastOfferJoinPolicy : public JoinPolicy {};
*/

#pragma once
#include "Agent.h"

using std::vector;

class JoinPolicy {
    public:
        JoinPolicy(string type);
        virtual int join(vector<int> &offers,Simulation &s)=0;
        virtual ~JoinPolicy() = default;
        virtual JoinPolicy* copyValue();
        string _type;
    private:
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        MandatesJoinPolicy();
        virtual int join(vector<int> &offers,Simulation &s);
        virtual JoinPolicy* copyValue();
    private:
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        LastOfferJoinPolicy();
        virtual int join(vector<int> &offers,Simulation &s);
        virtual JoinPolicy* copyValue();
        
    private:
};