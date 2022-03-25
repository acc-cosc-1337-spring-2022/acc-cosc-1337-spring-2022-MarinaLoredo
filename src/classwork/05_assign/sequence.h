#include<iostream>
using std::string;

double get_gc_content(const string &dna);

string get_dna_compliment(string dna);

string reverse_string(string dna);

void menu_options();

void menu();

int handle_menu(int menu_selection);

string valid_dna();

string string_convert(string dna_raw);