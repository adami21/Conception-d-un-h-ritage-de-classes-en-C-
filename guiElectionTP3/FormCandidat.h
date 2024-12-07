/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   FormCandidat.h
 * Author: etudiant
 *
 * Created on 6 décembre 2024, 20 h 59
 */

#ifndef _FORMCANDIDAT_H
#define _FORMCANDIDAT_H

#include "ui_FormCandidat.h"

class FormCandidat : public QDialog
{
  Q_OBJECT
public:
  FormCandidat ();
  virtual ~FormCandidat ();
private:
  Ui::FormCandidat widget;
};

#endif /* _FORMCANDIDAT_H */
