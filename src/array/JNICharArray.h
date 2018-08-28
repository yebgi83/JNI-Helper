#pragma once
#include "../JNIArray.h"

using namespace std;

class JNICharArray : public JNIArray<jcharArray>
{
private:
	jchar *pData;

public:
	static JNICharArray FromVector(JNIEnv *pEnv, vector<jchar> vector)
	{
		JNICharArray jniArray(pEnv, pEnv->NewCharArray(static_cast<int>(vector.size())));
		{
			pEnv->SetCharArrayRegion(jniArray.GetJavaObject(), 0, static_cast<int>(vector.size()), vector.data());
		}

		return jniArray;
	}

	JNICharArray(JNIEnv *pEnv, jcharArray javaObject) : JNIArray(pEnv, javaObject)
	{
		this->pData = pEnv->GetCharArrayElements(javaObject, 0);
	}

	~JNICharArray()
	{
		GetEnv()->ReleaseCharArrayElements(GetJavaObject(), pData, 0);
	}

	void Set(int index, jchar value)
	{
		pData[index] = value;
	}

	jchar Get(int index)
	{
		return pData[index];
	}

	vector<jchar> ToVector()
	{
		return vector<jchar>(pData, pData + GetSize());
	}
};