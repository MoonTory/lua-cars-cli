#ifndef ADRESS_H
#define ADRESS_H

#include <string>

namespace Luna {

    class Adress
    {
    public:
        Adress();
        Adress(std::string _cep, std::string _log, std::string _comp,
               std::string _bairro, std::string _estado, std::string _cidade);
        ~Adress() { delete this; }

        std::string cep() const;
        void setCep(const std::string &cep);

        std::string logradouro() const;
        void setLogradouro(const std::string &logradouro);

        std::string completmento() const;
        void setCompletmento(const std::string &completmento);

        std::string bairro() const;
        void setBairro(const std::string &bairro);

        std::string estado() const;
        void setEstado(const std::string &estado);

        std::string cidade() const;
        void setCidade(const std::string &cidade);

    private:
        std::string m_cep, m_logradouro,
                    m_completmento, m_bairro,
                    m_estado, m_cidade; // std::string
    };

}

#endif // ADRESS_H
