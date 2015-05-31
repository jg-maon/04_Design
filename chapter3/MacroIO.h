#ifndef ___MacroIO_h___
#define ___MacroIO_h___

#include <string>
#include <fstream>

namespace ex04_Design
{
	namespace chapter3
	{
		/**
			@class	MacroIO
			@brief	��^���̓ǂݏ���
		*/
		class MacroIO
		{
		public:

			MacroIO();

			virtual ~MacroIO();

			/**
				@brief		�t�@�C���I�[�v��
				@details	�������ݗp�Ƃ��ĊJ���ۂ̓t�@�C�����㏑���쐬���܂��B
				@param[in]	isRead	�ǂݍ��ݗp�Ƃ��ăI�[�v��
				@return		�t�@�C���I�[�v��
				@retval		true	����
				@retval		false	���s(�ǂݍ��ݎ�"macro.ini"�t�@�C������������)
			*/
			bool Open(bool isRead = true);

			/**
				@brief		�t�@�C���N���[�Y
				@return		�Ȃ�
			*/
			void Close();

			/**
				@brief		�ǂݍ���
				@details	����"[�L�[�R�[�h],[��^��]"
				@param[out]	macro	�i�[��
				@param[in]	size	�i�[��̗v�f��
				@return		�ǂݍ��݊�����
				@retval		true	����
				@retval		false	�s���ȃt�H�[�}�b�g
			*/
			bool Read(std::string macro[], size_t size);

			/**
				@brief		��������
				@param[in]	mecro	��^��
				@param[in]	size	�i�[��̗v�f��
				@return		�������݊�����
				@retval		true	����
				@retval		false	�t�@�C�����J����Ă��Ȃ�
				@par
							���̒�^���t�@�C�����㏑�����܂��B
							�܂��A��^������̏ꍇ�͏������܂�܂���B
			*/
			bool Write(const std::string macro[], size_t size);

		private:
			std::fstream	m_file;
		};
	}
}

#endif	// ___MacroIO_h___