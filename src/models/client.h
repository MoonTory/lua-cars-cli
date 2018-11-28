#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "adress.h"

namespace Luna {

    class Client
    {
    public:
        Client();
        Client(std::string &_nome, std::string &_cpf, Adress &_adress);
        ~Client() { delete this; }

        std::string nome() const;
        void setNome(const std::string &nome);

        std::string cpf() const;
        void setCpf(const std::string &cpf);

        Adress adress() const;
        void setAdress(const Adress &adress);

    private:
        std::string m_nome;
        std::string m_cpf;
        Adress m_adress;
    };

}

#endif // CLIENT_H
