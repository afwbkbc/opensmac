#pragma once

#include <string>

#include "base/ObjectLink.h"

namespace types {

class Font {
public:
	~Font() {
		if ( m_renderer_object )
			m_renderer_object->Remove();
	}

	typedef struct dimensions_t {
		float width;
		float height;
	} dimensions_t;

	typedef struct bitmap_t {
		int ax; // advance.x
		int ay; // advance.y
		unsigned int width; // bitmap.width;
		unsigned int height; // bitmap.rows;
		int left; // bitmap_left;
		int top; // bitmap_top;
		unsigned char *data;
	} bitmap_t;

	std::string m_name;
	bitmap_t m_symbols[128];
	dimensions_t m_dimensions;

	base::ObjectLink *m_renderer_object = NULL;
};

} /* namespace types */
