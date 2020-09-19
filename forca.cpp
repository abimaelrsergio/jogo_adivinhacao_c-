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
    chutou[chute] = true;

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
    int quantidade_palavras;
    arquivo >> quantidade_palavras;
    vector<string> palavras_do_arquivo;
    for (int i = 0; i < quantidade_palavras; i++)
    {
        string palavra_lida;
        arquivo >> palavra_lida;
        palavras_do_arquivo.push_back(palavra_lida);
    }
    return palavras_do_arquivo;
}

void sortear_palavra()
{
    vector<string> palavras = ler_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}
