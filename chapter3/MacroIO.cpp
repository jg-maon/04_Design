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
	// �ǂݍ��ݎ��ꎞ�ۑ��p
	std::vector<std::string> tmpMacro(size);
	std::stringstream pattern;
	pattern << "^F([1-9]|1[012])," << "," << ".{0," << TextManager::MAX_INPUT_LENGTH << "}$";
	std::regex regex(pattern.str());

	std::string line, key;
	while (!m_file.eof() && std::getline(m_file, line))
	{
		// ��s����
		if (line.empty())
		{
			return false;
		}
		// ���K�\���ɂ�鏑���`�F�b�N
		if (!std::regex_match(line, regex))
		{
			return false;
		}

		// ,��؂�œǂݍ���
		std::stringstream ss(line);
		std::getline(ss, key, ',');
		int keyCode = atoi(&key[1]);	// [0]�ɂ�'F'�������Ă��邽��
		// �L�[�R�[�h�ɑΉ������z��ɒǉ�
		std::getline(ss, tmpMacro[keyCode-1]);
	}

	// ���f
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
		// ��^�����o�^����Ă����
		if (!macro[i].empty())
		{
			m_file << "F" << (i + 1) << "," << macro[i] << std::endl;
		}
	}

	return true;
}