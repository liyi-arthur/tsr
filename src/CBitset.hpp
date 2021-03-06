/*
* @file CBitset.hpp
* @authur liyi_whu@163.com
* @create 2018-11-03
*/

#ifndef __CBITSET_HPP__
#define __CBITSET_HPP__

#include <vector>

namespace tsr
{
	class CBitset
	{
	public:
        CBitset();
		~CBitset();

        void SetSize(int size);

        void Set(int pos);
        bool IsSet(int pos);

	private:
        char*       m_bs;
        int         m_size;
	};

}

#endif //__CMAT_HPP__