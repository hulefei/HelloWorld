--name1 = "aa"
--for n in pairs(_G) do
--	print(n)
--end
a = 100
setmetatable(_G, {
	__newindex = function (_,n)
		error("attempt to write to undeclared variable" .. n, 2)
	end,
	__index = function (_, n)
		error("attempt to read undeclared variable" .. n, 2)
	end
})

a = 1