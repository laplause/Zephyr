Texture2D shaderTexture;
SamplerState shaderSampler;

struct PixelInput
{
	float4 position : SV_POSITION;
	float2 texCoordinates : TEXCOORD0;
};

float4 main(PixelInput input) : SV_TARGET
{
	return shaderTexture.Sample(shaderSampler, input.texCoordinates);
}