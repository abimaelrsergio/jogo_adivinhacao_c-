#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "*****************************************" << endl;
    cout << "* Seja Bem vindo ao jogo da adivinhação *" << endl;
    cout << "*****************************************" << endl;

    int numero_secreto = 42;

    int chute;
    cout << "Qual seu chute? ";
    cin >> chute;
    cout << "O valor do seu chute é: " << chute << endl;

    if (chute == numero_secreto)
    {
        cout << "Parabéns, você acertou o número secreto!" << endl;
    }

    return 0;
}