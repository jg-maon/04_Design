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
			@brief	Observerに変更を通知する機能を持つクラスです。
			@par
					状態の変更があった際に、必ずNotifyObservers()を呼んでください。
		*/
		class Subject
		{
		public:
			Subject();

			virtual ~Subject();

			/**
				@brief		Observerの追加
				@param[in]	observer	通知対象
				@return		追加成功したか
				@retval		true	追加成功
				@retval		false	既に追加されている
			*/
			bool AddObserver(Observer& observer);
	
			
			/**
				@brief		Observerの削除
				@param[in]	observer	通知対象
				@return		削除成功したか
				@retval		true	削除成功
				@retval		false	登録されていない
			*/
			bool DeleteObserver(const Observer& observer);


			/**
				@brief		登録されているObserverに変更を通知します。
				@return		なし
			*/
			void NotifyObservers();

		private:

			std::vector<Observer*>	m_observers;		//!< 通知するObserver

		};

	}
}
#endif	// ___Subject_h___