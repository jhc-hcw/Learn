// msgbox��Ŀ
# include <windows.h>

// ���������������MessageBox API������user32���������
#pragma comment(lib,"user32.lib")

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	::MessageBox(
		NULL,						// û�и�����
		"hello win10",       // ��Ϣ���е��ı�
		"GREET",					// ��Ϣ��ı���
		MB_OK);						// ����ֻ��һ��ok��ť

    // ����0�Ա�֪ͨϵͳ��������Ϣѭ��
	return 0;
}