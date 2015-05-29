#ifndef ___Application_h___
#define ___Application_h___

#include <Windows.h>

namespace ex04_Design
{
	namespace chapter3
	{
		/**
			@class	Application
			@brief	�A�v���P�[�V�����N���X
			*/
		class Application
		{
		public:
			/**
				@struct		windowParam
				@brief		�E�B���h�E�쐬���̈���
			*/
			struct windowParam
			{
				TCHAR szTitle[32];			//!< �^�C�g��
				TCHAR windowClassName[32];	//!< �E�B���h�E�N���X��
			};
		public:

			/**
				@brief	�R���X�g���N�^
			*/
			Application();

			/**
				@brief	�f�X�g���N�^
			*/
			virtual ~Application();

		public:

			/**
				@brief		������
				@param[in]	hInstance	�E�B���h�E�̃C���X�^���X
				@param[in]	nCmdShow
				@retval		true		����
				@retval		false		�E�B���h�E�̍쐬�Ɏ��s
			*/
			bool Initialize(HINSTANCE hInstance, int nCmdShow, windowParam& param);
			

			int MessageLoop();

			/**
				@brief		�E�B���h�E�̃��b�Z�[�W����
				@param[in]	hWnd	�E�B���h�E�n���h��
				@param[in]	message	���b�Z�[�W
				@param[in]	wParam	word�p�����[�^
				@param[in]	lParam	long�p�����[�^
				@return		LRESULT
			*/
			static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


		private:
			bool _InitInstance(int nCmdShow, const windowParam& param);

			bool _RegisterClass(const windowParam& param);


			static INT_PTR CALLBACK _About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
		
		private:
			static HINSTANCE	s_hInstance;	//!< �C���X�^���X

			HACCEL		m_hAccelTable;

		};

	}	// namespace chapter3
}	// namespace ex04_Design
#endif	// ___Application_h___