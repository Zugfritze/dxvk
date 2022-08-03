#pragma once

#include "d3d11_include.h"

#include "../dxvk/dxvk_annotation.h"
#include "../dxvk/dxvk_device.h"

namespace dxvk {

  class D3D11DeviceContext;

  class D3D11UserDefinedAnnotation final : public IDXVKUserDefinedAnnotation {

  public:

    D3D11UserDefinedAnnotation(
            D3D11DeviceContext*   container,
      const Rc<DxvkDevice>&       dxvkDevice);

    ~D3D11UserDefinedAnnotation();

    D3D11UserDefinedAnnotation             (const D3D11UserDefinedAnnotation&) = delete;
    D3D11UserDefinedAnnotation& operator = (const D3D11UserDefinedAnnotation&) = delete;

    ULONG STDMETHODCALLTYPE AddRef();
    
    ULONG STDMETHODCALLTYPE Release();
    
    HRESULT STDMETHODCALLTYPE QueryInterface(
            REFIID                  riid,
            void**                  ppvObject);
    
    INT STDMETHODCALLTYPE BeginEvent(
            D3DCOLOR                Color,
            LPCWSTR                 Name);

    INT STDMETHODCALLTYPE EndEvent();

    void STDMETHODCALLTYPE SetMarker(
            D3DCOLOR                Color,
            LPCWSTR                 Name);

    BOOL STDMETHODCALLTYPE GetStatus();

  private:

    D3D11DeviceContext*   m_container;
    int32_t               m_eventDepth;
    bool                  m_annotationsEnabled;
  };

}
