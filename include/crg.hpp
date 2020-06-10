
#ifndef STDLIB
#define STDLIB

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <cstdio>
#include <cstring>

#endif

#ifndef SFMLIB
#define SFMLIB

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#endif

#ifndef MY_LIB
#define MY_LIB

#include "crg/company.hpp"
#include "crg/specs.hpp"
#include "crg/hud.hpp"

#include "my_lib.hpp"

#endif

#ifndef CRG
#define CRG

HUD parsor(char *av);
void displayer(HUD hud);

#endif