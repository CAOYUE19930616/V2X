#pragma once
#include "CrowdFactory.h"
#include "DefaultCrowd.h"

/*Ĭ�ϷִصĹ����࣬��������ָ��Ĭ�Ϸִ����ָ��*/
class DefaultCrowdFactory : public CrowdFactory {
public:
	Crowd* CreateCrowd() { return new DefaultCrowd(); }
};