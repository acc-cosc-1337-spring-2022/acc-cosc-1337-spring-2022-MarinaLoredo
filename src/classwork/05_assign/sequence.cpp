
#include<iostream>
#include<cctype>
#include "sequence.h"

using std::cout; using std::cin; using std::string;

void menu_options()
{
    cout<<"\n\nWhat would you like to do?";
    cout<<"\n1. Get GC Content";
    cout<<"\n2. Get DNA Compliment";
    cout<<"\n3. Exit";
}

void menu()
{
    int menu_selection = 0;
	do
    {
        menu_options();
        cout<<"\n\nEnter number from menu: ";
        cin>> menu_selection;
        if (menu_selection > 0 && menu_selection < 3) {
            handle_menu(menu_selection);
        }
        else if (menu_selection == 3){
            char confirm = 'n';
            cout << "\nAre you sure you would like to exit? (y/n): ";
            cin >> confirm;
            if (toupper(confirm) == 'Y') {
                cout << "\nThank you! Have a nice day!";
            }
            else {
                menu_selection = 0;
            }
        }
        else {
            cout << "\nSelection error: please enter valid selection from menu.";
        }
    }
    while(menu_selection != 3);
}

int handle_menu(int menu_selection)
{
    switch(menu_selection)
    {
        case 1: {
            cout << "\nThis function displays the percentage of a DNA strand that contains a 'G' or 'C'.";
            string dna = valid_dna();
            cout << "\nThe GC content percentage is: " << (get_gc_content(dna)*100) << "%";
            break;
        }
        case 2: {
            cout << "\nThis function displays the reverse compliment of the supplied DNA strand.";
            string dna = valid_dna();

            cout << "\nThe reverse compliment is: " << get_dna_compliment(dna);
            break;
        }
    }
    return(menu_selection);
}

string valid_dna()
{
    string dna = "";
    string dna_raw = "";
    do
    {
        cout << "\nPlease enter a DNA strand: ";
        cin >> dna_raw;
        dna = string_convert(dna_raw);
        for (int i=0; i < dna.size(); i++)
        {
            if (dna[i] != 'G' && dna[i] != 'C' && dna[i] != 'T' && dna[i] != 'A') {
                cout << "\nCharacter " << dna[i] << " is not valid. Please enter only G, C, T, or A.";
                dna = "";
            }
        }
    } while (dna == "");
    return dna;
}


string string_convert(string dna_raw)
{
    string dna = "";
    for (int i= 0; i < dna_raw.size(); i++)
    {
        dna += toupper(dna_raw[i]);
    }
    cout << dna;
    return dna;
}

double get_gc_content(const string &dna)
{
    double c_or_g = 0;
    double dna_total= 0;

    for (int i = 1; i <= dna.size(); i++)
    {
        if (dna[dna_total] == 'G' || dna[dna_total] =='C') {
            c_or_g++;
        }
        dna_total++;
    }
    double gc_content = c_or_g / dna_total;
    return gc_content;
}


string get_dna_compliment(string dna)
{
    string compliment = "";
    for (int i = 0; i < dna.size(); i++)
    {
        switch(dna[i])
        {
            case 'G': {
                compliment += "C";
                break;
            }
            case 'C': {
                compliment += "G";
                break;
            }
            case 'T': {
                compliment += "A";
                break;
            }
            case 'A': {
                compliment += "T";
                break;
            }
        }
    }
    dna = reverse_string(compliment);
    return dna;
}


string reverse_string(string dna)
{
    string reverse = "";
    for (int i = dna.size(); i >= 0; i--)
    {
        reverse += dna[i];
    }
    return reverse;
}