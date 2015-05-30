#ifndef ___EventListener_h___
#define ___EventListener_h___

namespace ex04_Design
{
	namespace chapter3
	{
		class RendererBase;
	}
}
namespace ex04_Design
{
	namespace chapter3
	{
		/**
			@enum		KeyCode
			@brief		キーコード
			@note
						Windowsの仮想キーコードと同じです。
						KEY_$で始まるキーコードは予約領域のキーです。
						KEY_LとKEY_Rで始まる各キーはWindowsのGetAsyncKeyState関数と
						GetKeyState関数のパラメータとしてのみ使用されます。
		*/
		enum KeyCode
		{
			KEY_$00					= 0x00,	//!< 予約領域
			KEY_LBUTTON				= 0x01,	//!< マウス左ボタン
			KEY_RBUTTON				= 0x02,	//!< マウス右ボタン
			KEY_CANCEL				= 0x03,	//!< Cancelキー(Ctrl+Break)
			KEY_MBUTTON				= 0x04,	//!< マウス中ボタン
			KEY_XBUTTON1			= 0x05,	//!< マウスX1ボタン
			KEY_XBUTTON2			= 0x06,	//!< マウスX2ボタン
			KEY_$07					= 0x07,	//!< 予約領域
			KEY_BACK				= 0x08,	//!< BackSpace
			KEY_TAB					= 0x09,	//!< TABキー
			KEY_$0A					= 0x0A,	//!< 予約領域
			KEY_$0B					= 0x0B,	//!< 予約領域
			KEY_CLEAR				= 0x0C,	//!< Clearキー(NumLockを外したテンキー5)
			KEY_RETURN				= 0x0D,	//!< Enterキー
			KEY_$0E					= 0x0E,	//!< 予約領域
			KEY_$0F					= 0x0F,	//!< 予約領域
			KEY_SHIFT				= 0x10,	//!< Shiftキー
			KEY_CONTROL				= 0x11,	//!< Ctrlキー
			KEY_MENU				= 0x12,	//!< Altキー
			KEY_PAUSE				= 0x13,	//!< Pauseキー
			KEY_CAPITAL				= 0x14,	//!< CapsLockキー
			KEY_KANA				= 0x15,	//!< カナモード
			KEY_$16					= 0x16,	//!< 予約領域
			KEY_JUNJA				= 0x17,	//!< 
			KEY_FINAL				= 0x18,	//!< 
			KEY_KANJI				= 0x19,	//!< 漢字モード
			KEY_$1A					= 0x1A,	//!< 予約領域
			KEY_ESCAPE				= 0x1B,	//!< ESCキー
			KEY_CONVERT				= 0x1C,	//!< 変換
			KEY_NONCONVERT			= 0x1D,	//!< 無変換
			KEY_ACCEPT				= 0x1E,	//!< 
			KEY_MODECHANGE			= 0x1F,	//!< IMEモード変更
			KEY_SPACE				= 0x20,	//!< スペースキー
			KEY_PRIOR				= 0x21,	//!< PageUp
			KEY_NEXT				= 0x22,	//!< PageDown
			KEY_END					= 0x23,	//!< End
			KEY_HOME				= 0x24,	//!< Home
			KEY_LEFT				= 0x25,	//!< ←
			KEY_UP					= 0x26,	//!< ↑
			KEY_RIGHT				= 0x27,	//!< →
			KEY_DOWN				= 0x28,	//!< ↓
			KEY_SELECT				= 0x29,	//!< Selectキー
			KEY_PRINT				= 0x2A,	//!< Printキー
			KEY_VK_EXECUTE			= 0x2B,	//!< Executeキー
			KEY_SNAPSHOT			= 0x2C,	//!< PrintScreen
			KEY_INSERT				= 0x2D,	//!< Insert
			KEY_DELETE				= 0x2E,	//!< Delete
			KEY_HELP				= 0x2F,	//!< Helpキー
			KEY_0					= 0x30,	//!< 0
			KEY_1					= 0x31,	//!< 1
			KEY_2					= 0x32,	//!< 2
			KEY_3					= 0x33,	//!< 3
			KEY_4					= 0x34,	//!< 4
			KEY_5					= 0x35,	//!< 5
			KEY_6					= 0x36,	//!< 6
			KEY_7					= 0x37,	//!< 7
			KEY_8					= 0x38,	//!< 8
			KEY_9					= 0x39,	//!< 9
			KEY_$3A					= 0x3A,	//!< 予約領域
			KEY_$3B					= 0x3B,	//!< 予約領域
			KEY_$3C					= 0x3C,	//!< 予約領域
			KEY_$3D					= 0x3D,	//!< 予約領域
			KEY_$3E					= 0x3E,	//!< 予約領域
			KEY_$3F					= 0x3F,	//!< 予約領域
			KEY_$40					= 0x40,	//!< 予約領域
			KEY_A					= 0x41,	//!< A
			KEY_B					= 0x42,	//!< B
			KEY_C					= 0x43,	//!< C
			KEY_D					= 0x44,	//!< D
			KEY_E					= 0x45,	//!< E
			KEY_F					= 0x46,	//!< F
			KEY_G					= 0x47,	//!< G
			KEY_H					= 0x48,	//!< H
			KEY_I					= 0x49,	//!< I
			KEY_J					= 0x4A,	//!< J
			KEY_K					= 0x4B,	//!< K
			KEY_L					= 0x4C,	//!< L
			KEY_M					= 0x4D,	//!< M
			KEY_N					= 0x4E,	//!< N
			KEY_O					= 0x4F,	//!< O
			KEY_P					= 0x50,	//!< P
			KEY_Q					= 0x51,	//!< Q
			KEY_R					= 0x52,	//!< R
			KEY_S					= 0x53,	//!< S
			KEY_T					= 0x54,	//!< T
			KEY_U					= 0x55,	//!< U
			KEY_V					= 0x56,	//!< V
			KEY_W					= 0x57,	//!< W
			KEY_X					= 0x58,	//!< X
			KEY_Y					= 0x59,	//!< Y
			KEY_Z					= 0x5A,	//!< Z
			KEY_LWIN				= 0x5B,	//!< 左Windowsキー
			KEY_RWIN				= 0x5C,	//!< 右Windowsキー
			KEY_APPS				= 0x5D,	//!< アプリケーションキー
			KEY_$5E					= 0x5E,	//!< 予約領域
			KEY_SLEEP				= 0x5F,	//!< スリープキー
			KEY_NUMPAD0				= 0x60,	//!< Num 0
			KEY_NUMPAD1				= 0x61,	//!< Num 1
			KEY_NUMPAD2				= 0x62,	//!< Num 2
			KEY_NUMPAD3				= 0x63,	//!< Num 3
			KEY_NUMPAD4				= 0x64,	//!< Num 4
			KEY_NUMPAD5				= 0x65,	//!< Num 5
			KEY_NUMPAD6				= 0x66,	//!< Num 6
			KEY_NUMPAD7				= 0x67,	//!< Num 7
			KEY_NUMPAD8				= 0x68,	//!< Num 8
			KEY_NUMPAD9				= 0x69,	//!< Num 9
			KEY_MULTIPLY			= 0x6A,	//!< Num *
			KEY_ADD					= 0x6B,	//!< Num +
			KEY_SEPARATOR			= 0x6C,	//!< Num ,
			KEY_SUBTRACT			= 0x6D,	//!< Num -
			KEY_DECIMAL				= 0x6E,	//!< Num .
			KEY_DIVIDE				= 0x6F,	//!< Num /
			KEY_F1					= 0x70,	//!< F1	
			KEY_F2					= 0x71,	//!< F2	
			KEY_F3					= 0x72,	//!< F3	
			KEY_F4					= 0x73,	//!< F4	
			KEY_F5					= 0x74,	//!< F5	
			KEY_F6					= 0x75,	//!< F6	
			KEY_F7					= 0x76,	//!< F7	
			KEY_F8					= 0x77,	//!< F8	
			KEY_F9					= 0x78,	//!< F9	
			KEY_F10					= 0x79,	//!< F10
			KEY_F11					= 0x7A,	//!< F11
			KEY_F12					= 0x7B,	//!< F12
			KEY_F13					= 0x7C,	//!< F13
			KEY_F14					= 0x7D,	//!< F14
			KEY_F15					= 0x7E,	//!< F15
			KEY_F16					= 0x7F,	//!< F16
			KEY_F17					= 0x80,	//!< F17
			KEY_F18					= 0x81,	//!< F18
			KEY_F19					= 0x82,	//!< F19
			KEY_F20					= 0x83,	//!< F20
			KEY_F21					= 0x84,	//!< F21
			KEY_F22					= 0x85,	//!< F22
			KEY_F23					= 0x86,	//!< F23
			KEY_F24					= 0x87,	//!< F24
			KEY_$88					= 0x88,	//!< 予約領域
			KEY_$89					= 0x89,	//!< 予約領域
			KEY_$8A					= 0x8A,	//!< 予約領域
			KEY_$8B					= 0x8B,	//!< 予約領域
			KEY_$8C					= 0x8C,	//!< 予約領域
			KEY_$8D					= 0x8D,	//!< 予約領域
			KEY_$8E					= 0x8E,	//!< 予約領域
			KEY_$8F					= 0x8F,	//!< 予約領域
			KEY_NUMLOCK				= 0x90,	//!< NumLock
			KEY_SCROLL				= 0x91,	//!< ScrollLock
			KEY_EQUAL				= 0x92,	//!< Num =
			KEY_$93					= 0x93,	//!< 予約領域
			KEY_$94					= 0x94,	//!< 予約領域
			KEY_$95					= 0x95,	//!< 予約領域
			KEY_$96					= 0x96,	//!< 予約領域
			KEY_$97					= 0x97,	//!< 予約領域
			KEY_$98					= 0x98,	//!< 予約領域
			KEY_$99					= 0x99,	//!< 予約領域
			KEY_$9A					= 0x9A,	//!< 予約領域
			KEY_$9B					= 0x9B,	//!< 予約領域
			KEY_$9C					= 0x9C,	//!< 予約領域
			KEY_$9D					= 0x9D,	//!< 予約領域
			KEY_$9E					= 0x9E,	//!< 予約領域
			KEY_$9F					= 0x9F,	//!< 予約領域
			KEY_LSHIFT				= 0xA0,	//!< 左Shiftキー
			KEY_RSHIFT				= 0xA1,	//!< 右Shiftキー
			KEY_LCONTROL			= 0xA2,	//!< 左Ctrlキー
			KEY_RCONTROL			= 0xA3,	//!< 右Ctrlキー
			KEY_LMENU				= 0xA4,	//!< 左Altキー
			KEY_RMENU				= 0xA5,	//!< 右Altキー
			KEY_BROWSER_BACK		= 0xA6,	//!< ブラウザ戻るキー
			KEY_BROWSER_FORWARD		= 0xA7,	//!< ブラウザ次へキー
			KEY_BROWSER_REFRESH		= 0xA8,	//!< ブラウザ更新キー
			KEY_BROWSER_STOP		= 0xA9,	//!< ブラウザ中止キー
			KEY_BROWSER_SEARCH		= 0xAA,	//!< ブラウザ検索キー
			KEY_BROWSER_FAVORITES	= 0xAB,	//!< ブラウザお気に入りキー
			KEY_BROWSER_HOME		= 0xAC,	//!< ブラウザホームキー
			KEY_VOLUME_MUTE			= 0xAD,	//!< ボリュームミュート
			KEY_VOLUME_DOWN			= 0xAE,	//!< ボリュームダウン
			KEY_VOLUME_UP			= 0xAF,	//!< ボリュームアップ
			KEY_MEDIA_NEXT_TRACK	= 0xB0,	//!< 次のトラック
			KEY_MEDIA_PREV_TRACK	= 0xB1,	//!< 前のトラック
			KEY_MEDIA_STOP			= 0xB2,	//!< メディア中止
			KEY_MEDIA_PLAY_PAUSE	= 0xB3,	//!< メディアStart/Stop
			KEY_LAUNCH_MAIL			= 0xB4,	//!< メール開始
			KEY_LAUNCH_MEDIA_SELECT	= 0xB5,	//!< メディア選択
			KEY_LAUNCH_APP1			= 0xB6,	//!< アプリケーション1起動キー
			KEY_LAUNCH_APP2			= 0xB7,	//!< アプリケーション2起動キー
			KEY_$B8					= 0xB8,	//!< 予約領域
			KEY_$B9					= 0xB9,	//!< 予約領域
			KEY_OEM_1				= 0xBA,	//!< : U.S.標準';:'
			KEY_OEM_PLUS			= 0xBB,	//!< ; U.S.標準'+'
			KEY_OEM_COMMA			= 0xBC,	//!< , U.S.標準','
			KEY_OEM_MINUS			= 0xBD,	//!< - U.S.標準'-'
			KEY_OEM_PERIOD			= 0xBE,	//!< . U.S.標準'.'
			KEY_OEM_2				= 0xBF,	//!< / U.S.標準'/?'
			KEY_OEM_3				= 0xC0,	//!< @ U.S.標準'`~'
			KEY_$C1					= 0xC1,	//!< 予約領域
			KEY_$C2					= 0xC2,	//!< 予約領域
			KEY_$C3					= 0xC3,	//!< 予約領域
			KEY_$C4					= 0xC4,	//!< 予約領域
			KEY_$C5					= 0xC5,	//!< 予約領域
			KEY_$C6					= 0xC6,	//!< 予約領域
			KEY_$C7					= 0xC7,	//!< 予約領域
			KEY_$C8					= 0xC8,	//!< 予約領域
			KEY_$C9					= 0xC9,	//!< 予約領域
			KEY_$CA					= 0xCA,	//!< 予約領域
			KEY_$CB					= 0xCB,	//!< 予約領域
			KEY_$CC					= 0xCC,	//!< 予約領域
			KEY_$CD					= 0xCD,	//!< 予約領域
			KEY_$CE					= 0xCE,	//!< 予約領域
			KEY_$CF					= 0xCF,	//!< 予約領域
			KEY_$D0					= 0xD0,	//!< 予約領域
			KEY_$D1					= 0xD1,	//!< 予約領域
			KEY_$D2					= 0xD2,	//!< 予約領域
			KEY_$D3					= 0xD3,	//!< 予約領域
			KEY_$D4					= 0xD4,	//!< 予約領域
			KEY_$D5					= 0xD5,	//!< 予約領域
			KEY_$D6					= 0xD6,	//!< 予約領域
			KEY_$D7					= 0xD7,	//!< 予約領域
			KEY_$D8					= 0xD8,	//!< 予約領域
			KEY_$D9					= 0xD9,	//!< 予約領域
			KEY_$DA					= 0xDA,	//!< 予約領域
			KEY_OEM_4				= 0xDB,	//!< [ U.S.標準'[{'
			KEY_OEM_5				= 0xDC,	//!< \ U.S.標準'\|'
			KEY_OEM_6				= 0xDD,	//!< ] U.S.標準']}'
			KEY_OEM_7				= 0xDE,	//!< ^ U.S.標準''"'
			KEY_OEM_8				= 0xDF,	//!< _
			KEY_$E0					= 0xE0,	//!< 予約領域
			KEY_OEM_AX				= 0xE1,	//!< AXキーボードの'AX'
			KEY_OEM_102				= 0xE2,	//!< _ RT 102-keyキーボード"<>"または"\|"
			KEY_ICO_HELP			= 0xE3,	//!< ICOキーボードHelpキー
			KEY_ICO_00				= 0xE4,	//!< ICOキーボード00キー
			KEY_PROCESSKEY			= 0xE5,	//!< 半角/全角 前候補
			KEY_ICO_CLEAR			= 0xE6,	//!< ICOキーボードClearキー
			KEY_PACKET				= 0xE7,	//!< 
			KEY_$E8					= 0xE8,	//!< 予約領域
			KEY_OEM_RESET			= 0xE9,	//!< 
			KEY_OEM_JUMP			= 0xEA,	//!< 
			KEY_OEM_PA1				= 0xEB,	//!< 
			KEY_OEM_PA2				= 0xEC,	//!< 
			KEY_OEM_PA3				= 0xED,	//!< 
			KEY_OEM_WSCTRL			= 0xEE,	//!< 
			KEY_OEM_CUSEL			= 0xEF,	//!< 
			KEY_OEM_ATTN			= 0xF0,	//!< CapsLock
			KEY_OEM_FINISH			= 0xF1,	//!< 
			KEY_OEM_COPY			= 0xF2,	//!< カタカナ/ひらがな
			KEY_OEM_AUTO			= 0xF3,	//!< 
			KEY_OEM_ENLW			= 0xF4,	//!< 
			KEY_OEM_BACKTAB			= 0xF5,	//!< 
			KEY_ATTN				= 0xF6,	//!< Attn
			KEY_CRSEL				= 0xF7,	//!< CrSel
			KEY_EXSEL				= 0xF8,	//!< ExSel
			KEY_EREOF				= 0xF9,	//!< Erase EOF
			KEY_PLAY				= 0xFA,	//!< Play
			KEY_ZOOM				= 0xFB,	//!< Zoom
			KEY_NONAME				= 0xFC,	//!< 予約
			KEY_PA1					= 0xFD,	//!< PA1
			KEY_OEM_CLEAR			= 0xFE,	//!< Clear
			KEY_$FF					= 0xFF,	//!< 予約領域
		};

		/**
			@enum	MouseButtons
			@brief	マウスボタン
		*/
		enum MouseButtons
		{
			MOUSE_LBUTTON = 1,				//!< マウス左ボタン
			MOUSE_RBUTTON = 1 << 1,			//!< マウス右ボタン
			MOUSE_MBUTTON = 1 << 2,			//!< マウス中ボタン

			MOUSE_BUTTON_0 = MOUSE_LBUTTON,	//!< マウス左ボタン
			MOUSE_BUTTON_1 = MOUSE_RBUTTON,	//!< マウス右ボタン
			MOUSE_BUTTON_2 = MOUSE_MBUTTON,	//!< マウス中ボタン
		};


		/**
			@class	EventListener
			@brief	イベント受け取りリスナー
		*/
		class EventListener
		{
		public:
			virtual ~EventListener() = 0;

			/**
				@brief		キーが押された
				@param[in]	keyCode	キーコード
				@return		イベント通知を続けるか
				@retval		true	続ける
				@retval		false	イベントの破棄
			*/
			virtual bool OnKeyDown(int keyCode) = 0;
			/**
				@brief		キーが離された
				@param[in]	keyCode	キーコード
				@return		イベント通知を続けるか
				@retval		true	続ける
				@retval		false	イベントの破棄
			*/
			virtual bool OnKeyUp(int keyCode) = 0;
			/**
				@brief		マウスのボタンが押された
				@param[in]	button	ボタン
				@return		イベント通知を続けるか
				@retval		true	続ける
				@retval		false	イベントの破棄
			*/
			virtual bool OnMouseButtonUp(int button) = 0;
			/**
				@brief		マウスのボタンが離された
				@param[in]	button	ボタン
				@return		イベント通知を続けるか
				@retval		true	続ける
				@retval		false	イベントの破棄
			*/
			virtual bool OnMouseButtonDown(int button) = 0;

			/**
				@brief		マウスが移動した
				@param[in]	mouseX	マウスX座標(単位:ピクセル)
				@param[in]	mouseY	マウスY座標(単位:ピクセル)
				@return		イベント通知を続けるか
				@retval		true	続ける
				@retval		false	イベントの破棄
			*/
			virtual bool OnMouseMove(int mouseX, int mouseY) = 0;

			/**
				@brief		描画
				@param[in]	renderer	レンダラー
				@return		イベント通知を続けるか
				@retval		true	続ける
				@retval		false	イベントの破棄
			*/
			virtual bool OnPaint(RendererBase& renderer) = 0;
		};

	}
}

#endif	// ___EventListener_h___