/*
 * box_geometry.cpp
 *
 *  Created on: 30 Dec 2018
 *      Author: adamsoderstrom
 */

#include <box_geometry.h>

namespace GE{
namespace Geometry {

BoxGeometry::BoxGeometry(float width, float height, float depth) :
		m_width(width),
		m_height(height),
		m_depth(depth)
{
	float vertices[] = {
		// Position				// Tex pos		// Normal
		-0.5f, -0.5f, -0.5f,  	0.0f, 0.0f,		0.0, 0.0, -1.0,
		 0.5f,  0.5f, -0.5f,    1.0f, 1.0f,		0.0, 0.0, -1.0,
		 0.5f,  0.5f, -0.5f,    1.0f, 1.0f,     0.0, 0.0, -1.0,
		 0.5f, -0.5f, -0.5f,    1.0f, 0.0f,     0.0, 0.0, -1.0,
		-0.5f,  0.5f, -0.5f,    0.0f, 1.0f,     0.0, 0.0, -1.0,
		-0.5f, -0.5f, -0.5f,    0.0f, 0.0f,     0.0, 0.0, -1.0,

		-0.5f, -0.5f,  0.5f,    0.0f, 0.0f,		0.0, 0.0, 1.0,
		 0.5f, -0.5f,  0.5f,    1.0f, 0.0f,		0.0, 0.0, 1.0,
		 0.5f,  0.5f,  0.5f,    1.0f, 1.0f,     0.0, 0.0, 1.0,
		 0.5f,  0.5f,  0.5f,    1.0f, 1.0f,     0.0, 0.0, 1.0,
		-0.5f,  0.5f,  0.5f,    0.0f, 1.0f,     0.0, 0.0, 1.0,
		-0.5f, -0.5f,  0.5f,    0.0f, 0.0f,     0.0, 0.0, 1.0,

		-0.5f,  0.5f,  0.5f,    1.0f, 0.0f,		-1.0, 0.0, 0.0,
		-0.5f,  0.5f, -0.5f,    1.0f, 1.0f,		-1.0, 0.0, 0.0,
		-0.5f, -0.5f, -0.5f,    0.0f, 1.0f,     -1.0, 0.0, 0.0,
		-0.5f, -0.5f, -0.5f,    0.0f, 1.0f,     -1.0, 0.0, 0.0,
		-0.5f, -0.5f,  0.5f,    0.0f, 0.0f,     -1.0, 0.0, 0.0,
		-0.5f,  0.5f,  0.5f,    1.0f, 0.0f,     -1.0, 0.0, 0.0,

		 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 	1.0, 0.0, 0.0,
		 0.5f,  0.5f, -0.5f,    1.0f, 1.0f,		1.0, 0.0, 0.0,
		 0.5f, -0.5f, -0.5f,    0.0f, 1.0f,     1.0, 0.0, 0.0,
		 0.5f, -0.5f, -0.5f,    0.0f, 1.0f,     1.0, 0.0, 0.0,
		 0.5f, -0.5f,  0.5f,    0.0f, 0.0f,     1.0, 0.0, 0.0,
		 0.5f,  0.5f,  0.5f,    1.0f, 0.0f,     1.0, 0.0, 0.0,

		-0.5f, -0.5f, -0.5f,    0.0f, 1.0f,		0.0, -1.0, 0.0,
		 0.5f, -0.5f, -0.5f,    1.0f, 1.0f,		0.0, -1.0, 0.0,
		 0.5f, -0.5f,  0.5f,    1.0f, 0.0f,     0.0, -1.0, 0.0,
		 0.5f, -0.5f,  0.5f,    1.0f, 0.0f,     0.0, -1.0, 0.0,
		-0.5f, -0.5f,  0.5f,    0.0f, 0.0f,     0.0, -1.0, 0.0,
		-0.5f, -0.5f, -0.5f,    0.0f, 1.0f,     0.0, -1.0, 0.0,

		-0.5f,  0.5f, -0.5f,    0.0f, 1.0f,		0.0, 1.0, 0.0,
		 0.5f,  0.5f, -0.5f,    1.0f, 1.0f,		0.0, 1.0, 0.0,
		 0.5f,  0.5f,  0.5f,    1.0f, 0.0f,		0.0, 1.0, 0.0,
		 0.5f,  0.5f,  0.5f,    1.0f, 0.0f,     0.0, 1.0, 0.0,
		-0.5f,  0.5f,  0.5f,    0.0f, 0.0f,     0.0, 1.0, 0.0,
		-0.5f,  0.5f, -0.5f,    0.0f, 1.0f,     0.0, 1.0, 0.0
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

}

void BoxGeometry::Render() const {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

BoxGeometry::~BoxGeometry() {
}

}
}

