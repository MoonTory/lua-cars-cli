#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "address.h"

namespace Luna {

    class Client
    {
    public:
        Client();
        Client(std::string &_name, std::string &_cpf, Address &_address);
        ~Client() { delete this; }

        std::string name() const;
        void setName(const std::string &name);

        std::string cpf() const;
        void setCpf(const std::string &cpf);

        Address address() const;
        void setAddress(const Address &address);

    private:
        std::string m_name;
        std::string m_cpf;
        Address m_address;
    };

}

#endif // CLIENT_H
