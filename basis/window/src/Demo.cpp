#include <windows.h>				//һ��windowsӦ�ó���Ӧ�ð�����ͷ�ļ�
#include <stdio.h>					//��׼����������ļ�
LRESULT CALLBACK WinSunProc		/*����һ���ص�����*/
(
 HWND hwnd,      				/*���ڵľ��*/
 UINT uMsg,      					/*���ڵ���Ϣ*/
 WPARAM wParam,
 LPARAM lParam
 );

int WINAPI WinMain
(
 HINSTANCE hInstance,     			//ʵ����� ��ǰӦ�ó����ʵ�����
 HINSTANCE hPrevInstance, 			//Ĭ���������ΪNULL
 LPSTR lpCmdLine,          			//����һ�������в���
 int nCmdShow)
{
	WNDCLASS wndcls;				//����һ�����ڶ���
	wndcls.cbClsExtra=0;			//ָ�������ڴ�ռ�
	wndcls.cbWndExtra=0;			//ָ�������ڴ�ռ�
	//ָ�����ڱ���ɫ
	wndcls.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	//���ù����ʽ
	wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);
	//����ͼ����ʽ
	wndcls.hIcon=LoadIcon(NULL,IDI_ERROR);
	wndcls.hInstance=hInstance;		//ָ������ʵ�����
	wndcls.lpfnWndProc=WinSunProc;	//ָ�����ں�������������������
	//����������
	wndcls.lpszClassName="Visual C++ Game";
	wndcls.lpszMenuName=NULL;		//�˵�
	wndcls.style= CS_HREDRAW|CS_VREDRAW;
	RegisterClass(&wndcls); 			//ע�ᴰ����
	HWND hwnd;					//�������ھ��
	hwnd=CreateWindow			/*�������ڣ�������Ĵ����ǲ�����ʾ��*/
		(
		"Visual C++ Game",          /*��ע�ᴰ���������*/
		"Visual C++ ��Ϸ����", 		/*���ڱ���*/
		WS_OVERLAPPEDWINDOW, /*���ڷ��*/
		200,                        /*����λ�õĺ�����*/
		200,                        	/*����λ�õ�������*/
		600,                        	/*���ڵĿ��*/
		400,                        	/*���ڵĸ߶�*/
		NULL,
		NULL,
		hInstance,                  	//ʵ�����
		NULL);
	//������������ʾ����
	ShowWindow(hwnd,SW_SHOWNORMAL);
	UpdateWindow(hwnd);			//������ʾ

	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);	//ת��������Ϣ
		DispatchMessage(&msg);		//������Ϣ
	}
	return 0;
}

LRESULT CALLBACK WinSunProc(
							HWND hwnd,      			/*���ھ��*/
							UINT uMsg,      				/*��Ϣ*/
							WPARAM wParam, 			/*����1*/
							LPARAM lParam   			/*����2*/
							)
{
	char tmsg[128] = {0};
	int num1, num2, num3, num4,num5;			//����5������
	num1 = 3+8;							//�ӷ�����
	num2 = 10-7;							//��������
	num3 = 100*33;						//�˷�����
	num4 = 155/5;						//��������
	num5 = 9%2;						//ȡģ����

	sprintf(tmsg, "3+8=%d 10-7=%d 100*33=%d 155/5=%d 9%%2=%d",
			num1, num2, num3, num4, num5);

	switch(uMsg)					/*�ж���Ϣ����*/
	{
	case WM_PAINT:				/*���´�����Ϣ*/
		HDC hDC;				/*���� DC�豸*/
		PAINTSTRUCT ps;
		hDC=BeginPaint(hwnd,&ps);	/*�õ��豸hDC*/
		TextOut(hDC,150,0,tmsg,strlen(tmsg));
		EndPaint(hwnd,&ps);
		break;
	case WM_CLOSE:				/*�������رհ�ťʱ�������ر���Ϣ*/
		if(IDYES==MessageBox(hwnd,"�Ƿ���Ľ�����","��Ϸ����",MB_YESNO))
		{
			DestroyWindow(hwnd);	/*����ȷʵ�����ٴ���*/
		}
		break;
	case WM_DESTROY:			/*���ٴ�����Ϣ*/
		PostQuitMessage(0);		/*�˳�����*/
		break;
	default:
		//��default:���������DefWindowProc,����Windows�ڲ�Ĭ�ϵ���Ϣ������
		return DefWindowProc(hwnd,uMsg,wParam,lParam);
	}
	return 0;
}
