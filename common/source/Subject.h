#ifndef ___Subject_h___
#define ___Subject_h___

#include "Observer.h"

#include <vector>

namespace ex04_Design
{
	namespace chapter3
	{
		
		/**
			@class	Subject
			@brief	Observer�ɕύX��ʒm����@�\�����N���X�ł��B
			@par
					��Ԃ̕ύX���������ۂɁA�K��NotifyObservers()���Ă�ł��������B
		*/
		class Subject
		{
		public:
			Subject();

			virtual ~Subject();

			/**
				@brief		Observer�̒ǉ�
				@param[in]	observer	�ʒm�Ώ�
				@return		�ǉ�����������
				@retval		true	�ǉ�����
				@retval		false	���ɒǉ�����Ă���
			*/
			bool AddObserver(Observer& observer);
	
			
			/**
				@brief		Observer�̍폜
				@param[in]	observer	�ʒm�Ώ�
				@return		�폜����������
				@retval		true	�폜����
				@retval		false	�o�^����Ă��Ȃ�
			*/
			bool DeleteObserver(const Observer& observer);


			/**
				@brief		�o�^����Ă���Observer�ɕύX��ʒm���܂��B
				@return		�Ȃ�
			*/
			void NotifyObservers();

		private:

			std::vector<Observer*>	m_observers;		//!< �ʒm����Observer

		};

	}
}
#endif	// ___Subject_h___