#include "stdafx.h"
#include "TextManager.h"

#include "EventListener.h"	// KeyCode

using namespace ex04_Design::chapter3;

TextManager::TextManager()
	: m_inputText()
	, m_dispText()
{}
TextManager::~TextManager()
{}

// •¶š“ü—Í
void TextManager::InputText(int keyCode)
{
	// BackSpace
	if (keyCode == KeyCode::KEY_BACK)
	{
		// 1•¶šíœ
		if (!m_inputText.empty())
		{
			m_inputText.pop_back();
		}
	}
	// “ü—Í•¶š’·–¢–
	else if (m_inputText.size() < MAX_INPUT_LENGTH)
	{
		m_inputText += static_cast<char>(keyCode);
	}
}
			
// ’èŒ^•¶“ü—Í
int TextManager::InputMacro(int keyCode)
{

}
			
// ƒAƒ“ƒhƒD
void TextManager::Undo()
{

}

// ƒŠƒhƒD
void TextManager::Redo()
{

}