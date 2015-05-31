#include "stdafx.h"
#include "ViewStateManager.h"

using namespace ex04_Design::chapter3;

ViewStateManager::ViewStateManager()
	: m_viewRect(100,100,300,300)
	, m_isInputting(false)
{}

ViewStateManager::~ViewStateManager()
{}


// 入力位置の表示
void ViewStateManager::ShowInputPosition()
{
	m_isInputting = true;
	NotifyObservers();
}


// 入力位置の非表示
void ViewStateManager::HideInputPosition()
{
	m_isInputting = false;
	NotifyObservers();
}


// 入力位置表示フラグの取得
bool ViewStateManager::IsShowInputPosition() const
{
	return m_isInputting;
}


// ビューのサイズを取得
const ex04_Design::chapter3::RECT& ViewStateManager::GetViewRect() const
{
	return m_viewRect;
}