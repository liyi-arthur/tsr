
#include "Common.hpp"
#include "CColor.hpp"

namespace tsr
{
    double threeway_max(double a, double b, double c) {
        return MAX(a, MAX(b, c));
    }

    double threeway_min(double a, double b, double c) {
        return MIN(a, MIN(b, c));
    }

	CColor::CColor()
	{
	}

    CColor::CColor(int r, int g, int b): m_r(r), m_g(g), m_b(b)
    {

    }

	CColor::~CColor()
	{
	}

    void CColor::Rgb2Hsv()
    {
        double rd = (double)m_r / 255;
        double gd = (double)m_g / 255;
        double bd = (double)m_b / 255;
        double max = threeway_max(rd, gd, bd), min = threeway_min(rd, gd, bd);
        
        m_v = max;
        double d = max - min;
        m_s = max == 0 ? 0 : d / max;

        if (max == min) {
            m_h = 0; // achromatic
        }
        else {
            if (max == rd) {
                m_h = (gd - bd) / d + (gd < bd ? 6 : 0);
            }
            else if (max == gd) {
                m_h = (bd - rd) / d + 2;
            }
            else if (max == bd) {
                m_h = (rd - gd) / d + 4;
            }
            m_h /= 6;
        }

        m_hi = static_cast<int>(m_h / 2);
        m_si = static_cast<int>(m_s * 255);
        m_vi = static_cast<int>(m_v * 255);
    }

    void CColor::Hsv2Rgb()
    {
        double r, g, b;

        int i = int(m_h * 6);
        double f = m_h * 6 - i;
        double p = m_v * (1 - m_s);
        double q = m_v * (1 - f * m_s);
        double t = m_v * (1 - (1 - f) * m_s);

        switch (i % 6) {
        case 0: r = m_v, g = t, b = p; break;
        case 1: r = q, g = m_v, b = p; break;
        case 2: r = p, g = m_v, b = t; break;
        case 3: r = p, g = q, b = m_v; break;
        case 4: r = t, g = p, b = m_v; break;
        case 5: r = m_v, g = p, b = q; break;
        }
        m_r = r * 255;  m_g = g * 255; m_b = b * 255;
    }

    CColor& CColor::operator=(const CColor& rhs)
    {
        if (this != &rhs) {
            m_r = rhs.GetR();  m_g = rhs.GetG(); m_b = rhs.GetB();
            m_h = rhs.GetH();  m_s = rhs.GetS(); m_v = rhs.GetV();
            m_hi = rhs.GetHi();  m_si = rhs.GetSi(); m_vi = rhs.GetVi();
        }
        return *this;
    }
}