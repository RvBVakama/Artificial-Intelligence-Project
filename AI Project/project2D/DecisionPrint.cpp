#include "DecisionPrint.h"
#include <iostream>

using namespace std;

DecisionPrint::DecisionPrint()
{
	m_fTimer = 0.0f;
}


DecisionPrint::~DecisionPrint()
{
}

void DecisionPrint::MakeDecision(Entity * pEntity, float fDeltaTime)
{
	m_fTimer += fDeltaTime;
	system("cls");
	cout << "Space has been pressed for " << m_fTimer << " seconds." << endl;
}
