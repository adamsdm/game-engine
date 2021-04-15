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
	Vertices = {
		// Position				// Tex pos	  // Normal
		// Back
		-0.5f,	-0.5f,  -0.5f,  0.0f,  0.0f,   0.0f,  0.0f, -1.0f,	
		 0.5f, 	-0.5f,  -0.5f,  1.0f,  0.0f,   0.0f,  0.0f, -1.0f,
		 0.5f,   0.5f,  -0.5f,  1.0f,  1.0f,   0.0f,  0.0f, -1.0f,
		 0.5f,   0.5f,  -0.5f,  1.0f,  1.0f,   0.0f,  0.0f, -1.0f,
		-0.5f,   0.5f,  -0.5f,  0.0f,  1.0f,   0.0f,  0.0f, -1.0f,
		-0.5f, 	-0.5f,  -0.5f,  0.0f,  0.0f,   0.0f,  0.0f, -1.0f,
		// Front
		-0.5f,  -0.5f,   0.5f,  0.0f,  0.0f,   0.0f,  0.0f,  1.0f,   
		 0.5f,  -0.5f,   0.5f,  1.0f,  0.0f,   0.0f,  0.0f,  1.0f,
		 0.5f,   0.5f,   0.5f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,
		 0.5f,   0.5f,   0.5f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,
		-0.5f,   0.5f,   0.5f,  0.0f,  1.0f,   0.0f,  0.0f,  1.0f,
		-0.5f,  -0.5f,   0.5f,  0.0f,  0.0f,   0.0f,  0.0f,  1.0f,
		// Left
		-0.5f,   0.5f,   0.5f,  1.0f,  0.0f,  -1.0f,  0.0f,  0.0f,    	
		-0.5f,   0.5f,  -0.5f,  1.0f,  1.0f,  -1.0f,  0.0f,  0.0f, 
		-0.5f,  -0.5f,  -0.5f,  0.0f,  1.0f,  -1.0f,  0.0f,  0.0f, 
		-0.5f,  -0.5f,  -0.5f,  0.0f,  1.0f,  -1.0f,  0.0f,  0.0f, 
		-0.5f,  -0.5f,   0.5f,  0.0f,  0.0f,  -1.0f,  0.0f,  0.0f, 
		-0.5f,   0.5f,   0.5f,  1.0f,  0.0f,  -1.0f,  0.0f,  0.0f, 
		// Right
		 0.5f,   0.5f,   0.5f,  1.0f,  0.0f,   1.0f,  0.0f,  0.0f,
		 0.5f,   0.5f,  -0.5f,  1.0f,  1.0f,   1.0f,  0.0f,  0.0f,
		 0.5f,  -0.5f,  -0.5f,  0.0f,  1.0f,   1.0f,  0.0f,  0.0f,
		 0.5f,  -0.5f,  -0.5f,  0.0f,  1.0f,   1.0f,  0.0f,  0.0f,
		 0.5f,  -0.5f,   0.5f,  0.0f,  0.0f,   1.0f,  0.0f,  0.0f,
		 0.5f,   0.5f,   0.5f,  1.0f,  0.0f,   1.0f,  0.0f,  0.0f,
		// Down
		-0.5f,  -0.5f,  -0.5f,  0.0f,  1.0f,   0.0f, -1.0f,  0.0f,
		 0.5f,  -0.5f,  -0.5f,  1.0f,  1.0f,   0.0f, -1.0f,  0.0f,
		 0.5f,  -0.5f,   0.5f,  1.0f,  0.0f,   0.0f, -1.0f,  0.0f,
		 0.5f,  -0.5f,   0.5f,  1.0f,  0.0f,   0.0f, -1.0f,  0.0f,
		-0.5f,  -0.5f,   0.5f,  0.0f,  0.0f,   0.0f, -1.0f,  0.0f,
		-0.5f,  -0.5f,  -0.5f,  0.0f,  1.0f,   0.0f, -1.0f,  0.0f,
		// Up
		-0.5f,   0.5f,  -0.5f,  0.0f,  1.0f,   0.0f,  1.0f,  0.0f,
		 0.5f,   0.5f,  -0.5f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,
		 0.5f,   0.5f,   0.5f,  1.0f,  0.0f,   0.0f,  1.0f,  0.0f,
		 0.5f,   0.5f,   0.5f,  1.0f,  0.0f,   0.0f,  1.0f,  0.0f,
		-0.5f,   0.5f,   0.5f,  0.0f,  0.0f,   0.0f,  1.0f,  0.0f,
		-0.5f,   0.5f,  -0.5f,  0.0f,  1.0f,   0.0f,  1.0f,  0.0f
	};

	Indices = {
		0,   1,  2,
		3,   4,  5,
		6,   7,  8,
		9,  10, 11,
		12, 13, 14,
		15, 16, 17,
		18, 19, 20,
		21, 22, 23,
		24, 25, 26,
		27, 28, 29,
		30, 31, 32,
		33, 34, 35
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(float), &Vertices[0], GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int), &Indices[0], GL_STATIC_DRAW);


	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0); 

}

void BoxGeometry::Render() const {
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

BoxGeometry::~BoxGeometry() {
}

}
}

