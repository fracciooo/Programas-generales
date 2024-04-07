#include <windows.h>

int WINAPI WinMain(HINSTANCE hinstanciaActual, HINSTANCE hinstanciaPrevia
, LPSTR lpCmdLinea, int nCmdShow)
{
	MessageBox(NULL, "Hola putica", "Mensaje Emergente", MB_OKCANCEL|MB_ICONQUESTION);

	return 0;
}
