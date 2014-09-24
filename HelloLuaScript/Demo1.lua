Set = {}
Set.mt = {}
function Set.new(t)
	local set = {}
	setmetatable(set, Set.mt)
	for _, l in ipairs(t) do
		set[l] = true
	end
	return set
end

function Set.union(a,b)
	local res = Set.new{}
	for k in pairs(a) do res[k] = true end
	for k in pairs(b) do res[k] = true end
	return res
end

function Set.tostring(set)
	local s ="{"
	local sep = ""
	for e in pairs(set) do
		s = s .. sep .. e
		sep = ", "
	end
	return s .. "}"
end

function Set.print(s)
	print(Set.tostring(s))
end

Set.mt.__add = Set.union
Set.mt.__tostring = Set.tostring

s1 = Set.new({1,2,3})
s2 = Set.new({10,20,30})

s3 = s1 + s2
Set.print(s3)

print(s3)


--function Set.new(t)
--	local set = {}
--	setmetatable(set, Set.mt)
--	for _, l in ipairs(t) do set[l] = true end
--	return set
--end

