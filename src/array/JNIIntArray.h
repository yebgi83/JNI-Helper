#pragma once
#include "../JNIArray.h"

using namespace std;

class JNIIntArray : public JNIArray<jintArray>
{
private:
	jint *pData;

public:
	static JNIIntArray FromVector(JNIEnv *pEnv, vector<jint> vector)
	{
		JNIIntArray jniArray(pEnv, pEnv->NewIntArray(static_cast<int>(vector.size())));
		{
			pEnv->SetIntArrayRegion(jniArray.GetJavaObject(), 0, static_cast<int>(vector.size()), vector.data());
		}

		return jniArray;
	}

	JNIIntArray(JNIEnv *pEnv, jintArray javaObject) : JNIArray(pEnv, javaObject)
	{
		this->pData = pEnv->GetIntArrayElements(javaObject, 0);
	}

	~JNIIntArray()
	{
		GetEnv()->ReleaseIntArrayElements(GetJavaObject(), pData, 0);
	}

	void Set(int index, jint value)
	{
		pData[index] = value;
	}

	jint Get(int index)
	{
		return pData[index];
	}

	vector<jint> ToVector()
	{
		return vector<jint>(pData, pData + GetSize());
	}
};