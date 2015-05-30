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
			@brief	�C�x���g�Ǘ��N���X
			@par
					
		*/
		class EventManager
		{
		public:
			EventManager();

			virtual ~EventManager();
			
			/**
				@brief		���X�i�[�̒ǉ�
				@param[in]	listener	���X�i�[
				@return		�ǉ�����������
				@retval		true	�ǉ�����
				@retval		false	���ɒǉ�����Ă���
			*/
			static bool AddListener(EventListener& listener);
			
			/**
				@brief		���X�i�[�̍폜
				@param[in]	listener	���X�i�[
				@return		�폜����������
				@retval		true	�폜����
				@retval		false	�o�^����Ă��Ȃ�
			*/
			static bool DeleteListener(EventListener& listener);

			/**
				@brief		�L�[�������ꂽ
				@param[in]	keyCode	�L�[�R�[�h
				@return		�Ȃ�
			*/
			void OnKeyDown(int keyCode);
			/**
				@brief		�L�[�������ꂽ
				@param[in]	keyCode	�L�[�R�[�h
				@return		�Ȃ�
			*/
			void OnKeyUp(int keyCode);
			/**
				@brief		�}�E�X�̃{�^���������ꂽ
				@param[in]	button	�{�^��
				@return		�Ȃ�
			*/
			void OnMouseButtonUp(int button);
			/**
				@brief		�}�E�X�̃{�^���������ꂽ
				@param[in]	button	�{�^��
				@return		�Ȃ�
			*/
			void OnMouseButtonDown(int button);

			/**
				@brief		�}�E�X���ړ�����
				@param[in]	mouseX	�}�E�XX���W(�P��:�s�N�Z��)
				@param[in]	mouseY	�}�E�XY���W(�P��:�s�N�Z��)
				@return		�Ȃ�
			*/
			void OnMouseMove(int mouseX, int mouseY);

			/**
				@brief		�`��
				@param[in]	renderer	�����_���[
				@return		�Ȃ�
			*/
			void OnPaint(RendererBase& renderer);

		private:
			static std::vector<EventListener*>	s_listeners;
		};
	}
}

#endif	// ___EventManager_h___