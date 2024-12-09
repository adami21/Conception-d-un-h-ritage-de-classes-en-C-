/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   FormElecteur.h
 * Author: etudiant
 *
 * Created on 9 décembre 2024, 13 h 29
 */

#ifndef _FORMELECTEUR_H
#define _FORMELECTEUR_H

#include "ui_FormElecteur.h"

class FormElecteur : public QDialog
{
  Q_OBJECT
public:
  FormElecteur ();
  virtual ~FormElecteur ();
private:
  Ui::FormElecteur widget;
};

#endif /* _FORMELECTEUR_H */
