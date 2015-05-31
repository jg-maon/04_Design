#ifndef ___Rect_h___
#define ___Rect_h___

namespace ex04_Design
{
	namespace chapter3
	{
		/**
			@struct		RECT
			@brief		��`
		*/
		struct RECT
		{
			int left;		//!< ��
			int top;		//!< ��
			int right;		//!< �E
			int bottom;		//!< ��

			RECT();
			/**
				@breif		�R���X�g���N�^
				@param[in]	left	��
				@param[in]	top		��
				@param[in]	right	�E
				@param[in]	bottom	��
			*/
			RECT(int left, int top, int right, int bottom);
		};

	}
}

#endif	// ___Rect_h___