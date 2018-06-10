/*
 * GUITest.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: Jasper
 */

#include <gtk/gtk.h>
#include "WindowManager.cpp"

using namespace std;

int main(int argc, char *argv[]) {

	gtk_init (&argc, &argv);

	g_print("args passed to gtk_init\n");

	Window::set_icon("icon.png");

	WindowManager::loadxml("window_data.xml");
	WindowManager::go_to_window("welcome_screen");

	gtk_main();

	return 0;

}

