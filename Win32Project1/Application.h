#ifndef ___Application_h___
#define ___Application_h___

#include <Windows.h>

namespace ex04_Design
{
	namespace chapter3
	{
		/**
			@class	Application
			@brief	アプリケーションクラス
			*/
		class Application
		{
		public:
			/**
				@struct		windowParam
				@brief		ウィンドウ作成時の引数
			*/
			struct windowParam
			{
				TCHAR szTitle[32];			//!< タイトル
				TCHAR windowClassName[32];	//!< ウィンドウクラス名
			};
		public:

			/**
				@brief	コンストラクタ
			*/
			Application();

			/**
				@brief	デストラクタ
			*/
			virtual ~Application();

		public:

			/**
				@brief		初期化
				@param[in]	hInstance	ウィンドウのインスタンス
				@param[in]	nCmdShow
				@retval		true		成功
				@retval		false		ウィンドウの作成に失敗
			*/
			bool Initialize(HINSTANCE hInstance, int nCmdShow, windowParam& param);
			

			int MessageLoop();

			/**
				@brief		ウィンドウのメッセージ処理
				@param[in]	hWnd	ウィンドウハンドル
				@param[in]	message	メッセージ
				@param[in]	wParam	wordパラメータ
				@param[in]	lParam	longパラメータ
				@return		LRESULT
			*/
			static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


		private:
			bool _InitInstance(int nCmdShow, const windowParam& param);

			bool _RegisterClass(const windowParam& param);


			static INT_PTR CALLBACK _About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
		
		private:
			static HINSTANCE	s_hInstance;	//!< インスタンス

			HACCEL		m_hAccelTable;

		};

	}	// namespace chapter3
}	// namespace ex04_Design
#endif	// ___Application_h___