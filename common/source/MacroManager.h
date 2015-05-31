#ifndef ___MacroManager_h___
#define ___MacroManager_h___

#include <string>

namespace ex04_Design
{
	namespace chapter3
	{

		/**
			@class	MacroManager
			@brief	定型文の管理をするクラス
		*/
		class MacroManager
		{
		public:
			enum
			{
				MACRO_NUM = 12,		//!< 定型文の登録数

				LOAD_RESULT_OK = 0,			//!< 読み込み完了
				LOAD_RESULT_NOT_FOUND,		//!< macro.ini存在しない
				LOAD_RESULT_INVALID_FORMAT,	//!< ファイルのフォーマットが不正
			};

			static const char* MACRO_FILE_PATH;	//!< マクロファイルパス

		public:

			/**
				@brief		定型文を外部ファイルから読み込み
				@return		読込結果
				@retval		LOAD_RESULT_OK				読み込み完了
				@retval		LOAD_RESULT_NOT_FOUND		macro.ini存在しない
				@retval		LOAD_RESULT_INVALID_FORMAT	ファイルのフォーマットが不正
			*/
			int LoadMacro();

			/**
				@brief		定型文を外部ファイルへ書き込み
				@return		書き込み完了か
				@retval		true	完了
				@retval		false	ファイルオープン失敗
			*/
			bool SaveMacro();

			/**
				@brief		定型文の取得
				@param[in]	keyCodeIndex	キーコード(F1:0 ~ F12:11)
				@return		定型文
			*/
			const std::string& GetMacro(int keyCodeIndex) const;

			/**
				@brief		定型文の登録
				@param[in]	keyCodeIndex	キーコード(F1:0 ~ F12:11)
				@param[in]	text	定型文
				@return		なし
			*/
			void RegisterMacro(int keyCodeIndex, const std::string& text);


		private:

			std::string			m_macro[MACRO_NUM];		//!< 定型文

		};

	}
}

#endif	// ___MacroManager_h___