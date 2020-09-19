#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute);
bool nao_acertou();
bool nao_enforcou();
void imprimir_cabecalho();
void imprimir_erros();
void imprimir_palavra();
void chutar();
vector<string> ler_arquivo();
void sortear_palavra();
void adicionar_palavra();
void salvar_arquivo(vector<string> lista_palavras);

int main(int argc, char const *argv[])
{
    imprimir_cabecalho();

    sortear_palavra();

    while (nao_acertou() && nao_enforcou())
    {
        imprimir_erros();

        imprimir_palavra();

        chutar();
    }
    cout << "FIM DO JOGO!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if (nao_acertou())
    {
        cout << "PERDEU!! \n Tente novamente!" << endl;
    }
    else
    {
        cout << "PARABÉNS !!! \n Você acertou a palavra secreta." << endl;
        cout << "Você deseja adicionar uma nova palavra no banco de palavras? (S/N) ";
        char resposta;
        cin >> resposta;
        if (resposta == 'S' || resposta == 's')
        {
            adicionar_palavra();
        }
    }

    return 0;
}

bool letra_existe(char chute)
{
    // For melorado do C++11
    // compilar com: g++ forca.cpp -o forca.out -std=c++11
    for (char letra : palavra_secreta)
    {
        if (chute == letra)
        {
            return true;
        }
    }
    return false;
}

bool nao_acertou()
{
    for (char letra : palavra_secreta)
    {
        if (!chutou[letra])
        {
            return true;
        }
    }
    return false;
}

bool nao_enforcou()
{
    return chutes_errados.size() < 5;
}

void imprimir_cabecalho()
{
    cout << "*********************" << endl;
    cout << "*** JOGO DA FORCA ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void imprimir_erros()
{
    cout << "Chutes errados: ";
    for (char letra : chutes_errados)
    {
        cout << letra << " ";
    }
    cout << endl;
}

void imprimir_palavra()
{
    for (char letra : palavra_secreta)
    {
        if (chutou[letra])
        {
            cout << letra << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

void chutar()
{
    cout << "Seu chute: ";
    char chute;
    cin >> chute;
    chutou[toupper(chute)] = true;

    cout << "O seu chute foi: " << chute << endl;

    if (!letra_existe(chute))
    {
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

vector<string> ler_arquivo()
{
    ifstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;
        vector<string> palavras_do_arquivo;
        for (int i = 0; i < quantidade_palavras; i++)
        {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_do_arquivo;
    }
    else
    {
        cout << "Nao foi possível acessar o banco de palavras." << endl;
        exit(0);
    }
}

void sortear_palavra()
{
    vector<string> palavras = ler_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

void adicionar_palavra()
{
    cout << "Digite a nova palavra, usando letras maiúsculas: ";
    string nova_palavra;
    cin >> nova_palavra;
    vector<string> lista_palavras = ler_arquivo();
    lista_palavras.push_back(nova_palavra);
    salvar_arquivo(lista_palavras);
}

void salvar_arquivo(vector<string> lista_palavras)
{
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        arquivo << lista_palavras.size() << endl;
        for (string palavra : lista_palavras)
        {
            arquivo << palavra << endl;
        }
        arquivo.close();
    }
    else
    {
        cout << "Não fo possível acessar o banco de palavras." << endl;
        exit(0);
    }
}
