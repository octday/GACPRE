// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BASE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BASE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef BASE_EXPORTS
#define BASE_API __declspec(dllexport)
#define BASE_TEMPLATE_API __declspec(dllexport)
#else
#define BASE_API __declspec(dllimport)
#define BASE_TEMPLATE_API
#endif

#define _USE_MATH_DEFINES  1 // Include constants defined in math.h
#include <math.h>