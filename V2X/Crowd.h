#pragma once
#include <list>
#include "CommunicationNode.h"

/*�ִظ���*/
class Crowd {
public:
	Crowd() {};
	virtual std::list<std::list<CommunicationNode>>* getCrowds(std::list<CommunicationNode> communicationNode) = 0;
};