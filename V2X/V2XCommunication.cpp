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

	//��ģ��֮��Ľ������
	string res = "";
	list<CommunicationNode>::iterator iter;
	for (iter = (*comNode).begin(); iter != (*comNode).end(); iter++)
	{
		list<Message> recvList = *(*iter).getMessageToRecv();
		if (recvList.size() == 0) {
			continue;
		}
		else {
			if (iter == (*comNode).begin()) {
				res += "{\"CommunicationNode:\": [{\"ID\":";
			}
			else {
				res += ", {\"ID\":"; //ͨ�Žڵ�ID
			}
				res += (*iter).getNodeID();
				res += ",";
				res += "\"ReceiveMessage\": [ ";
				//ͨ�Žڵ��յ�����Ϣ
				list<Message>::iterator msgIter;
				for (msgIter = recvList.begin(); msgIter != recvList.end(); msgIter++) {

					if (msgIter != recvList.begin()) {
						res += ",";
					}
					res += "{\"MessageID\":";
					res += (*msgIter).getMessageID();
					res += ", \"sendID\": ";
					res += (*msgIter).getSourceAddress();
					res += ", \"size\": ";
					res += (*msgIter).getSize();
				}
				res += "]}";
		}
	}
	return res;
}
