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

	 glLoadIdentity();//参考置原点（屏幕中心）
	  glDrawBuffer(GL_BACK);	 
	  glClearColor(0.0f,0.0f,0.0f,0.0f);//设置背景色为黑色
   	//glClearColor ( 0.0, 0.0, 1.0, 0.0 ); //设置背景色为蓝色 
	/*  glBegin(GL_LINE_STRIP);// 开始绘制直线
	glColor3f(1.0,0.0,0.0);// 设置颜色，红
	glVertex2s(-12,-10);// 第一条线的起点

	glColor3f(0,1,0.0);// 设置颜色，绿
	glVertex2s(0,10);// 第一条线的终点，即第二天线的起点。
    
	glColor3f(0,0.0,1);
	glVertex2s(12,-10);

	glColor3f(1.0,0.0,0.0);
	glVertex2s(-12,-10);
	glEnd();// 结束绘制*/
	
/*	 GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);//set material 镜面光反射
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//设置材料反射指数
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);//光源位置

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	auxSolidSphere(2.0);*/
    GLfloat light_position [ ] = { 0.0, 0.0, 1.0, 0 }; 
	GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };//红色材质
	GLfloat mat_diffuse1[] = { 0.8, 0.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };//如果N值越大，则光斑尺寸越小，物体越有光泽，反之越大。N值可取1-128之间的任意整数。
    GLUquadricObj *quadObj = gluNewQuadric();//创建一个二次曲面物体

	glShadeModel ( GL_SMOOTH ); 
	glEnable (GL_LIGHTING); 
	glEnable (GL_LIGHT0); //白光
	glEnable (GL_DEPTH_TEST);
//	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_specular);//镜面材料
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//设置材料反射指数
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//设定材质的颜色，不管在哪里，对全部模型有作用，除了glDisable( GL_LIGHTING )之间的
 
	glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);//没这两句以下的几何体glColor3f上色不起作用

   //glLightfv(GL_LIGHT0,GL_AMBIENT,mat_diffuse); //光源的光强
  // glLightfv(GL_LIGHT0,GL_DIFFUSE,mat_diffuse); //光源的颜色
  // glLightfv(GL_LIGHT0,GL_SPECULAR,white_light); //光源中的镜面反射光强度 


	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLightfv( GL_LIGHT0, GL_POSITION, light_position); 

//以下四句直线反走样设置
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);



 glPushMatrix();
      glTranslatef(-100.0f,-150.0f,-0.0f);
	  glRotatef(-90,0.0f,0.0f,1.0f);//在xy面内旋转
      glRotatef(angle,1.0f,0.0f,0.0f);//在xz面内旋转

//第1个点 
	glColor3f(1.0,0.0,0);//红    
    glBindTexture(GL_TEXTURE_2D, texture[0]);//绑定纹理     
	glPushMatrix();
	glTranslatef(0.0f,0.0f,1500.0f);
	glTranslatef(point[0][0],point[0][1],point[0][2]);
    glRotatef(-90,1.0f,0.0f,0.0f);//为了贴图能正对我
	glRotatef(-90,0.0f,1.0f,0.0f);//为了贴图能正对我
    //glutSolidSphere (5.5, 40, 50); //半径5.5mm,glut不能贴纹理
     glBegin(GL_QUADS);
     gluQuadricTexture(quadObj,GL_TRUE);        //启用该二次曲面的纹理
     gluSphere(quadObj,5.5,40,40); //画圆
     gluDeleteQuadric(quadObj);
     glEnd();
   	glPopMatrix();

//第2个点 
	glColor3f(1.0,0.0,0);//红
    glBindTexture(GL_TEXTURE_2D, texture[0]);//绑定纹理     
	glPushMatrix();//隔离
    //glRotatef(angle,0.0f,1.0f,0.0f);//在xz面内旋转
	glTranslatef(0.0f,0.0f,1500.0f);
    glTranslatef(point[1][0],point[1][1],point[1][2]);
    glRotatef(-90,1.0f,0.0f,0.0f);//为了贴图能正对我
	glRotatef(-90,0.0f,1.0f,0.0f);//为了贴图能正对我
    //glutSolidSphere (5.5, 40, 50); //半径5.5mm	
     GLUquadricObj *quadObj2 = gluNewQuadric();//创建一个二次曲面物体
     glBegin(GL_QUADS);
     gluQuadricTexture(quadObj2,GL_TRUE);        //启用该二次曲面的纹理
     gluSphere(quadObj2,5.5,20,20); //画圆
     gluDeleteQuadric(quadObj2);
    glPopMatrix();//隔离

//连线
	glPushMatrix();//隔离
	glTranslatef(0.0f,0.0f,1500.0f);
	glLineWidth(3); 
    glBegin(GL_LINES);	
    glVertex3f(point[0][0],point[0][1],point[0][2]);
    glVertex3f(point[1][0],point[1][1],point[1][2]);    
    glEnd();
    glPopMatrix();//隔离

//第3个点 
	glColor3f(0,1,0);//绿
    glBindTexture(GL_TEXTURE_2D, texture[1]);//绑定纹理     
    glPushMatrix();	
	glTranslatef(point[2][0],point[2][1],point[2][2]);
	glTranslatef(0.0f,0.0f,1500.0f);
    glRotatef(-90,1.0f,0.0f,0.0f);//为了贴图能正对我
	glRotatef(-90,0.0f,1.0f,0.0f);//为了贴图能正对我
    //glutSolidSphere (5.5, 40, 50); //半径5.5mm
     GLUquadricObj *quadObj3 = gluNewQuadric();//创建一个二次曲面物体
     glBegin(GL_QUADS);
     gluQuadricTexture(quadObj3,GL_TRUE);      //启用该二次曲面的纹理
     gluSphere(quadObj3,5.5,20,20); //画圆
     gluDeleteQuadric(quadObj3);
    glPopMatrix();

//第4个点
	glColor3f(0,1,0);//绿
    glBindTexture(GL_TEXTURE_2D, texture[1]);//绑定纹理       
    glPushMatrix();	
	glTranslatef(point[3][0],point[3][1],point[3][2]);
	glTranslatef(0.0f,0.0f,1500.0f);
    glRotatef(-90,1.0f,0.0f,0.0f);//为了贴图能正对我
	glRotatef(-90,0.0f,1.0f,0.0f);//为了贴图能正对我
    //glutSolidSphere (5.5, 40, 50); //半径5.5mm
     GLUquadricObj *quadObj4= gluNewQuadric();//创建一个二次曲面物体
     glBegin(GL_QUADS);
     gluQuadricTexture(quadObj4,GL_TRUE);     //启用该二次曲面的纹理
     gluSphere(quadObj4,5.5,20,20); //画圆
     gluDeleteQuadric(quadObj4);
    glPopMatrix();

 //连线
	glPushMatrix();//隔离
	glTranslatef(0.0f,0.0f,1500.0f);
	glLineWidth(3); 
    glBegin(GL_LINES);
    glVertex3f(point[2][0],point[2][1],point[2][2]);
    glVertex3f(point[3][0],point[3][1],point[3][2]);    
    glEnd();
    glPopMatrix();//隔离

/*	glColor3f(1.0,1.0,0);//黄
	glPushMatrix();
	//glScalef(0.2,0.2,0.2);//注意此句的位置不同显示效果完全不同
	glRotatef(angle,0.0f,0.0f,1.0f);//在xy面内旋转
	auxSolidCylinder(2.0f,85.0f);
    glPopMatrix();*/
  glPopMatrix();
	glFlush();// 刷新	
	SwapBuffers(wglGetCurrentDC());//没这句不出图，连黑色的背景都不出了
	glDrawBuffer(GL_FRONT);//没这句不影响任何

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
		MessageBox("选择像素格式失败！");
		return -1;									// Return FALSE
	}

	if(SetPixelFormat(m_pDC->GetSafeHdc(),PixelFormat,&pfd)==FALSE)		// Are We Able To Set The Pixel Format?
	{
	    MessageBox("设置像素格式失败");   
		return -1;								// Return FALSE
	}
    n=::GetPixelFormat(m_pDC->GetSafeHdc());
	::DescribePixelFormat(m_pDC->GetSafeHdc(),n,sizeof(pfd),&pfd);
	m_hglrc=wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(),m_hglrc);
	x=-85.0;
	angle=0.0;
   
    AUX_RGBImageRec *TextureImage[2]; //为纹理创建存储空间
	memset(TextureImage,0,sizeof(void *)*2);           //将指针设为NULL
    TextureImage[0]=auxDIBImageLoad("Data/T1.bmp");

    TextureImage[1]=auxDIBImageLoad("Data/T2.bmp");

	glGenTextures(1, &texture[0]);   //创建纹理
   glBindTexture(GL_TEXTURE_2D, texture[0]);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
  if (TextureImage[0])        // 纹理是否存在
 {
  if (TextureImage[0]->data)      // 纹理图像是否存在
  {
   free(TextureImage[0]->data);    // 释放纹理图像占用的内存
  }

  free(TextureImage[0]);       // 释放图像结构
 }


	glGenTextures(1, &texture[1]);   //创建纹理
   glBindTexture(GL_TEXTURE_2D, texture[1]);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[1]->sizeX, TextureImage[1]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[1]->data);
  if (TextureImage[1])        // 纹理是否存在
 {
  if (TextureImage[1]->data)      // 纹理图像是否存在
  {
   free(TextureImage[1]->data);    // 释放纹理图像占用的内存
  }

  free(TextureImage[1]);       // 释放图像结构
 }

   glEnable(GL_TEXTURE_2D); 
	

	CString strSQL,strDriver,strDSN;
	CString x,y,z;
//	CString strFile = "D:\\ExcelFile1.xls";// 将被读取的Excel文件名
	CString strFile = "Data/ExcelFile1.xls";	
	// 检索是否安装有Excel驱动 "Microsoft Excel Driver (*.xls)"
	strDriver = GetExcelDriver();
	if (strDriver.IsEmpty())
	{
		// 没有发现Excel驱动
		AfxMessageBox("没有安装Excel驱动!");
		return -1;
	}
	// 创建进行存取的字符串
	strDSN.Format("ODBC;DRIVER={%s};DSN='';DBQ=%s",
		strDriver,strFile);
	TRY
	{

		// 打开数据库(既Excel文件)
		m_database.Open(NULL, false, false, strDSN);
		//CRecordset Recordset(&m_database);		

        Recordset=new CRecordset(&m_database);
		// 设置读取的查询语句
		strSQL = "SELECT * FROM Table1";
		//执行查询语句
		Recordset->Open(CRecordset::forwardOnly, strSQL, 
			           CRecordset::readOnly);
		
		// 获取查询结果
	
		
		for(int i=0;i<4;i++)
		{
			if (!Recordset->IsEOF())
			{
			//读取Excel数据表中的记录
			Recordset->GetFieldValue("Tx", x);
			Recordset->GetFieldValue("Ty", y);
			Recordset->GetFieldValue("Tz", z);
		    point[i][0]=atof(x);
			point[i][1]=atof(y);
			point[i][2]=atof(z);
			// 移到下一行
			Recordset->MoveNext();

			}
			else
			{
		    point[i][0]=0;
			point[i][1]=0;
			point[i][2]=0;
			}
			
		}
		// 关闭数据库
	  
	}
	CATCH(CDBException, e)
	{
		// 数据库操作产生异常时...
		AfxMessageBox("数据库错误: " + e->m_strError);
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
	glViewport(0,0,cx,cy);//往后此函数就写成窗口的宽和高
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(cx<=cy)
		glOrtho(-250.0,10.0,-250.0*(GLfloat)cy/(GLfloat)cx,100.0*(GLfloat)cy/(GLfloat)cx,-5000,5000);
	//	glOrtho(-50.0,50.0,-50.0*(GLfloat)cy/(GLfloat)cx,50.0*(GLfloat)cy/(GLfloat)cx,-500,500);//不要妄想通过此函数进行X,Y方向的截取
		

	else
		glOrtho(-250.0*(GLfloat)cx/(GLfloat)cy,100.0*(GLfloat)cx/(GLfloat)cy,-250.0,100.0,-5000,5000);
	//	glOrtho(-50.0*(GLfloat)cx/(GLfloat)cy,50.0*(GLfloat)cx/(GLfloat)cy,-50.0,50.0,-500,500);//不要妄想通过此函数进行X,Y方向的截取
	
	glMatrixMode(GL_MODELVIEW);//设置变换模式为模型变换，这里可不要。
	glLoadIdentity();// 初始化模型变换
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
	

		for(int i=0;i<4;i++)//每次读四个点因是两个TOOL，当TOOL多的时候，改这里即可，还要注意数组大小。
		{
			if (!Recordset->IsEOF())
			{
			//读取Excel数据表中的记录
			Recordset->GetFieldValue("Tx", x);
			Recordset->GetFieldValue("Ty", y);
			Recordset->GetFieldValue("Tz", z);
		    point[i][0]=atof(x);
			point[i][1]=atof(y);
			point[i][2]=atof(z);
			// 移到下一行
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
	// 获取已安装驱动的名称(涵数在odbcinst.h里)
	if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
		return "";
	// 检索已安装的驱动是否有Excel...
	do
	{
		if (strstr(pszBuf, "Excel") != 0)
		{
			//找到
			sDriver = CString(pszBuf);
			break;
		}
		pszBuf = strchr(pszBuf, '\0') + 1;
	}
	while (pszBuf[1] != '\0');
	return sDriver;
}