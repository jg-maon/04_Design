#ifndef ___ViewStateManager_h___
#define ___ViewStateManager_h___

#include "Subject.h"

#include "Rect.h"

namespace ex04_Design
{
	namespace chapter3
	{

		/**	
			@class	ViewStateManager
			@brief	�r���[�̏�Ԃ��Ǘ�����N���X
		*/
		class ViewStateManager : public Subject
		{
		public:

			ViewStateManager();

			virtual ~ViewStateManager();

		public:

			/**
				@brief		���͈ʒu�̕\��
			*/
			void ShowInputPosition();

			/**
				@brief		���͈ʒu�̔�\��
			*/
			void HideInputPosition();

			/**
				@brief		���͈ʒu�\���t���O�̎擾
				@return		���͈ʒu��\�����邩
			*/
			bool IsShowInputPosition() const;

			/**
				@brief		�r���[�̃T�C�Y���擾
				@return		�r���[�̃T�C�Y
			*/
			const RECT& GetViewRect() const;

		private:
			RECT		m_viewRect;		//!< �r���[�T�C�Y
			bool		m_isInputting;	//!< ���ݓ��͒���
		};


	}

}



#endif	// ___ViewStateManager_h___