//
//  CLuaFn.h
//  HelloLua
//
//  Created by Hanson on 13-11-21.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#ifndef __HelloLua__CLuaFn__
#define __HelloLua__CLuaFn__

#include <iostream>
#include "lua.hpp"

class CLuaFn
{
public:
    CLuaFn(void);
    ~CLuaFn(void);
    
    void Init();            //初始化Lua对象指针参数
    void Close();         //关闭Lua对象指针
    
    bool LoadLuaFile(const char* pFileName);                              //加载指定的Lua文件
    bool CallFileFn(const char* pFunctionName, int nParam1, int nParam2);        //执行指定Lua文件中的函数
    
private:
    lua_State* m_pState;   //这个是Lua的State对象指针，你可以一个lua文件对应一个。
};

#endif /* defined(__HelloLua__CLuaFn__) */
