//
//  CLuaFn.cpp
//  HelloLua
//
//  Created by Hanson on 13-11-21.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include "CLuaFn.h"


CLuaFn::CLuaFn(void) {
    
}

CLuaFn::~CLuaFn(void) {
    
}

void CLuaFn::Init() {
    if(NULL == m_pState) {
        m_pState = luaL_newstate();
        luaL_openlibs(m_pState);
    }
}

void CLuaFn::Close() {
    if(NULL != m_pState) {
        lua_close(m_pState);
        m_pState = NULL;
    }
}

bool CLuaFn::LoadLuaFile(const char* pFileName) {
    int nRet = 0;
    if(NULL == m_pState) {
        printf("[CLuaFn:: LoadLuaFile]m_pState is NULL./n");
        return false;
    }
    
    nRet = luaL_dofile(m_pState, pFileName);
    if (nRet != 0) {
        printf("[CLuaFn:: LoadLuaFile]luaL_loadfile(%s) is file(%d)(%s)./n", pFileName, nRet, lua_tostring(m_pState, -1));
        return false;
    }
    
    return true;
}

bool CLuaFn::CallFileFn(const char* pFunctionName, int nParam1, int nParam2) {
    int nRet = 0;
    if(NULL == m_pState)
    {
        printf("[CLuaFn::CallFileFn]m_pState is NULL./n");
        return false;
    }
    
    lua_getglobal(m_pState, pFunctionName);
    
    lua_pushnumber(m_pState, nParam1);
    lua_pushnumber(m_pState, nParam2);
    
    int nIn = lua_gettop(m_pState);
    printf("nIn:%d \n", nIn);
    printf("%f, %f, %f", lua_tonumber(m_pState, -3), lua_tonumber(m_pState, -2), lua_tonumber(m_pState, -1));
    
    nRet = lua_pcall(m_pState, 2, 1, 0);
    if (nRet != 0)
    {
        printf("[CLuaFn::CallFileFn]call function(%s) error(%d)./n", pFunctionName, nRet);
        return false;
    }
    
    if (lua_isnumber(m_pState, -1) == 1)
    {
        int nSum = lua_tonumber(m_pState, -1);
        printf("[CLuaFn::CallFileFn]Sum = %d.\n", nSum);
    }
    
    int nOut = lua_gettop(m_pState);
    printf("nOut:%d \n", nOut);
    lua_settop(m_pState, -2);
    printf("nOut:%d \n", nOut);
    
    return true;
}

