#include "client.h"

namespace Luna {

    Client::Client()
    {

    }

    Client::Client(std::string &_nome, std::string &_cpf, Adress &_adress)
    {
        this->setNome(_nome);
        this->setCpf(_cpf);
        this->setAdress(_adress);
    }

    std::string Client::nome() const
    {
        return m_nome;
    }

    void Client::setNome(const std::string &nome)
    {
        m_nome = nome;
    }

    std::string Client::cpf() const
    {
        return m_cpf;
    }

    void Client::setCpf(const std::string &cpf)
    {
        m_cpf = cpf;
    }

    Adress Client::adress() const
    {
        return m_adress;
    }

    void Client::setAdress(const Adress &adress)
    {
        m_adress = adress;
    }

}
