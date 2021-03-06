/**/

#ifndef __CFILTER_HPP__
#define __CFILTER_HPP__
#include "CBitmap.hpp"

namespace tsr
{
	class CFilter
	{
	public:
        CFilter(CBitmap& bitmap);
		~CFilter();

        void FilterRed(CBitmap& dst);
        void FilterGreen(CBitmap& dst);

        void FilterGreenAndRed(CBitmap& dst);

	private:
        CBitmap&  m_bitmap;
	};

}

#endif //__CFILTER_HPP__