#include "Hora.h"

bool Hora::horaValida() const
{
    return (m_hora >= 0 && m_hora < 24 && m_minut >= 0 && m_minut < 60 && m_segon >= 0 && m_segon < 60);
}

Hora Hora::operator+(const int segons) const
{
    Hora h = *this;
    h.m_segon += segons;
    while (h.m_segon >= 60)
    {
        h.m_segon -= 60;
        h.m_minut++;
        if (h.m_minut >= 60)
        {
            h.m_minut -= 60;
            h.m_hora++;
            if (h.m_hora >= 24)
                h.m_hora = 0;
        }
    }
    return h;
}

Hora Hora::operator+(const Hora& h) const
{
    Hora res = *this;
    res.m_segon += h.m_segon;
    res.m_minut += h.m_minut;
    res.m_hora += h.m_hora;
    while (res.m_segon >= 60)
    {
        res.m_segon -= 60;
        res.m_minut++;
    }
    while (res.m_minut >= 60)
    {
        res.m_minut -= 60;
        res.m_hora++;
    }
    while (res.m_hora >= 24)
        res.m_hora -= 24;
    return res;
}

bool Hora::operator==(const Hora& h) const
{
    return (m_hora == h.m_hora && m_minut == h.m_minut && m_segon == h.m_segon);
}

bool Hora::operator<(const Hora& h) const
{
    if (m_hora < h.m_hora)
        return true;
    if (m_hora > h.m_hora)
        return false;
    if (m_minut < h.m_minut)
        return true;
    if (m_minut > h.m_minut)
        return false;
    return (m_segon < h.m_segon);
}