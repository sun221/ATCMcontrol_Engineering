



// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "pouvarselctrlwrapper.h"
#include "PouVarSelection.h"


/////////////////////////////////////////////////////////////////////////////
// CPouVarSelCtrlWrapper

IMPLEMENT_DYNCREATE(CPouVarSelCtrlWrapper, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CPouVarSelCtrlWrapper properties

/////////////////////////////////////////////////////////////////////////////
// CPouVarSelCtrlWrapper operations
HRESULT CPouVarSelCtrlWrapper::ShowPouSelection()
{
	//InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        return m_pPouVarSel->ShowPouSelection();
    }
}

HRESULT CPouVarSelCtrlWrapper::ShowVarSelection(const CString& strPouName)
{
	/*static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 sPouName);
         */
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        CComBSTR sName(strPouName);
        return m_pPouVarSel->ShowVarSelection(sName);
    }
}

HRESULT CPouVarSelCtrlWrapper::InitPouVarSelection()
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        return m_pPouVarSel->InitPouVarSelection();
    }
}

HRESULT CPouVarSelCtrlWrapper::SetVarSelectionHint(const CString& strPouName,
                                                   const CString& strVarNamePrefix,
                                                   const CString& strDataType)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        CComBSTR sPouName(strPouName);
        CComBSTR sVarNamePrefix(strVarNamePrefix);
        CComBSTR sDataType(strDataType);
        return m_pPouVarSel->SetVarSelectionHint(sPouName, sVarNamePrefix,
                                                 sDataType);
    }
}


HRESULT CPouVarSelCtrlWrapper::LookupUserHelp(const CString& strPou,
                                              CString& strFileName)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        CComBSTR sPou(strPou);
        CComBSTR sFileName;
        HRESULT hr = m_pPouVarSel->LookupUserHelp(sPou, &sFileName);
        if (hr==S_OK)
        {
            strFileName = sFileName;
        }
        return hr;
    }
}


HRESULT CPouVarSelCtrlWrapper::LookupHeader(const CString& strPou,
                                            CString& strHeaderFile)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        CComBSTR sPou(strPou);
        CComBSTR sHeaderFile;
        HRESULT hr =  m_pPouVarSel->LookupHeader(sPou, &sHeaderFile);
        if (hr==S_OK)
        {
            strHeaderFile = sHeaderFile;
        }
        return hr;
    }
}



HRESULT CPouVarSelCtrlWrapper::GetLRUPous(SAFEARRAY** parrPous)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        HRESULT hr =  m_pPouVarSel->GetLRUPous(parrPous);
        return hr;
    }
}

HRESULT CPouVarSelCtrlWrapper::GetPouXML(BSTR szPouName, 
                                         BSTR* pszPouDef)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        HRESULT hr =  m_pPouVarSel->GetPouXML(szPouName, pszPouDef);
        return hr;
    }
}

HRESULT CPouVarSelCtrlWrapper::GetVarList(SAFEARRAY** parrVars)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        HRESULT hr =  m_pPouVarSel->GetVarList(parrVars);
        return hr;
    }
}

HRESULT CPouVarSelCtrlWrapper::GetPouList(SAFEARRAY** parrPous)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        HRESULT hr =  m_pPouVarSel->GetPouList(parrPous);
        return hr;
    }
}

HRESULT CPouVarSelCtrlWrapper::GetPouDefinition(BSTR szPouName, 
                                                BSTR* pszPouDef)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        HRESULT hr =  m_pPouVarSel->GetPouDefinition(szPouName, pszPouDef);
        return hr;
    }
}

HRESULT CPouVarSelCtrlWrapper::GetPouMember(BSTR szPouName, 
                                            SAFEARRAY** parrMembers)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        HRESULT hr =  m_pPouVarSel->GetPouMember(szPouName, parrMembers);
        return hr;
    }
}

HRESULT CPouVarSelCtrlWrapper::ShowVarSelectionBox(LONG lXPos, LONG lYPos,
                                                   BSTR szLine, LONG lColumn,
                                                   BSTR szTypeHint,
                                                   BSTR szPouName,
                                                   BSTR* pszSelection,
                                                   LONG* plStartColumn,
                                                   LONG* plEndColumn)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        HRESULT hr =  m_pPouVarSel->ShowVarSelectionBox(lXPos, lYPos,
                                                        szLine, lColumn,
                                                        szTypeHint,
                                                        szPouName,
                                                        pszSelection,
                                                        plStartColumn,
                                                        plEndColumn);
        return hr;
    }
}

HRESULT CPouVarSelCtrlWrapper::DisablePouVarSelection(BOOL bDisable)
{
    if (!m_pPouVarSel)
    {
        IUnknown* pUnk = GetControlUnknown();
        ASSERT(pUnk);
        m_pPouVarSel = pUnk;
        ASSERT(!(!m_pPouVarSel));
    }
    if (!m_pPouVarSel)
    {
        return E_FAIL;
    }
    else
    {
        HRESULT hr =  m_pPouVarSel->DisablePouVarSelection(bDisable);
        return hr;
    }
}