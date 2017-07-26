//#include "Player.h"
//#include "Define.h"
//
//int DiagonalHeurisitic(AStarNode* pNode, AStarNode* pEnd)
//{
//	//Diagonal Shortcut Method
//	int difX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
//	int difY = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;
//
//	difX = abs(difX);
//	difY = abs(difY);
//
//	if (difX > difY)
//		return (DIAGONAL_COST * difY) + ADJACENT_COST * (difX - difY);
//	else
//		return (DIAGONAL_COST * difX) + ADJACENT_COST * (difY - difX);
//}
//
//Player::Player(GridNode** ppGrid)
//{
//	m_ppGrid = ppGrid;
//
//	//Setup AStar
//	m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);
//	
//	m_pAStar->SetHeuristic(&DiagonalHeurisitic);
//
//	m_nNextNode = 0;
//
//	nTime = 0;
//}
//
//Player::~Player()
//{
//	delete m_pAStar;
//}
//
//void Player::Update(float fDeltaTime)
//{
//	m_path.clear();
//	//if (nTime < 900)
//		m_pAStar->CalculatePath(m_ppGrid[1], m_ppGrid[899], &m_path);
//
//		if (m_nNextNode >= m_path.size())
//		{
//			++nTime;
//			m_nNextNode = 0;
//		}
//
//	Vector2 dest = ((GridNode*)m_path[m_nNextNode])->m_v2Pos;
//	Vector2 dir = dest - m_v2Pos;
//	dir.Normalise();
//	m_v2Pos = m_v2Pos + dir * 200.0f * fDeltaTime;
//
//	Vector2 dist = dest - m_v2Pos;
//	float fDist = dist.Magnitude();
//	if (fDist < 10)
//	{
//		++m_nNextNode;
//	}
//}
//
//void Player::Draw(Renderer2D* m_pRenderer2D)
//{
//	//Draw Path
//
//	for (size_t i = 0; i < m_path.size(); ++i)
//	{
//		GridNode* pNode = (GridNode*)m_path[i];
//
//		m_pRenderer2D->setRenderColour(0x00FF00FF);
//		m_pRenderer2D->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 0.9f, NODE_SIZE / 0.9f);
//		m_pRenderer2D->setRenderColour(0xFFFFFFFF);
//	}
//
//	//Draw Player
//	m_pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 30, 30);
//}
