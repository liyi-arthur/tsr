/*
* @file CDetect.hpp
* @authur liyi_whu@163.com
* @create 2018-11-03
*/

#ifndef __CDETECT_HPP__
#define __CDETECT_HPP__

#include <vector>
#include <bitset>
#include "Common.hpp"
#include "CBitmap.hpp"
#include "CRect.hpp"
#include "CPointSet.hpp"

namespace tsr
{
	class CDetect
	{
	public:
        CDetect(CBitmap& bitmap, CBitmap& orig);
		~CDetect();

        void FindRects();

        void MarkRects();
        void MarkRect(CRect& rect);
        void RemoveRects(int len);
        void MergeRects();
        void FindClosure();
        void FindLights();
        void ExpandLightArea(CPointSet& ps, int T);

        bool IsInRects(int x, int y);
        bool IsRatioOK(int w, int h)
        {
            float max_ = (float)MAX(w, h);
            float min_ = (float)MIN(w, h);
            return (max_ / min_ < 1.5);
        }

        bool IsCloseToEdge(CRect& rect);

        std::vector<CPointSet>&  GetPss() { return m_ptSets; }

	private:
        CBitmap&                m_bitmap;
        CBitmap&                m_origPic;
        CBitmap                 m_edgePic;
        std::vector<CRect>      m_rects;
        std::vector<CPointSet>  m_ptSets;

        void ExpandLightArea(CPointSet& ps, int T, int x, int y, CRect& rect);
	};

}

#endif //__CDETECT_HPP__