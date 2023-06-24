#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "util.hpp"
#include "pessoa.hpp"
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"
#include "empresa.hpp"
#include <iomanip>

using namespace std;

Empresa::Empresa() {}

Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal, Data hoje)
{
    this->setFaturamentoMensal(faturamentoMensal);
    this->setNomeEmpresa(nomeEmpresa);
    this->setCnpj(cnpj);
    this->setHoje(hoje);
}

float Empresa::getFaturamentoMensal()
{
    return this->_faturamentoMensal;
}

string Empresa::getNomeEmpresa()
{
    return this->_nomeEmpresa;
}

string Empresa::getCnpj()
{
    return this->_cnpj;
}

Pessoa Empresa::getDono()
{
    return this->_dono;
}

Data Empresa::getHoje()
{
    return this->_hoje;
}

vector<Asg> &Empresa::getAsgs()
{
    return this->_asgs;
}

vector<Vendedor> &Empresa::getVendedores()
{
    return this->_vendedores;
}

vector<Gerente> &Empresa::getGerentes()
{
    return this->_gerentes;
}

void Empresa::setFaturamentoMensal(float faturamentoMensal)
{
    this->_faturamentoMensal = faturamentoMensal;
}

void Empresa::setNomeEmpresa(string nomeEmpresa)
{
    this->_nomeEmpresa = nomeEmpresa;
}

void Empresa::setCnpj(string cnpj)
{
    this->_cnpj = cnpj;
}

void Empresa::setHoje(Data hoje)
{
    this->_hoje = hoje;
}

void Empresa::carregaFuncoes()
{

    string nomeArquivo = "funcoes.txt";

    try
    {

        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::in);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        string linha;
        cout << "***** Carregar funções *****" << endl;
        while (getline(arquivo, linha))
        {
            if (linha == "carregarEmpresa()")
            {
                this->carregarEmpresa();
            }
            else if (linha == "carregarAsg()")
            {
                this->carregarAsg();
            }
            else if (linha == "carregarVendedor()")
            {
                this->carregarVendedor();
            }
            else if (linha == "carregarGerente()")
            {
                this->carregarGerente();
            }
            else if (linha == "carregaDono()")
            {
                this->carregaDono();
            }
            else if (linha == "imprimeAsgs()")
            {
                this->imprimeAsgs();
            }
            else if (linha == "imprimeVendedores()")
            {
                this->imprimeVendedores();
            }
            else if (linha == "imprimeGerentes()")
            {
                this->imprimeGerentes();
            }
            else if (linha == "imprimeDono()")
            {
                this->imprimeDono();
            }
            else if (linha == "buscaFuncionario()")
            {
                getline(arquivo, linha);
                this->buscaFuncionario(linha);
            }
            else if (linha == "calculaSalarioFuncionario()")
            {
                getline(arquivo, linha);
                this->calculaSalarioFuncionario(linha);
            }
            else if (linha == "calculaTodoOsSalarios()")
            {
                this->calculaTodoOsSalarios();
            }
            else if (linha == "calcularRecisao()")
            {
                string matricula;
                Data desligamento;

                getline(arquivo, linha);
                matricula = linha;

                getline(arquivo, linha);
                desligamento.ano = stoi(linha);

                getline(arquivo, linha);
                desligamento.mes = stoi(linha);

                getline(arquivo, linha);
                desligamento.dia = stoi(linha);

                this->calcularRecisao(matricula, desligamento);
            }
            else if (linha == "demitirFuncionario()")
            {
                string matricula;
                Data desligamento;

                getline(arquivo, linha);
                matricula = linha;

                getline(arquivo, linha);
                desligamento.ano = stoi(linha);

                getline(arquivo, linha);
                desligamento.mes = stoi(linha);

                getline(arquivo, linha);
                desligamento.dia = stoi(linha);

                this->demitirFuncionario(matricula, desligamento);
            }
            else if (linha == "contratarFuncionario()")
            {
                this->contratarFuncionario();
            }
        }

        arquivo.close();
        cout << "********* CARREGAR FUNÇÕES CONCLUÍDO*********" << endl
             << endl;
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
        cout << "********* CARREGAR FUNÇÕES FALHOU*********" << endl
             << endl;
    }
}

void Empresa::carregarEmpresa()
{
    string nomeArquivo = "empresa.txt";
    try
    {

        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::in);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        string nomeEmpresa, cnpj;
        float faturamentoMensal;
        cout << "Empresa carregada:" << endl; 

        string linha;
        getline(arquivo, linha);
        getline(arquivo, linha);

        getline(arquivo, linha);
        nomeEmpresa = linha;
        cout << "Nome da empresa: " << nomeEmpresa << endl;

        getline(arquivo, linha);
        cnpj = linha;
        cout << "Cnpj da empresa: " << cnpj << endl;

        getline(arquivo, linha);
        faturamentoMensal = stof(linha);
        cout << "Faturamento da empresa: " << faturamentoMensal << endl;

        arquivo.close();

        this->setNomeEmpresa(nomeEmpresa);
        this->setCnpj(cnpj);
        this->setFaturamentoMensal(faturamentoMensal);
        cout << "********* CARREGAR EMPRESA CONCLUÍDO*********" << endl
             << endl;
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
        cout << "********* CARREGAR EMPRESA FALHOU*********" << endl
             << endl;
    }
}

void Empresa::carregarAsg()
{
    // TODO: Implementar a linha de diasDeFalta

    string nomeArquivo = "asg.txt";

    try
    {

        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::in);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        vector<Asg> &asgs = this->getAsgs();

        string linha;
        vector<string> vetor;

        while (getline(arquivo, linha))
        {
            vetor.push_back(linha);
        }

        arquivo.close();

        for (int ii = 3; ii < vetor.size(); ii += 22)
        {

            Asg asg1;
            cout << "ASG carregada:" << endl;

            asg1.setNome(vetor[ii]);
            cout << "Nome da ASG: " << vetor[ii] << endl;
            asg1.setCpf(vetor[ii + 1]);
            cout << "Cpf da ASG: " << vetor[ii+1] << endl;
            asg1.setQtdFilhos(stoi(vetor[ii + 2]));
            cout << "Quantidade de filhos da ASG: " << vetor[ii+2] << endl;
            asg1.setEstadoCivil(vetor[ii + 3]);
            cout << "Estado civil da ASG: " << vetor[ii+3] << endl;

            ii++;
            Endereco enderecoAsg;
            cout << "Endereço da ASG:" << endl;
            enderecoAsg.cidade = vetor[ii + 4];
            cout << "Cidade: " << vetor[ii+4] << endl;
            enderecoAsg.cep = vetor[ii + 5];
            cout << "Cep: " << vetor[ii+5] << endl;
            enderecoAsg.bairro = vetor[ii + 6];
            cout << "Bairro: " << vetor[ii+6] << endl;
            enderecoAsg.rua = vetor[ii + 7];
            cout << "Rua: " << vetor[ii+7] << endl;
            enderecoAsg.numero = stoi(vetor[ii + 8]);
            cout << "Número: " << vetor[ii+8] << endl;
            asg1.setEnderecoPessoal(enderecoAsg);

            ii++;
            Data dataNascimentoAsg;
            cout << "Data de nascimento da ASG: " << endl;
            cout << vetor[ii+11] << "/" << vetor[ii+10] << "/" << vetor[ii+9] << endl;
            dataNascimentoAsg.ano = stoi(vetor[ii + 9]);
            dataNascimentoAsg.mes = stoi(vetor[ii + 10]);
            dataNascimentoAsg.dia = stoi(vetor[ii + 11]);
            asg1.setDataNascimento(dataNascimentoAsg);

            ii++;
            cout << "Matricula da ASG: " << vetor[ii+12] << endl;
            asg1.setMatricula(vetor[ii + 12]);
            cout << "Salario da ASG: " << vetor[ii+13] << endl;
            asg1.setSalario(stof(vetor[ii + 13]));
            cout << "Adicional insalubridade da ASG: " << vetor[ii+14] << endl;
            asg1.setAdicionalInsalubridade(stof(vetor[ii + 14]));
            asg1.setDiasFalta(stoi(vetor[ii + 15]));
            cout << "Dias de faltas da ASG: " << vetor[ii+15] << endl;
            ii++;

            Data dataIngressoAsg;
            cout << "Data de ingresso da ASG: " << endl;
            cout << vetor[ii+18] << "/" << vetor[ii+17] << "/" << vetor[ii+16] << endl;
            dataIngressoAsg.ano = stoi(vetor[ii + 16]);
            dataIngressoAsg.mes = stoi(vetor[ii + 17]);
            dataIngressoAsg.dia = stoi(vetor[ii + 18]);
            asg1.setIngressoEmpresa(dataIngressoAsg);

            asgs.push_back(asg1);
        }

        cout << "********* CARREGAR ASGS CONCLUÍDO*********" << endl
             << endl;
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
        cout << "********* CARREGAR ASGS FALHOU*********" << endl
             << endl;
    }
}

void Empresa::carregarVendedor()
{
    // TODO: Implementar a linha de diasDeFalta

    string nomeArquivo = "vendedor.txt";

    try
    {

        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::in);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        vector<Vendedor> &vendedores = this->getVendedores();

        string linha;
        vector<string> vetor;

        while (getline(arquivo, linha))
        {
            vetor.push_back(linha);
        }

        arquivo.close();

        for (int ii = 3; ii < vetor.size(); ii += 22)
        {

            Vendedor vendedor1;
            cout << "Vendedor carregado:" << endl;

            vendedor1.setNome(vetor[ii]);
            cout << "Nome do vendedor: " << vetor[ii] << endl;
            vendedor1.setCpf(vetor[ii + 1]);
            cout << "Cpf do vendedor: " << vetor[ii+1] << endl;
            vendedor1.setQtdFilhos(stoi(vetor[ii + 2]));
            cout << "Quantidade de filhos do vendedor: " << vetor[ii+2] << endl;
            vendedor1.setEstadoCivil(vetor[ii + 3]);
            cout << "Estado civil do vendedor: " << vetor[ii+3] << endl;

            ii++;
            Endereco enderecoAsg;
            cout << "Endereço do vendedor: " << endl;
            enderecoAsg.cidade = vetor[ii + 4];
            cout << "Cidade: " << vetor[ii+4] << endl;
            enderecoAsg.cep = vetor[ii + 5];
            cout << "Cep: " << vetor[ii+5] << endl;
            enderecoAsg.bairro = vetor[ii + 6];
            cout << "Bairro: " << vetor[ii+6] << endl;
            enderecoAsg.rua = vetor[ii + 7];
            cout << "Rua: " << vetor[ii+7] << endl;
            enderecoAsg.numero = stoi(vetor[ii + 8]);
            cout << "Número: " << vetor[ii+8] << endl;
            vendedor1.setEnderecoPessoal(enderecoAsg);

            ii++;
            Data dataNascimentoAsg;
            cout << "Data de nascimento:" << endl;
            dataNascimentoAsg.ano = stoi(vetor[ii + 9]);
            cout << vetor[ii + 11] << "/" << vetor[ii + 10] << "/" << vetor[ii + 9] << endl;
            dataNascimentoAsg.mes = stoi(vetor[ii + 10]);
            dataNascimentoAsg.dia = stoi(vetor[ii + 11]);
            vendedor1.setDataNascimento(dataNascimentoAsg);

            ii++;
            vendedor1.setMatricula(vetor[ii + 12]);
            cout << "Matricula vendedor: " << vetor[ii+12] << endl;
            vendedor1.setSalario(stof(vetor[ii + 13]));
            cout << "Salario vendedor: " << vetor[ii+13] << endl;
            vendedor1.setTipoVendedor(vetor[ii + 14][0]);
            cout << "Tipo vendedor: " << vetor[ii+14][0] << endl;
            vendedor1.setDiasFalta(stoi(vetor[ii + 15]));
            cout << "Dias de faltas do vendedor: " << vetor[ii+15] << endl;
            ii++;

            Data dataIngressoAsg;
            cout << "Data de ingresso:" << endl;
            dataIngressoAsg.ano = stoi(vetor[ii + 16]);
            cout << vetor[ii + 18] << "/" << vetor[ii+17] << "/" << vetor[ii+16] << endl;
            dataIngressoAsg.mes = stoi(vetor[ii + 17]);
            dataIngressoAsg.dia = stoi(vetor[ii + 18]);
            vendedor1.setIngressoEmpresa(dataIngressoAsg);

            vendedores.push_back(vendedor1);
        }

        cout << "********* CARREGAR VENDEDORES CONCLUÍDO*********" << endl
             << endl;
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
        cout << "********* CARREGAR VENDEDORES FALHOU*********" << endl
             << endl;
    }
}

void Empresa::carregarGerente()
{
    // TODO: Implementar a linha de diasDeFalta

    string nomeArquivo = "gerente.txt";

    try
    {

        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::in);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        vector<Gerente> &gerentes = this->getGerentes();

        string linha;
        vector<string> vetor;

        while (getline(arquivo, linha))
        {
            vetor.push_back(linha);
        }

        arquivo.close();

        for (int ii = 3; ii < vetor.size(); ii += 22)
        {

            Gerente gerente1;
            cout << "Gerente:" << endl;

            gerente1.setNome(vetor[ii]);
            cout << "Nome do gerente: " << vetor[ii] << endl;
            gerente1.setCpf(vetor[ii + 1]);
            cout << "Cpf do gerente: " << vetor[ii + 1] << endl;
            gerente1.setQtdFilhos(stoi(vetor[ii + 2]));
            cout << "Quantidade de filhos do gerente: " << vetor[ii + 2] << endl;
            gerente1.setEstadoCivil(vetor[ii + 3]);
            cout << "Estado civil do gerente: " << vetor[ii + 3] << endl;

            ii++;
            Endereco enderecoAsg;
            cout << "Endereço: " << endl;
            enderecoAsg.cidade = vetor[ii + 4];
            cout << "Cidade: " << vetor[ii + 4] << endl;
            enderecoAsg.cep = vetor[ii + 5];
            cout << "Cep: " << vetor[ii + 5] << endl;
            enderecoAsg.bairro = vetor[ii + 6];
            cout << "Bairro: " << vetor[ii + 6] << endl;
            enderecoAsg.rua = vetor[ii + 7];
            cout << "Rua: " << vetor[ii + 7] << endl;
            enderecoAsg.numero = stoi(vetor[ii + 8]);
            cout << "Número: " << vetor[ii + 8] << endl;
            gerente1.setEnderecoPessoal(enderecoAsg);

            ii++;
            Data dataNascimentoAsg;
            cout << "Data de nascimento: " << endl;
            dataNascimentoAsg.ano = stoi(vetor[ii + 9]);
            cout << vetor[ii + 11] << "/" << vetor[ii +10] << "/" << vetor[ii +9] << endl;
            dataNascimentoAsg.mes = stoi(vetor[ii + 10]);
            dataNascimentoAsg.dia = stoi(vetor[ii + 11]);
            gerente1.setDataNascimento(dataNascimentoAsg);

            ii++;
            gerente1.setMatricula(vetor[ii + 12]);
            cout << "Matricula do gerente: " << vetor[ii + 12] << endl;
            gerente1.setSalario(stof(vetor[ii + 13]));
            cout << "Salario do gerente: " << vetor[ii + 13] << endl;
            gerente1.setParticipacaoLucros(stof(vetor[ii + 14]));
            cout << "Participação dos lucros: " << vetor[ii + 14] << endl;
            gerente1.setDiasFalta(stoi(vetor[ii + 15]));
            cout << "Dias de falta do gerente: " << vetor[ii + 15] << endl;

            ii++;

            Data dataIngressoAsg;
            cout << "Data de ingresso: " << endl;
            dataIngressoAsg.ano = stoi(vetor[ii + 16]);
            cout << vetor[ii + 18] << "/" << vetor[ii + 17] << "/" << vetor[ii + 16] << endl;
            dataIngressoAsg.mes = stoi(vetor[ii + 17]);
            dataIngressoAsg.dia = stoi(vetor[ii + 18]);
            gerente1.setIngressoEmpresa(dataIngressoAsg);

            gerentes.push_back(gerente1);
        }

        cout << "********* CARREGAR GERENTES CONCLUÍDO*********" << endl
             << endl;
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
        cout << "********* CARREGAR GERENTES FALHOU*********" << endl
             << endl;
    }
}

void Empresa::carregaDono()
{
    string nomeArquivo = "dono.txt";

    try
    {

        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::in);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        string linha;
        vector<string> vetor;

        // OBS: Sei que só tem apenas um dono, mas decidi fazer assim para padronizar com os ags, vendedores, gerentes
        while (getline(arquivo, linha))
        {
            vetor.push_back(linha);
        }

        arquivo.close();

        for (int ii = 2; ii < vetor.size(); ii += 13)
        {
            cout << "Dono carregado: " << endl;
            this->_dono.setNome(vetor[ii]);
            cout << "Nome do dono: " << vetor[ii] << endl;
            this->_dono.setCpf(vetor[ii + 1]);
            cout << "Cpf do dono: " << vetor[ii + 1] << endl;
            this->_dono.setQtdFilhos(stoi(vetor[ii + 2]));
            cout << "Quantidade de filhos do dono: " << vetor[ii + 2] << endl;
            this->_dono.setEstadoCivil(vetor[ii + 3]);
            cout << "Estado civil do dono: " << vetor[ii + 3] << endl;

            Endereco enderecoAsg;
            cout << "Endereço do dono:" << endl;
            enderecoAsg.cidade = vetor[ii + 4];
            cout << "Cidade: " << vetor[ii + 4] << endl;
            enderecoAsg.cep = vetor[ii + 5];
            cout << "Cep: " << vetor[ii + 5] << endl;
            enderecoAsg.bairro = vetor[ii + 6];
            cout << "Bairro: " << vetor[ii + 6] << endl;
            enderecoAsg.rua = vetor[ii + 7];
            cout << "Rua: " << vetor[ii + 7] << endl;
            enderecoAsg.numero = stoi(vetor[ii + 8]);
            cout << "Número: " << vetor[ii + 8] << endl;
            this->_dono.setEnderecoPessoal(enderecoAsg);

            Data dataNascimentoAsg;
            cout << "Data de nascimento:" << endl;
            dataNascimentoAsg.ano = stoi(vetor[ii + 9]);
            cout << vetor[ii + 11] << "/" << vetor[ii + 10] << "/" << vetor[ii + 9] << endl;
            dataNascimentoAsg.mes = stoi(vetor[ii + 10]);
            dataNascimentoAsg.dia = stoi(vetor[ii + 11]);
            this->_dono.setDataNascimento(dataNascimentoAsg);
        }

        cout << "********* CARREGAR DONO CONCLUÍDO*********" << endl
             << endl;
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
        cout << "********* CARREGAR DONO FALHOU*********" << endl
             << endl;
    }
}

void Empresa::imprimeAsgs()
{
    cout << "********* LISTAR AGS*********" << endl;

    vector<Asg> &asgs = this->getAsgs();

    for (auto ii : this->getAsgs())
    {

        ii.imprimirAtributosAsg();

        cout << "____________________________________" << endl;
    }
    cout << "********* FIM LISTAR AGS*********" << endl
         << endl;
}

void Empresa::imprimeVendedores()
{
    cout << "********* LISTAR VENDEDORES*********" << endl;

    for (auto ii : this->getVendedores())
    {

        ii.imprimirAtributosVendedor();

        cout << "____________________________________" << endl;
    }
    cout << "********* FIM LISTAR VENDEDORES*********" << endl
         << endl;
}

void Empresa::imprimeGerentes()
{
    cout << "********* LISTAR GERENTES*********" << endl;

    for (auto ii : this->getGerentes())
    {

        ii.imprimirAtributosGerente();

        cout << "____________________________________" << endl;
    }
    cout << "********* FIM LISTAR GERENTES*********" << endl
         << endl;
}

void Empresa::imprimeDono()
{
    cout << "********* INÍCIO LISTAR DONO*********" << endl;

    Pessoa dono = this->getDono();

    dono.imprimirAtributosPessoa();
    cout << "********* FIM LISTAR DONO*********" << endl
         << endl;
}

void Empresa::buscaFuncionario(string matricula)
{
    cout << "********* INÍCIO BUSCA FUNCIONÁRIO*********" << endl;

    bool existe = false;

    for (auto ii : this->getAsgs())
    {
        if (ii.getMatricula() == matricula)
        {
            ii.imprimirAtributosAsg();
            existe = true;
        }
    }

    for (auto ii : this->getVendedores())
    {
        if (ii.getMatricula() == matricula)
        {
            ii.imprimirAtributosVendedor();
            existe = true;
        }
    }

    for (auto ii : this->getGerentes())
    {
        if (ii.getMatricula() == matricula)
        {
            ii.imprimirAtributosGerente();
            existe = true;
        }
    }

    if (!existe)
        cout << "Funcionário não encontrado no sistema" << endl;

    cout << "********* FIM BUSCA FUNCIONÁRIO*********" << endl
         << endl;
}

void Empresa::calculaSalarioFuncionario(string matricula)
{
    cout << "********* INÍCIO CALCULA SALÁRIO FUNCIONÁRIO*********" << endl;

    bool existe = false;

    for (auto ii : this->getAsgs())
    {
        if (ii.getMatricula() == matricula)
        {
            cout << ii.calcularSalario() << endl;
            existe = true;
        }
    }

    for (auto ii : this->getVendedores())
    {
        if (ii.getMatricula() == matricula)
        {
            cout << ii.calcularSalario() << endl;
            existe = true;
        }
    }

    for (auto ii : this->getGerentes())
    {
        if (ii.getMatricula() == matricula)
        {
            cout << ii.calcularSalario() << endl;
            existe = true;
        }
    }

    if (!existe)
        cout << "Funcionário não encontrado no sistema" << endl;

    cout << "********* FIM CALCULA SALÁRIO FUNCIONÁRIO*********" << endl
         << endl;
}

void Empresa::calculaTodoOsSalarios()
{
    cout << "********* GERANDO RELATÓRIO...*********" << endl;

    try
    {

        string nomeArquivo = "relatorioFinanceiro.txt";
        fstream arquivo;
        arquivo.open(caminhoArquivosEscrita + nomeArquivo, ios::out);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        float totalSalarioAsgs = 0;
        float totalSalarioVendedores = 0;
        float totalSalarioGerentes = 0;
        float totalSalarios = 0;

        float lucro, custoAsg, custoVendedor, custoGerente;

        arquivo << "######### Relatório Financeiro ########" << endl
                << endl;
        cout << "######### Relatório Financeiro ########" << endl
                << endl;
        arquivo << "Cargo: ASG" << endl;
        cout << "Cargo: ASG" << endl;
        for (auto ii : this->getAsgs())
        {
            totalSalarioAsgs += ii.getSalario();
            arquivo << ii.getMatricula() << " - " << ii.getNome() << " - "
                    << "R$ " << ii.getSalario() << endl;
            cout << ii.getMatricula() << " - " << ii.getNome() << " - "
                    << "R$ " << ii.getSalario() << endl;
        }

        arquivo << "Total ASG: " << fixed << setprecision(2) << totalSalarioAsgs << endl
                << endl;
        cout << "Total ASG: " << fixed << setprecision(2) << totalSalarioAsgs << endl
                << endl;

        arquivo << "Cargo: Vendedor" << endl;
        cout << "Cargo: Vendedor" << endl;
        for (auto ii : this->getVendedores())
        {
            totalSalarioVendedores += ii.getSalario();
            arquivo << ii.getMatricula() << " - " << ii.getNome() << " - "
                    << "R$ " << ii.getSalario() << endl;
            cout << ii.getMatricula() << " - " << ii.getNome() << " - "
                    << "R$ " << ii.getSalario() << endl;
        }

        arquivo << "Total Vendedor: " << fixed << setprecision(2) << totalSalarioVendedores << endl
                << endl;
        cout << "Total Vendedor: " << fixed << setprecision(2) << totalSalarioVendedores << endl
                << endl;

        arquivo << "Cargo: Gerente" << endl;
        cout << "Cargo: Gerente" << endl;
        for (auto ii : this->getGerentes())
        {
            totalSalarioGerentes += ii.getSalario();
            arquivo << ii.getMatricula() << " - " << ii.getNome() << " - "
                    << "R$ " << ii.getSalario() << endl;
            cout << ii.getMatricula() << " - " << ii.getNome() << " - "
                    << "R$ " << ii.getSalario() << endl;
        }

        arquivo << "Total Gerente: " << fixed << setprecision(2) << totalSalarioGerentes << endl
                << endl;
        cout << "Total Gerente: " << fixed << setprecision(2) << totalSalarioGerentes << endl
                << endl;

        totalSalarios = totalSalarioAsgs + totalSalarioVendedores + totalSalarioGerentes;

        arquivo << "CUSTO TOTAL DE RH: R$ " << fixed << setprecision(2) << totalSalarios << endl;
        arquivo << endl;
        cout << "CUSTO TOTAL DE RH: R$ " << fixed << setprecision(2) << totalSalarios << endl;
        cout << endl;

        lucro = (getFaturamentoMensal() - totalSalarios);
        arquivo << "FATURAMENTO MENSAL: " << getFaturamentoMensal() << endl;
        arquivo << endl;
        cout << "FATURAMENTO MENSAL: " << getFaturamentoMensal() << endl;
        cout << endl;

        custoAsg = totalSalarioAsgs / totalSalarios;
        custoVendedor = totalSalarioVendedores / totalSalarios;
        custoGerente = totalSalarioGerentes / totalSalarios;

        arquivo << "Custo ASG(%): " << custoAsg * 100 << endl;
        arquivo << "Custo Vendedor(%): " << custoVendedor * 100 << endl;
        arquivo << "Custo Gerente(%): " << custoGerente * 100 << endl;
        arquivo << endl;
        cout << "Custo ASG(%): " << custoAsg * 100 << endl;
        cout << "Custo Vendedor(%): " << custoVendedor * 100 << endl;
        cout << "Custo Gerente(%): " << custoGerente * 100 << endl;
        cout << endl;

        arquivo << "LUCRO DA EMPRESA: " << lucro << endl;
        arquivo << endl;
        cout << "LUCRO DA EMPRESA: " << lucro << endl;
        cout << endl;

        if (lucro > 0){
            arquivo << "SITUAÇÃO: Lucro" << endl;
            cout << "SITUAÇÃO: Lucro" << endl;
        }

        else if (lucro <= 0){
            arquivo << "SITUAÇÃO: Prejuizo" << endl;
            cout << "SITUAÇÃO: Prejuizo" << endl;
        }

        arquivo.close();

        cout << "********* RELATÓRIO GERADO *********" << endl
             << endl;
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
        cout << "********* RELATÓRIO FALHOU *********" << endl
             << endl;
    }
}

void Empresa::calcularRecisao(string matricula, Data desligamento)
{
    cout << "********* INÍCIO CALCULA RECISÃO FUNCIONÁRIO*********" << endl;

    bool existe = false;

    for (auto ii : this->getAsgs())
    {
        if (ii.getMatricula() == matricula)
        {
            cout << ii.calcularRecisao(desligamento) << endl;
            existe = true;
        }
    }

    for (auto ii : this->getVendedores())
    {
        if (ii.getMatricula() == matricula)
        {
            cout << ii.calcularRecisao(desligamento) << endl;
            existe = true;
        }
    }

    for (auto ii : this->getGerentes())
    {
        if (ii.getMatricula() == matricula)
        {
            cout << ii.calcularRecisao(desligamento) << endl;
            existe = true;
        }
    }

    if (!existe)
        cout << "Funcionário não encontrado no sistema" << endl;

    cout << "********* FIM CALCULA RECISÃO FUNCIONÁRIO*********" << endl
         << endl;
}

template <typename T>
void Empresa::escreverArquivoRelatorioDemissional(T funcionario, fstream &arquivo, Data desligamento, string cargo)
{
    arquivo << "##############################" << endl;
    arquivo << "    Relatorio Demissional" << endl;
    arquivo << "##############################" << endl;
    arquivo << "Cargo: " << cargo << endl;
    arquivo << "Nome: " << funcionario.getNome() << endl;
    arquivo << "CPF: " << funcionario.getCpf() << endl;
    arquivo << "Matrícula: " << funcionario.getMatricula() << endl;
    arquivo << "Data de ingresso: " << funcionario.getIngressoEmpresa().dia << "/" << funcionario.getIngressoEmpresa().mes << "/" << funcionario.getIngressoEmpresa().ano << endl;
    arquivo << "Data de demissão: " << desligamento.dia << "/" << desligamento.mes << "/" << desligamento.ano << endl;
    arquivo << "******************************" << endl;
    arquivo << "Valor de rescisão: " << funcionario.calcularRecisao(desligamento) << endl;
    arquivo << "******************************" << endl;
    cout << "##############################" << endl;
    cout << "    Relatorio Demissional" << endl;
    cout << "##############################" << endl;
    cout << "Cargo: " << cargo << endl;
    cout << "Nome: " << funcionario.getNome() << endl;
    cout << "CPF: " << funcionario.getCpf() << endl;
    cout << "Matrícula: " << funcionario.getMatricula() << endl;
    cout << "Data de ingresso: " << funcionario.getIngressoEmpresa().dia << "/" << funcionario.getIngressoEmpresa().mes << "/" << funcionario.getIngressoEmpresa().ano << endl;
    cout << "Data de demissão: " << desligamento.dia << "/" << desligamento.mes << "/" << desligamento.ano << endl;
    cout << "******************************" << endl;
    cout << "Valor de rescisão: " << funcionario.calcularRecisao(desligamento) << endl;
    cout << "******************************" << endl;

    float anoIngresso = calcularAnoData(funcionario.getIngressoEmpresa());
    float anoDesligamento = calcularAnoData(desligamento);
    float anoTrabalhado = anoDesligamento - anoIngresso;

    // Convertendo anos em inteiros
    int anos = static_cast<int>(anoTrabalhado);

    // Calculando meses e dias
    float meses_em_float = (anoTrabalhado - anos) * 12;
    int meses = static_cast<int>(meses_em_float);

    float dias_em_float = (meses_em_float - meses) * 30; // Estimando 30 dias por mês
    int dias = static_cast<int>(dias_em_float);

    arquivo << "Tempo de Trabalho: " << anos << " anos, " << meses << " meses, "
            << "e " << dias << " dias" << endl;
    cout << "Tempo de Trabalho: " << anos << " anos, " << meses << " meses, "
            << "e " << dias << " dias" << endl;
}

template <typename T>
bool Empresa::buscaFuncionarioDemite(vector<T> &funcionarios, std::string matricula, fstream &arquivo, Data desligamento, string cargo)
{
    bool existe = false;

    for (typename vector<T>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++)
    {
        if (it->getMatricula() == matricula)
        {
            escreverArquivoRelatorioDemissional<T>(*it, arquivo, desligamento, cargo);
            existe = true;
            cout << "Funcionário " << cargo << " " << it->getNome() << " demitido com sucesso." << endl;
            funcionarios.erase(it);
            arquivo.close(); // qeuria colocar antes do return existe, mas está empatando (ATT: Está dando erro pois está fechando o arquivo mesmo sem ser o cara, enfim arrumar isso dps)
            break;
        }
    }

    return existe;
}

// A PARTIR DAKI COMEÇA AS FUNCOES DO 3 PROJETO

// template <typename T>
// void Empresa::atualizarArquivo(string nomeArquivo, vector<T> &funcionarios, string cargo)
// {
//     try
//     {

//         fstream arquivo;
//         arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::out);
//         if (!arquivo.is_open())
//         {
//             string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
//             throw runtime_error(erroMensagem);
//         }

//         int codigoFuncionario = 0;

//         for (auto ii : funcionarios)
//         {
//             arquivo << "#########################################################" << endl;
//             arquivo << cargo << " Nº: " << codigoFuncionario << endl;
//             arquivo << "##### DADOS PESSOAIS #####" << endl;

//             arquivo << ii.getNome() << endl;
//             arquivo << ii.getCpf() << endl;
//             arquivo << ii.getQtdFilhos() << endl;
//             arquivo << ii.getEstadoCivil() << endl;

//             arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;

//             arquivo << ii.getEnderecoPessoal().cidade << endl;
//             arquivo << ii.getEnderecoPessoal().cep << endl;
//             arquivo << ii.getEnderecoPessoal().bairro << endl;
//             arquivo << ii.getEnderecoPessoal().rua << endl;
//             arquivo << ii.getEnderecoPessoal().numero << endl;

//             arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;

//             arquivo << ii.getDataNascimento().ano << endl;
//             arquivo << ii.getDataNascimento().mes << endl;
//             arquivo << ii.getDataNascimento().dia << endl;

//             arquivo << "##### DADOS FUNCIONAIS #####" << endl;
//             arquivo << ii.getMatricula() << endl;
//             arquivo << ii.getSalario() << endl;
//             if (cargo == "ASG")
//             {
//                 arquivo << ii.getAdicionalInsalubridade() << endl;
//             }
//             else if (cargo == "VENDEDOR")
//             {
//                 arquivo << ii.getTipoVendedor() << endl;
//             }
//             else if (cargo == "GERENTE")
//             {
//                 arquivo << ii.getParticipacaoLucros() << endl;
//             }

//             arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;

//             arquivo << ii.getIngressoEmpresa().ano << endl;
//             arquivo << ii.getIngressoEmpresa().mes << endl;
//             arquivo << ii.getIngressoEmpresa().dia << endl;

//             codigoFuncionario++;
//         }

//         arquivo.close();
//     }
//     catch (exception &e)
//     {
//         cout << "Erro: " << e.what() << endl;
//     }
// }

void Empresa::atualizarArquivoAsg()
{
    try
    {

        string nomeArquivo = "asg.txt";

        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::out);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        int codigoFuncionario = 0;

        for (auto ii : this->getAsgs())
        {
            arquivo << "#########################################################" << endl;
            arquivo << "ASG Nº: " << codigoFuncionario << endl;
            arquivo << "##### DADOS PESSOAIS #####" << endl;
            cout << "#########################################################" << endl;
            cout << "ASG Nº: " << codigoFuncionario << endl;
            cout << "##### DADOS PESSOAIS #####" << endl;

            arquivo << ii.getNome() << endl;
            arquivo << ii.getCpf() << endl;
            arquivo << ii.getQtdFilhos() << endl;
            arquivo << ii.getEstadoCivil() << endl;
            cout << "Nome: " << ii.getNome() << endl;
            cout << "Cpf: " << ii.getCpf() << endl;
            cout << "Quantidade de filhos: " << ii.getQtdFilhos() << endl;
            cout << "Estado civil: " << ii.getEstadoCivil() << endl;

            arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
            cout << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;

            arquivo << ii.getEnderecoPessoal().cidade << endl;
            arquivo << ii.getEnderecoPessoal().cep << endl;
            arquivo << ii.getEnderecoPessoal().bairro << endl;
            arquivo << ii.getEnderecoPessoal().rua << endl;
            arquivo << ii.getEnderecoPessoal().numero << endl;
            cout << "Cidade: " << ii.getEnderecoPessoal().cidade << endl;
            cout << "Cep: " << ii.getEnderecoPessoal().cep << endl;
            cout << "Bairro: " << ii.getEnderecoPessoal().bairro << endl;
            cout << "Rua: " << ii.getEnderecoPessoal().rua << endl;
            cout << "Número: " << ii.getEnderecoPessoal().numero << endl;

            arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
            cout << "***** Data de nascimento (ano, mes, dia) ****" << endl;

            arquivo << ii.getDataNascimento().ano << endl;
            arquivo << ii.getDataNascimento().mes << endl;
            arquivo << ii.getDataNascimento().dia << endl;
            cout << ii.getDataNascimento().dia << "/" << ii.getDataNascimento().mes << "/" << ii.getDataNascimento().ano << endl;

            arquivo << "##### DADOS FUNCIONAIS #####" << endl;
            arquivo << ii.getMatricula() << endl;
            arquivo << ii.getSalario() << endl;
            arquivo << ii.getAdicionalInsalubridade() << endl;
            arquivo << ii.getDiasFalta() << endl;
            cout << "Matricula: " << ii.getMatricula() << endl;
            cout << "Salario: " << ii.getSalario() << endl;
            cout << "Adicional de insalubridade: " << ii.getAdicionalInsalubridade() << endl;
            cout << "Dias de faltas: " << ii.getDiasFalta() << endl;

            arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
            cout << "***** Data de ingresso (ano, mes, dia) ****" << endl;

            arquivo << ii.getIngressoEmpresa().ano << endl;
            arquivo << ii.getIngressoEmpresa().mes << endl;
            arquivo << ii.getIngressoEmpresa().dia << endl;
            cout << ii.getIngressoEmpresa().dia << "/" << ii.getIngressoEmpresa().mes << "/" << ii.getIngressoEmpresa().ano << endl;

            codigoFuncionario++;
        }

        arquivo.close();
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
    }
}

void Empresa::atualizarArquivoVendedor()
{
    try
    {

        string nomeArquivo = "vendedor.txt";

        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::out);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        int codigoFuncionario = 0;

        for (auto ii : this->getVendedores())
        {
            arquivo << "#########################################################" << endl;
            arquivo << "VENDEDOR Nº: " << codigoFuncionario << endl;
            arquivo << "##### DADOS PESSOAIS #####" << endl;
            cout << "#########################################################" << endl;
            cout << "VENDEDOR Nº: " << codigoFuncionario << endl;
            cout << "##### DADOS PESSOAIS #####" << endl;

            arquivo << ii.getNome() << endl;
            arquivo << ii.getCpf() << endl;
            arquivo << ii.getQtdFilhos() << endl;
            arquivo << ii.getEstadoCivil() << endl;
            cout << "Nome: " << ii.getNome() << endl;
            cout << "Cpf: " << ii.getCpf() << endl;
            cout << "Quantidade de filhos: " << ii.getQtdFilhos() << endl;
            cout << "Estado civil: " << ii.getEstadoCivil() << endl;

            arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
            cout << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;

            arquivo << ii.getEnderecoPessoal().cidade << endl;
            arquivo << ii.getEnderecoPessoal().cep << endl;
            arquivo << ii.getEnderecoPessoal().bairro << endl;
            arquivo << ii.getEnderecoPessoal().rua << endl;
            arquivo << ii.getEnderecoPessoal().numero << endl;
            cout << "Cidade: " << ii.getEnderecoPessoal().cidade << endl;
            cout << "Endereço pessoal: " << ii.getEnderecoPessoal().cep << endl;
            cout << "Bairro: " << ii.getEnderecoPessoal().bairro << endl;
            cout << "Rua: " << ii.getEnderecoPessoal().rua << endl;
            cout << "Número: " << ii.getEnderecoPessoal().numero << endl;

            arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
            cout << "***** Data de nascimento (ano, mes, dia) ****" << endl;

            arquivo << ii.getDataNascimento().ano << endl;
            arquivo << ii.getDataNascimento().mes << endl;
            arquivo << ii.getDataNascimento().dia << endl;
            cout << ii.getDataNascimento().dia << "/" << ii.getDataNascimento().mes << "/" << ii.getDataNascimento().ano << endl;

            arquivo << "##### DADOS FUNCIONAIS #####" << endl;
            arquivo << ii.getMatricula() << endl;
            arquivo << ii.getSalario() << endl;
            arquivo << ii.getTipoVendedor() << endl;
            arquivo << ii.getDiasFalta() << endl;
            cout << "##### DADOS FUNCIONAIS #####" << endl;
            cout << "Matricula: " << ii.getMatricula() << endl;
            cout << "Salario: " << ii.getSalario() << endl;
            cout << "Tipo do vendedor: " << ii.getTipoVendedor() << endl;
            cout << "Dias de faltas: " << ii.getDiasFalta() << endl;

            arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
            cout << "***** Data de ingresso (ano, mes, dia) ****" << endl;

            arquivo << ii.getIngressoEmpresa().ano << endl;
            arquivo << ii.getIngressoEmpresa().mes << endl;
            arquivo << ii.getIngressoEmpresa().dia << endl;
            cout << ii.getIngressoEmpresa().dia << "/" << ii.getIngressoEmpresa().mes << "/" << ii.getIngressoEmpresa().ano << endl;

            codigoFuncionario++;
        }

        arquivo.close();
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
    }
}

void Empresa::atualizarArquivoGerente()
{
    try
    {

        string nomeArquivo = "gerente.txt";

        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::out);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        int codigoFuncionario = 0;

        for (auto ii : this->getGerentes())
        {
            arquivo << "#########################################################" << endl;
            arquivo << "GERENTE Nº: " << codigoFuncionario << endl;
            arquivo << "##### DADOS PESSOAIS #####" << endl;
            cout << "#########################################################" << endl;
            cout << "GERENTE Nº: " << codigoFuncionario << endl;
            cout << "##### DADOS PESSOAIS #####" << endl;

            arquivo << ii.getNome() << endl;
            arquivo << ii.getCpf() << endl;
            arquivo << ii.getQtdFilhos() << endl;
            arquivo << ii.getEstadoCivil() << endl;
            cout << "Nome: " << ii.getNome() << endl;
            cout << "Cpf: " << ii.getCpf() << endl;
            cout << "Quantidade de filhos: " << ii.getQtdFilhos() << endl;
            cout << "Estado civil:" << ii.getEstadoCivil() << endl;

            arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
            cout << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;

            arquivo << ii.getEnderecoPessoal().cidade << endl;
            arquivo << ii.getEnderecoPessoal().cep << endl;
            arquivo << ii.getEnderecoPessoal().bairro << endl;
            arquivo << ii.getEnderecoPessoal().rua << endl;
            arquivo << ii.getEnderecoPessoal().numero << endl;
            cout << "Cidade: " << ii.getEnderecoPessoal().cidade << endl;
            cout << "Cep: " << ii.getEnderecoPessoal().cep << endl;
            cout << "Bairro: " << ii.getEnderecoPessoal().bairro << endl;
            cout << "Rua: " << ii.getEnderecoPessoal().rua << endl;
            cout << "Número: " << ii.getEnderecoPessoal().numero << endl;

            arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
            cout << "***** Data de nascimento (ano, mes, dia) ****" << endl;

            arquivo << ii.getDataNascimento().ano << endl;
            arquivo << ii.getDataNascimento().mes << endl;
            arquivo << ii.getDataNascimento().dia << endl;
            cout << ii.getDataNascimento().dia << "/" << ii.getDataNascimento().mes << "/" << ii.getDataNascimento().ano << endl;

            arquivo << "##### DADOS FUNCIONAIS #####" << endl;
            arquivo << ii.getMatricula() << endl;
            arquivo << ii.getSalario() << endl;
            arquivo << ii.getParticipacaoLucros() << endl;
            arquivo << ii.getDiasFalta() << endl;
            cout << "##### DADOS FUNCIONAIS #####" << endl;
            cout << "Matricula: " << ii.getMatricula() << endl;
            cout << "Salario: " << ii.getSalario() << endl;
            cout << "Partição nos lucros: " << ii.getParticipacaoLucros() << endl;
            cout << "Dias de falta: " << ii.getDiasFalta() << endl;

            arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
            cout << "***** Data de ingresso (ano, mes, dia) ****" << endl;

            arquivo << ii.getIngressoEmpresa().ano << endl;
            arquivo << ii.getIngressoEmpresa().mes << endl;
            arquivo << ii.getIngressoEmpresa().dia << endl;
            cout << ii.getIngressoEmpresa().dia << "/" << ii.getIngressoEmpresa().mes << "/" << ii.getIngressoEmpresa().ano << endl;

            codigoFuncionario++;
        }

        arquivo.close();
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
    }
}

void Empresa::demitirFuncionario(string matricula, Data desligamento)
{
    cout << "********* DEMITINDO FUNCIONÁRIO...*********" << endl;

    try
    {

        string nomeArquivo = "relatórioDemissional.txt";
        fstream arquivo;
        arquivo.open(caminhoArquivosEscrita + nomeArquivo, ios::out);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        vector<Asg> &asgs = this->getAsgs();
        vector<Vendedor> &vendedores = this->getVendedores();
        vector<Gerente> &gerentes = this->getGerentes();

        if (this->buscaFuncionarioDemite<Asg>(asgs, matricula, arquivo, desligamento, "Asg"))
        {
            atualizarArquivoAsg();
            return;
        }
        if (this->buscaFuncionarioDemite<Vendedor>(vendedores, matricula, arquivo, desligamento, "Vendedor"))
        {
            atualizarArquivoVendedor();
            return;
        }
        if (this->buscaFuncionarioDemite<Gerente>(gerentes, matricula, arquivo, desligamento, "Gerente"))
        {
            atualizarArquivoGerente();
            return;
        }

        throw runtime_error("Funcionário não encontrado!");
    }

    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
        cout << "********* DEMITIR FUNCIONARIO FALHOU *********" << endl
             << endl;
    }
}

void Empresa::contratarFuncionario()
{
    // TODO: Implementar a linha de diasDeFalta
    try
    {
        string nomeArquivo = "novoFuncionario.txt";
        fstream arquivo;
        arquivo.open(caminhoArquivosLeitura + nomeArquivo, ios::in);
        if (!arquivo.is_open())
        {
            string erroMensagem = "O arquivo " + nomeArquivo + " não foi lido.";
            throw runtime_error(erroMensagem);
        }

        string linha1, linha2;
        Endereco ende;
        Data nascimento, ingresso;

        vector<Asg> &asgs = this->getAsgs();
        vector<Vendedor> &vendedores = this->getVendedores();
        vector<Gerente> &gerentes = this->getGerentes();
        while (getline(arquivo, linha1))
        {
            if (linha1 == "ASG" || linha1 == "Asg")
            {
                Asg asg;
                cout << "----- ASG contratada -----" << endl;

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                asg.setNome(linha2);
                cout << "Nome: " << linha2 << endl;
                getline(arquivo, linha2);
                asg.setCpf(linha2);
                cout << "Cpf: " << linha2 << endl;
                getline(arquivo, linha2);
                asg.setQtdFilhos(stoi(linha2));
                cout << "Quantidade de filhos: " << linha2 << endl;
                getline(arquivo, linha2);
                asg.setEstadoCivil(linha2);
                cout << "Estado civil: " << linha2 << endl;

                cout << "*** Endereço da ASG ***" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ende.cidade = linha2;
                cout << "Cidade: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.cep = linha2;
                cout << "Cep: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.bairro = linha2;
                cout << "Bairro: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.rua = linha2;
                cout << "Rua: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.numero = stoi(linha2);
                cout << "Número: " << linha2 << endl;
                asg.setEnderecoPessoal(ende);

                cout << "***** Data de nascimento da ASG *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                nascimento.ano = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.mes = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.dia = stoi(linha2);
                cout << nascimento.dia << "/" << nascimento.mes << "/" << nascimento.ano << endl;
                asg.setDataNascimento(nascimento);

                cout << "***** Dados funcionais *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                asg.setMatricula(linha2);
                cout << "Matricula: " << linha2 << endl;
                getline(arquivo, linha2);
                asg.setSalario(stod(linha2));
                cout << "Slario: " << linha2 << endl;
                getline(arquivo, linha2);
                asg.setAdicionalInsalubridade(stod(linha2));
                cout << "Adicional de insalubridade: " << linha2 << endl;
                getline(arquivo, linha2);
                asg.setDiasFalta(stoi(linha2));
                cout << "Dias de falta: " << linha2 << endl;

                cout << "***** Data de ingresso na empresa *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ingresso.ano = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.mes = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.dia = stoi(linha2);
                cout << ingresso.dia << "/" << ingresso.mes << "/" << ingresso.ano << endl;
                asg.setIngressoEmpresa(ingresso);

                asgs.push_back(asg);
                cout << "Asg cadastrada com sucesso." << endl;

                atualizarArquivoAsg();
            }
            else if (linha1 == "Vendedor" || linha1 == "VENDEDOR")
            {
                Vendedor vendedor;
                cout << "----- Vendedor contratado -----" << endl;

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                vendedor.setNome(linha2);
                cout << "Nome: " << linha2 << endl;
                getline(arquivo, linha2);
                vendedor.setCpf(linha2);
                cout << "Cpf: " << linha2 << endl;
                getline(arquivo, linha2);
                vendedor.setQtdFilhos(stoi(linha2));
                cout << "Quantidade de filhos: " << linha2 << endl;
                getline(arquivo, linha2);
                vendedor.setEstadoCivil(linha2);
                cout << "Estado civil: " << linha2 << endl;

                cout << "***** Endereço do vendedor *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ende.cidade = linha2;
                cout << "Cidade: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.cep = linha2;
                cout << "Cep: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.bairro = linha2;
                cout << "Bairro: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.rua = linha2;
                cout << "Rua: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.numero = stoi(linha2);
                cout << "Número: " << linha2 << endl;
                vendedor.setEnderecoPessoal(ende);

                cout << "***** Data de nascimento do vendedor *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                nascimento.ano = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.mes = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.dia = stoi(linha2);
                cout << nascimento.dia << "/" << nascimento.mes << "/" << nascimento.ano << endl;
                vendedor.setDataNascimento(nascimento);

                cout << "***** Dados funcionais *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                vendedor.setMatricula(linha2);
                cout << "Matricula: " << linha2 << endl;
                getline(arquivo, linha2);
                vendedor.setSalario(stod(linha2));
                cout << "Salario: " << linha2 << endl;
                getline(arquivo, linha2);
                vendedor.setTipoVendedor(linha2[0]);
                cout << "Tipo vendedor: " << linha2 << endl;
                getline(arquivo, linha2);
                vendedor.setDiasFalta(stoi(linha2));
                cout << "Dias de falta: " << linha2 << endl;

                cout << "***** Data de ingresso *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ingresso.ano = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.mes = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.dia = stoi(linha2);
                cout << ingresso.dia << "/" << ingresso.mes << "/" << ingresso.ano << endl;
                vendedor.setIngressoEmpresa(ingresso);

                vendedores.push_back(vendedor);
                cout << "Vendedor cadastrado com sucesso." << endl;
                atualizarArquivoVendedor();
            }
            else if (linha1 == "Gerente" || linha1 == "GERENTE")
            {
                Gerente gerente;
                cout << "----- Gerente contratado -----" << endl;

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                gerente.setNome(linha2);
                cout << "Nome: " << linha2 << endl;
                getline(arquivo, linha2);
                gerente.setCpf(linha2);
                cout << "Cpf: " << linha2 << endl;
                getline(arquivo, linha2);
                gerente.setQtdFilhos(stoi(linha2));
                cout << "Quantidade de filhos: " << linha2 << endl;
                getline(arquivo, linha2);
                gerente.setEstadoCivil(linha2);
                cout << "Estado civil: " << linha2 << endl;

                cout << "***** Endereço do gerente *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ende.cidade = linha2;
                cout << "Cidade: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.cep = linha2;
                cout << "Cep: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.bairro = linha2;
                cout << "Bairro: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.rua = linha2;
                cout << "Rua: " << linha2 << endl;
                getline(arquivo, linha2);
                ende.numero = stoi(linha2);
                cout << "Número: " << linha2 << endl;
                gerente.setEnderecoPessoal(ende);

                cout << "***** Data de nascimento do gerente *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                nascimento.ano = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.mes = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.dia = stoi(linha2);
                cout << nascimento.dia << "/" << nascimento.mes << "/" << nascimento.ano << endl;
                gerente.setDataNascimento(nascimento);

                cout << "***** Dados funcionais*****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                gerente.setMatricula(linha2);
                cout << "Matricula: " << linha2 << endl;
                getline(arquivo, linha2);
                gerente.setSalario(stod(linha2));
                cout << "Salario: " << linha2 << endl;
                getline(arquivo, linha2);
                gerente.setParticipacaoLucros(stod(linha2));
                cout << "Participação nos lucros: " << linha2 << endl;
                getline(arquivo, linha2);
                gerente.setDiasFalta(stoi(linha2));
                cout << "Dias de falta: " << linha2 << endl;

                cout << "***** Data de ingresso *****" << endl;
                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ingresso.ano = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.mes = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.dia = stoi(linha2);
                cout << ingresso.dia << "/" << ingresso.mes << "/" << ingresso.ano << endl;
                gerente.setIngressoEmpresa(ingresso);

                gerentes.push_back(gerente);
                cout << "Gerente cadastrado com sucesso." << endl;
                atualizarArquivoGerente();
            }
        }

        arquivo.close();
    }
    catch (exception &e)
    {
        cout << "Erro: " << e.what() << endl;
        cout << "********* Não foi possível contratar o funcionário *********" << endl;
        cout << endl;
    }
}