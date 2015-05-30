#include "stdafx.h"
#include "EventManager.h"

#include <algorithm>

using namespace ex04_Design::chapter3;

std::vector<EventListener*> EventManager::s_listeners;

EventManager::EventManager()
{}

EventManager::~EventManager()
{}
			
// リスナーの追加
bool EventManager::AddListener(EventListener& listener)
{
	auto it = std::find(s_listeners.begin(), s_listeners.end(), &listener);
	// 既に登録されている
	if (it == s_listeners.end())
	{
		return false;
	}
	// 登録
	s_listeners.push_back(&listener);

	return true;
}
			
// リスナーの削除
bool EventManager::DeleteListener(EventListener& listener)
{
	auto it = std::find(s_listeners.begin(), s_listeners.end(), &listener);
	// 登録されていない
	if (it != s_listeners.end())
	{
		return false;
	}
	// 削除
	s_listeners.erase(it);

	return true;
}

/**
	@brief		キーが押された
	@param[in]	keyCode	キーコード
	@return		なし
*/
void EventManager::OnKeyDown(int keyCode)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnKeyDown(keyCode))
		{
			// イベントをこれ以上通知しない
			break;
		}
	}
}
/**
	@brief		キーが離された
	@param[in]	keyCode	キーコード
	@return		なし
*/
void EventManager::OnKeyUp(int keyCode)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnKeyUp(keyCode))
		{
			// イベントをこれ以上通知しない
			break;
		}
	}
}
/**
	@brief		マウスのボタンが押された
	@param[in]	button	ボタン
	@return		なし
*/
void EventManager::OnMouseButtonUp(int button)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnMouseButtonUp(button))
		{
			// イベントをこれ以上通知しない
			break;
		}
	}
}
/**
	@brief		マウスのボタンが離された
	@param[in]	button	ボタン
	@return		なし
*/
void EventManager::OnMouseButtonDown(int button)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnMouseButtonDown(button))
		{
			// イベントをこれ以上通知しない
			break;
		}
	}
}

/**
	@brief		マウスが移動した
	@param[in]	mouseX	マウスX座標(単位:ピクセル)
	@param[in]	mouseY	マウスY座標(単位:ピクセル)
	@return		なし
*/
void EventManager::OnMouseMove(int mouseX, int mouseY)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnMouseMove(mouseX, mouseY))
		{
			// イベントをこれ以上通知しない
			break;
		}
	}
}

/**
	@brief		描画
	@param[in]	renderer	レンダラー
	@return		なし
*/
void EventManager::OnPaint(RendererBase& renderer)
{
	for (EventListener* pListener : s_listeners)
	{
		if (!pListener->OnPaint(renderer))
		{
			// イベントをこれ以上通知しない
			break;
		}
	}
}
