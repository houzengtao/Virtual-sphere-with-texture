// FirstMFCopenglDoc.cpp : implementation of the CFirstMFCopenglDoc class
//

#include "stdafx.h"
#include "FirstMFCopengl.h"

#include "FirstMFCopenglDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglDoc

IMPLEMENT_DYNCREATE(CFirstMFCopenglDoc, CDocument)

BEGIN_MESSAGE_MAP(CFirstMFCopenglDoc, CDocument)
	//{{AFX_MSG_MAP(CFirstMFCopenglDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglDoc construction/destruction

CFirstMFCopenglDoc::CFirstMFCopenglDoc()
{
	// TODO: add one-time construction code here

}

CFirstMFCopenglDoc::~CFirstMFCopenglDoc()
{
}

BOOL CFirstMFCopenglDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglDoc serialization

void CFirstMFCopenglDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglDoc diagnostics

#ifdef _DEBUG
void CFirstMFCopenglDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFirstMFCopenglDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglDoc commands
