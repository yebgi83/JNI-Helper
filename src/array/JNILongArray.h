#pragma once
#include "../JNIArray.h"

using namespace std;

class JNILongArray : public JNIArray<jlongArray>
{
private:
	jlong *pData;
	
public:
	static JNILongArray FromVector(JNIEnv *pEnv, vector<jlong> vector)
	{
		JNILongArray jniArray(pEnv, pEnv->NewLongArray(static_cast<int>(vector.size())));
		{
			pEnv->SetLongArrayRegion(jniArray.GetJavaObject(), 0, static_cast<int>(vector.size()), vector.data());
		}

		return jniArray;
	}

	JNILongArray(JNIEnv *pEnv, jlongArray javaObject) : JNIArray(pEnv, javaObject)
	{
		return;
	}

	void Set(int index, jlong value)
	{
		pData[index] = value;
	}

	jlong Get(int index)
	{
		return pData[index];
	}

	vector<jlong> ToVector()
	{
		return vector<jlong>(pData, pData + GetSize());
	}
};