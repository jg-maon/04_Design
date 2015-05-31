#ifndef ___TextManager_h___
#define ___TextManager_h___

#include "Subject.h"

#include <string>

namespace ex04_Design
{
	namespace chapter3
	{
		/**
			@class	TextManager
			@brief	�r���[�ɕ\�������镶����̊Ǘ��N���X
		*/
		class TextManager : public Subject
		{
		public:
			enum
			{
				MAX_INPUT_LENGTH = 80,		//!< ���͕����̍Œ�
			};

		public:
			TextManager();
			virtual ~TextManager();

		public:
			/**
				@brief		��������
				@param[in]	keyCode	�L�[�R�[�h
				@return		�Ȃ�
			*/
			void InputText(int keyCode);
			
			/**
				@brief		��^������
				@param[in]	keyCode	�L�[�R�[�h
				@return		���͕������܂��͕���
				@retval		0�ȏ�	���͕�����
				@retval		����		���肫��Ȃ�������
			*/
			int InputMacro(int keyCode);

			
			/**
				@brief		�A���h�D
				@return		�Ȃ�
			*/
			void Undo();

			/**
				@brief		���h�D
				@return		�Ȃ�
			*/
			void Redo();
			

		private:
			std::string			m_inputText;	//!< ���͒��̕�����
			std::string			m_dispText;		//!< �\�����̕�����


		};
	}
}


#endif	// ___TextManager_h___