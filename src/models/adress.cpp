#include "adress.h"

namespace Luna {

    Adress::Adress()
    {

    }

    Adress::Adress(std::string _cep, std::string _log, std::string _comp,
                   std::string _bairro, std::string _estado, std::string _cidade)
    {
        this->setCep(_cep);
        this->setLogradouro(_log);
        this->setCompletmento(_comp);
        this->setBairro(_bairro);
        this->setEstado(_estado);
        this->setCidade(_cidade);
    }

    std::string Adress::cep() const
    {
        return m_cep;
    }

    void Adress::setCep(const std::string &cep)
    {
        m_cep = cep;
    }

    std::string Adress::logradouro() const
    {
        return m_logradouro;
    }

    void Adress::setLogradouro(const std::string &logradouro)
    {
        m_logradouro = logradouro;
    }

    std::string Adress::completmento() const
    {
        return m_completmento;
    }

    void Adress::setCompletmento(const std::string &completmento)
    {
        m_completmento = completmento;
    }

    std::string Adress::bairro() const
    {
        return m_bairro;
    }

    void Adress::setBairro(const std::string &bairro)
    {
        m_bairro = bairro;
    }

    std::string Adress::estado() const
    {
        return m_estado;
    }

    void Adress::setEstado(const std::string &estado)
    {
        m_estado = estado;
    }

    std::string Adress::cidade() const
    {
        return m_cidade;
    }

    void Adress::setCidade(const std::string &cidade)
    {
        m_cidade = cidade;
    }

}
