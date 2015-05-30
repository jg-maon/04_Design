#ifndef ___Observer_h___
#define ___Observer_h___

namespace ex04_Design
{
	namespace chapter3
	{
		/**
			@class	Observer
			@brief	モデルの変更を監視するクラス
		*/
		class Observer
		{
		public:
			virtual ~Observer() = 0;

			/**
				@brief		更新
				@details	Subjectクラスより呼び出される状態変更を適用するメソッドです。
				@return		なし
			*/
			virtual void Update() = 0;

		};
	}
}
#endif	// ___Observer_h___