cbuffer MatrixBuffer
{
	matrix world;
	matrix view;
	matrix projection;
};

struct VertexInput
{
	float4 position : POSITION;
	float2 texCoordinates : TEXCOORD0;
};

struct PixelInput
{
	float4 position : SV_POSITION;
	float2 texCoordinates : TEXCOORD0;
};

PixelInput main(VertexInput input)
{
	PixelInput output;

	input.position.w = 1.0f;

	output.position = mul(input.position, world);
	output.position = mul(output.position, view);
	output.position = mul(output.position, projection);

	output.texCoordinates = input.texCoordinates;

	return output;
}