#include "stdafx.h"
#include "Subject.h"

using namespace ex04_Design::chapter3;


Subject::Subject()
	: m_observers()
{}

Subject::~Subject()
{}

/**
	@brief		Observer�̒ǉ�
	@param[in]	observer	�ʒm�Ώ�
	@return		�ǉ�����������
	@retval		true	�ǉ�����
	@retval		false	���ɒǉ�����Ă���
*/
bool Subject::AddObserver(Observer& observer)
{
	auto it = std::find(m_observers.begin(), m_observers.end(), &observer);
	// ���ɓo�^����Ă���
	if (it == m_observers.end())
	{
		return false;
	}
	// �o�^
	m_observers.push_back(&observer);

	return true;
}
	
			
/**
	@brief		Observer�̍폜
	@param[in]	observer	�ʒm�Ώ�
	@return		�폜����������
	@retval		true	�폜����
	@retval		false	�o�^����Ă��Ȃ�
*/
bool Subject::DeleteObserver(const Observer& observer)
{
	auto it = std::find(m_observers.begin(), m_observers.end(), &observer);
	// �o�^����Ă��Ȃ�
	if (it != m_observers.end())
	{
		return false;
	}
	// �폜
	m_observers.erase(it);

	return true;
}


/**
	@brief		�o�^����Ă���Observer�ɕύX��ʒm���܂��B
	@return		�Ȃ�
*/
void Subject::NotifyObservers()
{
	for (Observer* pObserver : m_observers)
	{
		pObserver->Update();
	}
}
