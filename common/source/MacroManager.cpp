#include "stdafx.h"
#include "MacroManager.h"

#include "MacroIO.h"

using namespace ex04_Design::chapter3;

const char* MacroManager::MACRO_FILE_PATH = "macro.ini";


// 定型文を外部ファイルから読み込み
int MacroManager::LoadMacro()
{
	MacroIO macroIO;
	if (!macroIO.Open())
	{
		return LOAD_RESULT_NOT_FOUND;
	}
	if (!macroIO.Read(m_macro, MACRO_NUM))
	{
		return LOAD_RESULT_INVALID_FORMAT;
	}
	return LOAD_RESULT_OK;
}


// 定型文を外部ファイルへ書き込み
bool MacroManager::SaveMacro()
{
	MacroIO macroIO;
	return macroIO.Write(m_macro, MACRO_NUM);
}


// 定型文の取得
const std::string& MacroManager::GetMacro(int keyCodeIndex) const
{
	return m_macro[keyCodeIndex];
}


// 定型文の登録
void MacroManager::RegisterMacro(int keyCodeIndex, const std::string& text)
{
	m_macro[keyCodeIndex] = text;
}