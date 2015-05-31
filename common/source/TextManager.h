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
			@brief	ビューに表示させる文字列の管理クラス
		*/
		class TextManager : public Subject
		{
		public:
			enum
			{
				MAX_INPUT_LENGTH = 80,		//!< 入力文字の最長
			};

		public:
			TextManager();
			virtual ~TextManager();

		public:
			/**
				@brief		文字入力
				@param[in]	keyCode	キーコード
				@return		なし
			*/
			void InputText(int keyCode);
			
			/**
				@brief		定型文入力
				@param[in]	keyCode	キーコード
				@return		入力文字数または負数
				@retval		0以上	入力文字数
				@retval		負数		入りきらない文字数
			*/
			int InputMacro(int keyCode);

			
			/**
				@brief		アンドゥ
				@return		なし
			*/
			void Undo();

			/**
				@brief		リドゥ
				@return		なし
			*/
			void Redo();
			

		private:
			std::string			m_inputText;	//!< 入力中の文字列
			std::string			m_dispText;		//!< 表示中の文字列


		};
	}
}


#endif	// ___TextManager_h___