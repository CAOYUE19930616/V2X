#pragma once
#include "Channel.h"
/*
*Э��ջ��������
*/
class ChannelFactory {
public:
	virtual Channel* CreateChannel() = 0;
};