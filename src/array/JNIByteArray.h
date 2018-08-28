#pragma once
#include "../JNIArray.h"

using namespace std;

class JNIByteArray : public JNIArray<jbyteArray>
{
private:
	jbyte *pData;

public:
	static JNIByteArray FromVector(JNIEnv *pEnv, vector<jbyte> vector)
	{
		JNIByteArray jniArray(pEnv, pEnv->NewByteArray(static_cast<int>(vector.size())));
		{
			pEnv->SetByteArrayRegion(jniArray.GetJavaObject(), 0, static_cast<int>(vector.size()), vector.data());
		}

		return jniArray;
	}

	JNIByteArray(JNIEnv *pEnv, jbyteArray javaObject) : JNIArray(pEnv, javaObject)
	{
		this->pData = pEnv->GetByteArrayElements(javaObject, 0);
	}

	~JNIByteArray() 
	{
		GetEnv()->ReleaseByteArrayElements(GetJavaObject(), pData, 0);
	}

	void Set(int index, jbyte value)
	{
		pData[index] = value;
	}

	jbyte Get(int index)
	{
		return pData[index];
	}

	vector<jbyte> ToVector()
	{
		return vector<jbyte>(pData, pData + GetSize());
	}
};