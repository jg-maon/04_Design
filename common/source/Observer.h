#ifndef ___Observer_h___
#define ___Observer_h___

namespace ex04_Design
{
	namespace chapter3
	{
		/**
			@class	Observer
			@brief	���f���̕ύX���Ď�����N���X
		*/
		class Observer
		{
		public:
			virtual ~Observer() = 0;

			/**
				@brief		�X�V
				@details	Subject�N���X���Ăяo������ԕύX��K�p���郁�\�b�h�ł��B
				@return		�Ȃ�
			*/
			virtual void Update() = 0;

		};
	}
}
#endif	// ___Observer_h___