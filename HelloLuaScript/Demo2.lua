Window = {}
Window.mt = {}
Window.prototype = {x=0,y=0,width=100,height=100}
--Window.mt = {__index = function () return 111 end}
--Window.mt.__index = function (table, key)
--	return Window.prototype[key]
--end
Window.mt.__index = Window.prototype
function Window.new (o)
	setmetatable(o, Window.mt)
	return o
end

w = Window.new{x=10,y=20}
print(w.x)
print(w.width)
print(w.width1)

print()

--
--local mt = {__index = function (t) return t.__ end}

--------------------------------------------------------------------------------
tab = { x=1, y = 2}


--always create
--function setDefault(t, d)
--	t.__ = d
--	local mt = {__index = function () return d end}
--	setmetatable(t, mt)
--end

--create once
local mt = {__index = function(t) return t.__ end}
function setDefault(t, d)
	t.__ = d
	setmetatable(t, mt)
end

setDefault(tab, 13)
print(tab.x)
print(tab.width)





