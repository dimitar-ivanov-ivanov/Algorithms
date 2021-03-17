#include <iostream>
#include <string.h>
#include "saobshteniq.h"

using namespace std;

#define MAX_REDOVE 50
#define MAX_KOLONI 50
#define NO_OF_CHARS 256

string vavedeteText(string saobshtenie);
int vavedeteChislo(string saobshtenie);
void vhodMatrica(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni);
void izhodMatrica(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni);
void markiraneNaNalichie(string str, int size,int nalichie[NO_OF_CHARS]);
int booyerMoore(string text, string shablon);
void proveriZaBoyerMoore(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni,string maxStr,string minStr);
