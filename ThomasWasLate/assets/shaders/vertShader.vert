// varying "out" variables to be used in the fragment shader 
varying vec4 vColor;
varying vec2 vTexCoord;

void main(){
	vColor = gl_Color;
	vTexCoord = (gl_TextureMatrix[0] * gl_MultiTextCoord0.xy);
	gl_Position = gl_ModelViewProjectMatrix * gl_vertex;
}
