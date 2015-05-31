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
			@brief	ビューの状態を管理するクラス
		*/
		class ViewStateManager : public Subject
		{
		public:

			ViewStateManager();

			virtual ~ViewStateManager();

		public:

			/**
				@brief		入力位置の表示
			*/
			void ShowInputPosition();

			/**
				@brief		入力位置の非表示
			*/
			void HideInputPosition();

			/**
				@brief		入力位置表示フラグの取得
				@return		入力位置を表示するか
			*/
			bool IsShowInputPosition() const;

			/**
				@brief		ビューのサイズを取得
				@return		ビューのサイズ
			*/
			const RECT& GetViewRect() const;

		private:
			RECT		m_viewRect;		//!< ビューサイズ
			bool		m_isInputting;	//!< 現在入力中か
		};


	}

}



#endif	// ___ViewStateManager_h___