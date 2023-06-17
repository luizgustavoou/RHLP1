#include <iostream>
#include <fstream>
#include <stdexcept>
#include "empresa.hpp"
using namespace std;


//Construtores
Empresa::Empresa(){
}
Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal, Data hoje){
  this->setNomeEmpresa(nomeEmpresa);
  this->setCnpj(cnpj);
  this->setFaturamentoMensal(faturamentoMensal);
}


//Gets e sets de empresa
float Empresa::getFaturamentoMensal(){
  return this->faturamentoMensal;
}
void Empresa::setFaturamentoMensal(float faturamentoMensal){
  this->faturamentoMensal = faturamentoMensal;
}

std::string Empresa::getNomeEmpresa(){
  return this->nomeEmpresa;
}
void Empresa::setNomeEmpresa(std::string nomeEmpresa){
  this->nomeEmpresa = nomeEmpresa;
}

std::string Empresa::getCnpj(){
  return this->cnpj;
}
void Empresa::setCnpj(std::string cnpj){
  this->cnpj = cnpj;
}

Pessoa Empresa::getDono(){
  return this->dono;
}

vector<Asg> Empresa::getAsgs(){
  return this->asgs;
}

vector<Vendedor> Empresa::getVendedores(){
  return this->vendedores;
}

vector<Gerente> Empresa::getGerentes(){
  return this->gerentes;
}


//######## Outras funções ########
void Empresa::carregarFuncoes(){ //Ler o arquivo de funções e as executa

  try{ //Tenta ler o arquivo
    ifstream arquivo;
    arquivo.open("funcoes.txt");
    if(!arquivo.is_open()) throw "O arquivo funcoes.txt não foi lido";
    string linha1, linha2, linha3, linha4, linha5;
    Data data;
    
    while(getline(arquivo, linha1)){ //Função carregar empresa
      if(linha1 == "carregarempresa()"){
        cout << "##### Carregar Empresa #####" << endl;
        cout << endl;
        this->carregarEmpresa();
        cout << endl;
      }
      else if(linha1 == "carregarAsg()"){ //Função carregar Asg
        cout << "##### Carregar Asg #####" << endl;
        cout << endl;
        this->carregarAsg();
        cout << endl;
      }
      else if(linha1 == "carregarVendedor()"){ //Função carregar vendedor
        cout << "##### Carregar Vendedor #####" << endl;
        cout << endl;
        this->carregarVendedor();
        cout << endl;
      }
      else if(linha1 == "carregarGerente()"){ //Função carregar gerente
        cout << "##### Carregar Gerente #####" << endl;
        cout << endl;
        this->carregarGerente();
        cout << endl;
      }
      else if(linha1 == "carregaDono()"){ //Função carregar dono
        cout << "##### Carregar Dono #####" << endl;
        cout << endl;
        this->carregaDono();
        cout << endl;
      }
      else if(linha1 == "imprimeAsgs()"){ //Função imprimir ASGs
        cout << "##### Imprime Asgs #####" << endl;
        cout << endl;
        this->imprimeAsgs();
        cout << endl;
      }
      else if(linha1 == "imprimeVendedores()"){ //Função imprimmir vendedores
        cout << "##### Imprime vendedores #####" << endl;
        cout << endl;
        this->imprimeVendedores();
        cout << endl;
      }
      else if(linha1 == "imprimeGerentes()"){ //Função imprimir gerentes
        cout << "##### Imprime gerentes #####" << endl;
        cout << endl;
        this->imprimeGerentes();
        cout << endl;
      }
      else if(linha1 == "imprimeDono()"){ //Função imprimir dono
        cout << "##### Imprime dono #####" << endl;
        cout << endl;
        this->imprimeDono();
        cout << endl;
      }
      else if(linha1 == "buscaFuncionario()"){ //Função buscar funcionario
        cout << "##### Busca funcionario #####" << endl;
        cout << endl;
        getline(arquivo, linha2); //Pega a proxima linha como argumento
        this->buscaFuncionario(linha2);
        cout << endl;
      }
      else if(linha1 == "calculaSalarioFuncionario()"){ //Função calcular salario do funcionario
        cout << "##### Calcular salario do funcionario #####" << endl;
        cout << endl;
        getline(arquivo, linha2);//Pega a proxima linha como argumento
        this->calculaSalarioFuncionario(linha2);
        cout << endl;
      }
      else if(linha1 == "calculaTodoOsSalarios()"){ //Função calcular todos os salarios
        cout << "##### Calcular todos os salarios #####" << endl;
        cout << endl;
        this->calculaTodoOsSalarios();
        cout << endl;
      }
      else if(linha1 == "calcularRecisao()"){ //Função calcular recisão
        //Pega os argumentos da função
        cout << "##### Calcular recisão #####" << endl;
        cout << endl;
        getline(arquivo, linha2);
        getline(arquivo, linha3);
        getline(arquivo, linha4);
        getline(arquivo, linha5);

        //Armazena valores de data
        data.ano = stoi(linha3);
        data.mes = stoi(linha4);
        data.dia = stoi(linha5);
        
        calcularRecisao(linha2, data);
      }
    }
    arquivo.close();
  }
  catch(const char *error) {
    cout << "Erro: " << error << endl;
  }
  catch(exception &e) {
    cout << "Erro: " << e.what() << endl;
  }
}
  
void Empresa::carregarEmpresa(){ //Carregar empresa
  try{
    ifstream arquivo;
    string linha1, linha2, linha3;
    arquivo.open("empresa.txt");
    if(!arquivo.is_open()) throw "O arquivo empresa.txt não foi lido";
    
    while(getline(arquivo, linha1)){
      if(linha1[0] != '#'){ //Ler a partir da primeira linha de conteudo
        getline(arquivo, linha2);
        getline(arquivo, linha3);
        this->setNomeEmpresa(linha1);
        this->setCnpj(linha2);
        this->setFaturamentoMensal(stod(linha3));
      }
    }
    arquivo.close();
  }
  catch(const char *error){
    cout << "Erro: " << error << endl;
  }
  catch(exception &e){
    cout << "Erro: " << e.what() << endl;
  }
}

void Empresa::carregarAsg(){ //Carregar asgs
  try{
    ifstream arquivo;
    Asg asgs;
    Endereco endereco;
    Data dataNascimento, ingressoEmpresa;

    //Linhas para receberem as linhas do arquivo
    string linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8, linha9, linha10, linha11, linha12, linha13, linha14, linha15, linha16, linha17, linha18, linha19, linha20, linha21, linha22, linha23, linha24, linha25;
    arquivo.open("asg.txt");

    if(!arquivo.is_open()){ //VErifica se foi possivel abrir o arquivo
      throw "O arquivo asg.txt não foi lido";
    }

    //Pega as linha e vai armazenando em uma asg
    while(getline(arquivo, linha1), getline(arquivo, linha2), getline(arquivo, linha3), getline(arquivo, linha4), getline(arquivo, linha5), getline(arquivo, linha6), getline(arquivo, linha7), getline(arquivo, linha8), getline(arquivo, linha9), getline(arquivo, linha10), getline(arquivo, linha11), getline(arquivo, linha12), getline(arquivo, linha13), getline(arquivo, linha14), getline(arquivo, linha15), getline(arquivo, linha16), getline(arquivo, linha17), getline(arquivo, linha18), getline(arquivo, linha19), getline(arquivo, linha20), getline(arquivo, linha21), getline(arquivo, linha22), getline(arquivo, linha23), getline(arquivo, linha24), getline(arquivo, linha25)){
      asgs.setNome(linha4);
      asgs.setCpf(linha5);
      asgs.setQtdFilhos(stoi(linha6));
      asgs.setEstadoCivil(linha7);

      //Pega o endereço e coloca em uma variavel para por na ASG
      endereco.cidade = linha9;
      endereco.cep = linha10;
      endereco.bairro = linha11;
      endereco.rua = linha12;
      endereco.numero = stoi(linha13);
      asgs.setEnderecoPessoal(endereco);

      //Pega a data de nascimento e coloca em uma variavel para por na ASG
      dataNascimento.ano = stoi(linha15);
      dataNascimento.mes = stoi(linha16);
      dataNascimento.dia = stoi(linha17);
      asgs.setDataNascimento(dataNascimento);
      
      asgs.setMatricula(linha19);
      asgs.setSalario(stod(linha20));
      asgs.setAdicionalInsalubridade(stod(linha21));

      //Pega a data do ingresso e coloca em uma variavel para por na ASG
      ingressoEmpresa.ano = stoi(linha23);
      ingressoEmpresa.mes = stoi(linha24);
      ingressoEmpresa.dia = stoi(linha25);
      asgs.setIngressoEmpresa(ingressoEmpresa);

      //Coloca a asg no vector asgs
      this->asgs.push_back(asgs);
    }
    arquivo.close();
  }
  catch(exception &e){
    cout << "Erro: " << e.what() << endl;
  } catch(const char *error) {
    cout << "Erro: " << error << endl;
  }
}

void Empresa::carregarVendedor(){ //Carregar vendedores
  
  try{
    ifstream arquivo;
    Vendedor vendedores;
    Endereco endereco;
    Data dataNascimento, ingressoEmpresa;

    //Linhas para receberem as linhas do arquivo
    string linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8, linha9, linha10, linha11, linha12, linha13, linha14, linha15, linha16, linha17, linha18, linha19, linha20, linha21, linha22, linha23, linha24, linha25;
    
    arquivo.open("vendedor.txt");
    if(!arquivo.is_open()){
      throw "O arquivo vendedor.txt não foi lido";
    }

    //Pegar as linhas e armazenar em um vendedor
    while(getline(arquivo, linha1), getline(arquivo, linha2), getline(arquivo, linha3), getline(arquivo, linha4), getline(arquivo, linha5), getline(arquivo, linha6), getline(arquivo, linha7), getline(arquivo, linha8), getline(arquivo, linha9), getline(arquivo, linha10), getline(arquivo, linha11), getline(arquivo, linha12), getline(arquivo, linha13), getline(arquivo, linha14), getline(arquivo, linha15), getline(arquivo, linha16), getline(arquivo, linha17), getline(arquivo, linha18), getline(arquivo, linha19), getline(arquivo, linha20), getline(arquivo, linha21), getline(arquivo, linha22), getline(arquivo, linha23), getline(arquivo, linha24), getline(arquivo, linha25)){
      vendedores.setNome(linha4);
      vendedores.setCpf(linha5);
      vendedores.setQtdFilhos(stoi(linha6));
      vendedores.setEstadoCivil(linha7);

      //Pega o endereço e coloca em uma variavel para por em vendedor
      endereco.cidade = linha9;
      endereco.cep = linha10;
      endereco.bairro = linha11;
      endereco.rua = linha12;
      endereco.numero = stoi(linha13);
      vendedores.setEnderecoPessoal(endereco);

      //Pega a data de nascimento e coloca em uma variavel para por em vendedor
      dataNascimento.ano = stoi(linha15);
      dataNascimento.mes = stoi(linha16);
      dataNascimento.dia = stoi(linha17);
      vendedores.setDataNascimento(dataNascimento);
      
      vendedores.setMatricula(linha19);
      vendedores.setSalario(stod(linha20));
      vendedores.setTipoVendedor(linha21[0]);

      //Pega a data de ingresso e coloca em uma variavel para por em vendedor
      ingressoEmpresa.ano = stoi(linha23);
      ingressoEmpresa.mes = stoi(linha24);
      ingressoEmpresa.dia = stoi(linha25);
      vendedores.setIngressoEmpresa(ingressoEmpresa);

      //Armazena o vendedor no vector vendedores
      this->vendedores.push_back(vendedores);
    }
    arquivo.close();
  }
  catch(exception &e){
    cout << "Erro: " << e.what() << endl;
  }
  catch(const char *error){
    cout << "Erro: " << error << endl;
  }
}

void Empresa::carregarGerente(){ //Carrregar gerente
  
  try{
    ifstream arquivo;
    Gerente gerentes;
    Endereco endereco;
    Data dataNascimento, ingressoEmpresa;

    //Linhas para receberem as linhas do arquivo
    string linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8, linha9, linha10, linha11, linha12, linha13, linha14, linha15, linha16, linha17, linha18, linha19, linha20, linha21, linha22, linha23, linha24, linha25;
    
    arquivo.open("gerente.txt");
    if(!arquivo.is_open()){
      throw "arquivo gerente.txt não foi lido";
    }

    //Pega os argumentos e armazena em um gerente
    while(getline(arquivo, linha1), getline(arquivo, linha2), getline(arquivo, linha3), getline(arquivo, linha4), getline(arquivo, linha5), getline(arquivo, linha6), getline(arquivo, linha7), getline(arquivo, linha8), getline(arquivo, linha9), getline(arquivo, linha10), getline(arquivo, linha11), getline(arquivo, linha12), getline(arquivo, linha13), getline(arquivo, linha14), getline(arquivo, linha15), getline(arquivo, linha16), getline(arquivo, linha17), getline(arquivo, linha18), getline(arquivo, linha19), getline(arquivo, linha20), getline(arquivo, linha21), getline(arquivo, linha22), getline(arquivo, linha23), getline(arquivo, linha24), getline(arquivo, linha25)){
      gerentes.setNome(linha4);
      gerentes.setCpf(linha5);
      gerentes.setQtdFilhos(stoi(linha6));
      gerentes.setEstadoCivil(linha7);

      //Pega o endereço e coloca em uma variavel para por em gerente
      endereco.cidade = linha9;
      endereco.cep = linha10;
      endereco.bairro = linha11;
      endereco.rua = linha12;
      endereco.numero = stoi(linha13);
      gerentes.setEnderecoPessoal(endereco);

      //Pega a data de nascimento e coloca em uma variavel para por em gerente
      dataNascimento.ano = stoi(linha15);
      dataNascimento.mes = stoi(linha16);
      dataNascimento.dia = stoi(linha17);
      gerentes.setDataNascimento(dataNascimento);

      
      gerentes.setMatricula(linha19);
      gerentes.setSalario(stod(linha20));
      gerentes.setParticipacaoLucros(stod(linha21));

      //Pega a data de ingresso e coloca em uma variavel para por em gerente
      ingressoEmpresa.ano = stoi(linha23);
      ingressoEmpresa.mes = stoi(linha24);
      ingressoEmpresa.dia = stoi(linha25);
      gerentes.setIngressoEmpresa(ingressoEmpresa);

      //Armazena o gerente no vector gerentes
      this->gerentes.push_back(gerentes);
    }
    arquivo.close();
  }
  catch(exception &e){
    cout << "Erro: " << e.what() << endl;
  }
  catch(const char *error){
    cout << "Erro: " << error << endl;
  }
}

void Empresa::carregaDono(){ //Carregar dono
  
  try{
    ifstream arquivo;
    Endereco endereco;
    Data dataNascimento;
    
    arquivo.open("dono.txt");
    if(!arquivo.is_open()){
      throw "arquivo dono.txt não foi lido";
    }

    //Linhas para receberem as linhas do arquivo
    string linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8, linha9, linha10, linha11, linha12, linha13, linha14;

    //Pega os valores do arquivo e coloca em dono
    while(getline(arquivo, linha1), getline(arquivo, linha2), getline(arquivo, linha3), getline(arquivo, linha4),getline(arquivo, linha5), getline(arquivo, linha6), getline(arquivo, linha7), getline(arquivo, linha8), getline(arquivo, linha9), getline(arquivo, linha10), getline(arquivo, linha11), getline(arquivo, linha12), getline(arquivo, linha13), getline(arquivo, linha14)){
      this->dono.setNome(linha3);
      this->dono.setCpf(linha4);
      this->dono.setQtdFilhos(stoi(linha5));
      this->dono.setEstadoCivil(linha6);

      //Pega o endereço e coloca em uma variavel para por em dono
      endereco.cidade = linha7;
      endereco.cep = linha8;
      endereco.bairro = linha9;
      endereco.rua = linha10;
      endereco.numero = stoi(linha11);
      this->dono.setEnderecoPessoal(endereco);

      //Pega a data de nascimento e coloca em uma variavel para por em dono
      dataNascimento.ano = stoi(linha12);
      dataNascimento.mes = stoi(linha13);
      dataNascimento.dia = stoi(linha14);
      this->dono.setDataNascimento(dataNascimento);
    }
    arquivo.close();
  }
  catch(exception &e){
    cout << "Erro: " << e.what() << endl;
  }
  catch(const char *error){
    cout << "Erro: " << error << endl;
  }
}

void Empresa::imprimeAsgs (){  //imprime asgs
  for(auto& asg : this->asgs){
    cout << endl;
    cout << "Nome asg: " << asg.getNome() << endl;
    cout << "Cpf asg: " << asg.getCpf() << endl;
    cout << "Data de nascimento: " << asg.getDataNascimento().dia << "/" << asg.getDataNascimento().mes << "/" << asg.getDataNascimento().ano  << endl;
    cout << "Endereço: " << "Cidade " << asg.getEnderecoPessoal().cidade << " Cep: " << asg.getEnderecoPessoal().cep << " Bairro: " << asg.getEnderecoPessoal().bairro << " Rua: " << asg.getEnderecoPessoal().rua << " Número: " << asg.getEnderecoPessoal().numero << endl;
    cout << "Estado civil asg: " << asg.getEstadoCivil() << endl;
    cout << "Quantidade de filhos asg: " << asg.getQtdFilhos() << endl;
    cout << "Adicional inssalubridade asg: " << asg.getAdicionalInsalubridade() << endl;
    cout << "Salario asg: " << asg.getSalario() << endl;
    cout << "Matricula asg: " << asg.getMatricula() << endl;
    cout << "Data de ingresso: " << asg.getIngressoEmpresa().dia << "/" << asg.getIngressoEmpresa().mes << "/" << asg.getIngressoEmpresa().ano  << endl;
  }
  cout << endl;
}

void Empresa::imprimeVendedores(){ //Imprime vendedores
  for(auto& vendedor : this->vendedores){
    cout << endl;
    cout << "Tipo do Vendedor: " << vendedor.getNome() << endl;
    cout << "Nome Vendedor: " << vendedor.getNome() << endl;
    cout << "Cpf Vendedor: " << vendedor.getCpf() << endl;
    cout << "Data de nascimento: " << vendedor.getDataNascimento().dia << "/" << vendedor.getDataNascimento().mes << "/" << vendedor.getDataNascimento().ano  << endl;
    cout << "Endereço: " << "Cidade " << vendedor.getEnderecoPessoal().cidade << " Cep: " << vendedor.getEnderecoPessoal().cep << " Bairro: " << vendedor.getEnderecoPessoal().bairro << " Rua: " << vendedor.getEnderecoPessoal().rua << " Número: " << vendedor.getEnderecoPessoal().numero << endl;
    cout << "Estado civil Vendedor: " << vendedor.getEstadoCivil() << endl;
    cout << "Quantidade de filhos Vendedor: " << vendedor.getQtdFilhos() << endl;
    cout << "Salario Vendedor: " << vendedor.getSalario() << endl;
    cout << "Matricula Vendedor: " << vendedor.getMatricula() << endl;
    cout << "Data de ingresso: " << vendedor.getIngressoEmpresa().dia << "/" << vendedor.getIngressoEmpresa().mes << "/" << vendedor.getIngressoEmpresa().ano  << endl;
  }
  cout << endl;
}

void Empresa::imprimeGerentes(){ //Imprimir Gerentes
  for(auto& gerente : this->gerentes){
    cout << endl;
    cout << "Tipo do Gerente: " << gerente.getNome() << endl;
    cout << "Nome Gerente: " << gerente.getNome() << endl;
    cout << "Cpf Gerente: " << gerente.getCpf() << endl;
    cout << "Data de nascimento: " << gerente.getDataNascimento().dia << "/" << gerente.getDataNascimento().mes << "/" << gerente.getDataNascimento().ano  << endl;
    cout << "Endereço: " << "Cidade " << gerente.getEnderecoPessoal().cidade << " Cep: " << gerente.getEnderecoPessoal().cep << " Bairro: " << gerente.getEnderecoPessoal().bairro << " Rua: " << gerente.getEnderecoPessoal().rua << " Número: " << gerente.getEnderecoPessoal().numero << endl;
    cout << "Estado civil Gerente: " << gerente.getEstadoCivil() << endl;
    cout << "Quantidade de filhos Gerente: " << gerente.getQtdFilhos() << endl;
    cout << "Salario Gerente: " << gerente.getSalario() << endl;
    cout << "Matricula Gerente: " << gerente.getMatricula() << endl;
    cout << "Data de ingresso: " << gerente.getIngressoEmpresa().dia << "/" << gerente.getIngressoEmpresa().mes << "/" << gerente.getIngressoEmpresa().ano  << endl;
  }
  cout << endl;
}

void Empresa::imprimeDono(){ //Imprime o dono
  cout << endl;
  cout << "Nome do dono: " << this->dono.getNome() << endl;
  cout << "Cpf do dono: " << this->dono.getCpf() << endl;
  cout << "Data de nascimento do dono: " << this->dono.getDataNascimento().dia << "/" << this->dono.getDataNascimento().mes << "/" << this->dono.getDataNascimento().ano << endl;
   cout << "Endereço : " << "Cidade " << dono.getEnderecoPessoal().cidade << " Cep: " << dono.getEnderecoPessoal().cep << " Bairro: " << dono.getEnderecoPessoal().bairro << " Rua: " << dono.getEnderecoPessoal().rua << " Número: " << dono.getEnderecoPessoal().numero << endl;
  cout << "Estado civil do Dono: " << dono.getEstadoCivil() << endl;
  cout << "Quantidade de filhos do dono: " << dono.getQtdFilhos() << endl;
}


void Empresa::buscaFuncionario(string matricula){ //Buscar Funcionario
  int achou = 0;
  for (auto& gerente : this->gerentes){ //Busca em gerentes e se encontrar imprime o nome e cargo
    if(gerente.getMatricula() == matricula){
      cout << "Cargo: Gerente" << endl;
      cout << "Nome: " << gerente.getNome() << endl;
      achou = 1;
    }
  }
  if(achou == 0){ //Se não achou busca em vendedores
    for (auto& vendedor : this->vendedores) { //Mesmo caso de busca para vendedores
    if(vendedor.getMatricula() == matricula){
      cout << "Cargo: Vendedor" << endl;
      cout << "Nome: " << vendedor.getNome() << endl;
      achou = 1;
    }
    }
  }
  if(achou == 0){ //Se não achou em vendedores procura em asgs
    for (auto& asg : this->asgs){ //Mesmo caso de busca para asgs
    if(asg.getMatricula() == matricula){
      cout << "Cargo: Asg" << endl;
      cout << "Nome: " << asg.getNome() << endl;
      achou = 1;
    }
    }
  }
  if(achou == 0){ //Se não encontrou ninguem, imprime a mensagem
    cout << "Funcionário não encontrado no sistema" << endl;
  }
}

void Empresa::calculaSalarioFuncionario(string matricula){ //Calcular Funcionario

  int achou = 0;
  for(auto& gerente : this->gerentes){ //Ler o vector gerentes e se a matricula for igual, imprime o salario do gerente
    if(gerente.getMatricula() == matricula){
      cout << "Salario: " << gerente.calcularSalario(0) << endl;
      achou = 1;
    }
  }
  if(achou == 0){ //Se não achou em gerente, busque em vendedores
    for(auto& vendedor : this->vendedores){ //Mesmo caso de busca para vendedores
      if(vendedor.getMatricula() == matricula){
        cout << "Salario: " << vendedor.calcularSalario(0) << endl;
        achou = 1;
      }
    }
  }
  if(achou == 0){ //Se não achou em vendedores, procure em asgs
    for(auto& asg : this->asgs){ //Mesmo caso de busca para asgs
      if(asg.getMatricula() == matricula){
        cout << "Salario: " << asg.calcularSalario(0) << endl;
        achou = 1;
      }
    }
  }
  if(achou == 0){ //Se não encontrou ninguem, imprime a mensagem
    cout << "Funcionário não encontrado no sistema" << endl;
  }
}

void Empresa::calculaTodoOsSalarios(){ //Calcular todos os salarios
  try{
    fstream arquivo;
    float totalSalarioAsgs, totalSalarioVendedores, totalSalarioGerentes, somaSalarios;
    string nomeArquivo = "relatorio.txt";
    arquivo.open("./" + nomeArquivo, ios::out);
    if(!arquivo.is_open()) throw "O arquivo relatorio.txt não foi lido";
    
    totalSalarioAsgs = totalSalarioVendedores = totalSalarioGerentes = somaSalarios = 0;

    //Geração do relatorio
    arquivo << "######### Relatório Financeiro #########" << endl;
    arquivo << endl;
    arquivo << "Cargo: ASG" << endl;

    cout << "######### Relatório Financeiro #########" << endl;
    cout << endl;
    cout << "Cargo: ASG" << endl;

    for(auto asg : this->asgs) { //Pega o total do salario das asgs
      totalSalarioAsgs += asg.getSalario();
      arquivo << asg.getMatricula() << " - " << asg.getNome() << " - " << "R$ " << asg.getSalario() << endl;
      cout << asg.getMatricula() << " - " << asg.getNome() << " - " << "R$ " << asg.getSalario() << endl;
    }

    arquivo << "Total ASG: " << totalSalarioAsgs << endl;
    arquivo << endl;

    cout << "Total ASG: " << totalSalarioAsgs << endl;
    cout << endl;
    
    arquivo << "Cargo: Vendedor" << endl;
    cout << "Cargo: Vendedor" << endl;

    
    for(auto vendedor : this->vendedores){ //Pega o total do salario dos vendedores
      totalSalarioVendedores += vendedor.getSalario();
      arquivo << vendedor.getMatricula() << " - " << vendedor.getNome() << " - " << "R$ " << vendedor.getSalario() << endl;
      cout << vendedor.getMatricula() << " - " << vendedor.getNome() << " - " << "R$ " << vendedor.getSalario() << endl;
    }

    arquivo << "Total Vendedor: " << totalSalarioVendedores << endl;
    arquivo << endl;

    cout << "Total Vendedor: " << totalSalarioVendedores << endl;
    cout << endl;
    
    arquivo << "Cargo: Gerente" << endl;
    cout << "Cargo: Gerente" << endl;
    for(auto gerente : this->gerentes){ ///Pega o total do salario dos gerentes
      totalSalarioGerentes += gerente.getSalario();
      arquivo << gerente.getMatricula() << " - " << gerente.getNome() << " - " << "R$ " << gerente.getSalario() << endl;
      cout << gerente.getMatricula() << " - " << gerente.getNome() << " - " << "R$ " << gerente.getSalario() << endl;
    }

    arquivo << "Total Gerente: " << totalSalarioGerentes << endl;
    arquivo << endl;

    cout << "Total Gerente: " << totalSalarioGerentes << endl;
    cout << endl;

    somaSalarios = totalSalarioAsgs + totalSalarioVendedores + totalSalarioGerentes;

    arquivo << "CUSTO TOTAL DE RH: R$ " << somaSalarios << endl;
    cout << "CUSTO TOTAL DE RH: R$ " << somaSalarios << endl;
    cout << endl;

    arquivo.close();
  }
  catch (const char *error){
    cout << "Erro: " << error << endl;
  }
  catch (exception &e){
    cout << "Erro: " << e.what() << endl;  
  }
}

void Empresa::calcularRecisao(string matricula, Data desligamento){ //Calcular recisão
  int achou = 0;
  int anosTrabalhados;
  
  for(auto& gerente : this->gerentes){ //Busca se o funcionario informado é um gerente
    if(gerente.getMatricula() == matricula){
      cout << "Cargo: Gerente" << endl;
      cout << "Nome: " << gerente.getNome() << endl;
      anosTrabalhados = (desligamento.ano - gerente.getIngressoEmpresa().ano) + (desligamento.mes - gerente.getIngressoEmpresa().mes)/12 + (desligamento.dia - gerente.getIngressoEmpresa().dia)/30;
      cout << "A recisão foi: " << gerente.getSalario()*anosTrabalhados << endl;
    }
  }
  if(achou == 0){ //Se não achou em gerentes, busque em vendedores
    for(auto& vendedor : this->vendedores){ //Busca se o funcionario informado é um vendedor
    if(vendedor.getMatricula() == matricula){
      cout << "Cargo: Vendedor" << endl;
      cout << "Nome: " << vendedor.getNome() << endl;
      achou = 1;
      anosTrabalhados = (desligamento.ano - vendedor.getIngressoEmpresa().ano) + (desligamento.mes - vendedor.getIngressoEmpresa().mes)/12 + (desligamento.dia - vendedor.getIngressoEmpresa().dia)/30;
      cout << "A recisão foi: " << vendedor.getSalario()*anosTrabalhados << endl;
    }
    }
  }
  if(achou == 0){ //Se não achou em vendedores, busque em asgs
    for (auto& asg : this->asgs) { //Busca se o funcionario informado é um asg
      if(asg.getMatricula() == matricula){
        cout << "Cargo: Asg" << endl;
        cout << "Nome: " << asg.getNome() << endl;
        achou = 1;
        anosTrabalhados = (desligamento.ano - asg.getIngressoEmpresa().ano) + (desligamento.mes - asg.getIngressoEmpresa().mes)/12 + (desligamento.dia - asg.getIngressoEmpresa().dia)/30;
        cout << "A recisão foi: " << asg.getSalario()*anosTrabalhados << endl;
      }
    }
  }
  if(achou == 0){ //Se não encontrou ninguem, imprima a mensagem
    cout << "Funcionário não encontrado no sistema" << endl;
  }
}