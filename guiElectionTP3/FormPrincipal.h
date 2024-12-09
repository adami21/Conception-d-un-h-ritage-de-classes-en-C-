
#ifndef _FORMPRINCIPAL_H
#define _FORMPRINCIPAL_H

#include "Circonscription.h"
#include "ui_FormPrincipal.h"

class FormPrincipal : public QMainWindow
{
  Q_OBJECT
public:
  FormPrincipal ();
  virtual ~FormPrincipal ();
  
private slots:
  void slotOuvrirElecteur();
private:
  Ui::FormPrincipal widget;
  elections::Circonscription m_circonscription;
};

#endif /* _FORMPRINCIPAL_H */
