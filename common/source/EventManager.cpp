#include "stdafx.h"
#include "EventManager.h"

#include <algorithm>

using namespace ex04_Design::chapter3;

std::vector<EventListener*> EventManager::s_listeners;

EventManager::EventManager()
{}

EventManager::~EventManager()
{}
			
// ���X�i�[�̒ǉ�
bool EventManager::AddListener(EventListener& listener)
{
	auto it = std::find(s_listeners.begin(), s_listeners.end(), &listener);
	// ���ɓo�^����Ă���
	if (it == s_listeners.end())
	{
		return false;
	}
	// �o�^
	s_listeners.push_back(&listener);

	return true;
}
			
// ���X�i�[�̍폜
bool EventManager::DeleteListener(EventListener& listener)
{
	auto it = std::find(s_listeners.begin(), s_listeners.end(), &listener);
	// �o�^����Ă��Ȃ�
	if (it != s_listeners.end())
	{
		return false;
	}
	// �폜
	s_listeners.erase(it);

	return true;
}

/**
	@brief		�L�[�������ꂽ
	@param[in]	keyCode	�L�[�R�[�h
	@return		�Ȃ�
*/
void EventManager::OnKeyDown(int keyCode)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnKeyDown(keyCode))
		{
			// �C�x���g������ȏ�ʒm���Ȃ�
			break;
		}
	}
}
/**
	@brief		�L�[�������ꂽ
	@param[in]	keyCode	�L�[�R�[�h
	@return		�Ȃ�
*/
void EventManager::OnKeyUp(int keyCode)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnKeyUp(keyCode))
		{
			// �C�x���g������ȏ�ʒm���Ȃ�
			break;
		}
	}
}
/**
	@brief		�}�E�X�̃{�^���������ꂽ
	@param[in]	button	�{�^��
	@return		�Ȃ�
*/
void EventManager::OnMouseButtonUp(int button)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnMouseButtonUp(button))
		{
			// �C�x���g������ȏ�ʒm���Ȃ�
			break;
		}
	}
}
/**
	@brief		�}�E�X�̃{�^���������ꂽ
	@param[in]	button	�{�^��
	@return		�Ȃ�
*/
void EventManager::OnMouseButtonDown(int button)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnMouseButtonDown(button))
		{
			// �C�x���g������ȏ�ʒm���Ȃ�
			break;
		}
	}
}

/**
	@brief		�}�E�X���ړ�����
	@param[in]	mouseX	�}�E�XX���W(�P��:�s�N�Z��)
	@param[in]	mouseY	�}�E�XY���W(�P��:�s�N�Z��)
	@return		�Ȃ�
*/
void EventManager::OnMouseMove(int mouseX, int mouseY)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnMouseMove(mouseX, mouseY))
		{
			// �C�x���g������ȏ�ʒm���Ȃ�
			break;
		}
	}
}

/**
	@brief		�`��
	@param[in]	renderer	�����_���[
	@return		�Ȃ�
*/
void EventManager::OnPaint(RendererBase& renderer)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnPaint(renderer))
		{
			// �C�x���g������ȏ�ʒm���Ȃ�
			break;
		}
	}
}
