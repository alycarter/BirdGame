struct VOut
{
    float4 position : SV_POSITION;
    float4 normal : NORMAL;
	float3 texcoord : TEXCOORD;
	float4 lightDirection : LIGHT;
};

Texture2DArray Texture;
SamplerState ss;

cbuffer VS_CONSTANT_BUFFER : register(b0)
{
    float4 light;
	matrix viewProjection;
};

VOut VShader(float3 position : VPOSITION, float3 normal : VNORMAL, float2 texcoord : VTEXCOORD, matrix model : IMODEL, matrix rotation : IROTATION, uint textureSample : ITEXTURE)
{
    VOut output;
	output.position = float4(position, 1.0);
	output.position = mul(model, output.position);
	output.lightDirection = normalize(light - output.position);
	output.position = mul(viewProjection, output.position);
	output.normal = mul(rotation, float4(normalize(normal), 1.0));
	output.texcoord = float3(texcoord, textureSample);
    return output;
}


float4 PShader(float4 position : SV_POSITION, float4 normal : NORMAL, float3 texcoord : TEXCOORD, float4 lightDirection : LIGHT) : SV_TARGET
{
	return  Texture.Sample(ss, texcoord) *  dot(normal, lightDirection);
}
