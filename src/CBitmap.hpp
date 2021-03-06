
#ifndef __CBITMAP_HPP__
#define __CBITMAP_HPP__
#include <vector>
#include "CColor.hpp"
#include "CMat.hpp"
#include "CRect.hpp"

namespace tsr
{
	class CBitmap
	{
	public:
		CBitmap();
		CBitmap(int w, int h);
		CBitmap(CBitmap& bitmap);
		~CBitmap();

		void SetSize(int w, int h);

	private:
		int  m_w;
		int  m_h;
		std::vector<CColor>   m_bitmap;
        uint8_t*  m_membgr;

	public:
		// 获取宽度
		int GetW() const;
		// 获取高度
		int GetH() const;
		// 获取像素
		CColor& GetPixel(int x, int y);
		// 设置坐标颜色
		int SetPixel(int x, int y, const CColor& color);
		// 坐标是否合法
		bool IsValidPixel(int x, int y);
		// 加载数据
		int Load(char* file);
		// 保存位图到文件 RGB格式
		void Save(char* file);
        // 以HSV格式保存
        void SaveAsHsv(char* file);
        // 生成HSV信息
        void Rgb2Hsv();
        // 生成RGB信息
        void Hsv2Rgb();
        // 卷积后
        void Convolution(CMat& mat, CBitmap& dst);
        // 高斯模糊
        void GaussBlur(float sigma, CBitmap& dst);

        void Cut(CRect& rect, CBitmap& dst);

        void Sobel(CBitmap& dst);

        void Magnitude(CBitmap& gx, CBitmap& gy);

        void Canny(CBitmap& bmp);

        void ToMemBgr();
        uint8_t* GetMemBgr() { return m_membgr; }

        void FromMemBgr();

        CBitmap& operator=(CBitmap& rhs);
	};
}



#endif //__CBITMAP_HPP__
