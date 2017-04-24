local counter = 1

function permutation(n, index, v, set)
    if index>n then
        local line = ''
        for i=1,n do
            line = line .. ' ' .. v[i]
        end
        print(counter .. ' = ' ..line)
        counter = counter+1
        return
    end

    v[index] = 0
    for i=1,n do
        if not set[i] then
            v[index] = i
            intoDiagonal = false
            for j=1,index-1 do
                if v[index-j]+j == v[index] or v[index-j]-j == v[index] then
                    intoDiagonal = true
                    break
                end
            end
            if not intoDiagonal then
                set[i] = true
                permutation(n,index+1,v,set)
                set[i] = nil
            end
        end
    end
end

function queen()
    permutation(8,1,{},{})
end

queen()
