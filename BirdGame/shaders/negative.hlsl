struct VOut
{
    float4 position : SV_POSITION;
    float4 normal : NORMAL;
	float3 texcoord : TEXCOORD;
	float4 lightDirection : COLOR;
};

Texture2DArray Texture;
SamplerState ss;

cbuffer VS_CONSTANT_BUFFER : register(b0)
{
    matrix modelViewProjection;
	matrix rotation;
	float3 objectPosition;
	unsigned int textureSample;
	float3 lightPosition;
};

VOut VShader(float4 position : POSITION, float4 normal : NORMAL, float2 texcoord : TEXCOORD)
{
    VOut output;
	output.lightDirection = normalize(float4(lightPosition,1) - (float4(objectPosition,1) + mul(position,rotation)));
	output.position = mul(modelViewProjection, position);
	output.normal = mul(rotation, normalize(normal));
	output.texcoord = float3(texcoord, textureSample);
    return output;
}


float4 PShader(float4 position : SV_POSITION, float4 normal : NORMAL, float3 texcoord : TEXCOORD, float4 lightDirection : COLOR) : SV_TARGET
{
	float4 col = Texture.Sample(ss, texcoord) * dot(normal, lightDirection);
	col.r = 1 - col.r;
	col.g = 1 - col.g;
	col.b = 1 - col.b;
	return col;
}
