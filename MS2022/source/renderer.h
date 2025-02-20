#pragma once


// 頂点構造体
struct VERTEX_3D {
    XMFLOAT3 Position;
    XMFLOAT3 Normal;
    XMFLOAT4 Diffuse;
    XMFLOAT2 TexCoord;
};

struct VERTEX_3D_NORMAL {
    XMFLOAT3 Position;
    XMFLOAT3 Normal;
    XMFLOAT3 Binormal;
    XMFLOAT3 Tangent;
    XMFLOAT4 Diffuse;
    XMFLOAT2 TexCoord;
};

// 色構造体
struct COLOR {
    COLOR() {}
    COLOR(float _r, float _g, float _b, float _a) {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }

    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float a = 0.0f;
};

// マテリアル構造体
struct MATERIAL {
    COLOR		Ambient;
    COLOR		Diffuse;
    COLOR		Specular;
    COLOR		Emission;
    float		Shininess;
    float		Dummy[3];//16bit境界用
};

// マテリアル構造体
struct DX11_MODEL_MATERIAL {
    MATERIAL		Material;
    class CTexture* Texture;
};

// 描画サブセット構造体
struct DX11_SUBSET {
    unsigned short	StartIndex;
    unsigned short	IndexNum;
    DX11_MODEL_MATERIAL	Material;
};

struct LIGHT {
    XMFLOAT4	Direction;
    COLOR		Diffuse;
    COLOR		Ambient;
};


class CVertexBuffer;
class CIndexBuffer;
class CTexture;

class CRenderer {
private:

    static D3D_FEATURE_LEVEL       m_FeatureLevel;

    static ID3D11Device* m_D3DDevice;
    static ID3D11DeviceContext* m_ImmediateContext;
    static IDXGISwapChain* m_SwapChain;
    static ID3D11RenderTargetView* m_RenderTargetView;
    static ID3D11DepthStencilView* m_DepthStencilView;

    static XMFLOAT4X4		    m_ViewMatrix;
    static XMFLOAT4X4		    m_ProjectionMatrix;
    /*
        static XMMATRIX				m_WorldMatrix;
        static XMMATRIX				m_ViewMatrix;
        static XMMATRIX				m_ProjectionMatrix;
    */
    static ID3D11DepthStencilState* m_DepthStateEnable;
    static ID3D11DepthStencilState* m_DepthStateDisable;


public:
    static void Init();
    static void Uninit();

    static void Begin();
    static void End();

    static void SetDepthEnable(bool Enable);
    static void SetVertexBuffers(ID3D11Buffer* VertexBuffer, unsigned int stride = sizeof(VERTEX_3D));
    static void SetIndexBuffer(ID3D11Buffer* IndexBuffer);
    static void SetTexture(CTexture* Texture, unsigned int Slot = 0);

    static void DrawIndexed(unsigned int IndexCount, unsigned int StartIndexLocation, int BaseVertexLocation);

    static ID3D11Device* GetDevice(void) { return m_D3DDevice; }
    static ID3D11DeviceContext* GetDeviceContext(void) { return m_ImmediateContext; }

    static void SetViewMatrix(XMFLOAT4X4 ViewMatrix) { m_ViewMatrix = ViewMatrix; }
    static XMFLOAT4X4 GetViewMatrix() { return m_ViewMatrix; }

    static void SetProjectionMatrix(XMFLOAT4X4 ProjectionMatrix) { m_ProjectionMatrix = ProjectionMatrix; }
    static XMFLOAT4X4 GetProjectionMatrix() { return m_ProjectionMatrix; }
};
