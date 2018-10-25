// cvter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#pragma comment(lib, "gdiplus.lib")

using namespace std;
using namespace Gdiplus;

std::wstring CharToWchar(const char* c, size_t m_encode = CP_ACP)
{
	std::wstring str;
	int len = MultiByteToWideChar(m_encode, 0, c, strlen(c), NULL, 0);
	wchar_t*	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar(m_encode, 0, c, strlen(c), m_wchar, len);
	m_wchar[len] = '\0';
	str = m_wchar;
	delete m_wchar;
	return str;
}

std::string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP)
{
	std::string str;
	int len = WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), NULL, 0, NULL, NULL);
	char	*m_char = new char[len + 1];
	WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), m_char, len, NULL, NULL);
	m_char[len] = '\0';
	str = m_char;
	delete m_char;
	return str;
}


int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT num = 0;                     // number of image encoders   
	UINT size = 0;                   // size of the image encoder array in bytes   
	ImageCodecInfo* pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;     //   Failure   

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;     //   Failure   

	GetImageEncoders(num, size, pImageCodecInfo);
	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;     //   Success   
		}
	}
	free(pImageCodecInfo);
	return -1;     //   Failure   
}

void jpg2in(wstring infilename, string outfilename)
{
	//读图片
	Bitmap* bmp = new Bitmap(infilename.c_str());
	UINT height = bmp->GetHeight();
	UINT width = bmp->GetWidth();
	cout <<  width << " " << height << endl;

	Color color;
	ofstream fout(outfilename.c_str());

	for (UINT x = 0; x < width; x++)
	{
		for (UINT y = 0; y < height; y++)
		{
			bmp->GetPixel(x, y, &color);
			fout << (int)color.GetRed() << " "
				<< (int)color.GetGreen() << " "
				<< (int)color.GetBlue() << endl;
		}
	}

	fout.close();
	delete bmp;
}

void in2jpg(string infilename, wstring outfilename)
{
	//读图片
	ifstream  fin(infilename);
	UINT height;
	UINT width;

	fin >> width >> height;
	
	int red, green, blue;

	Bitmap* bmp = new Bitmap(width, height);
	for (UINT x = 0; x < width; x++)
	{
		for (UINT y = 0; y < height; y++)
		{
			fin >> red >> green >> blue;
			Color color(red, green, blue);
			bmp->SetPixel(x, y, color);
		}
	}

	CLSID  id;
	GetEncoderClsid(L"image/jpeg", &id);
	bmp->Save(outfilename.c_str(), &id);

	delete bmp;
}

int main(int argc, char* argv[])
{
	GdiplusStartupInput gdiplusstartupinput;
	ULONG_PTR gdiplustoken;
	GdiplusStartup(&gdiplustoken, &gdiplusstartupinput, NULL);

	if (argc < 4)
	{
		cout << "Usage: cvter -d jpg txt" << endl;
		cout << "Usage: cvter -e txt jpg" << endl;
		return -1;
	}

	if (2 != strlen(argv[1]))
	{
		cout << "Usage: cvter -d jpg txt" << endl;
		cout << "Usage: cvter -e txt jpg" << endl;
		return -1;
	}

	if ('-' != argv[1][0])
	{
		cout << "Usage: cvter -d jpg txt" << endl;
		cout << "Usage: cvter -e txt jpg" << endl;
		return -1;
	}

	if ('e' == argv[1][1])
	{
		in2jpg(argv[2], CharToWchar(argv[3]));
	}
	else
	{
		jpg2in(CharToWchar(argv[2]), argv[3]);
	}

	GdiplusShutdown(gdiplustoken);
	return 0;
}

