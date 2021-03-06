/*****************************************************************************
// * This source file is part of ArkGameFrame                                *
// * For the latest info, see https://github.com/ArkGame                     *
// *                                                                         *
// * Copyright(c) 2013 - 2017 ArkGame authors.                               *
// *                                                                         *
// * Licensed under the Apache License, Version 2.0 (the "License");         *
// * you may not use this file except in compliance with the License.        *
// * You may obtain a copy of the License at                                 *
// *                                                                         *
// *     http://www.apache.org/licenses/LICENSE-2.0                          *
// *                                                                         *
// * Unless required by applicable law or agreed to in writing, software     *
// * distributed under the License is distributed on an "AS IS" BASIS,       *
// * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
// * See the License for the specific language governing permissions and     *
// * limitations under the License.                                          *
// *                                                                         *
// *                                                                         *
// * @file  	AFCObject.h                                                *
// * @author    Ark Game Tech                                                *
// * @date      2015-12-15                                                   *
// * @brief     AFCObject                                                  *
*****************************************************************************/
#pragma once

#include <iostream>
#include <string>
#include "SDK/Core/AFIObject.h"
#include "SDK/Core/AFIRecordManager.h"
#include "SDK/Core/AFIHeartBeatManager.h"
#include "SDK/Core/AFIPropertyMgr.h"

class AFCObject
    : public AFIObject
{
public:
    AFCObject() = delete;
    AFCObject(const AFGUID& self, AFIPluginManager* pLuginManager);
    virtual ~AFCObject();

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();
    ///////////////////////////////////////////////////////////////////////
    virtual const AFGUID& Self();

    virtual bool FindHeartBeat(const std::string& strHeartBeatName);
    virtual bool RemoveHeartBeat(const std::string& strHeartBeatName);
    /////////////////////////////////////////////////////////////////
    virtual bool FindProperty(const std::string& strPropertyName);

    virtual bool SetPropertyBool(const std::string& strPropertyName, const bool value);
    virtual bool SetPropertyInt(const std::string& strPropertyName, const int32_t value);
    virtual bool SetPropertyInt64(const std::string& strPropertyName, const int64_t value);
    virtual bool SetPropertyFloat(const std::string& strPropertyName, const float value);
    virtual bool SetPropertyDouble(const std::string& strPropertyName, const double value);
    virtual bool SetPropertyString(const std::string& strPropertyName, const std::string& value);
    virtual bool SetPropertyObject(const std::string& strPropertyName, const AFGUID& value);

    virtual bool GetPropertyBool(const std::string& strPropertyName);
    virtual int32_t GetPropertyInt(const std::string& strPropertyName);
    virtual int64_t GetPropertyInt64(const std::string& strPropertyName);
    virtual float GetPropertyFloat(const std::string& strPropertyName);
    virtual double GetPropertyDouble(const std::string& strPropertyName);
    virtual const char*  GetPropertyString(const std::string& strPropertyName);
    virtual const AFGUID& GetPropertyObject(const std::string& strPropertyName);

    virtual bool FindRecord(const std::string& strRecordName);

    virtual bool SetRecordBool(const std::string& strRecordName, const int nRow, const int nCol, const bool value);
    virtual bool SetRecordInt(const std::string& strRecordName, const int nRow, const int nCol, const int32_t value);
    virtual bool SetRecordInt64(const std::string& strRecordName, const int nRow, const int nCol, const int64_t value);
    virtual bool SetRecordFloat(const std::string& strRecordName, const int nRow, const int nCol, const float value);
    virtual bool SetRecordDouble(const std::string& strRecordName, const int nRow, const int nCol, const double value);
    virtual bool SetRecordString(const std::string& strRecordName, const int nRow, const int nCol, const std::string& value);
    virtual bool SetRecordObject(const std::string& strRecordName, const int nRow, const int nCol, const AFGUID& value);

    virtual bool SetRecordBool(const std::string& strRecordName, const int nRow, const std::string& strColTag, const bool value);
    virtual bool SetRecordInt(const std::string& strRecordName, const int nRow, const std::string& strColTag, const int32_t value);
    virtual bool SetRecordInt64(const std::string& strRecordName, const int nRow, const std::string& strColTag, const int64_t value);
    virtual bool SetRecordFloat(const std::string& strRecordName, const int nRow, const std::string& strColTag, const float value);
    virtual bool SetRecordDouble(const std::string& strRecordName, const int nRow, const std::string& strColTag, const double value);
    virtual bool SetRecordString(const std::string& strRecordName, const int nRow, const std::string& strColTag, const std::string& value);
    virtual bool SetRecordObject(const std::string& strRecordName, const int nRow, const std::string& strColTag, const AFGUID& value);

    virtual bool GetRecordBool(const std::string& strRecordName, const int nRow, const int nCol);
    virtual int32_t GetRecordInt(const std::string& strRecordName, const int nRow, const int nCol);
    virtual int64_t GetRecordInt64(const std::string& strRecordName, const int nRow, const int nCol);
    virtual float GetRecordFloat(const std::string& strRecordName, const int nRow, const int nCol);
    virtual double GetRecordDouble(const std::string& strRecordName, const int nRow, const int nCol);
    virtual const std::string& GetRecordString(const std::string& strRecordName, const int nRow, const int nCol);
    virtual const AFGUID& GetRecordObject(const std::string& strRecordName, const int nRow, const int nCol);

    virtual bool GetRecordBool(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual int32_t GetRecordInt(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual int64_t GetRecordInt64(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual float GetRecordFloat(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual double GetRecordDouble(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual const std::string& GetRecordString(const std::string& strRecordName, const int nRow, const std::string& strColTag);
    virtual const AFGUID& GetRecordObject(const std::string& strRecordName, const int nRow, const std::string& strColTag);

    //////////////////////////////////////////////////////////////////////////
    virtual ARK_SHARE_PTR<AFIPropertyMgr> GetPropertyManager();
    virtual ARK_SHARE_PTR<AFIRecordManager> GetRecordManager();
    virtual ARK_SHARE_PTR<AFIHeartBeatManager> GetHeartBeatManager();
    virtual ARK_SHARE_PTR<AFIEventManager> GetEventManager();

protected:
    virtual bool AddRecordCallBack(const std::string& strRecordName, const RECORD_EVENT_FUNCTOR_PTR& cb);

    virtual bool AddPropertyCallBack(const std::string& strCriticalName, const PROPERTY_EVENT_FUNCTOR_PTR& cb);

    virtual bool AddHeartBeat(const std::string& strHeartBeatName, const HEART_BEAT_FUNCTOR_PTR& cb, const int64_t nTime, const int nCount);

private:
    AFGUID mSelf;

    ARK_SHARE_PTR<AFIRecordManager> m_pRecordManager;
    ARK_SHARE_PTR<AFIHeartBeatManager> m_pHeartBeatManager;
    ARK_SHARE_PTR<AFIPropertyMgr> m_pPropertyManager;
    ARK_SHARE_PTR<AFIEventManager> m_pEventManager;
};

