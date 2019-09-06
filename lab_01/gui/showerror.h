#ifndef SHOWERROR_H
#define SHOWERROR_H

#include "../library/errors.h"

#include <QMessageBox>

void showError(QString msg);

void showError(typeError error);

#endif // SHOWERROR_H

