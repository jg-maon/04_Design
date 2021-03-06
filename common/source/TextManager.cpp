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

// 文字入力
void TextManager::InputText(int keyCode)
{
	// BackSpace
	if (keyCode == KeyCode::KEY_BACK)
	{
		// 1文字削除
		if (!m_inputText.empty())
		{
			m_inputText.pop_back();
		}
	}
	// 入力文字長未満
	else if (m_inputText.size() < MAX_INPUT_LENGTH)
	{
		m_inputText += static_cast<char>(keyCode);
	}
}
			
// 定型文入力
int TextManager::InputMacro(int keyCode)
{

}
			
// アンドゥ
void TextManager::Undo()
{

}

// リドゥ
void TextManager::Redo()
{

}