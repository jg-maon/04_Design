#ifndef ___Rect_h___
#define ___Rect_h___

namespace ex04_Design
{
	namespace chapter3
	{
		/**
			@struct		RECT
			@brief		矩形
		*/
		struct RECT
		{
			int left;		//!< 左
			int top;		//!< 上
			int right;		//!< 右
			int bottom;		//!< 下

			RECT();
			/**
				@breif		コンストラクタ
				@param[in]	left	左
				@param[in]	top		上
				@param[in]	right	右
				@param[in]	bottom	下
			*/
			RECT(int left, int top, int right, int bottom);
		};

	}
}

#endif	// ___Rect_h___