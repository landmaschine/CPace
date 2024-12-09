#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D sampledTex;

void main()
{
    FragColor = texture(sampledTex, TexCoord);
}