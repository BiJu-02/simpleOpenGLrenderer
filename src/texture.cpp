//unsigned int tex;
//glGenTextures(1, &tex);
//glBindTexture(GL_TEXTURE_2D, tex);

//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//int tex_w, tex_h, tex_nr_channels;
//unsigned char *tex_data = stbi_load("res/images/wall.jpg", &tex_w, &tex_h, &tex_nr_channels, 0);
//if (tex_data)
//{
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_w, tex_h, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_data);
//	glGenerateMipmap(GL_TEXTURE_2D);
//}
//else
//{
//	std::cout << "could not load texture" << std::endl;
//}
//stbi_image_free(tex_data);