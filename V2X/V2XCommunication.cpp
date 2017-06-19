#include "V2XCommunication.h"
#include "ProtocolFactory.h"
#include "Protocol.h"
#include "DefaultProtocolFactory.h"
#include "Util.h"
#include "ProcessManagement.h"
#include "CommunicationNode.h"
#include "ChannelFactory.h"
#include "DefaultChannelFactory.h"
#include "Crowd.h"
#include "DefaultCrowd.h"
#include "CrowdFactory.h"
#include "DefaultCrowdFactory.h"
#include <sstream>

std::string V2XCommunication()
{
	//��ʼ��Э��ջ
	ProtocolFactory *f = new DefaultProtocolFactory();
	Protocol *protocol = (*f).CreateProtocol();

	//��ʼ�������ŵ�
	ChannelFactory *c = new DefaultChannelFactory();
	Channel *channel = (*c).CreateChannel();

	//��ʼ���ִع���
	CrowdFactory *cf = new DefaultCrowdFactory();
	Crowd *crowd = (*cf).CreateCrowd();

	//��ȡͨ�Žڵ�
	string comNodeStr;
	list<CommunicationNode> *comNode = getAllCommunicationNode(comNodeStr);

	//��ʼģ��
	ProcessManagement process;
	process.startSimulation(*comNode, *protocol, *channel, *crowd);

	//��ģ��֮��Ľ�������json��
	stringstream ss;
	string res = "";
	list<CommunicationNode>::iterator iter;
	bool flag = true;
	ss << "\"CommunicationNode\": " << "[";
	for (iter = (*comNode).begin(); iter != (*comNode).end(); iter++)
	{
		if (flag == true) {
			ss << communicationToJson(*iter);
			flag = false;
		}
		else {
			ss << ", " << communicationToJson(*iter);
		}
	}
	ss << "]}";
	ss >> res;
	return res;
}
