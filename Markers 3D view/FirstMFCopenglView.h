// FirstMFCopenglView.h : interface of the CFirstMFCopenglView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIRSTMFCOPENGLVIEW_H__F285BB99_897D_4FD3_9DF8_B52BBCF9F6CD__INCLUDED_)
#define AFX_FIRSTMFCOPENGLVIEW_H__F285BB99_897D_4FD3_9DF8_B52BBCF9F6CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<gl/gl.h>
#include<gl/glu.h>
#include <GL/GLAUX.H>
#include< GL/glut.h > 
#include "Afxdb.h"
#include <odbcinst.h>
class CFirstMFCopenglView : public CView
{
protected: // create from serialization only
	CFirstMFCopenglView();
	DECLARE_DYNCREATE(CFirstMFCopenglView)

// Attributes
public:
	CFirstMFCopenglDoc* GetDocument();
    CClientDC *m_pDC;
	HGLRC m_hglrc;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFirstMFCopenglView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	float angle;
	float x,point[4][3];
	CDatabase m_database;
	CRecordset *Recordset;
    GLuint texture[2];                //纹理的存储空间 ( 新 )  
	virtual ~CFirstMFCopenglView();
	CString GetExcelDriver();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFirstMFCopenglView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FirstMFCopenglView.cpp
inline CFirstMFCopenglDoc* CFirstMFCopenglView::GetDocument()
   { return (CFirstMFCopenglDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIRSTMFCOPENGLVIEW_H__F285BB99_897D_4FD3_9DF8_B52BBCF9F6CD__INCLUDED_)
