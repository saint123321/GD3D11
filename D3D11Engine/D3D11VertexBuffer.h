#pragma once
#include "basevertexbuffer.h"
class D3D11VertexBuffer : public BaseVertexBuffer
{
public:
	D3D11VertexBuffer(void);
	~D3D11VertexBuffer(void);

	/** Creates the vertexbuffer with the given arguments */
	virtual XRESULT Init(void* initData, unsigned int sizeInBytes, EBindFlags EBindFlags = B_VERTEXBUFFER, EUsageFlags usage = EUsageFlags::U_DEFAULT, ECPUAccessFlags cpuAccess = ECPUAccessFlags::CA_NONE, const std::string& fileName = "");

	/** Updates the vertexbuffer with the given data */
	virtual XRESULT UpdateBuffer(void* data, UINT size = 0);

	/** Updates the vertexbuffer with the given data */
	virtual XRESULT UpdateBufferAligned16(void* data, UINT size = 0);

	/** Maps the buffer */
	virtual XRESULT Map(int flags, void** dataPtr, UINT* size);

	/** Unmaps the buffer */
	virtual XRESULT Unmap();

	/** Optimizes the given set of vertices */
	virtual XRESULT OptimizeVertices(VERTEX_INDEX* indices, byte* vertices, unsigned int numIndices, unsigned int numVertices, unsigned int stride);

	/** Optimizes the given set of vertices */
	virtual XRESULT OptimizeFaces(VERTEX_INDEX* indices, byte* vertices, unsigned int numIndices, unsigned int numVertices, unsigned int stride);

	/** Returns the D3D11-Buffer object */
	ID3D11Buffer* GetVertexBuffer();

	/** Returns the size in bytes of this buffer */
	virtual unsigned int GetSizeInBytes();
private:
	/** Vertex buffer object */
	ID3D11Buffer* VertexBuffer;

	/** Size of the buffer in bytes */
	unsigned int SizeInBytes;
};

