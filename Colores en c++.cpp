#include <iostream>

using namespace std;

int main() 
{
    cout<<"Colores disponibles:\n";

    // Colores de text / texto / titulos / etc
    cout<<"\033[0;30mNegro\033[0m\n";
    cout<<"\033[0;31mRojo\033[0m\n";
    cout<<"\033[0;32mVerde\033[0m\n";
    cout<<"\033[0;33mAmarillo\033[0m\n";
    cout<<"\033[0;34mAzul\033[0m\n";
    cout<<"\033[0;35mMagenta\033[0m\n";
    cout<<"\033[0;36mCian\033[0m\n";
    cout<<"\033[0;37mBlanco\033[0m\n";
    cout<<"\x1B[38;2;255;128;0mNaranja\x1b[0m\n";
    cout<<"\033[1;36mCeleste\x1b[0m\n";
    cout<<"\x1b[35mMorado\x1b[0m\n";
    cout<<"\x1b[36mTurquesa\x1b[0m\n";
    cout<<"\033[1;35mMagenta Claro\x1b[0m\n";
	cout<<"\033[1;31mRojo Claro\x1b[0m\n";
	cout<<"\033[1;32mVerde Claro\x1b[0m\n";
	cout<<"\033[0;34mAzul Claro\x1b[0m\n";
	cout<<"\x1B[38;2;176;174;174mGris\x1b[0m\n";

    cout<<"\n";

    // Colores de background / fondo
    cout<<"\033[0;40mNegro\033[0m\n";
    cout<<"\033[0;41mRojo\033[0m\n";
    cout<<"\033[0;42mVerde\033[0m\n";
    cout<<"\033[0;43mAmarillo\033[0m\n";
    cout<<"\033[0;44mAzul\033[0m\n";
    cout<<"\033[0;45mMagenta\033[0m\n";
    cout<<"\033[0;46mCian\033[0m\n";
    cout<<"\033[0;47mBlanco\033[0m\n";

}
