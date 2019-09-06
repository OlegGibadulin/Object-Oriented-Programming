#ifndef SHOWERROR_CPP
#define SHOWERROR_CPP

#include "showerror.h"

void showError(QString msg)
{
    QMessageBox::information(NULL, "Error", msg);
}

void showError(typeError error)
{
    showError(QString(getErrorMsg(error)));
}

#endif // SHOWERROR_CPP

