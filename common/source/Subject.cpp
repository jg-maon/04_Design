#include "stdafx.h"
#include "Subject.h"

using namespace ex04_Design::chapter3;


Subject::Subject()
	: m_observers()
{}

Subject::~Subject()
{}

/**
	@brief		Observerの追加
	@param[in]	observer	通知対象
	@return		追加成功したか
	@retval		true	追加成功
	@retval		false	既に追加されている
*/
bool Subject::AddObserver(Observer& observer)
{
	auto it = std::find(m_observers.begin(), m_observers.end(), &observer);
	// 既に登録されている
	if (it == m_observers.end())
	{
		return false;
	}
	// 登録
	m_observers.push_back(&observer);

	return true;
}
	
			
/**
	@brief		Observerの削除
	@param[in]	observer	通知対象
	@return		削除成功したか
	@retval		true	削除成功
	@retval		false	登録されていない
*/
bool Subject::DeleteObserver(const Observer& observer)
{
	auto it = std::find(m_observers.begin(), m_observers.end(), &observer);
	// 登録されていない
	if (it != m_observers.end())
	{
		return false;
	}
	// 削除
	m_observers.erase(it);

	return true;
}


/**
	@brief		登録されているObserverに変更を通知します。
	@return		なし
*/
void Subject::NotifyObservers()
{
	for (Observer* pObserver : m_observers)
	{
		pObserver->Update();
	}
}
