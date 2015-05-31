#ifndef ___MacroManager_h___
#define ___MacroManager_h___

#include <string>

namespace ex04_Design
{
	namespace chapter3
	{

		/**
			@class	MacroManager
			@brief	��^���̊Ǘ�������N���X
		*/
		class MacroManager
		{
		public:
			enum
			{
				MACRO_NUM = 12,		//!< ��^���̓o�^��

				LOAD_RESULT_OK = 0,			//!< �ǂݍ��݊���
				LOAD_RESULT_NOT_FOUND,		//!< macro.ini���݂��Ȃ�
				LOAD_RESULT_INVALID_FORMAT,	//!< �t�@�C���̃t�H�[�}�b�g���s��
			};

			static const char* MACRO_FILE_PATH;	//!< �}�N���t�@�C���p�X

		public:

			/**
				@brief		��^�����O���t�@�C������ǂݍ���
				@return		�Ǎ�����
				@retval		LOAD_RESULT_OK				�ǂݍ��݊���
				@retval		LOAD_RESULT_NOT_FOUND		macro.ini���݂��Ȃ�
				@retval		LOAD_RESULT_INVALID_FORMAT	�t�@�C���̃t�H�[�}�b�g���s��
			*/
			int LoadMacro();

			/**
				@brief		��^�����O���t�@�C���֏�������
				@return		�������݊�����
				@retval		true	����
				@retval		false	�t�@�C���I�[�v�����s
			*/
			bool SaveMacro();

			/**
				@brief		��^���̎擾
				@param[in]	keyCodeIndex	�L�[�R�[�h(F1:0 ~ F12:11)
				@return		��^��
			*/
			const std::string& GetMacro(int keyCodeIndex) const;

			/**
				@brief		��^���̓o�^
				@param[in]	keyCodeIndex	�L�[�R�[�h(F1:0 ~ F12:11)
				@param[in]	text	��^��
				@return		�Ȃ�
			*/
			void RegisterMacro(int keyCodeIndex, const std::string& text);


		private:

			std::string			m_macro[MACRO_NUM];		//!< ��^��

		};

	}
}

#endif	// ___MacroManager_h___