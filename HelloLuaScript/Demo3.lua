t = {} --original table
-- keep a private access to original table
local _t = t
--create proxy
t = {}
--creat metatable
local mt = {
	__index = function (t, k)
		print("*access to element" .. tostring(k))
		return _t[k] --access the original table
	end,
	__newindex = function (t,k,v)
		print("*update of element " .. tostring(k) .. " to " .. tostring(v))
		_t[k] = v --update original table
	end
}
setmetatable(t, mt)

t[2] = "hello"
print(t[2])

----------------------------------------------------------------------------------------
local index = {} -- create private index
--create metatable
local mt = {
	__index = function (t, k)
		print("*access to element" .. tostring(k))
		return t[index][k] --access the original table
	end,
	
	__newindex = function (t,k,v)
		print("*update of element" .. tostring(k) .. " to " .. tostring(v))
		t[index][k] = v --update
	end
}
function track(t)
	local proxy = {}
	proxy[index] = t
	setmetatable(proxy, mt)
	return proxy
end
a = {}
a = track(a)
a[2] = 100
print(a[2])
print()
----------------------------------------------------------------------------------------
function readOnly(t)
	local proxy = {}
	local mt = {
		__index = t,
		__newindex = function (t,k,v)
			error("attempt to update a read-only table", 2)
		end
	}
	setmetatable(proxy, mt)
	return proxy
end

days = readOnly{"Sunday", "Monday"}
print(days[1])
days[2] = "aaaa"


