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

// ��������
void TextManager::InputText(int keyCode)
{
	// BackSpace
	if (keyCode == KeyCode::KEY_BACK)
	{
		// 1�����폜
		if (!m_inputText.empty())
		{
			m_inputText.pop_back();
		}
	}
	// ���͕���������
	else if (m_inputText.size() < MAX_INPUT_LENGTH)
	{
		m_inputText += static_cast<char>(keyCode);
	}
}
			
// ��^������
int TextManager::InputMacro(int keyCode)
{

}
			
// �A���h�D
void TextManager::Undo()
{

}

// ���h�D
void TextManager::Redo()
{

}