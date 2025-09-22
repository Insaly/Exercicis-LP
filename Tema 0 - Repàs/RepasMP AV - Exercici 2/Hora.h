#pragma once

class Hora
{
public:
    Hora() : m_hora(0), m_minut(0), m_segon(0) {}
    Hora(int hora, int minut, int segon) { m_hora = hora; m_minut = minut; m_segon = segon; }
    Hora(const Hora& h) { m_hora = h.m_hora; m_minut = h.m_minut; m_segon = h.m_segon; }

    void setHora(int hora) { m_hora = hora; }
    void setMinuts(int minut) { m_minut = minut; }
    void setSegons(int segon) { m_segon = segon; }

    int getHora() const { return m_hora; }
    int getMinuts() const { return m_minut; }
    int getSegons() const { return m_segon; }

    bool horaValida() const;

    Hora operator+(const int segons) const;
    Hora operator+(const Hora& h) const;
    bool operator==(const Hora& h) const;
    bool operator<(const Hora& h) const;

    Hora& operator=(const Hora& h) { m_hora = h.m_hora; m_minut = h.m_minut; m_segon = h.m_segon; return *this; }

private:
    int m_hora;
    int m_minut;
    int m_segon;
};
