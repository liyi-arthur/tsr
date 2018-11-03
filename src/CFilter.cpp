
#include "Common.hpp"
#include "CFilter.hpp"

namespace tsr
{
    CFilter::CFilter(CBitmap& bitmap) : m_bitmap(bitmap)
    {

    }
    CFilter::~CFilter()
    {
        
    }

    void CFilter::FilterRed(CBitmap& dst)
    {
        dst = m_bitmap;

        CColor white(255, 255, 255);

        for (int x = 0; x < dst.GetW(); x++) {
            for (int y = 0; y < dst.GetH(); y++) {
                if (!IsRed(dst.GetPixel(x, y))) {
                    dst.GetPixel(x, y) = white;
                }
            }
        }
    }
    void CFilter::FilterGreen(CBitmap& dst)
    {
        dst = m_bitmap;

        CColor white(255, 255, 255);

        for (int x = 0; x < dst.GetW(); x++) {
            for (int y = 0; y < dst.GetH(); y++) {
                if (!IsGreen(dst.GetPixel(x, y))) {
                    dst.GetPixel(x, y) = white;
                }
            }
        }
    }

    bool CFilter::IsRed(CColor& c)
    {
        return true;
    }
    bool CFilter::IsGreen(CColor& c)
    {
        return false;
    }
}