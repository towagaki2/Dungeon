#pragma once
/*!
 *@brief	グラフィックスエンジン。
 */
class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();
	/*!
	 *@brief	初期化。
	 *@param[in]	hWnd		ウィンドウハンドル。
	 */
	void Init(HWND hWnd);
	/*!
	 *@brief	解放。
	 */
	void Release();
	/*!
	 *@brief	D3D11デバイスを取得。
	 */
	ID3D11Device* GetD3DDevice()
	{
		return m_pd3dDevice;
	}
	/*!
	 *@brief	D3D11デバイスコンテキストを取得。
	 */
	ID3D11DeviceContext* GetD3DDeviceContext()
	{
		return m_pd3dDeviceContext;
	}
	/// <summary>
	/// ラスタライザステートのゲット
	/// </summary>
	/// <returns>
	/// ラスタライザステート（ID3D11RasterizerState* ）
	/// </returns>
	ID3D11RasterizerState* GetRasterizerState()
	{
		return m_rasterizerState;
	}
	/*!
	 *@brief	描画開始。
	 */
	void BegineRender();
	/*!
	 *@brief	描画終了。
	 */
	void EndRender();
	DirectX::SpriteFont* GetSpriteFont()
	{
		return m_SpriteFont;
	}
	/// <summary>
	/// フォント表示に必要なクラスを取得
	/// </summary>
	/// <returns>
	/// フォント表示に必要なクラス（DirectX::SpriteBatch*）
	/// </returns>
	DirectX::SpriteBatch* GetSpriteBatch()
	{
		return m_SpriteBatch;
	}
private:
	D3D_FEATURE_LEVEL		m_featureLevel;				//Direct3D デバイスのターゲットとなる機能セット。
	ID3D11Device*			m_pd3dDevice = NULL;		//D3D11デバイス。
	IDXGISwapChain*			m_pSwapChain = NULL;		//スワップチェイン。
	ID3D11DeviceContext*	m_pd3dDeviceContext = NULL;	//D3D11デバイスコンテキスト。
	ID3D11RenderTargetView* m_backBuffer = NULL;		//バックバッファ。
	ID3D11RasterizerState*	m_rasterizerState = NULL;	//ラスタライザステート。
	ID3D11Texture2D*		m_depthStencil = NULL;		//デプスステンシル。
	ID3D11DepthStencilView* m_depthStencilView = NULL;	//デプスステンシルビュー。
	DirectX::SpriteFont*    m_SpriteFont = NULL;		//ゲームのデフォルトのフォントデータ
	DirectX::SpriteBatch*   m_SpriteBatch = NULL;		//ゲームのデフォルトのフォント表示用データ

};

extern GraphicsEngine* g_graphicsEngine;			//グラフィックスエンジン