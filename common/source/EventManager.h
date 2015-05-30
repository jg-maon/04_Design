#ifndef ___EventManager_h___
#define ___EventManager_h___

#include <vector>
#include "EventListener.h"

namespace ex04_Design
{
	namespace chapter3
	{

		/**
			@class	EventManager
			@brief	イベント管理クラス
			@par
					
		*/
		class EventManager
		{
		public:
			EventManager();

			virtual ~EventManager();
			
			/**
				@brief		リスナーの追加
				@param[in]	listener	リスナー
				@return		追加成功したか
				@retval		true	追加成功
				@retval		false	既に追加されている
			*/
			static bool AddListener(EventListener& listener);
			
			/**
				@brief		リスナーの削除
				@param[in]	listener	リスナー
				@return		削除成功したか
				@retval		true	削除成功
				@retval		false	登録されていない
			*/
			static bool DeleteListener(EventListener& listener);

			/**
				@brief		キーが押された
				@param[in]	keyCode	キーコード
				@return		なし
			*/
			void OnKeyDown(int keyCode);
			/**
				@brief		キーが離された
				@param[in]	keyCode	キーコード
				@return		なし
			*/
			void OnKeyUp(int keyCode);
			/**
				@brief		マウスのボタンが押された
				@param[in]	button	ボタン
				@return		なし
			*/
			void OnMouseButtonUp(int button);
			/**
				@brief		マウスのボタンが離された
				@param[in]	button	ボタン
				@return		なし
			*/
			void OnMouseButtonDown(int button);

			/**
				@brief		マウスが移動した
				@param[in]	mouseX	マウスX座標(単位:ピクセル)
				@param[in]	mouseY	マウスY座標(単位:ピクセル)
				@return		なし
			*/
			void OnMouseMove(int mouseX, int mouseY);

			/**
				@brief		描画
				@param[in]	renderer	レンダラー
				@return		なし
			*/
			void OnPaint(RendererBase& renderer);

		private:
			static std::vector<EventListener*>	s_listeners;
		};
	}
}

#endif	// ___EventManager_h___