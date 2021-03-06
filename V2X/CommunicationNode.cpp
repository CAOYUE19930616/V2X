#include "CommunicationNode.h"
#include <sstream>

CommunicationNode::CommunicationNode()
{
}

//构造函数
CommunicationNode::CommunicationNode(long id, float lgt, float lat, float sp,
	float tp, float rp, float tr, list<Message> &sm, list<Message> & rm, SendQueue &sq, ReceiveQueue &rq)
{//注意指针的引用
	nodeID = id;
	longitude = lgt;
	latitude = lat;
	speed = sp;
	tPower = tp;
	rPower = rp;
	tRate = tr;
	send_msg = &sm;
	recv_msg = &rm;
	sendQ = &sq;
	receiveQ = &rq;
}

CommunicationNode::~CommunicationNode() {}

long CommunicationNode::getNodeID()
{
	return nodeID;
}

float CommunicationNode::getLongitude()
{
	return longitude;
}

float CommunicationNode::getLatitude()
{
	return latitude;
}

float CommunicationNode::getSpeed()
{
	return speed;
}

float CommunicationNode::getTPower()
{
	return tPower;
}

float CommunicationNode::getRPower()
{
	return rPower;
}

float CommunicationNode::getTRate()
{
	return tRate;
}

list<Message>* CommunicationNode::getMessageToSend()
{
	return send_msg;
}

list<Message>* CommunicationNode::getMessageToRecv()
{
	return recv_msg;
}

SendQueue* CommunicationNode::getSendQueue()
{
	return sendQ;
}

ReceiveQueue* CommunicationNode::getReceiveQueue()
{
	return receiveQ;
}

int CommunicationNode::getCrowd()
{
	return crowd;
}

bool CommunicationNode::getHaveMessage()
{
	return haveMessage;
}

void CommunicationNode::setNodeID(int id)
{
	nodeID = id;
}

void CommunicationNode::setLongitude(float lon)
{
	longitude = lon;
}

void CommunicationNode::setlatitude(float lat)
{
	latitude = lat;
}

void CommunicationNode::setSpeed(float sp)
{
	speed = sp;
}

void CommunicationNode::setTPower(float tPow)
{
	tPower = tPow;
}

void CommunicationNode::setRPower(float rPow)
{
	rPower = rPow;
}

void CommunicationNode::setTRate(float trate)
{
	tRate = trate;
}

void CommunicationNode::setSendMessage(list<Message> &lm)
{
	send_msg = &lm;
}

void CommunicationNode::setRecvMessage(list<Message> &rm)
{
	list<Message>::iterator iter;

	for (iter = rm.begin(); iter != rm.end(); iter++) {
		recv_msg->push_back(*iter);
	}
}


void CommunicationNode::setCrowd(int c)
{
	crowd = c;
}

void CommunicationNode::setHaveMessage(bool msg)
{
	haveMessage = msg;
}

bool CommunicationNode::isFinished()
{
	if ((*recv_msg).size() != 0) {//判断接收消息是否为空
		list<Message>::iterator iter;
		bool flag = false;
		//遍历每一个消息 判断该消息是否传输完成
		for (iter = (*recv_msg).begin(); iter != (*recv_msg).end(); iter++) {
			if ((*iter).getTransFinish() == true) {//有完成的 置判断标志为true
				flag = true;
			}
		}
		if (flag == true) {//如果有传输完成的消息 返回true
			return true;
		}
		else {//否则返回false
			return false;
		}
	}
	else return false;//没有消息接收 返回false
}

std::string CommunicationNode::toJson()
{
	stringstream ss;
	string res = "";
	ss << "{" << "\"id\":" << nodeID << ", ";
	if ((*recv_msg).size() != 0) {
		ss << "\"receiveMessage\": [";
		list<Message>::iterator iter;
		bool flag = true;
		for (iter = (*recv_msg).begin(); iter != (*recv_msg).end(); iter++) {
			if ((*iter).getTransFinish() == true) {//若该消息已经传输完成 则输出json串
				if (flag == true) {
					ss << (*iter).toJson();
					flag = false;
				}
				else {
					ss << ", " << (*iter).toJson();
				}
			}			
		}
		ss << "]";
	}
	ss >> res;
	return res;
}
