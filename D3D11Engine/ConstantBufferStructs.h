#pragma once
#include "pch.h"




__declspec( align( 16 ) )struct VobInstanceInfo
{
	D3DXMATRIX world;
};




#pragma pack (push, 1)	
struct SkyConstantBuffer
{
	float SC_TextureWeight;
	float3 SC_pad1;
};

struct OceanSettingsConstantBuffer
{
	float3 OS_CameraPosition;
	float OS_SpecularPower;

	// Water-reflected sky color
	float3			OS_SkyColor;
	float			unused0;
	// The color of bottomless water body
	float3			OS_WaterbodyColor;

	// The strength, direction and color of sun streak
	float			OS_Shineness;
	float3			OS_SunDir;
	float			unused1;
	float3			OS_SunColor;
	float			unused2;
	
	// The parameter is used for fixing an artifact
	float3			OS_BendParam;

	// Perlin noise for distant wave crest
	float			OS_PerlinSize;
	float3			OS_PerlinAmplitude;
	float			unused3;
	float3			OS_PerlinOctave;
	float			unused4;
	float3			OS_PerlinGradient;

	// Constants for calculating texcoord from position
	float			OS_TexelLength_x2;
	float			OS_UVScale;
	float			OS_UVOffset;
	float2			unused5;
};

struct OceanPerPatchConstantBuffer
{
	float3 OPP_LocalEye;
	float OPP_Pad1;

	float3 OPP_PatchPosition;
	float OPP_Pad2;
};

struct BlurConstantBuffer
{
	float2 B_PixelSize;
	float B_BlurSize;
	float B_Threshold;

	float4 B_ColorMod;
};

struct PerObjectState
{
	float3 OS_AmbientColor;
	float OS_Pad;
};

struct PFXVS_ConstantBuffer
{
	D3DXMATRIX PFXVS_InvProj;
};

struct HeightfogConstantBuffer
{
	D3DXMATRIX InvProj;
	D3DXMATRIX InvView;
	float3 CameraPosition;
	float HF_FogHeight;

	float HF_HeightFalloff;
	float HF_GlobalDensity;
	float HF_WeightZNear;
	float HF_WeightZFar;

	float3 HF_FogColorMod;
	float HF_pad2;

	float2 HF_ProjAB;
	float2 HF_Pad3;
};

struct LumAdaptConstantBuffer
{
	float LC_DeltaTime;
	float3 LC_Pad;
};

struct HDRSettingsConstantBuffer
{
	float HDR_MiddleGray;
	float HDR_LumWhite;
	float HDR_Threshold;
	float HDR_BloomStrength;
};

struct ViewportInfoConstantBuffer
{
	float2 VPI_ViewportSize;
	float2 VPI_pad;
};

struct DS_PointLightConstantBuffer
{
	float4 PL_Color;			

	float PL_Range;
	float3 Pl_PositionWorld;

	float PL_Outdoor;
	float3 Pl_PositionView;

	float2 PL_ViewportSize;
	float2 PL_Pad2;

	D3DXMATRIX PL_InvProj; // Optimize out!
	D3DXMATRIX PL_InvView;

	float3 PL_LightScreenPos;
	float PL_Pad3;
};

struct DS_ScreenQuadConstantBuffer
{
	D3DXMATRIX SQ_InvProj; // Optimize out!
	D3DXMATRIX SQ_InvView;
	float3 SQ_LightDirectionVS;
	float SQ_ShadowmapSize;

	float4 SQ_LightColor;

	D3DXMATRIX SQ_ShadowView;
	D3DXMATRIX SQ_ShadowProj;

	float2 SQ_ProjAB;
	float2 SQ_Pad2;
};

struct CloudConstantBuffer
{
	float3 C_LightDirection;
	float C_Pad;

	float3 C_CloudPosition;
	float C_Pad2;
};

struct VS_ExConstantBuffer_PerFrame
{
	D3DXMATRIX View;
	D3DXMATRIX Projection;
	D3DXMATRIX ViewProj;
};

struct VS_ExConstantBuffer_PerInstance
{
	D3DXMATRIX World;
};

struct VS_ExConstantBuffer_PerInstanceSkeletal
{
	D3DXMATRIX World;
	float PI_ModelFatness;
	float3 PI_Pad1;
};


struct GrassConstantBuffer
{
	float3 G_NormalVS;
	float G_Time;
	float G_WindStrength;
	float3 G_Pad1;
};

struct DefaultHullShaderConstantBuffer
{
	float H_EdgesPerScreenHeight;
	float H_Proj11;
	float H_GlobalTessFactor;
	float H_FarPlane;
	float2 H_ScreenResolution;
	float2 h_pad2;
};


struct PNAENConstantBuffer
{
	D3DXMATRIX    f4x4Projection;           // Projection matrix 
	float4      f4Eye;                    // Eye 
	float4      f4TessFactors;            // Tessellation factors 
											// x=Edge  
	float4      f4ViewportScale;          // The X and Y half  
											// resolution, 0, 0 
	INT4       adaptive;                 // Should use adaptive  
											// tessellation 
	INT4       clipping;                 // Should run clipping  
											// tests. 
};

struct RefractionInfoConstantBuffer
{
	D3DXMATRIX RI_Projection;
	float2 RI_ViewportSize;
	float RI_Time;
	float RI_Pad1;

	float3 RI_CameraPosition;
	float RI_Pad2;
};

struct AtmosphereConstantBuffer
{
	float AC_Kr4PI;
	float AC_Km4PI;	
	float AC_g;
	float AC_KrESun;

	float AC_KmESun;
	float AC_InnerRadius;
	float AC_OuterRadius;
	float AC_Scale;

	float3 AC_Wavelength;
	float AC_RayleighScaleDepth;


	float AC_RayleighOverScaleDepth;
	int AC_nSamples;
	float AC_fSamples;
	float AC_CameraHeight;

	float3 AC_CameraPos;
	float AC_Time;
	float3 AC_LightPos;
	float AC_pad2;

	float3 AC_SpherePosition;
	float AC_pad3;
};
#pragma pack (pop)