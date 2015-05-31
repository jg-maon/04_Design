#include "stdafx.h"
#include "MacroIO.h"

#include "MacroManager.h"
#include "TextManager.h"
#include <regex>
#include <vector>
#include <sstream>


using namespace ex04_Design::chapter3;

MacroIO::MacroIO()
	: m_file()
{
}

MacroIO::~MacroIO()
{
	Close();
}

bool MacroIO::Open(bool isRead /* = true*/)
{
	Close();
	if (isRead)
	{
		m_file.open(MacroManager::MACRO_FILE_PATH, std::ios_base::in);
	}
	else
	{
		m_file.open(MacroManager::MACRO_FILE_PATH, std::ios_base::out|std::ios_base::trunc);
	}

	return m_file.is_open();
}

void MacroIO::Close()
{
	if (m_file.is_open())
	{
		m_file.close();
	}
}

bool MacroIO::Read(std::string macro[], size_t size)
{
	if (!Open())
	{
		return false;
	}
	// 読み込み時一時保存用
	std::vector<std::string> tmpMacro(size);
	std::stringstream pattern;
	pattern << "^F([1-9]|1[012])," << "," << ".{0," << TextManager::MAX_INPUT_LENGTH << "}$";
	std::regex regex(pattern.str());

	std::string line, key;
	while (!m_file.eof() && std::getline(m_file, line))
	{
		// 空行あり
		if (line.empty())
		{
			return false;
		}
		// 正規表現による書式チェック
		if (!std::regex_match(line, regex))
		{
			return false;
		}

		// ,区切りで読み込む
		std::stringstream ss(line);
		std::getline(ss, key, ',');
		int keyCode = atoi(&key[1]);	// [0]には'F'が入っているため
		// キーコードに対応した配列に追加
		std::getline(ss, tmpMacro[keyCode-1]);
	}

	// 反映
	for (size_t i = 0; i < size; ++i)
	{
		macro[i] = tmpMacro[i];
	}
	
	return true;
}

bool MacroIO::Write(const std::string macro[], size_t size)
{
	if (!Open(false))
	{
		return false;
	}
	for (size_t i = 0; i < size; ++i)
	{
		// 定型文が登録されていれば
		if (!macro[i].empty())
		{
			m_file << "F" << (i + 1) << "," << macro[i] << std::endl;
		}
	}

	return true;
}