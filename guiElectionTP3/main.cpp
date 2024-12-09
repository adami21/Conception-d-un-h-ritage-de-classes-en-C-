/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/main.cc to edit this template
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 6 décembre 2024, 08 h 44
 */

#include "FormPrincipal.h"
#include <QApplication>
#include <qt5/QtWidgets/qwidget.h>

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  FormPrincipal formPrincipal;
  formPrincipal.show();

  return app.exec ();
}
