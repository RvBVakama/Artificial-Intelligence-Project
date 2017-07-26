#pragma once
#include "Renderer2D.h"

struct GridNode;

using namespace aie;

class Grid
{
public:
	static Grid* getInstance() { return m_grid; }
	static void create() { m_grid = new Grid(); /*ASSERT here?*/ }
	static void destroy() { delete m_grid; }
	void Draw(Renderer2D* m_2dRenderer);
	GridNode* GetNode(int index);

private:
	Grid();
	~Grid();
	
	static Grid* m_grid;

	GridNode**			m_ppGrid;
	aie::Renderer2D*	m_2dRenderer;
};
