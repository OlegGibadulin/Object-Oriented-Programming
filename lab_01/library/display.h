#ifndef DISPLAY_H
#define DISPLAY_H

#include "../gui/widget.h"
#include "errors.h"
#include "edgearray.h"
#include "nodearray.h"
#include "displaywork.h"

// provide coordinates of nodes for drawing lines
typeError getCoordForDrawLine(const nodeType* nodes, const int src, const int purp);

// get edges for drawing line
typeError drawDisplay(const edgeType* edges, const nodeType* nodes, \
                      const unsigned int size);

#endif // DISPLAY_H

