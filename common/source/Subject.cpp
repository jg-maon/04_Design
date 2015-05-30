#include "stdafx.h"
#include "Subject.h"

using namespace ex04_Design::chapter3;


Subject::Subject()
	: m_observers()
{}

Subject::~Subject()
{}

/**
	@brief		Observer‚Ì’Ç‰Á
	@param[in]	observer	’Ê’m‘ÎÛ
	@return		’Ç‰Á¬Œ÷‚µ‚½‚©
	@retval		true	’Ç‰Á¬Œ÷
	@retval		false	Šù‚É’Ç‰Á‚³‚ê‚Ä‚¢‚é
*/
bool Subject::AddObserver(Observer& observer)
{
	auto it = std::find(m_observers.begin(), m_observers.end(), &observer);
	// Šù‚É“o˜^‚³‚ê‚Ä‚¢‚é
	if (it == m_observers.end())
	{
		return false;
	}
	// “o˜^
	m_observers.push_back(&observer);

	return true;
}
	
			
/**
	@brief		Observer‚Ìíœ
	@param[in]	observer	’Ê’m‘ÎÛ
	@return		íœ¬Œ÷‚µ‚½‚©
	@retval		true	íœ¬Œ÷
	@retval		false	“o˜^‚³‚ê‚Ä‚¢‚È‚¢
*/
bool Subject::DeleteObserver(const Observer& observer)
{
	auto it = std::find(m_observers.begin(), m_observers.end(), &observer);
	// “o˜^‚³‚ê‚Ä‚¢‚È‚¢
	if (it != m_observers.end())
	{
		return false;
	}
	// íœ
	m_observers.erase(it);

	return true;
}


/**
	@brief		“o˜^‚³‚ê‚Ä‚¢‚éObserver‚É•ÏX‚ð’Ê’m‚µ‚Ü‚·B
	@return		‚È‚µ
*/
void Subject::NotifyObservers()
{
	for (Observer* pObserver : m_observers)
	{
		pObserver->Update();
	}
}
