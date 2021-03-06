#include "Message.h"
#include <sstream>

Message::Message()
{
}

Message::Message(long msgID, long sa, long da, int sz)
{
	MessageID = msgID;
	SourceAddress = sa;
	DestinationAddress = da;
	Size = sz;
}

Message::~Message()
{
}

long Message::getMessageID()
{
	return MessageID;
}

long Message::getSourceAddress()
{
	return SourceAddress;
}

long Message::getDestinationAddress()
{
	return DestinationAddress;
}

int Message::getSize()
{
	return Size;
}

int Message::getMessageType()
{
	return MessageType;
}

int Message::getTransmissionType()
{
	return TransmissionType;
}

float Message::getDelay()
{
	return Delay;
}

bool Message::getTransFinish()
{
	return TransFinish;
}

void Message::setMessageID(long id)
{
	MessageID = id;
}

void Message::setSourceAddress(long sourceAddress)
{
	SourceAddress = sourceAddress;
}

void Message::setDestinationAddress(long destinationAddress)
{
	DestinationAddress = destinationAddress;
}

void Message::setSize(int size)
{
	Size = size;
}

void Message::setMessageType(int messageType)
{
	MessageType = messageType;
}

void Message::setTransmissionType(int transmissionType)
{
	TransmissionType = transmissionType;
}

void Message::setDelay(float delay)
{
	Delay = delay;
}

void Message::setTransFinish(bool trans)
{
	TransFinish = trans;
}

std::string Message::toJson()
{
	stringstream ss;
	string result = "";
	ss << "{" << "\"MessageID\": " << MessageID << ", " << "\"MessageSize\": " << Size << "\"DelayTime\":" << Delay << "}";
	ss >> result;
	return result;
}
