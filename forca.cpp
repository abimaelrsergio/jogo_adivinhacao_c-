#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute);
bool nao_acertou();
bool nao_enforcou();
void imprimir_cabecalho();
void imprimir_erros();
void imprimir_palavra();
void chutar();

int main(int argc, char const *argv[])
{
    imprimir_cabecalho();

    while (nao_acertou() && nao_enforcou())
    {
        imprimir_erros();

        imprimir_palavra();

        chutar();
    }
    cout << "FIM DO JOGO!" << endl;
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;
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
    for (char letra : PALAVRA_SECRETA)
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
    for (char letra : PALAVRA_SECRETA)
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
    for (char letra : PALAVRA_SECRETA)
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
