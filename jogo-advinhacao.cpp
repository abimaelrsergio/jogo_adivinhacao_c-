#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "*****************************************" << endl;
    cout << "* Seja Bem vindo ao jogo da adivinhação *" << endl;
    cout << "*****************************************" << endl;

    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D): ";
    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;
    if (dificuldade == 'F')
    {
        numero_de_tentativas = 15;
    }
    else if (dificuldade == 'M')
    {
        numero_de_tentativas = 10;
    }
    else
    {
        numero_de_tentativas = 5;
    }

    const int NUMERO_SECRETO = 42;
    double pontos = 1000.0;

    bool nao_acertou = true;
    int tentativas = 0;

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++)
    {
        int chute;
        cout << "Tentativas " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos -= pontos_perdidos;

        cout << "O valor do seu chute é: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabéns, você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
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
    if (nao_acertou)
    {
        cout << "Você perdeu o jogo! Tente novamente." << endl;
    }
    else
    {
        cout << "Você acertou o numero secreto em " << tentativas << " tentativas." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Você ganhou " << pontos << " pontos" << endl;
        cout << "Fim do jogo!" << endl;
    }

    return 0;
}