// FirstMFCopenglView.cpp : implementation of the CFirstMFCopenglView class
//

#include "stdafx.h"
#include "FirstMFCopengl.h"

#include "FirstMFCopenglDoc.h"
#include "FirstMFCopenglView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglView

IMPLEMENT_DYNCREATE(CFirstMFCopenglView, CView)

BEGIN_MESSAGE_MAP(CFirstMFCopenglView, CView)
	//{{AFX_MSG_MAP(CFirstMFCopenglView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglView construction/destruction

CFirstMFCopenglView::CFirstMFCopenglView()
{
	// TODO: add construction code here

}

CFirstMFCopenglView::~CFirstMFCopenglView()
{
	m_database.Close();
}

BOOL CFirstMFCopenglView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
  cs.lpszClass=AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW);
  cs.style|=WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_MAXIMIZE;
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglView drawing

void CFirstMFCopenglView::OnDraw(CDC* pDC)
{
	CFirstMFCopenglDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	 if(!pDoc)
		 return;
	 if(m_hglrc) wglMakeCurrent(m_pDC->GetSafeHdc(),m_hglrc);
	  else return;

	 glLoadIdentity();//�ο���ԭ�㣨��Ļ���ģ�
	  glDrawBuffer(GL_BACK);	 
	  glClearColor(0.0f,0.0f,0.0f,0.0f);//���ñ���ɫΪ��ɫ
   	//glClearColor ( 0.0, 0.0, 1.0, 0.0 ); //���ñ���ɫΪ��ɫ 
	/*  glBegin(GL_LINE_STRIP);// ��ʼ����ֱ��
	glColor3f(1.0,0.0,0.0);// ������ɫ����
	glVertex2s(-12,-10);// ��һ���ߵ����

	glColor3f(0,1,0.0);// ������ɫ����
	glVertex2s(0,10);// ��һ���ߵ��յ㣬���ڶ����ߵ���㡣
    
	glColor3f(0,0.0,1);
	glVertex2s(12,-10);

	glColor3f(1.0,0.0,0.0);
	glVertex2s(-12,-10);
	glEnd();// ��������*/
	
/*	 GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);//set material ����ⷴ��
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//���ò��Ϸ���ָ��
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);//��Դλ��

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	auxSolidSphere(2.0);*/
    GLfloat light_position [ ] = { 0.0, 0.0, 1.0, 0 }; 
	GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };//��ɫ����
	GLfloat mat_diffuse1[] = { 0.8, 0.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };//���NֵԽ�����߳ߴ�ԽС������Խ�й��󣬷�֮Խ��Nֵ��ȡ1-128֮�������������
    GLUquadricObj *quadObj = gluNewQuadric();//����һ��������������

	glShadeModel ( GL_SMOOTH ); 
	glEnable (GL_LIGHTING); 
	glEnable (GL_LIGHT0); //�׹�
	glEnable (GL_DEPTH_TEST);
//	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_specular);//�������
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//���ò��Ϸ���ָ��
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//�趨���ʵ���ɫ�������������ȫ��ģ�������ã�����glDisable( GL_LIGHTING )֮���
 
	glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);//û���������µļ�����glColor3f��ɫ��������

   //glLightfv(GL_LIGHT0,GL_AMBIENT,mat_diffuse); //��Դ�Ĺ�ǿ
  // glLightfv(GL_LIGHT0,GL_DIFFUSE,mat_diffuse); //��Դ����ɫ
  // glLightfv(GL_LIGHT0,GL_SPECULAR,white_light); //��Դ�еľ��淴���ǿ�� 


	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLightfv( GL_LIGHT0, GL_POSITION, light_position); 

//�����ľ�ֱ�߷���������
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);



 glPushMatrix();
      glTranslatef(-100.0f,-150.0f,-0.0f);
	  glRotatef(-90,0.0f,0.0f,1.0f);//��xy������ת
      glRotatef(angle,1.0f,0.0f,0.0f);//��xz������ת

//��1���� 
	glColor3f(1.0,0.0,0);//��    
    glBindTexture(GL_TEXTURE_2D, texture[0]);//������     
	glPushMatrix();
	glTranslatef(0.0f,0.0f,1500.0f);
	glTranslatef(point[0][0],point[0][1],point[0][2]);
    glRotatef(-90,1.0f,0.0f,0.0f);//Ϊ����ͼ��������
	glRotatef(-90,0.0f,1.0f,0.0f);//Ϊ����ͼ��������
    //glutSolidSphere (5.5, 40, 50); //�뾶5.5mm,glut����������
     glBegin(GL_QUADS);
     gluQuadricTexture(quadObj,GL_TRUE);        //���øö������������
     gluSphere(quadObj,5.5,40,40); //��Բ
     gluDeleteQuadric(quadObj);
     glEnd();
   	glPopMatrix();

//��2���� 
	glColor3f(1.0,0.0,0);//��
    glBindTexture(GL_TEXTURE_2D, texture[0]);//������     
	glPushMatrix();//����
    //glRotatef(angle,0.0f,1.0f,0.0f);//��xz������ת
	glTranslatef(0.0f,0.0f,1500.0f);
    glTranslatef(point[1][0],point[1][1],point[1][2]);
    glRotatef(-90,1.0f,0.0f,0.0f);//Ϊ����ͼ��������
	glRotatef(-90,0.0f,1.0f,0.0f);//Ϊ����ͼ��������
    //glutSolidSphere (5.5, 40, 50); //�뾶5.5mm	
     GLUquadricObj *quadObj2 = gluNewQuadric();//����һ��������������
     glBegin(GL_QUADS);
     gluQuadricTexture(quadObj2,GL_TRUE);        //���øö������������
     gluSphere(quadObj2,5.5,20,20); //��Բ
     gluDeleteQuadric(quadObj2);
    glPopMatrix();//����

//����
	glPushMatrix();//����
	glTranslatef(0.0f,0.0f,1500.0f);
	glLineWidth(3); 
    glBegin(GL_LINES);	
    glVertex3f(point[0][0],point[0][1],point[0][2]);
    glVertex3f(point[1][0],point[1][1],point[1][2]);    
    glEnd();
    glPopMatrix();//����

//��3���� 
	glColor3f(0,1,0);//��
    glBindTexture(GL_TEXTURE_2D, texture[1]);//������     
    glPushMatrix();	
	glTranslatef(point[2][0],point[2][1],point[2][2]);
	glTranslatef(0.0f,0.0f,1500.0f);
    glRotatef(-90,1.0f,0.0f,0.0f);//Ϊ����ͼ��������
	glRotatef(-90,0.0f,1.0f,0.0f);//Ϊ����ͼ��������
    //glutSolidSphere (5.5, 40, 50); //�뾶5.5mm
     GLUquadricObj *quadObj3 = gluNewQuadric();//����һ��������������
     glBegin(GL_QUADS);
     gluQuadricTexture(quadObj3,GL_TRUE);      //���øö������������
     gluSphere(quadObj3,5.5,20,20); //��Բ
     gluDeleteQuadric(quadObj3);
    glPopMatrix();

//��4����
	glColor3f(0,1,0);//��
    glBindTexture(GL_TEXTURE_2D, texture[1]);//������       
    glPushMatrix();	
	glTranslatef(point[3][0],point[3][1],point[3][2]);
	glTranslatef(0.0f,0.0f,1500.0f);
    glRotatef(-90,1.0f,0.0f,0.0f);//Ϊ����ͼ��������
	glRotatef(-90,0.0f,1.0f,0.0f);//Ϊ����ͼ��������
    //glutSolidSphere (5.5, 40, 50); //�뾶5.5mm
     GLUquadricObj *quadObj4= gluNewQuadric();//����һ��������������
     glBegin(GL_QUADS);
     gluQuadricTexture(quadObj4,GL_TRUE);     //���øö������������
     gluSphere(quadObj4,5.5,20,20); //��Բ
     gluDeleteQuadric(quadObj4);
    glPopMatrix();

 //����
	glPushMatrix();//����
	glTranslatef(0.0f,0.0f,1500.0f);
	glLineWidth(3); 
    glBegin(GL_LINES);
    glVertex3f(point[2][0],point[2][1],point[2][2]);
    glVertex3f(point[3][0],point[3][1],point[3][2]);    
    glEnd();
    glPopMatrix();//����

/*	glColor3f(1.0,1.0,0);//��
	glPushMatrix();
	//glScalef(0.2,0.2,0.2);//ע��˾��λ�ò�ͬ��ʾЧ����ȫ��ͬ
	glRotatef(angle,0.0f,0.0f,1.0f);//��xy������ת
	auxSolidCylinder(2.0f,85.0f);
    glPopMatrix();*/
  glPopMatrix();
	glFlush();// ˢ��	
	SwapBuffers(wglGetCurrentDC());//û��䲻��ͼ������ɫ�ı�����������
	glDrawBuffer(GL_FRONT);//û��䲻Ӱ���κ�

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglView printing

BOOL CFirstMFCopenglView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFirstMFCopenglView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFirstMFCopenglView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglView diagnostics

#ifdef _DEBUG
void CFirstMFCopenglView::AssertValid() const
{
	CView::AssertValid();
}

void CFirstMFCopenglView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFirstMFCopenglDoc* CFirstMFCopenglView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFirstMFCopenglDoc)));
	return (CFirstMFCopenglDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCopenglView message handlers

int CFirstMFCopenglView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	int n;
	m_pDC=new CClientDC(this);
	ASSERT(m_pDC!=NULL);
		static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		24,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		32,											//  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	int PixelFormat;
   if ((PixelFormat=ChoosePixelFormat(m_pDC->GetSafeHdc(),&pfd))==0)	// Did Windows Find A Matching Pixel Format?
	{
		MessageBox("ѡ�����ظ�ʽʧ�ܣ�");
		return -1;									// Return FALSE
	}

	if(SetPixelFormat(m_pDC->GetSafeHdc(),PixelFormat,&pfd)==FALSE)		// Are We Able To Set The Pixel Format?
	{
	    MessageBox("�������ظ�ʽʧ��");   
		return -1;								// Return FALSE
	}
    n=::GetPixelFormat(m_pDC->GetSafeHdc());
	::DescribePixelFormat(m_pDC->GetSafeHdc(),n,sizeof(pfd),&pfd);
	m_hglrc=wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(),m_hglrc);
	x=-85.0;
	angle=0.0;
   
    AUX_RGBImageRec *TextureImage[2]; //Ϊ�������洢�ռ�
	memset(TextureImage,0,sizeof(void *)*2);           //��ָ����ΪNULL
    TextureImage[0]=auxDIBImageLoad("Data/T1.bmp");

    TextureImage[1]=auxDIBImageLoad("Data/T2.bmp");

	glGenTextures(1, &texture[0]);   //��������
   glBindTexture(GL_TEXTURE_2D, texture[0]);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
  if (TextureImage[0])        // �����Ƿ����
 {
  if (TextureImage[0]->data)      // ����ͼ���Ƿ����
  {
   free(TextureImage[0]->data);    // �ͷ�����ͼ��ռ�õ��ڴ�
  }

  free(TextureImage[0]);       // �ͷ�ͼ��ṹ
 }


	glGenTextures(1, &texture[1]);   //��������
   glBindTexture(GL_TEXTURE_2D, texture[1]);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[1]->sizeX, TextureImage[1]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[1]->data);
  if (TextureImage[1])        // �����Ƿ����
 {
  if (TextureImage[1]->data)      // ����ͼ���Ƿ����
  {
   free(TextureImage[1]->data);    // �ͷ�����ͼ��ռ�õ��ڴ�
  }

  free(TextureImage[1]);       // �ͷ�ͼ��ṹ
 }

   glEnable(GL_TEXTURE_2D); 
	

	CString strSQL,strDriver,strDSN;
	CString x,y,z;
//	CString strFile = "D:\\ExcelFile1.xls";// ������ȡ��Excel�ļ���
	CString strFile = "Data/ExcelFile1.xls";	
	// �����Ƿ�װ��Excel���� "Microsoft Excel Driver (*.xls)"
	strDriver = GetExcelDriver();
	if (strDriver.IsEmpty())
	{
		// û�з���Excel����
		AfxMessageBox("û�а�װExcel����!");
		return -1;
	}
	// �������д�ȡ���ַ���
	strDSN.Format("ODBC;DRIVER={%s};DSN='';DBQ=%s",
		strDriver,strFile);
	TRY
	{

		// �����ݿ�(��Excel�ļ�)
		m_database.Open(NULL, false, false, strDSN);
		//CRecordset Recordset(&m_database);		

        Recordset=new CRecordset(&m_database);
		// ���ö�ȡ�Ĳ�ѯ���
		strSQL = "SELECT * FROM Table1";
		//ִ�в�ѯ���
		Recordset->Open(CRecordset::forwardOnly, strSQL, 
			           CRecordset::readOnly);
		
		// ��ȡ��ѯ���
	
		
		for(int i=0;i<4;i++)
		{
			if (!Recordset->IsEOF())
			{
			//��ȡExcel���ݱ��еļ�¼
			Recordset->GetFieldValue("Tx", x);
			Recordset->GetFieldValue("Ty", y);
			Recordset->GetFieldValue("Tz", z);
		    point[i][0]=atof(x);
			point[i][1]=atof(y);
			point[i][2]=atof(z);
			// �Ƶ���һ��
			Recordset->MoveNext();

			}
			else
			{
		    point[i][0]=0;
			point[i][1]=0;
			point[i][2]=0;
			}
			
		}
		// �ر����ݿ�
	  
	}
	CATCH(CDBException, e)
	{
		// ���ݿ���������쳣ʱ...
		AfxMessageBox("���ݿ����: " + e->m_strError);
	}
	END_CATCH;
	SetTimer(1,1000,NULL);
	return 0;
}

void CFirstMFCopenglView::OnDestroy() 
{
	::wglMakeCurrent(NULL,NULL);
	if(m_hglrc) ::wglDeleteContext(m_hglrc);
	if(m_pDC) delete m_pDC;
	CView::OnDestroy();	
}

void CFirstMFCopenglView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	if(m_hglrc) wglMakeCurrent(m_pDC->GetSafeHdc(),m_hglrc);
	else return;
	glViewport(0,0,cx,cy);//����˺�����д�ɴ��ڵĿ�͸�
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(cx<=cy)
		glOrtho(-250.0,10.0,-250.0*(GLfloat)cy/(GLfloat)cx,100.0*(GLfloat)cy/(GLfloat)cx,-5000,5000);
	//	glOrtho(-50.0,50.0,-50.0*(GLfloat)cy/(GLfloat)cx,50.0*(GLfloat)cy/(GLfloat)cx,-500,500);//��Ҫ����ͨ���˺�������X,Y����Ľ�ȡ
		

	else
		glOrtho(-250.0*(GLfloat)cx/(GLfloat)cy,100.0*(GLfloat)cx/(GLfloat)cy,-250.0,100.0,-5000,5000);
	//	glOrtho(-50.0*(GLfloat)cx/(GLfloat)cy,50.0*(GLfloat)cx/(GLfloat)cy,-50.0,50.0,-500,500);//��Ҫ����ͨ���˺�������X,Y����Ľ�ȡ
	
	glMatrixMode(GL_MODELVIEW);//���ñ任ģʽΪģ�ͱ任������ɲ�Ҫ��
	glLoadIdentity();// ��ʼ��ģ�ͱ任
	// TODO: Add your message handler code here
	
}

void CFirstMFCopenglView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==VK_RIGHT)
	{
		x=x+100;
		angle=angle+5;
	}	
	if(nChar==VK_LEFT)
	{
		x=x-100;
		angle=angle-5;
	}
	if(nChar==VK_UP)
	{
		x=x-100;
		angle=angle+90;
	}
	if(nChar==VK_DOWN)
	{
		x=x-100;
		angle=angle-90;
	}	
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CFirstMFCopenglView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString x,y,z;
	

		for(int i=0;i<4;i++)//ÿ�ζ��ĸ�����������TOOL����TOOL���ʱ�򣬸����Ｔ�ɣ���Ҫע�������С��
		{
			if (!Recordset->IsEOF())
			{
			//��ȡExcel���ݱ��еļ�¼
			Recordset->GetFieldValue("Tx", x);
			Recordset->GetFieldValue("Ty", y);
			Recordset->GetFieldValue("Tz", z);
		    point[i][0]=atof(x);
			point[i][1]=atof(y);
			point[i][2]=atof(z);
			// �Ƶ���һ��
			Recordset->MoveNext();
			}		
		}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
CString CFirstMFCopenglView::GetExcelDriver()
{
	char szBuf[2001];
	WORD cbBufMax = 2000;
	WORD cbBufOut;
	char *pszBuf = szBuf;
	CString sDriver;
	// ��ȡ�Ѱ�װ����������(������odbcinst.h��)
	if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
		return "";
	// �����Ѱ�װ�������Ƿ���Excel...
	do
	{
		if (strstr(pszBuf, "Excel") != 0)
		{
			//�ҵ�
			sDriver = CString(pszBuf);
			break;
		}
		pszBuf = strchr(pszBuf, '\0') + 1;
	}
	while (pszBuf[1] != '\0');
	return sDriver;
}