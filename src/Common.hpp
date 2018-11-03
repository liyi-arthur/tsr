/**/

#ifndef __TSR_COMMON_HPP__
#define __TSR_COMMON_HPP__
namespace tsr
{
#define MAX(x, y) (((x)>(y))?(x):(y))
#define MIN(x, y) (((x)>(y))?(y):(x))

#define TRUE_RET(c, r) if(c) {return r;}
#define TRUE_RETURN(c) if(c) {return;}

#define RET_OK   (int)0
#define RET_ERR   (int)-1

#define M_PI 3.1415

#define QBOUND(min_, max_, v_)  MAX((min_), MIN((max_), (v_)))
}

#endif //__TSR_COMMON_HPP__