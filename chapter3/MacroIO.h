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
			@brief	定型文の読み書き
		*/
		class MacroIO
		{
		public:

			MacroIO();

			virtual ~MacroIO();

			/**
				@brief		ファイルオープン
				@details	書き込み用として開く際はファイルを上書き作成します。
				@param[in]	isRead	読み込み用としてオープン
				@return		ファイルオープン
				@retval		true	成功
				@retval		false	失敗(読み込み時"macro.ini"ファイルが無かった)
			*/
			bool Open(bool isRead = true);

			/**
				@brief		ファイルクローズ
				@return		なし
			*/
			void Close();

			/**
				@brief		読み込み
				@details	書式"[キーコード],[定型文]"
				@param[out]	macro	格納先
				@param[in]	size	格納先の要素数
				@return		読み込み完了か
				@retval		true	完了
				@retval		false	不正なフォーマット
			*/
			bool Read(std::string macro[], size_t size);

			/**
				@brief		書き込み
				@param[in]	mecro	定型文
				@param[in]	size	格納先の要素数
				@return		書き込み完了か
				@retval		true	完了
				@retval		false	ファイルが開かれていない
				@par
							元の定型文ファイルを上書きします。
							また、定型文が空の場合は書き込まれません。
			*/
			bool Write(const std::string macro[], size_t size);

		private:
			std::fstream	m_file;
		};
	}
}

#endif	// ___MacroIO_h___