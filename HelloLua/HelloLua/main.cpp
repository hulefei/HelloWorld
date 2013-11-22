//
//  main.cpp
//  HelloLua
//
//  Created by Hanson on 13-10-16.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include <iostream>
#include "lua.hpp"
#include "CLuaFn.h"

int main(int argc, const char * argv[]) {
//    char buff[256];
//    int error;
//    lua_State *L = luaL_newstate();
//    luaL_openlibs(L);        /* opens the standard libraries */
//    while (fgets(buff, sizeof(buff), stdin) != NULL) {
//        error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);
//        if (error) {
//            fprintf(stderr, "%s\n", lua_tostring(L, -1));
//            lua_pop(L, 1);  /* pop error message from the stack */
//        }
//    }
//    lua_close(L);
//    
//    return 0;
    
    CLuaFn LuaFn;
    
    LuaFn.Init();
    
    LuaFn.LoadLuaFile("/Users/hanson/Documents/Workspace/GitHub/HelloWorld/HelloLua/HelloLua/Sample.lua");
    
    
    LuaFn.CallFileFn("func_Add", 1, 10);
    LuaFn.CallFileFn("func_Add", 2, 20);
    LuaFn.CallFileFn("func_Add", 3, 30);
    
    getchar();
    
    return 0;
}

