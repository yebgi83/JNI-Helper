#pragma once
#include "../JNIArray.h"

using namespace std;

class JNIShortArray : public JNIArray<jshortArray>
{
private:
	jshort *pData;

public:
	static JNIShortArray FromVector(JNIEnv *pEnv, vector<jshort> vector)
	{
		JNIShortArray jniArray(pEnv, pEnv->NewShortArray(static_cast<int>(vector.size())));
		{
			pEnv->SetShortArrayRegion(jniArray.GetJavaObject(), 0, static_cast<int>(vector.size()), vector.data());
		}

		return jniArray;
	}

	JNIShortArray(JNIEnv *pEnv, jshortArray javaObject) : JNIArray(pEnv, javaObject)
	{
		this->pData = pEnv->GetShortArrayElements(javaObject, 0);
	}

	~JNIShortArray() 
	{
		GetEnv()->ReleaseShortArrayElements(GetJavaObject(), pData, 0);
	}

	void Set(int index, jshort value)
	{
		pData[index] = value;
	}

	jshort Get(int index)
	{
		return pData[index];
	}

	vector<jshort> ToVector()
	{
		return vector<jshort>(pData, pData + GetSize());
	}
};