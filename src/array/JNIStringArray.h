#pragma once
#include "../JNIArray.h"
#include "../JNIString.h"

using namespace std;

class JNIStringArray : public JNIArray<>
{
public:
	static JNIStringArray FromVector(JNIEnv *pEnv, vector<string> vector)
	{
		JNIStringArray jniArray(pEnv, pEnv->NewObjectArray(static_cast<int>(vector.size()), pEnv->FindClass("java/lang/String"), JNIString::ToJavaString(pEnv, "")));

		for (int index = 0; index < static_cast<int>(vector.size()); index++) {
			jniArray.Set(index, vector[index]);
		}

		return jniArray;
	}

	JNIStringArray(JNIEnv *pEnv, jobjectArray javaObject) : JNIArray(pEnv, javaObject)
	{
	}

	void Set(int index, string value)
	{
		GetEnv()->SetObjectArrayElement(GetJavaObject(), index, JNIString::ToJavaString(GetEnv(), value));
	}

	string Get(int index)
	{
		return JNIString(GetEnv(), GetEnv()->GetObjectArrayElement(GetJavaObject(), index)).GetString();
	}

	vector<string> ToVector()
	{
		vector<string> result;
		{
			result.reserve(GetSize());
		}

		for (int index = 0; index < static_cast<int>(result.capacity()); index++) {
			result.push_back(Get(index));
		}

		return result;
	}
};