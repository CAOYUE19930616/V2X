#pragma once
#include "ChannelFactory.h"
#include "DefaultChannel.h"
/*
*����Ĭ��Э��ջ�Ĺ���
*/
class DefaultChannelFactory : public ChannelFactory {
public:
	Channel* CreateChannel() { return new DefaultChannel(); }
};