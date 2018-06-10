/*
 * WindowManager.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: Jasper
 */

#include "WindowManager.h"
#include "Window.cpp"
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <iostream>
#include <cstddef> //for NULL

using namespace std;

//static variables
map<string, string> WindowManager::windows;
Window* WindowManager::current_window;
string WindowManager::current_window_id;

WindowManager::WindowManager() {
	
	current_window = NULL;
	
}

WindowManager::~WindowManager() {
	delete current_window;
}

void WindowManager::go_to_window(string id){
	current_window_id = id;
	string xml = WindowManager::windows[id];
	Window w(xml);	
	current_window = &w;
}

void WindowManager::go_to_window(string id, string options){
	
	//do some options stuff
	string xml = WindowManager::windows[id];
	Window w(xml);	
	current_window = &w;	
}



void WindowManager::loadxml(string path){

	ifstream xmlFile(path.c_str());
	if (xmlFile.is_open()){
		string line;
		while (getline(xmlFile, line)) {
			//this is the window line
			stringstream ss(line);
			string window_id;
			getline(ss, window_id, '\"'); //skip the first part 
			getline(ss, window_id, '\"'); //get the actual id
			string tag = "";
			getline(xmlFile, tag);
			string xml;
			while(tag != "</window>"){
				tag.erase(remove(tag.begin(),tag.end(),'\t'),tag.end()); //remove white space
				xml += tag + "\n";
				getline(xmlFile, tag);
			}
			windows.insert(make_pair(window_id,xml));
		}
	}
}

string WindowManager::get_current_window_id(){
	return current_window_id;
}

void WindowManager::run_pbar(){

	if(current_window_id == "end_screen"){

		clock_t start;
		double duration = 0;
		for(int i = 0; i < 10; i++){
			start = clock();
			while(duration < 10.0 ){

				duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
			}
			g_print("increasing pbar\n");
			current_window->increase_pbar();
		}
		
	}
}
