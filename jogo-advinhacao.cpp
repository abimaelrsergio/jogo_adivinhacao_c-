#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "*****************************************" << endl;
    cout << "* Seja Bem vindo ao jogo da adivinhação *" << endl;
    cout << "*****************************************" << endl;

    const int NUMERO_SECRETO = 42;

    bool nao_acertou = true;
    int tentativas = 0;

    while (nao_acertou)
    {
        tentativas++;
        int chute;
        cout << "Tentativas " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        cout << "O valor do seu chute é: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabéns, você acertou o número secreto!" << endl;
            nao_acertou = false;
        }
        else if (maior)
        {
            cout << "O chute foi maior que o número secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o número secreto!" << endl;
        }
        cout << "-----------------------------------------" << endl;
    }
    cout << "Você acertou o numero secreto em " << tentativas << " tentativas." << endl;
    cout << "Fim do jogo!" << endl;

    return 0;
}