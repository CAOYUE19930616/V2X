#include "Util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "constUtil.h"

using namespace std;

void getRandNum(vector<int> &a, int n, int count)
{
	srand((int)time(NULL));
	for (int i = 0; i < count; i++)
	{
		a.push_back((int)rand() % n);
	}
}

//补全
list<CommunicationNode>* getAllCommunicationNode(string str)
{
	return &(list<CommunicationNode>());
}



//获取节点ID为id的通信节点
CommunicationNode getNode(std::list<CommunicationNode> comNodes, long id)
{
	list<CommunicationNode>::iterator iter;
	CommunicationNode res;
	for (iter = comNodes.begin(); iter != comNodes.end(); ++iter)
	{
		if ((*iter).getNodeID() == id) {
			res = *iter;
			return res;
		}
	}
	return res;
}

double getDistance(CommunicationNode nodeA, CommunicationNode nodeB)
{
	double x1 = nodeA.getLongitude();
	double y1 = nodeA.getLatitude();
	double x2 = nodeB.getLongitude();
	double y2 = nodeB.getLatitude();
	double radLat1 = y1*PI / 180;
	double radLat2 = y2*PI / 180;
	double radLon1 = x1*PI / 180;
	double radLon2 = x2*PI / 180;
	double a = radLat1 - radLat2;
	double b = radLon1 - radLon2;
	double s = 2 * asin(sqrt(pow(sin(a / 2), 2) + cos(radLat1)*cos(radLat2)*pow(sin(b / 2), 2)));
	s = s*EARTH_RADIUS;
	return s;
}

//将一个CommunicationNode节点类转换成Json串
string communicationToJson(CommunicationNode comNode)
{
	stringstream ss;
	string res = "";
	ss <<"{" << "\"id\":" << comNode.getNodeID() << ", ";
	list<Message> *recvMsg = comNode.getMessageToRecv();
	if ((*recvMsg).size() != 0) {
		ss << "\"receiveMessage\": [";
		list<Message>::iterator iter;
		bool flag = true;
		for (iter = (*recvMsg).begin(); iter != (*recvMsg).end(); iter++) {
			if (flag == true) {
				ss << messageToJson(*iter);
				flag = false;
			}
			else {
				ss << ", " << messageToJson(*iter);
			}
		}
		ss << "]";
	}
	ss >> res;
	return res;
	
}

//将Message转换成Jsom
string messageToJson(Message message) {
	stringstream ss;
	string result = "";
	ss <<"{" << "\"MessageID\": " + message.getMessageID() << ", " << "\"MessageSize\": " + message.getSize() << "}";
	ss >> result;
	return result;
}
