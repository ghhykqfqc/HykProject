#pragma once

/*
* Code By Tojen (qq:342269237)
* �������ͼƬ��Դ80%ԭ����������ȫԭ��,ѧϰ��Ʒ����������ש
*/
#include <objbase.h>
#include <zmouse.h>
#include <exdisp.h>
#include <comdef.h>
#include <vector>
#include <sstream>
#include <io.h>
#include <shellapi.h>

#include "MenuWnd.h"
#include "..\DuiLib\UIlib.h"

#include <fstream>
#include <winioctl.h>
#include <map>
#include<iostream>
#include <string>
#include "../libcURL/include/curl.h"

#ifdef _DEBUG
#pragma comment(lib, "../libcURL/lib/libcurld.lib")
#else
#pragma comment(lib, "../libcURL/lib/libcurl.lib")
#endif

#include "kutfconv.h"

using namespace DuiLib;


#define WM_ADDLISTITEM WM_USER + 50
static map<string, string>myMap;

/*
*  �̺߳����д���Ľṹ�������ʹ���߳�Ϊ��ʹ�����߳��������أ���ֹ��ס�����Ƕ��á�
*/
struct Prama
{
	HWND hWnd;
	CListUI* pList;
	CButtonUI* pSearch;
	CDuiString tDomain;
};

struct TestMem {
	int count;
};


class ListMainForm : public CWindowWnd, public INotifyUI, public IListCallbackUI
{
public:
    ListMainForm() {
    };
	//void Text();

	void OnQQLogin();

	/*void SaveUserInfo(Context context, string number,
		string password);*/

	bool CheckUInfo(string str_UN, string str_Pwd);

	string GetUserInfo(CEditUI* m_pUNEdit, CEditUI* m_pPwdEdit);

	map<string, string> GetUrlInfo(const string& resString);

	void Format(string& str);

	void StrSplit(const string& str, string& s1, string& s2);

	CDuiString GetSkinFolder()
	{

		return _T("skin\\ListRes\\");
	}

	CDuiString GetSkinFile()
	{
		return _T("qq.xml");
	}

    LPCTSTR GetWindowClassName() const 
    { 
        return _T("ScanMainForm"); 
    };

    UINT GetClassStyle() const
    { 
        return CS_DBLCLKS; 
    };

    void OnFinalMessage(HWND /*hWnd*/) 
    { 
        delete this;
    };

	void Init();

    void OnPrepare(TNotifyUI& msg) 
    {

    }

	static DWORD WINAPI Search(LPVOID lpParameter);

	void Login();
	
	void ChangeImg();

	void ShakeWnd();

	//void SetImagePath();

	void OnSearch();

	void Changebk(DWORD control)
	{
		m_pMainbk->SetBkColor(control);
		m_pMainbk->SetBkImage(_T("͸��.png"));
	}
 
	LPCTSTR GetItemText(CControlUI* pControl, int iIndex, int iSubItem);

	void Notify(TNotifyUI& msg);

	LRESULT OnAddListItem(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

    LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        bHandled = FALSE;
        return 0;
    }
	void					onTimerTest();
	void				  OnTimer(WPARAM wParam, LPARAM lParam); //��ʱ��

    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        ::PostQuitMessage(0L);
        bHandled = FALSE;
        return 0;
    }

    LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        if( ::IsIconic(*this) ) bHandled = FALSE;
        return (wParam == 0) ? TRUE : FALSE;
    }

    LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        return 0;
    }

    LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        return 0;
    }

	LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	/**
	*��С�ı�Ļص����������Գ���ע�ͣ��޸Ĵ��� ��Ч��
	*/
	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	/***
	* ��������windowsϵͳ�ĸ�����Ϣ��WM= windows  message
	*/
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
    CPaintManagerUI m_pm;

private:
    CButtonUI* m_pCloseBtn;  //�˴���Ա������m_ ��ͷ�������׼�أ������Ⱪ¶�ĳ�Աһ����private����
    CButtonUI* m_pMaxBtn;
    CButtonUI* m_pRestoreBtn;
    CButtonUI* m_pMinBtn;
    CButtonUI* m_pSearch;
    CButtonUI* m_pChangeimg;
    CButtonUI* m_pQRcode;
    CButtonUI* m_pLogo;
    CButtonUI* m_pSetting;
    CButtonUI* m_pReturn;
    CButtonUI* m_pbkc_default;
	CButtonUI* m_pbkc_lightblue;
	CButtonUI* m_pbkc_green;
	CButtonUI* m_pbkc_red;
	CButtonUI* m_pbkc_bkiamge;
    CEditUI* m_pEdit;
	CEditUI* m_pUNEdit;
	CEditUI* m_pPwdEdit;
    CHorizontalLayoutUI* m_pLogin;
    CHorizontalLayoutUI* m_pQRcodepage;
    CVerticalLayoutUI* m_pSkinlayout;
    CVerticalLayoutUI* m_pLoginpage;
    CVerticalLayoutUI* m_pMainbk;

	CWebBrowserUI* m_pWebBrowser;

};