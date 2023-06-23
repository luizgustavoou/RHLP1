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

        string linha;
        getline(arquivo, linha);
        getline(arquivo, linha);

        getline(arquivo, linha);
        nomeEmpresa = linha;

        getline(arquivo, linha);
        cnpj = linha;

        getline(arquivo, linha);
        faturamentoMensal = stof(linha);

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

        for (int ii = 3; ii < vetor.size(); ii += 21)
        {

            Asg asg1;

            asg1.setNome(vetor[ii]);
            asg1.setCpf(vetor[ii + 1]);
            asg1.setQtdFilhos(stoi(vetor[ii + 2]));
            asg1.setEstadoCivil(vetor[ii + 3]);

            ii++;
            Endereco enderecoAsg;
            enderecoAsg.cidade = vetor[ii + 4];
            enderecoAsg.cep = vetor[ii + 5];
            enderecoAsg.bairro = vetor[ii + 6];
            enderecoAsg.rua = vetor[ii + 7];
            enderecoAsg.numero = stoi(vetor[ii + 8]);
            asg1.setEnderecoPessoal(enderecoAsg);

            ii++;
            Data dataNascimentoAsg;
            dataNascimentoAsg.ano = stoi(vetor[ii + 9]);
            dataNascimentoAsg.mes = stoi(vetor[ii + 10]);
            dataNascimentoAsg.dia = stoi(vetor[ii + 11]);
            asg1.setDataNascimento(dataNascimentoAsg);

            ii++;
            asg1.setMatricula(vetor[ii + 12]);
            asg1.setSalario(stof(vetor[ii + 13]));
            asg1.setAdicionalInsalubridade(stof(vetor[ii + 14]));
            ii++;

            Data dataIngressoAsg;
            dataIngressoAsg.ano = stoi(vetor[ii + 15]);
            dataIngressoAsg.mes = stoi(vetor[ii + 16]);
            dataIngressoAsg.dia = stoi(vetor[ii + 17]);
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

        for (int ii = 3; ii < vetor.size(); ii += 21)
        {

            Vendedor vendedor1;

            vendedor1.setNome(vetor[ii]);
            vendedor1.setCpf(vetor[ii + 1]);
            vendedor1.setQtdFilhos(stoi(vetor[ii + 2]));
            vendedor1.setEstadoCivil(vetor[ii + 3]);

            ii++;
            Endereco enderecoAsg;
            enderecoAsg.cidade = vetor[ii + 4];
            enderecoAsg.cep = vetor[ii + 5];
            enderecoAsg.bairro = vetor[ii + 6];
            enderecoAsg.rua = vetor[ii + 7];
            enderecoAsg.numero = stoi(vetor[ii + 8]);
            vendedor1.setEnderecoPessoal(enderecoAsg);

            ii++;
            Data dataNascimentoAsg;
            dataNascimentoAsg.ano = stoi(vetor[ii + 9]);
            dataNascimentoAsg.mes = stoi(vetor[ii + 10]);
            dataNascimentoAsg.dia = stoi(vetor[ii + 11]);
            vendedor1.setDataNascimento(dataNascimentoAsg);

            ii++;
            vendedor1.setMatricula(vetor[ii + 12]);
            vendedor1.setSalario(stof(vetor[ii + 13]));
            vendedor1.setTipoVendedor(vetor[ii + 14][0]);
            ii++;

            Data dataIngressoAsg;
            dataIngressoAsg.ano = stoi(vetor[ii + 15]);
            dataIngressoAsg.mes = stoi(vetor[ii + 16]);
            dataIngressoAsg.dia = stoi(vetor[ii + 17]);
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

        for (int ii = 3; ii < vetor.size(); ii += 21)
        {

            Gerente gerente1;

            gerente1.setNome(vetor[ii]);
            gerente1.setCpf(vetor[ii + 1]);
            gerente1.setQtdFilhos(stoi(vetor[ii + 2]));
            gerente1.setEstadoCivil(vetor[ii + 3]);

            ii++;
            Endereco enderecoAsg;
            enderecoAsg.cidade = vetor[ii + 4];
            enderecoAsg.cep = vetor[ii + 5];
            enderecoAsg.bairro = vetor[ii + 6];
            enderecoAsg.rua = vetor[ii + 7];
            enderecoAsg.numero = stoi(vetor[ii + 8]);
            gerente1.setEnderecoPessoal(enderecoAsg);

            ii++;
            Data dataNascimentoAsg;
            dataNascimentoAsg.ano = stoi(vetor[ii + 9]);
            dataNascimentoAsg.mes = stoi(vetor[ii + 10]);
            dataNascimentoAsg.dia = stoi(vetor[ii + 11]);
            gerente1.setDataNascimento(dataNascimentoAsg);

            ii++;
            gerente1.setMatricula(vetor[ii + 12]);
            gerente1.setSalario(stof(vetor[ii + 13]));
            gerente1.setParticipacaoLucros(stof(vetor[ii + 14]));
            ii++;

            Data dataIngressoAsg;
            dataIngressoAsg.ano = stoi(vetor[ii + 15]);
            dataIngressoAsg.mes = stoi(vetor[ii + 16]);
            dataIngressoAsg.dia = stoi(vetor[ii + 17]);
            gerente1.setIngressoEmpresa(dataIngressoAsg);

            gerentes.push_back(gerente1);
        }

        for (auto ii : this->getGerentes())
        {
            cout << ii.getNome() << endl;
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

            this->_dono.setNome(vetor[ii]);
            this->_dono.setCpf(vetor[ii + 1]);
            this->_dono.setQtdFilhos(stoi(vetor[ii + 2]));
            this->_dono.setEstadoCivil(vetor[ii + 3]);

            Endereco enderecoAsg;
            enderecoAsg.cidade = vetor[ii + 4];
            enderecoAsg.cep = vetor[ii + 5];
            enderecoAsg.bairro = vetor[ii + 6];
            enderecoAsg.rua = vetor[ii + 7];
            enderecoAsg.numero = stoi(vetor[ii + 8]);
            this->_dono.setEnderecoPessoal(enderecoAsg);

            Data dataNascimentoAsg;
            dataNascimentoAsg.ano = stoi(vetor[ii + 9]);
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
            cout << ii.calcularSalario(0) << endl;
            existe = true;
        }
    }

    for (auto ii : this->getVendedores())
    {
        if (ii.getMatricula() == matricula)
        {
            cout << ii.calcularSalario(0) << endl;
            existe = true;
        }
    }

    for (auto ii : this->getGerentes())
    {
        if (ii.getMatricula() == matricula)
        {
            cout << ii.calcularSalario(0) << endl;
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

        string nomeArquivo = "relatorio.txt";
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
        arquivo << "Cargo: ASG" << endl;
        for (auto ii : this->getAsgs())
        {
            totalSalarioAsgs += ii.getSalario();
            arquivo << ii.getMatricula() << " - " << ii.getNome() << " - "
                    << "R$ " << ii.getSalario() << endl;
        }

        arquivo << "Total ASG: " << fixed << setprecision(2) << totalSalarioAsgs << endl
                << endl;

        arquivo << "Cargo: Vendedor" << endl;
        for (auto ii : this->getVendedores())
        {
            totalSalarioVendedores += ii.getSalario();
            arquivo << ii.getMatricula() << " - " << ii.getNome() << " - "
                    << "R$ " << ii.getSalario() << endl;
        }

        arquivo << "Total Vendedor: " << fixed << setprecision(2) << totalSalarioVendedores << endl
                << endl;

        arquivo << "Cargo: Gerente" << endl;
        for (auto ii : this->getGerentes())
        {
            totalSalarioGerentes += ii.getSalario();
            arquivo << ii.getMatricula() << " - " << ii.getNome() << " - "
                    << "R$ " << ii.getSalario() << endl;
        }

        arquivo << "Total Gerente: " << fixed << setprecision(2) << totalSalarioGerentes << endl
                << endl;

        totalSalarios = totalSalarioAsgs + totalSalarioVendedores + totalSalarioGerentes;

        arquivo << "CUSTO TOTAL DE RH: R$ " << fixed << setprecision(2) << totalSalarios << endl;
        arquivo << endl;

        lucro = (getFaturamentoMensal() - totalSalarios);
        arquivo << "FATURAMENTO MENSAL: " << getFaturamentoMensal() << endl;
        arquivo << endl;

        custoAsg = totalSalarioAsgs/totalSalarios;
        custoVendedor = totalSalarioVendedores/totalSalarios;
        custoGerente = totalSalarioGerentes/totalSalarios;
        
        arquivo << "Custo ASG(%): " << custoAsg*100 << endl;
        arquivo << "Custo Vendedor(%): " << custoVendedor*100 << endl;
        arquivo << "Custo Gerente(%): " << custoGerente*100 << endl;
        arquivo << endl;

        arquivo << "LUCRO DA EMPRESA: " << lucro << endl;
        arquivo << endl;

        if(lucro > 0) arquivo << "SITUAÇÃO: Lucro" << endl;

        else if(lucro <= 0) arquivo << "SITUAÇÃO: Prejuizo" << endl;

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

            arquivo << ii.getNome() << endl;
            arquivo << ii.getCpf() << endl;
            arquivo << ii.getQtdFilhos() << endl;
            arquivo << ii.getEstadoCivil() << endl;

            arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;

            arquivo << ii.getEnderecoPessoal().cidade << endl;
            arquivo << ii.getEnderecoPessoal().cep << endl;
            arquivo << ii.getEnderecoPessoal().bairro << endl;
            arquivo << ii.getEnderecoPessoal().rua << endl;
            arquivo << ii.getEnderecoPessoal().numero << endl;

            arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;

            arquivo << ii.getDataNascimento().ano << endl;
            arquivo << ii.getDataNascimento().mes << endl;
            arquivo << ii.getDataNascimento().dia << endl;

            arquivo << "##### DADOS FUNCIONAIS #####" << endl;
            arquivo << ii.getMatricula() << endl;
            arquivo << ii.getSalario() << endl;
            arquivo << ii.getAdicionalInsalubridade() << endl;

            arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;

            arquivo << ii.getIngressoEmpresa().ano << endl;
            arquivo << ii.getIngressoEmpresa().mes << endl;
            arquivo << ii.getIngressoEmpresa().dia << endl;

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

            arquivo << ii.getNome() << endl;
            arquivo << ii.getCpf() << endl;
            arquivo << ii.getQtdFilhos() << endl;
            arquivo << ii.getEstadoCivil() << endl;

            arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;

            arquivo << ii.getEnderecoPessoal().cidade << endl;
            arquivo << ii.getEnderecoPessoal().cep << endl;
            arquivo << ii.getEnderecoPessoal().bairro << endl;
            arquivo << ii.getEnderecoPessoal().rua << endl;
            arquivo << ii.getEnderecoPessoal().numero << endl;

            arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;

            arquivo << ii.getDataNascimento().ano << endl;
            arquivo << ii.getDataNascimento().mes << endl;
            arquivo << ii.getDataNascimento().dia << endl;

            arquivo << "##### DADOS FUNCIONAIS #####" << endl;
            arquivo << ii.getMatricula() << endl;
            arquivo << ii.getSalario() << endl;
            arquivo << ii.getTipoVendedor() << endl;

            arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;

            arquivo << ii.getIngressoEmpresa().ano << endl;
            arquivo << ii.getIngressoEmpresa().mes << endl;
            arquivo << ii.getIngressoEmpresa().dia << endl;

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

            arquivo << ii.getNome() << endl;
            arquivo << ii.getCpf() << endl;
            arquivo << ii.getQtdFilhos() << endl;
            arquivo << ii.getEstadoCivil() << endl;

            arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;

            arquivo << ii.getEnderecoPessoal().cidade << endl;
            arquivo << ii.getEnderecoPessoal().cep << endl;
            arquivo << ii.getEnderecoPessoal().bairro << endl;
            arquivo << ii.getEnderecoPessoal().rua << endl;
            arquivo << ii.getEnderecoPessoal().numero << endl;

            arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;

            arquivo << ii.getDataNascimento().ano << endl;
            arquivo << ii.getDataNascimento().mes << endl;
            arquivo << ii.getDataNascimento().dia << endl;

            arquivo << "##### DADOS FUNCIONAIS #####" << endl;
            arquivo << ii.getMatricula() << endl;
            arquivo << ii.getSalario() << endl;
            arquivo << ii.getParticipacaoLucros() << endl;

            arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;

            arquivo << ii.getIngressoEmpresa().ano << endl;
            arquivo << ii.getIngressoEmpresa().mes << endl;
            arquivo << ii.getIngressoEmpresa().dia << endl;

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

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                asg.setNome(linha2);
                getline(arquivo, linha2);
                asg.setCpf(linha2);
                getline(arquivo, linha2);
                asg.setQtdFilhos(stoi(linha2));
                getline(arquivo, linha2);
                asg.setEstadoCivil(linha2);

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ende.cidade = linha2;
                getline(arquivo, linha2);
                ende.cep = linha2;
                getline(arquivo, linha2);
                ende.bairro = linha2;
                getline(arquivo, linha2);
                ende.rua = linha2;
                getline(arquivo, linha2);
                ende.numero = stoi(linha2);
                asg.setEnderecoPessoal(ende);

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                nascimento.ano = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.mes = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.dia = stoi(linha2);
                asg.setDataNascimento(nascimento);

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                asg.setMatricula(linha2);
                getline(arquivo, linha2);
                asg.setSalario(stod(linha2));
                getline(arquivo, linha2);
                asg.setAdicionalInsalubridade(stod(linha2));
                // getline(arquivo, linha2);
                // Dias de faltas
                // asg.set

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ingresso.ano = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.mes = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.dia = stoi(linha2);
                asg.setIngressoEmpresa(ingresso);

                asgs.push_back(asg);
                cout << "Asg cadastrada com sucesso." << endl;

                atualizarArquivoAsg();
            }
            else if (linha1 == "Vendedor" || linha1 == "VENDEDOR")
            {
                Vendedor vendedor;

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                vendedor.setNome(linha2);
                getline(arquivo, linha2);
                vendedor.setCpf(linha2);
                getline(arquivo, linha2);
                vendedor.setQtdFilhos(stoi(linha2));
                getline(arquivo, linha2);
                vendedor.setEstadoCivil(linha2);

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ende.cidade = linha2;
                getline(arquivo, linha2);
                ende.cep = linha2;
                getline(arquivo, linha2);
                ende.bairro = linha2;
                getline(arquivo, linha2);
                ende.rua = linha2;
                getline(arquivo, linha2);
                ende.numero = stoi(linha2);
                vendedor.setEnderecoPessoal(ende);

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                nascimento.ano = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.mes = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.dia = stoi(linha2);
                vendedor.setDataNascimento(nascimento);

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                vendedor.setMatricula(linha2);
                getline(arquivo, linha2);
                vendedor.setSalario(stod(linha2));
                getline(arquivo, linha2);
                vendedor.setTipoVendedor(linha2[0]);
                // getline(arquivo, linha2);
                // Dias de faltas
                // vendedor.set

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ingresso.ano = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.mes = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.dia = stoi(linha2);
                vendedor.setIngressoEmpresa(ingresso);

                vendedores.push_back(vendedor);
                cout << "Vendedor cadastrado com sucesso." << endl;
                atualizarArquivoVendedor();
            }
            else if (linha1 == "Gerente" || linha1 == "GERENTE")
            {
                Gerente gerente;

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                gerente.setNome(linha2);
                getline(arquivo, linha2);
                gerente.setCpf(linha2);
                getline(arquivo, linha2);
                gerente.setQtdFilhos(stoi(linha2));
                getline(arquivo, linha2);
                gerente.setEstadoCivil(linha2);

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ende.cidade = linha2;
                getline(arquivo, linha2);
                ende.cep = linha2;
                getline(arquivo, linha2);
                ende.bairro = linha2;
                getline(arquivo, linha2);
                ende.rua = linha2;
                getline(arquivo, linha2);
                ende.numero = stoi(linha2);
                gerente.setEnderecoPessoal(ende);

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                nascimento.ano = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.mes = stoi(linha2);
                getline(arquivo, linha2);
                nascimento.dia = stoi(linha2);
                gerente.setDataNascimento(nascimento);

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                gerente.setMatricula(linha2);
                getline(arquivo, linha2);
                gerente.setSalario(stod(linha2));
                getline(arquivo, linha2);
                gerente.setParticipacaoLucros(stod(linha2));
                // getline(arquivo, linha2);
                // Dias de faltas
                // gerente.set

                getline(arquivo, linha2);
                getline(arquivo, linha2);
                ingresso.ano = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.mes = stoi(linha2);
                getline(arquivo, linha2);
                ingresso.dia = stoi(linha2);
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