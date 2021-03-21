#include <iostream>
#include <string.h>
#include<stdio.h>
#include "saobshteniq.h"
#include "ogranicheniq.h"

using namespace std;

string vavedeteText(string saobshtenie);
int vavedeteChislo(string saobshtenie,int minGranica,int maxGranica);
void vhodMatrica(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni);
void izhodMatrica(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni);
void markiraneNaNalichie(string str, int size,int nalichie[NO_OF_CHARS]);
int booyerMoore(string text, string shablon);
void proveriZaBoyerMoore(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni,string maxStr,string minStr);
