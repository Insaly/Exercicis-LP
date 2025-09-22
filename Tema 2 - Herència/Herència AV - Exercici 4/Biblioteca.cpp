
#pragma once
#include <fstream>
#include "Biblioteca.h"

using namespace std;

void Biblioteca::llegirPublicacions(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        while (!fitxer.eof())
        {
            string titol, codi, tipus;
            fitxer >> tipus >> codi >> titol;

            if (tipus == "R")
            {
                int nExemplars;
                string periode;
                vector<int> exemplars;

                fitxer >> periode >> nExemplars;
                exemplars.resize(nExemplars);

                for (int i = 0; i < nExemplars; i++)
                    fitxer >> exemplars[i];

                Publicacio* revista = new Revista(titol, codi, tipus, periode, nExemplars, exemplars);
                m_publicacions.push_back(revista);
                revista->printPublicacio();
            }
            
            else
            {
                if (tipus == "L")
                {
                    int nCopies, nDies;
                    string autor;

                    fitxer >> autor >> nCopies >> nDies;

                    Publicacio* llibre = new Llibre(titol, codi, tipus, autor, nCopies, nDies);
                    m_publicacions.push_back(llibre);
                    llibre->printPublicacio();
                }
            }
        }
    }
    fitxer.close();
}

bool Biblioteca::prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar)
{
    list<Publicacio*>::iterator iterador = m_publicacions.begin();

    bool prestat = false;
    bool trobat = false;

    while (iterador != m_publicacions.end() && !trobat)
    {
        if ((*iterador)->getCodi() == codi)
        {
            trobat = true;

            if ((*iterador)->getTipus() == "R" && !(*iterador)->getPrestat(nExemplar))
            {
                dataRetorn = dataPrestec + 30;
                Prestec prestec(idUsuari, codi, dataPrestec, dataRetorn, nExemplar);
                m_prestecs.push_back(prestec);
                (*iterador)->setPrestat(true, nExemplar);
                prestat = true;
            }
            
            else
            {
                if ((*iterador)->getTipus() == "L" && (*iterador)->getPrestat(0) < (*iterador)->getNCopies())
                {
                    dataRetorn = dataPrestec + (*iterador)->getNDiesPrestat();
                    Prestec prestec(idUsuari, codi, dataPrestec, dataRetorn);
                    m_prestecs.push_back(prestec);
                    (*iterador)->setPrestat(1, 0);
                    prestat = true;
                }
            }
        }
        iterador++;
    }

    return prestat;
}

bool Biblioteca::retornar(const string& idUsuari, const string& codi, const Data& data, bool& dataCorrecta, int nExemplar)
{
    list<Prestec>::iterator iterador = m_prestecs.begin();

    bool trobat = false;
    bool tornat = false;

    while (iterador != m_prestecs.end() && !trobat)
    {
        if ((*iterador).getidUsuari() == idUsuari && (*iterador).getCodiPublicacio() == codi && (*iterador).getnExemplar() == nExemplar)
        {
            cout << "Data esperada de retorn: " << (*iterador).getDataRetorn().getDia() << "/"
                << (*iterador).getDataRetorn().getMes() << "/" << (*iterador).getDataRetorn().getAny() << endl << endl;
                
            if (data < (*iterador).getDataRetorn())
            {
                dataCorrecta = true;
            }

            else
            {
                dataCorrecta = false;
            }

            trobat = true;
            tornat = true;
        }

        else
        {
            iterador++;
        }
    }

    if (trobat)
        m_prestecs.erase(iterador);

    return tornat;
}