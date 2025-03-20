// FirstMFCopenglDoc.h : interface of the CFirstMFCopenglDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIRSTMFCOPENGLDOC_H__F01197B1_4146_4119_B9AE_59ED715FF5F0__INCLUDED_)
#define AFX_FIRSTMFCOPENGLDOC_H__F01197B1_4146_4119_B9AE_59ED715FF5F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFirstMFCopenglDoc : public CDocument
{
protected: // create from serialization only
	CFirstMFCopenglDoc();
	DECLARE_DYNCREATE(CFirstMFCopenglDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFirstMFCopenglDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFirstMFCopenglDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFirstMFCopenglDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIRSTMFCOPENGLDOC_H__F01197B1_4146_4119_B9AE_59ED715FF5F0__INCLUDED_)
