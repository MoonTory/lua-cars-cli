#include "client.h"

namespace Luna {

    Client::Client()
    {

    }

    Client::Client(std::string &_name, std::string &_cpf, Address &_address)
    {
        this->setName(_name);
        this->setCpf(_cpf);
        this->setAddress(_address);
    }

    std::string Client::name() const
    {
        return m_name;
    }

    void Client::setName(const std::string &name)
    {
        m_name = name;
    }

    std::string Client::cpf() const
    {
        return m_cpf;
    }

    void Client::setCpf(const std::string &cpf)
    {
        m_cpf = cpf;
    }

    Address Client::address() const
    {
        return m_address;
    }

    void Client::setAddress(const Address &address)
    {
        m_address = address;
    }

}
