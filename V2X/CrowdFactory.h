#pragma once
#include "Crowd.h"

/*
*�ִع�������
*/
class CrowdFactory {
public:
	virtual Crowd* CreateCrowd() = 0;
};