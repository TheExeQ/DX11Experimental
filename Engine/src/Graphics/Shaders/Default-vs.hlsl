#include "./Structures.hlsli"

VSOutput main(VSInput input)
{
    VSOutput output;
    output.pos = float4(input.pos.x, input.pos.y, input.pos.z, 1.f);
    output.color = float3(input.color.x, input.color.y, input.color.z);
    return output;
};