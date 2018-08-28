#pragma once
#include "../JNIArray.h"

using namespace std;

class JNIFloatArray : public JNIArray<jfloatArray>
{
private:
	jfloat *pData;

public:
	static JNIFloatArray FromVector(JNIEnv *pEnv, vector<jfloat> vector)
	{
		JNIFloatArray jniArray(pEnv, pEnv->NewFloatArray(static_cast<int>(vector.size())));
		{
			pEnv->SetFloatArrayRegion(jniArray.GetJavaObject(), 0, static_cast<int>(vector.size()), vector.data());
		}

		return jniArray;
	}

	JNIFloatArray(JNIEnv *pEnv, jfloatArray javaObject) : JNIArray(pEnv, javaObject)
	{
		this->pData = pEnv->GetFloatArrayElements(javaObject, 0);
	}

	~JNIFloatArray()
	{
		GetEnv()->ReleaseFloatArrayElements(GetJavaObject(), pData, 0);
	}

	void Set(int index, jfloat value)
	{
		pData[index] = value;
	}

	jfloat Get(int index)
	{
		return pData[index];
	}

	vector<jfloat> ToVector()
	{
		return vector<jfloat>(pData, pData + GetSize());
	}
};