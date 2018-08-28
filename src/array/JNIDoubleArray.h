#pragma once
#include "../JNIArray.h"

using namespace std;

class JNIDoubleArray : public JNIArray<jdoubleArray>
{
private:
	jdouble *pData;

public:
	static JNIDoubleArray FromVector(JNIEnv *pEnv, vector<jdouble> vector)
	{
		JNIDoubleArray jniArray(pEnv, pEnv->NewDoubleArray(static_cast<int>(vector.size())));
		{
			pEnv->GetDoubleArrayRegion(jniArray.GetJavaObject(), 0, static_cast<int>(vector.size()), vector.data());
		}

		return jniArray;
	}

	JNIDoubleArray(JNIEnv *pEnv, jdoubleArray javaObject) : JNIArray(pEnv, javaObject)
	{
		this->pData = pEnv->GetDoubleArrayElements(javaObject, 0);
	}

	~JNIDoubleArray()
	{
		GetEnv()->ReleaseDoubleArrayElements(GetJavaObject(), pData, 0);
	}

	void Set(int index, jdouble value)
	{
		pData[index] = value;
	}

	jdouble Get(int index)
	{
		return pData[index];
	}

	vector<jdouble> ToVector()
	{
		return vector<jdouble>(pData, pData + GetSize());
	}
};