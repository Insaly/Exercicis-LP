#include "LliuramentsEstudiant.h"

void LliuramentsEstudiant::afegeixTramesa(const string& fitxer, const string& data)
{
    Tramesa tramesa(fitxer, data);
    m_trameses.push_front(tramesa);
}

bool LliuramentsEstudiant::consultaTramesa(const string& data, string& fitxer)
{
    for (forward_list<Tramesa>::iterator it = m_trameses.begin(); it != m_trameses.end(); ++it)
    {
        if (it->getData() == data)
        {
            fitxer = it->getFitxer();
            return true;
        }
    }
    return false;
}

bool LliuramentsEstudiant::eliminaTramesa(const string& data)
{
    forward_list<Tramesa>::iterator anterior = m_trameses.before_begin();
    forward_list<Tramesa>::iterator actual = m_trameses.begin();

    while (actual != m_trameses.end())
    {
        if (actual->getData() == data)
        {
            m_trameses.erase_after(anterior);
            return true;
        }
        ++anterior;
        ++actual;
    }

    return false;
}