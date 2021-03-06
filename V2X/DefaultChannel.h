#pragma once
#include "constUtil.h"
#include "SliceMessage.h"
#include "CommunicationNode.h"
#include "Channel.h"
#include "windows.h"
#include <list>

/*
 *默认物理信道
*/
class DefaultChannel : public Channel
{
public:
	//构造函数
	DefaultChannel();

	//误码模拟
	void bitSimulation(SliceMessage &sMsg);
	//时延模拟
	void delaySimulation(SliceMessage &sMsg, int index, std::list<CommunicationNode> communicationNodes, int simulation_count);
	

private:
	//所有信道数
	int totleCount = CHANNEL_COUNT;
	//当前被占用的信道数
	int busyCount;
};