#include "stdafx.h"
#include "ViewStateManager.h"

using namespace ex04_Design::chapter3;

ViewStateManager::ViewStateManager()
	: m_viewRect(100,100,300,300)
	, m_isInputting(false)
{}

ViewStateManager::~ViewStateManager()
{}


// ���͈ʒu�̕\��
void ViewStateManager::ShowInputPosition()
{
	m_isInputting = true;
	NotifyObservers();
}


// ���͈ʒu�̔�\��
void ViewStateManager::HideInputPosition()
{
	m_isInputting = false;
	NotifyObservers();
}


// ���͈ʒu�\���t���O�̎擾
bool ViewStateManager::IsShowInputPosition() const
{
	return m_isInputting;
}


// �r���[�̃T�C�Y���擾
const ex04_Design::chapter3::RECT& ViewStateManager::GetViewRect() const
{
	return m_viewRect;
}