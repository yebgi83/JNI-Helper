#pragma once
#include "../JNIArray.h"

using namespace std;

class JNIBooleanArray : public JNIArray<jbooleanArray>
{
private:
	jboolean *pData;

public:
	static JNIBooleanArray FromVector(JNIEnv *pEnv, vector<jboolean> vector)
	{
		JNIBooleanArray jniArray(pEnv, pEnv->NewBooleanArray(static_cast<int>(vector.size())));
		{
			pEnv->SetBooleanArrayRegion(jniArray.GetJavaObject(), 0, static_cast<int>(vector.size()), vector.data());
		}

		return jniArray;
	}

	JNIBooleanArray(JNIEnv *pEnv, jbooleanArray javaObject) : JNIArray(pEnv, javaObject)
	{
		this->pData = pEnv->GetBooleanArrayElements(javaObject, 0);
	}

	~JNIBooleanArray()
	{
		GetEnv()->ReleaseBooleanArrayElements(GetJavaObject(), pData, 0);
	}

	void Set(int index, jboolean value)
	{
		pData[index] = value ? JNI_TRUE : JNI_FALSE;
	}

	jboolean Get(int index)
	{
		return pData[index] == JNI_TRUE;
	}

	vector<jboolean> ToVector()
	{
		vector<jboolean> result;
		{
			result.reserve(GetSize());
		}

		for (int index = 0; index < static_cast<int>(result.capacity()); index++) {
			result.push_back(Get(index));
		}

		return result;
	}
};